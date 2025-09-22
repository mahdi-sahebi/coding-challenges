/* TODO(MN): ASSERT APIs go out of function withtout free memories
 */
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>
#include "model/model.h"


typedef enum
{
  MC_SUCCESS = 0,
  MC_ERR_RUNTIME,
  MC_ERR_OUT_OF_RANGE,
}error_t;

#define STRING(EXP)\
  #EXP

#define ASSERT_EQ(EXP_1, EXP_2)\
do {\
  if ((EXP_1) != (EXP_2)) {\
    printf("[%s] is %" PRIu64 ", but expected to be %" PRIu64 "\n", STRING(EXP_1), (uint64_t)EXP_1, (uint64_t)EXP_2);\
    return MC_ERR_RUNTIME;\
  }\
} while (0)

#define ASSERT_NQ(EXP_1, EXP_2)\
do {\
  if ((EXP_1) == (EXP_2)) {\
    printf("[%s] is %" PRIu64 ", but expected to not be %" PRIu64 "\n", STRING(EXP_1), (uint64_t)EXP_1, (uint64_t)EXP_2);\
    return MC_ERR_RUNTIME;\
  }\
} while (0)

typedef struct
{
  uint32_t count;
  char*    name;
}pair_t;


static uint32_t find_model_index(const char* const model, const pair_t* const buffer, uint32_t capacity)
{
  for (uint32_t index = 0; index < capacity; index++) {
    if (0 == strcmp(model, buffer[index].name)) {
      return index;
    }
  }

  return -1;
}

static void on_progress(float percent)
{
  static uint16_t update_counter = 0;
  update_counter++;
  if (update_counter > 10000) {
    update_counter = 0;
    printf("%f%%\n", percent * 100);
  }
}

static int test_big_file()
{
  const char* const json_file = "/media/mahdi/common/repositories/bigf.json";
  model_init(json_file, 50, on_progress);
  const models_t* const models = model_count();

  ASSERT_EQ(models->count, 13);
  const pair_t SAMPLES[13] = {
    {.name = "RDV2",      .count = 33332954},
    {.name = "DRV1",      .count = 33338513},
    {.name = "SSDLP2",    .count = 33345174},
    {.name = "SSDF1",     .count = 33328579},
    {.name = "123456789", .count = 33327094},
    {.name = "HGST2048T", .count = 33332531},
    {.name = "DSD07461",  .count = 33333959},
    {.name = "broken",    .count = 33328584},
    {.name = "SSDDC1",    .count = 33327742},
    {.name = "SCSI3HD",   .count = 33329611},
    {.name = "HGST3T",    .count = 33337292},
    {.name = "HGST8T",    .count = 33337967},
    {.name = "MODEL",     .count = 1}
  };
  const uint32_t SAMPLES_COUNT = sizeof(SAMPLES) / sizeof(*SAMPLES);

  for (uint32_t index = 0; index < models->count; index++) {
    const uint32_t sample_index = find_model_index(models->list[index].name, SAMPLES, SAMPLES_COUNT);
    ASSERT_NQ(sample_index, -1);
    ASSERT_EQ(SAMPLES[sample_index].count, models->list[index].count);
  }

  model_print();
  model_deinit();
  return MC_SUCCESS;
}

int main()
{
  error_t error = MC_SUCCESS;

  error = test_big_file();
  if (error) {
    printf("test_big_file() failed - %u\n", error);
    return error;
  }

  return error;
}