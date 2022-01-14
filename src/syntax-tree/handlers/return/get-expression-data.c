#include <stdlib.h>
#include <stdio.h>

#include "utils/logger/log-src-error.h"
#include "syntax-tree/syntax-node.h"
#include "syntax-tree/syntax-helpers.h"
#include "./data.h"


void getReturnExpressionData(
  const char *src,
  void *raw_data,
  List *token,
  ExpressionData *result,
  int *offset,
  int handler_id
) {
  SyntaxReturnData *data = (SyntaxReturnData*)raw_data;
  expressionInit(result, EXPRESSION_RETURN, "return", token, false);

  if (data->expression == NULL) {
    return;
  }
  
  ExpressionData child_expression;
  child_expression.parent_scope = result->parent_scope;
  child_expression.result_type.data = NULL;
  child_expression.result_type.type_id = TYPE_ID_VOID;

  data->expression->handler->getExpressionData(
    src,
    data->expression->data,
    data->expression->token,
    &child_expression,
    offset,
    data->expression->handler->id
  );

  
}
