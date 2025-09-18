#include <stdio.h>
#include "common/error.h"
#include "alg/alg.h"


uint32_t alg_count_pure(const char* const file_path)
{
  uint32_t file_size = file_get_size(file_path);
  file_t* file = file_open(file_path);

  const uint32_t nums_count = file_size / sizeof(uint32_t);

  bitarr_t* bitarray = bitarr_create(nums_count);


  uint32_t buffer[1000] = {0};
  const uint32_t BUF_LEN = sizeof(buffer) / sizeof(*buffer);


  while (file_size) {
    result_u32 result = file_read(file, buffer, sizeof(buffer));

    if (MC_SUCCESS != result.error) {
      printf("Error\n");
      break;
    }

    for (uint32_t index = 0; index < BUF_LEN; index++) {
      bitarr_set(bitarray, buffer[index], 1);
    }

    file_size -= result.value;
  }

  uint32_t pure_numbers = 0;
  for (uint32_t index = 0; index < bitarray->capacity; index++) {
    if (bitarr_get(bitarray, index)) {
      pure_numbers++;
    }
  }

  bitarr_destroy(bitarray);
  file_close(file);

  return pure_numbers;
}

uint32_t alg_count_unique(const char* const file_path)
{
  uint32_t file_size = file_get_size(file_path);
  file_t* file = file_open(file_path);

  const uint32_t nums_count = file_size / sizeof(uint32_t);

  bitarr_t* existance_flag = bitarr_create(nums_count);
  bitarr_t* multi_visit_flag = bitarr_create(nums_count);


  uint32_t buffer[1000] = {0};
  const uint32_t BUF_LEN = sizeof(buffer) / sizeof(*buffer);


  while (file_size) {
    result_u32 result = file_read(file, buffer, sizeof(buffer));

    if (MC_SUCCESS != result.error) {
      printf("Error\n");
      break;
    }

    for (uint32_t index = 0; index < BUF_LEN; index++) {
      if (bitarr_get(existance_flag, buffer[index])) {
        bitarr_set(multi_visit_flag, buffer[index], 1);
      }
      bitarr_set(existance_flag, buffer[index], 1);
    }

    file_size -= result.value;
  }

  uint32_t unique_numbers = 0;
  for (uint32_t index = 0; index < existance_flag->capacity; index++) {
    if (bitarr_get(existance_flag, index) && !bitarr_get(multi_visit_flag, index)) {
      unique_numbers++;
    }
  }


  bitarr_destroy(existance_flag);
  file_close(file);

  return unique_numbers;
}
