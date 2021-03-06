#ifndef SYNTAX_DATA_OPERATION_POSTFIX_H
#define SYNTAX_DATA_OPERATION_POSTFIX_h

#include "syntax-tree/syntax-node.h"

#define OPERATION_POSTFIX_ID_INC         0
#define OPERATION_POSTFIX_ID_DEC         1

#define OPERATION_POSTFIX_COUNT          2

typedef struct {
  int operation_id;
  SyntaxNode expression;
} SyntaxOperationPostfixData;

void printSyntaxOperationPostfixData(SyntaxOperationPostfixData *data);

void getOperationPostfixExpressionData(
  void *raw_data,
  List *token,
  ExpressionData *result,
  int *offset,
  int handler_id
);

void compileOperationPostfixX86(ExpressionData *self, bool address, FILE *out_stream);

#endif
