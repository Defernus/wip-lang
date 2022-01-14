#ifndef SYNTAX_DATA_OPERATION_PREFIX_H
#define SYNTAX_DATA_OPERATION_PREFIX_H

#include "syntax-tree/syntax-node.h"

#define OPERATION_PREFIX_ID_INC             0
#define OPERATION_PREFIX_ID_DEC             1
#define OPERATION_PREFIX_ID_DEREFERENCING   2

#define OPERATION_PREFIX_COUNT              3

typedef struct {
  int operation_id;
  SyntaxNode expression;
} SyntaxOperationPrefixData;

void printSyntaxOperationPrefixData(SyntaxOperationPrefixData *data);

void getOperationPrefixExpressionData(
  const char *src,
  void *raw_data,
  List *token,
  ExpressionData *result,
  int *offset,
  int handler_id
);

#endif
