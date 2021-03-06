#ifndef TOKEN_DATA_H
#define TOKEN_DATA_H

#include "utils/list/list.h"

#include "./token.h"
#include "./source-data.h"


typedef struct {
  const SourceData *src;
  Token token;
  char *value;

  int row;
  int col;
  int size;
} TokenData;

typedef struct {
  List *first_token;
  List *last_token;
} TokenizeResult;

TokenizeResult tokenize(const SourceData *src);
void tokenDataPrint(TokenData *self);

#endif
