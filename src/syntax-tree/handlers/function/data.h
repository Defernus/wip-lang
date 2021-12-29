#ifndef SYNTAX_DATA_FUNCTION_H
#define SYNTAX_DATA_FUNCTION_H

#include "syntax-tree/syntax-node.h"
#include "syntax-tree/handlers/type-definition/data.h"
#include "syntax-tree/handlers/scope/data.h"

typedef struct {
  char *name;
  SyntaxTypeDefinitionData type_definition;
} FunctionArgument;

typedef struct {
  Array *arguments;
  SyntaxTypeDefinitionData return_type;
  SyntaxNode body_expression;
} SyntaxFunctionData;

void printSyntaxFunctionData(SyntaxFunctionData *data);

#endif