#include <stdio.h>
#include "common/error.h"
#include "storage/file.h"
#include "alg/bitarray.h"
#include "alg/alg.h"


result_u32 alg_count_pure(const char* const file_path)
{
  /* Data set file */
  result_u32 result = file_get_size(file_path);
  if (MC_SUCCESS != result.error) {
    return result;
  }
  uint32_t file_size = result.value;

  const result_ptr ptr = file_open(file_path);
  if (MC_SUCCESS != ptr.error) {
    return (result_u32){.value = 0, .error = ptr.error};
  }
  file_t* const file = ptr.value;


  /* Bit array as flag of visited */
  const uint32_t nums_count = file_size / sizeof(uint32_t);
  bitarr_t* const visited = bitarr_create(nums_count);
  if (NULL == visited) {
    return (result_u32){.value = 0, .error = MC_ERR_BAD_ALLOC};
  }


  /* Chunk memory */
  uint32_t buffer[1000] = {0};
  const uint32_t BUF_LEN = sizeof(buffer) / sizeof(*buffer);


  /* Read chunk by chunk */
  result = (result_u32){.value = 0, .error = MC_SUCCESS};
  while (file_size) {
    result = file_read(file, buffer, sizeof(buffer));
    if (MC_SUCCESS != result.error) {
      break;
    }

    /* Use number as bit array index */
    for (uint32_t index = 0; index < BUF_LEN; index++) {
      bitarr_set(visited, buffer[index], 1);
    }

    file_size -= result.value;
  }

  if (MC_SUCCESS == result.error) {
    uint32_t pure_numbers = 0;
    for (uint32_t index = 0; index < visited->capacity; index++) {
      if (bitarr_get(visited, index)) {
        pure_numbers++;
      }
    } 

    result.value = pure_numbers;
  }

  /* Free resources */
  bitarr_destroy(visited);
  file_close(file);

  return result;
}

result_u32 alg_count_unique(const char* const file_path)
{
  /* Data set file */
  result_u32 result = file_get_size(file_path);
  if (MC_SUCCESS != result.error) {
    return result;
  }
  uint32_t file_size = result.value;

  const result_ptr ptr = file_open(file_path);
  if (MC_SUCCESS != ptr.error) {
    return (result_u32){.value = 0, .error = ptr.error};
  }
  file_t* const file = ptr.value;
  
  
  /* Bit array as flag of visited */
  const uint32_t nums_count = file_size / sizeof(uint32_t);
  bitarr_t* visited = bitarr_create(nums_count);
  if (NULL == visited) {
    return (result_u32){.value = 0, .error = MC_ERR_BAD_ALLOC};
  }
  bitarr_t* multi_visited = bitarr_create(nums_count);
  if (NULL == visited) {
    return (result_u32){.value = 0, .error = MC_ERR_BAD_ALLOC};
  }


  /* Chunk memory */
  uint32_t buffer[1000] = {0};
  const uint32_t BUF_LEN = sizeof(buffer) / sizeof(*buffer);


  /* Read chunk by chunk */
  result = (result_u32){.value = 0, .error = MC_SUCCESS};
  while (file_size) {
    result_u32 result = file_read(file, buffer, sizeof(buffer));
    if (MC_SUCCESS != result.error) {
      break;
    }


    /* Use number as bit array index */
    for (uint32_t index = 0; index < BUF_LEN; index++) {
      if (bitarr_get(visited, buffer[index])) {
        bitarr_set(multi_visited, buffer[index], 1);
      }
      bitarr_set(visited, buffer[index], 1);
    }

    file_size -= result.value;
  }

  if (MC_SUCCESS == result.error) {   
    uint32_t unique_numbers = 0;
    for (uint32_t index = 0; index < visited->capacity; index++) {
      if (bitarr_get(visited, index) && !bitarr_get(multi_visited, index)) {
        unique_numbers++;
      }
    }
    
    result.value = unique_numbers;
  }


  /* Free resources */
  bitarr_destroy(visited);
  file_close(file);

  return result;
}
