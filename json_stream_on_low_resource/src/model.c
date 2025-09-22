#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <yajl/yajl_parse.h>
#include <yajl/yajl_gen.h>
#include "model/model.h"


static model_t CurrentModel = {0};
static models_t* Models = NULL;


static void disk_add(const char* const model, uint32_t length)
{
  for (uint32_t index = 0; index < Models->count; index++) {
    if (0 == memcmp(Models->list[index].name, model, length)) {
      Models->list[index].count++;
      return;
    }
  }

  if (Models->count >= Models->capacity) {
    printf("Container is full\n");
    return;
  }

  memcpy(Models->list[Models->count].name, model, length);
  Models->list[Models->count].name[length] = '\0';
  Models->list[Models->count].count = 1;
  Models->count++;
}

void model_init(const char* const json_file, uint16_t capacity, model_progress_cb on_progress)
{
  const uint32_t size = sizeof(models_t) + (sizeof(model_t) * capacity);
  Models = malloc(size);
  memset(Models, 0x00, size);

  Models->capacity = capacity;
  Models->count = 0;
}

void model_deinit()
{
  free(Models);
}

models_t* model_count()
{
  return Models;
}
