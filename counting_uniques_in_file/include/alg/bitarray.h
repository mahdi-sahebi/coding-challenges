#ifndef ALGORITHM_BITARRAY_H_
#define ALGORITHM_BITARRAY_H_

#include <stdint.h>
#include <stdbool.h>


typedef struct
{
  uint32_t capacity;
  uint8_t  data[0];
}bitarr_t;



bitarr_t* bitarr_t_create(uint32_t capacity);
void      bitarr_t_destroy(bitarr_t* this);
void      bitarr_t_clear(bitarr_t* this);
void      bitarr_t_set(bitarr_t* this, uint32_t index, bool bit);
bool      bitarr_t_get(bitarr_t* this, uint32_t index);


#endif /* ALGORITHM_BITARRAY_H_ */

