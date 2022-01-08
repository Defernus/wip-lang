#include <stdlib.h>
#include <stdio.h>

#include "utils/logger/log-src-error.h"
#include "syntax-tree/syntax-node.h"
#include "syntax-tree/syntax-helpers.h"
#include "./data.h"


void getInitializationExpressionData(
  const char *src,
  void *raw_data,
  List *token,
  ExpressionData *result,
  unsigned *offset,
  int handler_id
) {
  SyntaxInitializationData *data = (SyntaxInitializationData*)raw_data;

  result->id = EXPRESSION_INITIALIZATION;
  result->variables = createMap(sizeof(VariableData));

  if (mapGet(result->parent_scope->variables, data->identifier) != NULL) {
    List *identifier_token = trimTokensLeft(listNext(token));
    char msg[100];
    sprintf(msg, "name \"%s\" is already used", data->identifier);
    throwSourceError(src, msg, identifier_token);
  }

  VariableData new_var = (VariableData) {
    .is_constant = data->is_constant,
    .name = data->identifier,
    .result_type = result->result_type,
    .scope_offset = 0,
  };
  mapSet(result->parent_scope->variables, data->identifier, &new_var);
}
