/* TODO(MN): Return error for all APIs. use result_u32, result_ptr
 * Check all arguments
 *
 */
#include <stdio.h>
#include "storage/file.h"


result_ptr file_open(const char* const path)
{
  FILE* file = fopen(path, "rb+");

  if (NULL == file) {
    return (result_ptr){.value = NULL, .error = MC_ERR_BAD_ALLOC};
  }

  return (result_ptr){.value = file, .error = MC_SUCCESS};
}

error_t file_close(file_t* this)
{
  if (NULL == this) {
    return MC_ERR_INVALID_ARGUMENT;
  }

  return (0 == fclose(this));
}

result_u32 file_read(file_t* this, void* buffer, uint32_t size)
{
  if ((NULL == this) || (NULL == buffer)) {
    return (result_u32){.value = 0, .error = MC_ERR_INVALID_ARGUMENT};
  }

  if (0 != size) {
    size = fread(buffer, sizeof(char), size, this);
  }

  return (result_u32){.value = size, .error = MC_SUCCESS};
}

result_u32 file_write(file_t* this, const void* buffer, uint32_t size)
{
  if ((NULL == this) || (NULL == buffer)) {
    return (result_u32){.value = 0, .error = MC_ERR_INVALID_ARGUMENT};
  }

  if (0 != size) {
    size = fwrite(buffer, sizeof(char), size, this);
  }

  return (result_u32){.value = size, .error = MC_SUCCESS};
}

result_u32 file_append(file_t* this, void* buffer, uint32_t size)
{
  if ((NULL == this) || (NULL == buffer)) {
    return (result_u32){.value = 0, .error = MC_ERR_INVALID_ARGUMENT};
  }

  if (0 != size) {
    fseek(this, 0, SEEK_END);
    size = fwrite(buffer, sizeof(char), size, this);
  }

  return (result_u32){.value = size, .error = MC_SUCCESS};
}

error_t file_clear(file_t* this)
{
  if (NULL == this) {
    return MC_ERR_INVALID_ARGUMENT;
  }
  
  FILE* file = fopen("", "wb");

  if (NULL != file) {
    fclose(file);
  }
}

result_u32 file_seek(file_t* this, uint32_t offset)
{
  if (NULL == this) {
    return (result_u32){.value = 0, .error = MC_ERR_INVALID_ARGUMENT};
  }

  const uint32_t index = fseek(this, offset, SEEK_SET);
  return (result_u32){.value = index, .error = MC_SUCCESS};
}

result_bit file_eof(file_t* this)
{
  if (NULL == this) {
    return (result_bit){.value = false, .error = MC_ERR_INVALID_ARGUMENT};
  }

  return (result_bit){.value = feof(this), .error = MC_SUCCESS};
}

result_u32 file_get_size(const char* const path)
{
  if (NULL == path) {
    return (result_u32){.value = 0, .error = MC_ERR_INVALID_ARGUMENT};
  }

  FILE* file = fopen(path, "rb");

  if (NULL != file) {
    fseek(file, 0, SEEK_END);
    const uint32_t size = ftell(file);
    fclose(file);
    return (result_u32){.value = size, .error = MC_SUCCESS};
  }

  return (result_u32){.value = 0, .error = MC_ERR_RUNTIME};
}

result_bit file_create(const char* const path)
{
  if (NULL == path) {
    return (result_bit){.value = false, .error = MC_ERR_INVALID_ARGUMENT};
  }

  FILE* file = fopen(path, "wb");

  if (NULL != file) {
    fclose(file);
    return (result_bit){.value = true, .error = MC_ERR_BAD_ALLOC};
  }

  return (result_bit){.value = false, .error = MC_ERR_BAD_ALLOC};
}

result_bit file_exists(const char* const path)
{
  if (NULL == path) {
    return (result_bit){.value = false, .error = MC_ERR_INVALID_ARGUMENT};
  }

  FILE* file = fopen(path, "rb");

  if (NULL != file) {
    fclose(file);
    return (result_bit){.value = true, .error = MC_SUCCESS};
  }

  return (result_bit){.value = false, .error = MC_ERR_RUNTIME};
}

result_bit file_delete(const char* const path)
{
  if (NULL == path) {
    return (result_bit){.value = false, .error = MC_ERR_INVALID_ARGUMENT};
  }

  const bool result = (0 == remove(path));
  return (result_bit){.value = result, .error = MC_SUCCESS};
}
