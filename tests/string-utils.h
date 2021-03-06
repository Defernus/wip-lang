#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "utils/string/string.h"

void testStringUtils() {
  printf("Test string utils:\n");

  printf("\t- get substring\n");
  char *sub_string = stringGetSubstring("kek lol chebureck", 4, 10);
  assert(!strcmp(sub_string, "lol che"));
  free(sub_string);

  printf("\t- get reversed substring\n");
  sub_string = stringGetSubstring("kek lol chebureck", 10, 4);
  free(sub_string);

  printf("\t- reverse string\n");
  sub_string = stringGetSubstring("kek lol chebureck", -1, 0);
  assert(!strcmp(sub_string, "kcerubehc lol kek"));
  free(sub_string);

  printf("\t- trim string\n");
  sub_string = stringTrim(" \t\r\n\v\fqwe   thb 3erwd3e \t\r\n\v\f");
  assert(!strcmp(sub_string, "qwe   thb 3erwd3e"));
  free(sub_string);

  printf("\t- trim string without whitespaces\n");
  sub_string = stringTrim("kek lol chebureck");
  assert(!strcmp(sub_string, "kek lol chebureck"));
  free(sub_string);

  printf("\t- split string\n");
  Array *strings = stringSplit("1234567890123 ,  , 345 , 567, 444 , ", " , ", false);
  assert(arrayGetLength(strings) == 3);
  assert(!strcmp(*(char**)arrayAt(strings, 0), "1234567890123"));
  assert(!strcmp(*(char**)arrayAt(strings, 1), "345"));
  assert(!strcmp(*(char**)arrayAt(strings, 2), "567, 444"));
  arrayFree(strings);


  printf("\t- check if string starts with another string\n");
  assert(stringComparePrefix("123456789", "123") == 0);
  assert(stringComparePrefix("123456789", "234") == (int)'1' - (int)'2');
  assert(stringComparePrefix("123456789", "1235") == (int)'4' - (int)'5');
  assert(stringComparePrefix("123456789", "1234567890aaa") == -(int)'0');

  printf("Test string utils: OK\n");
}
