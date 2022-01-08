#include <stdlib.h>

#include "utils/logger/log-src-error.h"
#include "../initialization/data.h"
#include "./data.h"

void getWhileExpressionData(
  const char *src,
  void *raw_data,
  List *token,
  ExpressionData *result,
  unsigned *offset,
  int handler_id
) {
  SyntaxWhileData *data = (SyntaxWhileData*) raw_data;
  result->id = EXPRESSION_WHILE;
  result->variables = createMap(sizeof(VariableData));

  ExpressionData condition;
  condition.parent_scope = result->parent_scope;
  condition.result_type.type_id = SYNTAX_TYPE_ID_VOID;
  condition.result_type.data = NULL;

  data->condition.handler->getExpressionData(
    src,
    data->condition.data,
    data->condition.token,
    &condition,
    offset,
    data->condition.handler->id
  );

  // !TODO move out check for boolean compatability
  int condition_type = condition.result_type.type_id;
  if (
    condition_type != SYNTAX_TYPE_ID_INT &&
    condition_type != SYNTAX_TYPE_ID_FLOAT &&
    condition_type != SYNTAX_TYPE_ID_POINTER
  ) {
    throwSourceError(src, "if condition is not convertable to boolean", data->condition.token);
  }


  ExpressionData expression;
  expression.parent_scope = result->parent_scope;
  expression.result_type.type_id = SYNTAX_TYPE_ID_VOID;
  expression.result_type.data = NULL;

  data->expression.handler->getExpressionData(
    src,
    data->expression.data,
    data->expression.token,
    &expression,
    offset,
    data->expression.handler->id
  );

  result->child_expressions = newArray(ExpressionData, condition, expression);
}