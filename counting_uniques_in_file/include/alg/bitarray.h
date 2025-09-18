#ifndef ALGORITHM_BITARRAY_H_
#define ALGORITHM_BITARRAY_H_

#include <stdint.h>
#include <stdbool.h>


typedef struct
{
  uint32_t capacity;
  uint8_t  data[0];
}bitarr_t;



bitarr_t* bitarr_create(uint32_t capacity);
void      bitarr_destroy(bitarr_t* this);
void      bitarr_clear(bitarr_t* this);
void      bitarr_set(bitarr_t* this, uint32_t index, bool bit);
bool      bitarr_get(bitarr_t* this, uint32_t index);


#endif /* ALGORITHM_BITARRAY_H_ */

