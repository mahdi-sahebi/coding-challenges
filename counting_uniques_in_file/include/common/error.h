#ifndef ERROR_H_
#define ERROR_H_

#include <stdint.h>
#include <stdbool.h>


typedef enum
{
  MC_SUCCESS = 0,
  MC_ERR_RUNTIME,
  MC_ERR_BAD_ALLOC,
  MC_ERR_INVALID_ARGUMENT,
}error_t;


typedef struct
{
  uint32_t value;
  error_t  error;
}result_u32;

typedef struct
{
  bool value;
  error_t  error;
}result_bit;

typedef struct
{
  void*    value;
  error_t  error;
}result_ptr;


#endif /* ERROR_H_ */
