#ifndef SYNTAX_DATA_SCOPE_H
#define SYNTAX_DATA_SCOPE_H

#include "expression-data/expression-data.h"
#include "utils/array/array.h"
#include "utils/list/list.h"

typedef struct {
  Array *nodes;
} SyntaxScopeData;

void printSyntaxScopeData(SyntaxScopeData *data);
void getScopeExpressionData(
  const char *src,
  void *data,
  List *token,
  ExpressionData *result,
  int *offset,
  int handler_id
);

void compileScopeX86(char *src, ExpressionData *self, bool address, FILE *out_stream);

#endif
