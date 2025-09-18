#ifndef ERROR_H_
#define ERROR_H_

#include <stdint.h>


typedef enum
{
  MC_SUCCESS = 0,
  MC_ERR_RUNTIME
}error_t;


typedef struct
{
  uint32_t value;
  error_t  error;
}result_u32;


#endif /* ERROR_H_ */
