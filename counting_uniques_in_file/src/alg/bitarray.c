#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "alg/bitarray.h"


#define BITS_PER_BYTE     8
#define MOD_8(NUM)        ((NUM) & 7)


static uint32_t required_size(uint32_t capacity)
{
  return (uint32_t)ceilf(capacity / (float)BITS_PER_BYTE);
}

void bitarr_clear(bitarr_t* this)
{
  const uint32_t size = required_size(this->capacity);
  memset(this->data, 0x00, size);
}

bitarr_t* bitarr_create(uint32_t capacity)
{
  const uint32_t size = required_size(capacity);
  bitarr_t* this = malloc(sizeof(bitarr_t) + size);

  memset(this, 0x00, size);
  this->capacity = capacity;

  return this;
}

void bitarr_destroy(bitarr_t* this)
{
  free(this);
}

void bitarr_set(bitarr_t* this, uint32_t index, bool bit)
{
  if (index >= this->capacity) {
    return;// TODO(MN): Error
  }

  const uint32_t byte_index = index / BITS_PER_BYTE;
  const uint8_t bit_index = MOD_8(index);

  if (bit) {
    this->data[byte_index] |= (1 << bit_index);
  } else {
    this->data[byte_index] &= ~(1 << bit_index);
  }
}

bool bitarr_get(bitarr_t* this, uint32_t index)
{
  if (index >= this->capacity) {
    return false;// TODO(MN): Error
  }

  const uint32_t byte_index = index / BITS_PER_BYTE;
  const uint8_t bit_index = MOD_8(index);
  return (this->data[byte_index] >> bit_index) & 0b1;
}

#undef BITS_PER_BYTE
#undef MOD_8
