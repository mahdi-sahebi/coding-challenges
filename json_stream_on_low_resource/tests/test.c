#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <gtest/gtest.h>
#include "model/model.h"


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
  if (update_counter > 1000) {
    update_counter = 0;
    printf("%f%%\n", percent);
  }
}

TEST(model, big_file)
{
  const char* const json_file = "bigf.json";
  model_init(json_file, on_progress);
  const models_t* const modles = model_count();
  model_deinit();

  ASSERT_EQ(13 == models->count);
  const pair_t SAMPLES[13] = {
    {.name = "RDV2",-     .count = 33332954}
    {.name = "DRV1",-     .count = 33338513}
    {.name = "SSDLP2",-   .count = 33345174}
    {.name = "SSDF1",-    .count = 33328579}
    {.name = "123456789",-.count = 33327094}
    {.name = "HGST2048T",-.count = 33332531}
    {.name = "DSD07461", -.count = 33333959}
    {.name = "broken",-   .count = 33328584}
    {.name = "SSDDC1",-   .count = 33327742}
    {.name = "SCSI3HD",-  .count = 33329611}
    {.name = "HGST3T",-   .count = 33337292}
    {.name = "HGST8T",-   .count = 33337967}
    {.name = "MODEL",-    .count = 1}
  };
  const uint32_t SAMPLES_COUNT = sizeof(SAMPLES) / sizeof(*SAMPLES);

  for (uint32_t index = 0; index < models->count; index++) {
    const uint32_t sample_index = find_model_index(models->list[index].name, SAMPLES, SAMPLES_COUNT);
    ASSERT_NQ(sample_index, -1);
    ASSERT_EQ(SAMPLES[sample_index].count, modles->list[index].count);
  }
}

int main()
{
  InitGoogleTest();
  return RUN_ALL_TESTS();
}