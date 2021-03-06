#include <stdlib.h>
#include <stdio.h>

#include "utils/array/array.h"
#include "syntax-tree/handlers/expression/parser.h"
#include "syntax-tree/handlers/initialization/parser.h"
#include "syntax-tree/handlers/identifier/parser.h"
#include "syntax-tree/handlers/literal/parser.h"
#include "syntax-tree/syntax-helpers.h"
#include "./parser.h"
#include "./data.h"

List *parseAssignation(List *tokens, SyntaxNode *left_syntax_node, SyntaxNode *result, char **error) {
  *error = NULL;
  *result = (SyntaxNode) {
    .data = NULL,
    .handler = getSyntaxNodeHandler(SYNTAX_ASSIGNATION),
    .priority = SYNTAX_ASSIGNATION * SYNTAX_PRIORITY_OFFSET,
  };

  List *current_token = trimTokensLeft(tokens);
  result->token = current_token;
  
  if (current_token == NULL) {
    *error = "Failed to parse assignation, end of scope";
    return current_token;
  }

  current_token = trimTokensLeft(current_token);
  if (current_token == NULL) {
    *error = "Failed to parse assignation, end of scope";
    return current_token;
  }

  TokenData *middle_token = (TokenData*) listGetValue(current_token);

  if (middle_token->token.id != TOKEN_OPERATOR_ASSIGNATION) {
    *error = "Failed to parse assignation, missing '=' sign";
    return current_token;
  }
  current_token = trimTokensLeft(listNext(current_token));
  if (current_token == NULL) {
    *error = "Failed to parse assignation, end of scope";
    return current_token;
  }
  
  SyntaxNode right_syntax_node;
  current_token = parseExpression(current_token, &right_syntax_node, error, false, result->priority);
  if (*error != NULL) {
    return current_token;
  }

  SyntaxAssignationData *data = malloc(sizeof(SyntaxAssignationData));
  data->left = *left_syntax_node;
  data->right = right_syntax_node;
  result->data = data;

  return current_token;
}
