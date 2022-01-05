#include <stdlib.h>
#include <stdio.h>

#include "utils/logger/log-src-error.h"

#include "./handlers/scope/data.h"
#include "./handlers/assignation/data.h"
#include "./handlers/operation-lr/data.h"
#include "./handlers/initialization/data.h"
#include "./handlers/literal/data.h"
#include "./handlers/identifier/data.h"
#include "./handlers/function/data.h"
#include "./handlers/return/data.h"
#include "./handlers/function-call/data.h"
#include "./handlers/type-definition/data.h"
#include "./syntax-node-handler.h"

Array *handlers;

void getNotImplementedExpressionData(const char *src, void *raw_data, List *token, ExpressionData *result, unsigned *offset) {
  TokenData *token_data = (TokenData*) listGetValue(token);
  printSourceError(src, "syntax node is not implemented yet", token_data->row, token_data->col);
  exit(1);
}

static Array *getSyntaxNodeHandlers() {
  handlers = newArray(
    SyntaxNodeHandler,
    (SyntaxNodeHandler) {
      .id = SYNTAX_SCOPE,
      .name = "scope",
      .printData = (PrintData) printSyntaxScopeData,
      .getExpressionData = (GetExpressionData) getScopeExpressionData,
    },
    (SyntaxNodeHandler) {
      .id = SYNTAX_FUNCTION_CALL,
      .name = "function-call",
      .printData = (PrintData) printSyntaxFunctionCallData,
      .getExpressionData = (GetExpressionData) getNotImplementedExpressionData,
    },
    (SyntaxNodeHandler) {
      .id = SYNTAX_ASSIGNATION,
      .name = "assignation",
      .printData = (PrintData) printSyntaxAssignationData,
      .getExpressionData = (GetExpressionData) getAssignationExpressionData,
    },
    (SyntaxNodeHandler) {
      .id = SYNTAX_OPERATION_LR,
      .name = "operation-lr",
      .printData = (PrintData) printSyntaxOperationLRData,
      .getExpressionData = (GetExpressionData) getNotImplementedExpressionData,
    },
    (SyntaxNodeHandler) {
      .id = SYNTAX_INITIALIZATION,
      .name = "initialization",
      .printData = (PrintData) printSyntaxInitializationData,
      .getExpressionData = (GetExpressionData) getNotImplementedExpressionData,
    },
    (SyntaxNodeHandler) {
      .id = SYNTAX_LITERAL,
      .name = "literal",
      .printData = (PrintData) printSyntaxLiteralData,
      .getExpressionData = (GetExpressionData) getNotImplementedExpressionData,
    },
    (SyntaxNodeHandler) {
      .id = SYNTAX_IDENTIFIER,
      .name = "identifier",
      .printData = (PrintData) printSyntaxIdentifierData,
      .getExpressionData = (GetExpressionData) getNotImplementedExpressionData,
    },
    (SyntaxNodeHandler) {
      .id = SYNTAX_FUNCTION,
      .name = "function",
      .printData = (PrintData) printSyntaxFunctionData,
      .getExpressionData = (GetExpressionData) getNotImplementedExpressionData,
    },
    (SyntaxNodeHandler) {
      .id = SYNTAX_RETURN,
      .name = "return",
      .printData = (PrintData) printSyntaxReturnData,
      .getExpressionData = (GetExpressionData) getNotImplementedExpressionData,
    },
    (SyntaxNodeHandler) {
      .id = SYNTAX_TYPE_DEFINITION,
      .name = "type_refinition",
      .printData = (PrintData) printSyntaxTypeDefinitionData,
      .getExpressionData = (GetExpressionData) getNotImplementedExpressionData,
    },
  );
  return handlers;
}

SyntaxNodeHandler *getSyntaxNodeHandler(int id) {
  SyntaxNodeHandler *result = arrayAt(getSyntaxNodeHandlers(), id);
  if (result == NULL) {
    printf("failed to find syntax  id %d\n", id);
  }
  return result;
}
