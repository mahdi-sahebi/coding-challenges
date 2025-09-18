#include <stdio.h>
#include "storage/file.h"


file_t* file_open(const char* const path)
{
  FILE* file = fopen(path, "rb+");
  return file;
}

error_t file_close(file_t* this)
{
  return fclose(this);
}

uint32_t file_read(file_t* this, void* buffer, uint32_t size)
{
  return fread(buffer, sizeof(char), size, this);
}

uint32_t file_write(file_t* this, const void* buffer, uint32_t size)
{
  return fwrite(buffer, sizeof(char), size, this);
}

uint32_t file_append(file_t* this, void* buffer, uint32_t size)
{
  fseek(this, 0, SEEK_END);
  return fwrite(buffer, sizeof(char), size, this);
}

void file_clear(file_t* this)
{
  FILE* file = fopen("", "wb");

  if (NULL != file) {
    fclose(file);
  }
}

uint32_t file_seek(file_t* this, uint32_t offset)
{
  return fseek(this, offset, SEEK_SET);
}

bool file_eof(file_t* this)
{
  return feof(this);
}

uint32_t file_get_size(const char* const path)
{
  FILE* file = fopen(path, "rb");

  if (NULL != file) {
    fseek(file, 0, SEEK_END);
    const uint32_t size = ftell(file);
    fclose(file);
    return size;
  }

  return 0;
}

bool file_create(const char* const path)
{
  FILE* file = fopen(path, "wb");

  if (NULL != file) {
    fclose(file);
    return true;
  }

  return false;
}

bool file_exists(const char* const path)
{
  FILE* file = fopen(path, "rb");

  if (NULL != file) {
    fclose(file);
    return true;
  }

  return false;
}

bool file_delete(const char* const path)
{
  return (0 == remove(path));
}
