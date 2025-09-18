#ifndef STORAGE_FILE_H_
#define STORAGE_FILE_H_

#include <stdint.h>
#include <stdbool.h>
#include "common/error.h"


typedef void file_t;


result_ptr file_open(const char* const path);
error_t    file_close(file_t* this);
result_u32 file_read(file_t* this, void* buffer, uint32_t size);
result_u32 file_write(file_t* this, const void* buffer, uint32_t size);
result_u32 file_append(file_t* this, void* buffer, uint32_t size);
error_t    file_clear(file_t* this);
result_u32 file_seek(file_t* this, uint32_t offset);
result_bit file_eof(file_t* this);
result_u32 file_get_size(const char* const path);
result_bit file_create(const char* const path);
result_bit file_exists(const char* const path);
result_bit file_delete(const char* const path);


#endif /* STORAGE_FILE_H_ */
