#ifndef STORAGE_FILE_H_
#define STORAGE_FILE_H_

#include <stdint.h>
#include <stdbool.h>
#include "common/error.h"


typedef void file_t;


file_t*  file_open(const char* const path);
error_t  file_close(file_t* this);
uint32_t file_read(file_t* this, void* buffer, uint32_t size);
uint32_t file_write(file_t* this, const void* buffer, uint32_t size);
uint32_t file_append(file_t* this, void* buffer, uint32_t size);
void     file_clear(file_t* this);
uint32_t file_seek(file_t* this, uint32_t offset);
bool     file_eof(file_t* this);
uint32_t file_get_size(const char* const path);
bool     file_create(const char* const path);
bool     file_exists(const char* const path);
bool     file_delete(const char* const path);


#endif /* STORAGE_FILE_H_ */
