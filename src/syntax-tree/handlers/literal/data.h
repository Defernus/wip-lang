#ifndef SYNTAX_DATA_LITERAL_H
#define SYNTAX_DATA_LITERAL_H

#include <stdbool.h>
#include "syntax-tree/syntax-node.h"

typedef struct {
  int type_id;
  void *value;
} SyntaxLiteralData;

void printSyntaxLiteralData(SyntaxLiteralData *data);

#endif
