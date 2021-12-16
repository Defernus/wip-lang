#include <stdio.h>
#include <stdlib.h>

#include "token/token-data.h"
#include "syntax-tree/syntax-tree.h"

void printToken(TokenData *token, int index) {
  printf("tokens[%d]: ", index);
  tokenDataPrint(token);
}

int main() {
  char *file_name = "./src.wip";
  FILE *file = fopen(file_name, "r"); // read mode

  if (file == NULL) {
    printf("Failed to open file '%s'.\n", file_name);
    return 1;
  }

  fseek(file, 0, SEEK_END);
  long length = ftell(file);
  fseek(file, 0, SEEK_SET);
  char *src = malloc(length);
  if (src) {
    fread(src, 1, length, file);
  }
  fclose(file);

  printf("===src===\n%s\n===SRC===\n\n", src);
  List *tokens = tokenize(src);

  if (tokens == NULL) {
    printf("failed to tokenize sources\n");
    return 1;
  }

  printf("==tokens==\n");
  int i = 0;
  for (List *token = tokens; token != NULL; token = listNext(token)) {
    printToken((TokenData*) listGetValue(token), i);
    ++i;
  }
  printf("==TOKENS==\n");

  SyntaxTree tree = createSyntaxTree(tokens);
  printSyntaxTree(&tree);

  listFree(tokens);
  free(src);

  return 0;
}
