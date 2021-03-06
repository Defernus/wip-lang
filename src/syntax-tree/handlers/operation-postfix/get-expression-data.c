#include <stdlib.h>

#include "utils/logger/log-src-error.h"
#include "./data.h"

void getOperationPostfixExpressionData(
  void *raw_data,
  List *token,
  ExpressionData *result,
  int *offset,
  int handler_id
) {
  SyntaxOperationPostfixData *data = (SyntaxOperationPostfixData*) raw_data;
  expressionInit(result, EXPRESSION_OPERATIONS_POSTFIX + data->operation_id, "operation_postfix", token, false);
  result->compileX86 = compileOperationPostfixX86;

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

  // !TODO add expression overload
  if (expression.result_type.type_id != TYPE_ID_INT) {
    throwSourceError("wrong expression type, expected int", token);
  }

  result->result_type = expression.result_type;
  result->child_expressions = newArray(ExpressionData, expression);
}

