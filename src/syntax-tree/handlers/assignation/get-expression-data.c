#include "utils/logger/log-src-error.h"
#include "../initialization/data.h"
#include "./data.h"

void getAssignationExpressionData(
  const char *src,
  void *raw_data,
  List *token,
  ExpressionData *result,
  unsigned *offset,
  int handler_id
) {
  SyntaxAssignationData *data = (SyntaxAssignationData*) raw_data;
  result->id = EXPRESSION_ASSIGNATION;
  result->variables = createMap(sizeof(VariableData));

  ExpressionData left;
  left.parent_scope = result->parent_scope;
  ExpressionData right;
  right.parent_scope = result->parent_scope;

  data->right.handler->getExpressionData(
    src,
    data->right.data,
    data->right.token,
    &right,
    offset,
    data->right.handler->id
  );
  result->result_type = right.result_type;

  if (right.result_type.type_id == TYPE_ID_VOID) {
    throwSourceError(src, "unexpected right side expression with void type", data->right.token);
  }

  if (data->left.handler->getExpressionData == getInitializationExpressionData) {
    left.result_type = right.result_type;
  }

  data->left.handler->getExpressionData(
    src,
    data->left.data,
    data->left.token,
    &left,
    offset,
    data->left.handler->id
  );

  if (!isSameType(&(left.result_type), &(right.result_type))) {
    throwSourceError(src, "type mismatch", data->left.token);
  }

  result->child_expressions = newArray(ExpressionData, left, right);
}
