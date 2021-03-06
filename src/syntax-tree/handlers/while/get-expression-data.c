#include <stdlib.h>

#include "utils/logger/log-src-error.h"
#include "../initialization/data.h"
#include "./data.h"

void getWhileExpressionData(
  void *raw_data,
  List *token,
  ExpressionData *result,
  int *offset,
  int handler_id
) {
  SyntaxWhileData *data = (SyntaxWhileData*) raw_data;
  expressionInit(result, EXPRESSION_WHILE, "while", token, false);
  result->compileX86 = compileWhileX86;

  ExpressionData condition;
  condition.parent_scope = result->parent_scope;
  setVoidType(&(condition.result_type));

  data->condition.handler->getExpressionData(
    data->condition.data,
    data->condition.token,
    &condition,
    offset,
    data->condition.handler->id
  );

  if (!isBool(&(condition.result_type))) {
    throwSourceError("if condition is not convertable to boolean", data->condition.token);
  }

  ExpressionData expression;
  expression.parent_scope = result->parent_scope;
  setVoidType(&(expression.result_type));

  data->expression.handler->getExpressionData(
    data->expression.data,
    data->expression.token,
    &expression,
    offset,
    data->expression.handler->id
  );

  result->child_expressions = newArray(ExpressionData, condition, expression);
}
