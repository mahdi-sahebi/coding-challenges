#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "com"


#define TOKEN_STR(EXP)      #EXP

#define MC_TEST(TEST_CASE)\
    do {\
        const char* const function_name = TOKEN_STR(TEST_CASE);\
        printf("%s - Running...\n", TEST_CASE());\
        \
        error_t error = pure_number_without_unique();\
        if (error) {\
        printf("%s - failed: %u\n", function_name, error);\
        } else {\
        printf("%s - passed\n", function_name);\
        }\
    } while (0)


static uint32_t rand_range(uint32_t lower, uint32_t upper)
{
  const float norm = (rand() / (float)RAND_MAX);
  return (norm * (upper - lower)) + lower;
}

void generate_without_unique_dataset(const char* const path)
{
  if (file_exists(path)) {
    file_delete(path);
  }

  file_create(path);
  file_t* file = file_open(path);


  uint32_t buffer[1000] = {0};
  const uint32_t BATCH_COUNT = sizeof(buffer) / sizeof(*buffer);

  for (uint32_t batch_index = 0; batch_index < (1000000000 / BATCH_COUNT); batch_index++) {

    for (uint32_t index = 0; index < BATCH_COUNT; index++) {
      buffer[index] = index;
    }

    file_append(file, buffer, sizeof(buffer));
  }

  file_close(file);
}

static int pure_number_without_unique()
{
  printf("Generating data set...\n");
  generate_without_unique_dataset("data_set.bin");

  printf("Processing...\n");
  const uint32_t count = alg_count_pure("data_set.bin");
  if (count != 1000) {
    printf("Count: %u, Expected %u\n", count, 1000);
    return MC_ERR_RUNTIME;
  }

  return MC_SUCCESS;
}

static int pure_number_with_unique()
{
  printf("Generating data set...\n");
  generate_with_unique_dataset("data_set.bin");
 
  printf("Processing...\n");
  const uint32_t count = alg_count_pure("data_set.bin");
  if (count != 1000999) {
    printf("Count: %u, Expected %u\n", count, 1000);
    return MC_ERR_RUNTIME;
  }

  return MC_SUCCESS;
}
  
static int unique_number_without_unique()
{
  printf("Generating data set...\n");
  generate_without_unique_dataset("data_set.bin");

  printf("Processing...\n");
  const uint32_t count = alg_count_unique("data_set.bin");
  if (count != 0) {
    printf("Count: %u, Expected %u\n", count, 0);
    return MC_ERR_RUNTIME;
  }

  return MC_SUCCESS;
}

static int unique_number_with_unique()
{
  printf("Generating data set...\n");
  generate_with_unique_dataset("data_set.bin");
 
  printf("Processing...\n");
  const uint32_t count = alg_count_unique("data_set.bin");
  if (count != 1000000) {
    printf("Count: %u, Expected %u\n", count, 1000);
    return MC_ERR_RUNTIME;
  }

  return MC_SUCCESS;
}

int main()
{
  MC_TEST(pure_number_without_unique);
  MC_TEST(pure_number_with_unique);
  MC_TEST(unique_number_without_unique);
  MC_TEST(unique_number_with_unique);

  return MC_SUCCESS;
}