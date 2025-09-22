#ifndef MODLE_H_
#define MODLE_H_

#include <stdint.h>

typedef struct
{
  uint32_t count;
  char     name[16];
}model_t;

typedef struct
{
  uint64_t capacity;
  uint64_t count;
  model_t  list[0];
}models_t;

typedef void (*model_progress_cb)(float percent);


void      model_init(const char* const json_file, model_progress_cb on_progress);
void      model_deinit();
models_t* model_count();


#endif /* MODLE_H_ */
