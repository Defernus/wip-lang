#ifndef SYNTAX_DATA_OPERATION_H
#define SYNTAX_DATA_OPERATION_H

#include "syntax-tree/syntax-node.h"

#define OPERATION_ID_SUM                0
#define OPERATION_ID_DIFFERENCE         1
#define OPERATION_ID_RATIO              2
#define OPERATION_ID_PRODUCT            3
#define OPERATION_ID_POWER              4
#define OPERATION_ID_BIT_OR             5
#define OPERATION_ID_BIT_AND            6
#define OPERATION_ID_AND                7
#define OPERATION_ID_OR                 8
#define OPERATION_ID_EQUALS             9
#define OPERATION_ID_NOT_EQUALS         10
#define OPERATION_ID_EQUALS_STRICT      11
#define OPERATION_ID_NOT_EQUALS_STRICT  12
#define OPERATION_ID_GRATER_OR_EQUAL    13
#define OPERATION_ID_LESS_OR_EQUAL      14
#define OPERATION_ID_GRATER             15
#define OPERATION_ID_LESS               16

#define OPERATION_LR_COUNT               17

typedef struct {
  int operation_id;
  SyntaxNode left;
  SyntaxNode right;
} SyntaxOperationData;

void printSyntaxOperationLRData(SyntaxOperationData *data);

void getOperationLRExpressionData(
  const char *src,
  void *raw_data,
  List *token,
  ExpressionData *result
);

#endif
