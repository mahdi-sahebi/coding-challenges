#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <inttypes.h>
#include <yajl/yajl_parse.h>
#include <yajl/yajl_gen.h>
#include "model/model.h"


typedef struct
{
  const char*       json_file;
  model_progress_cb on_progress;
}config_t;

typedef struct
{
  char      Buffer[2 * 1024];
  model_t   CurrentModel;
  config_t  Config;
  models_t* Models;
  bool      IsModel;
}manager_t;

static manager_t Manager = {0}; 

typedef struct
{
  unsigned int numFrees;
  unsigned int numMallocs;
} yajlTestMemoryContext;

#define TEST_CTX(vptr) ((yajlTestMemoryContext *) (vptr))

static void model_add(const char* const model, uint32_t length)
{
  for (uint32_t index = 0; index < Manager.Models->count; index++) {
    if (0 == memcmp(Manager.Models->list[index].name, model, length)) {
      Manager.Models->list[index].count++;
      return;
    }
  }

  if (Manager.Models->count >= Manager.Models->capacity) {
    printf("Container is full\n");
    return;
  }

  memcpy(Manager.Models->list[Manager.Models->count].name, model, length);
  Manager.Models->list[Manager.Models->count].name[length] = '\0';
  Manager.Models->list[Manager.Models->count].count = 1;
  Manager.Models->count++;
}

static void yajlTestFree(void * ctx, void * ptr)
{
  TEST_CTX(ctx)->numFrees++;
  free(ptr);
}

static void * yajlTestMalloc(void * ctx, size_t sz)
{
  TEST_CTX(ctx)->numMallocs++;
  return malloc(sz);
}

static void * yajlTestRealloc(void * ctx, void * ptr, size_t sz)
{
  if (ptr == NULL) {
    TEST_CTX(ctx)->numMallocs++;
  } else if (sz == 0) {
    TEST_CTX(ctx)->numFrees++;
  }

  return realloc(ptr, sz);
}

static int test_yajl_null(void *ctx)
{
  return 1;
}

static int test_yajl_boolean(void * ctx, int boolVal)
{
  return 1;
}

static int test_yajl_integer(void *ctx, long long integerVal)
{
  return 1;
}

static int test_yajl_double(void *ctx, double doubleVal)
{
  return 1;
}

static int test_yajl_string(void *ctx, const unsigned char * stringVal, size_t stringLen)
{
  if (Manager.IsModel) {
    model_add(stringVal, stringLen);
    Manager.IsModel = false;
  }

  return 1;
}

static int test_yajl_map_key(void *ctx, const unsigned char* stringVal, size_t stringLen)
{
  if (0 == memcmp("model", stringVal, stringLen)) {
    Manager.IsModel = true;
  }

  return 1;
}

static int test_yajl_start_map(void *ctx)
{
  return 1;
}

static int test_yajl_end_map(void *ctx)
{
  return 1;
}

static int test_yajl_start_array(void *ctx)
{
  return 1;
}

static int test_yajl_end_array(void *ctx)
{
  return 1;
}

static yajl_callbacks callbacks = {
    test_yajl_null,
    test_yajl_boolean,
    test_yajl_integer,
    test_yajl_double,
    NULL,
    test_yajl_string,
    test_yajl_start_map,
    test_yajl_map_key,
    test_yajl_end_map,
    test_yajl_start_array,
    test_yajl_end_array
};

uint64_t file_get_size(const char* const path)
{
  FILE* file = fopen(path, "rb");
  fseek(file, 0, SEEK_END);
  const uint64_t size = ftell(file);
  fclose(file);
  return size;
}

static void reset()
{
  Manager.Models->count = 0;
}

static void parse()
{
  yajl_handle hand;
  FILE *file;
  yajl_status stat;
  int i, j;

  yajlTestMemoryContext memCtx = { 0,0 };

  yajl_alloc_funcs allocFuncs = {
    yajlTestMalloc,
    yajlTestRealloc,
    yajlTestFree,
    (void *) NULL
  };

  allocFuncs.ctx = (void *)&memCtx;
  hand = yajl_alloc(&callbacks, &allocFuncs, NULL);

  const uint64_t file_size = file_get_size(Manager.Config.json_file);
  file = fopen(Manager.Config.json_file, "r");
  if (NULL == file) {
    reset();
    return;
  }

  uint64_t total_read_size = 0;
  while (true) {
    const uint32_t read_size = fread(Manager.Buffer, 1, sizeof(Manager.Buffer), file);
    if ((-1 == read_size) || (0 == read_size)) {
      break;
    }

    total_read_size += read_size;

    Manager.Config.on_progress(total_read_size / (float)file_size);
    stat = yajl_parse(hand, Manager.Buffer, read_size);
    if (stat != yajl_status_ok) {
      break;
    }
  }

  stat = yajl_complete_parse(hand);
  if (stat != yajl_status_ok) {
    unsigned char * str = yajl_get_error(hand, 0, Manager.Buffer, total_read_size);
    fflush(stdout);
    fprintf(stderr, "%s", (char *) str);
    yajl_free_error(hand, str);
  }

  yajl_free(hand);
  fclose(file);
  fflush(stderr);
  fflush(stdout);
}

void model_init(const char* const json_file, uint16_t capacity, model_progress_cb on_progress)
{
  Manager.Config = (config_t){.json_file = json_file, .on_progress = on_progress};
  const uint32_t size = sizeof(models_t) + (sizeof(model_t) * capacity);
  Manager.Models = malloc(size);
  memset(Manager.Models, 0x00, size);

  Manager.Models->capacity = capacity;
  Manager.Models->count = 0;
}

void model_deinit()
{
  if (NULL != Manager.Models) {
    free(Manager.Models);
    Manager.Models = NULL;
  }
}

models_t* model_count()
{
  reset();
  parse();
  return Manager.Models;
}

void model_print()
{
  printf("\n\n\n Count of models: %" PRIu64 "\n", Manager.Models->count);
  for (uint32_t index = 0; index < Manager.Models->count; index++) {
    printf("[%s]: %d Times\n", Manager.Models->list[index].name, Manager.Models->list[index].count);
  }
  printf("\n\n\n");
}