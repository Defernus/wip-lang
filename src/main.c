#include <stdio.h>
#include "token/token-data.h"

void printToken(void *self, const void *_token, int index, const Array *tokens) {
  TokenData *token = (TokenData*)_token;
  printf("tokens[%d]: { id: \"%d\", value: \"%s\" }\n", index, token->id, token->value);
}

int main() {
  char *src =
    "kek = 1+2;\n"
    "lol=kek + 10;\n";
  printf("===src===\n%s\n===SRC===\n\n", src);
  Array *tokens = tokenize(src);

  printf("==tokens==\n");
  arrayForEach(tokens, printToken, NULL);
  printf("==TOKENS==\n");

  return 0;
}
