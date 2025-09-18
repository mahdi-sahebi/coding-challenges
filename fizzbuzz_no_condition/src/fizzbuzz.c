#include <stdio.h>
#include "include/types.h"


typedef union
{
  uint8_t value;

  struct
  {
    uint8_t bit_0: 1;
    uint8_t bit_1: 1;
  };
}word_t;


static void print_end(uint8_t number)
{

}

void print_num(uint8_t number)
{
  API apis[] = {
    print_end,
    print_num
  };

  char integer_string[4] = {0};
  sprintf(integer_string, "%u", number);

  const char* symbol[] = {
    integer_string,
    "A",
    "B",
    "AB"
  };

  word_t word = {.value = 0};
  word.bit_0 = (0 == (number % 3));
  word.bit_1 = (0 == (number % 5));
  const uint8_t symbol_index = word.value;

  printf("%s\n", symbol[symbol_index]);
  const uint8_t api_index = (number < 100);
  apis[api_index](number + 1);
}

