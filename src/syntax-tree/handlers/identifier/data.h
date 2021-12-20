#ifndef SYNTAX_DATA_IDENTIFIER_H
#define SYNTAX_DATA_IDENTIFIER_H

#include <stdbool.h>
#include "syntax-tree/syntax-node.h"

typedef struct {
  char *name;
} SyntaxIdentifierData;

void printSyntaxIdentifierData(SyntaxIdentifierData *data);

#endif