#ifndef TOKEN_H
#define TOKEN_H

enum Tokens {
  TOKEN_COMMENT,
  TOKEN_LITERAL_STRING,
  TOKEN_LITERAL_FLOAT,
  TOKEN_LITERAL_INT,
  TOKEN_FUNCTION_ARROW,
  TOKEN_BRACKET_OPEN,
  TOKEN_BRACKET_CLOSE,
  TOKEN_KEYWORD,
  TOKEN_IDENTIFIER,
  TOKEN_SEPARATOR_EXPRESSION,
  TOKEN_WHITE_SPACE,
  TOKEN_SEPARATOR,
  TOKEN_OPERATOR_NOT_EQUALS_STRICT,
  TOKEN_OPERATOR_EQUALS_STRICT,
  TOKEN_OPERATOR_NOT_EQUALS,
  TOKEN_OPERATOR_EQUALS,
  TOKEN_OPERATOR_GRATER_OR_EQUAL,
  TOKEN_OPERATOR_LESS_OR_EQUAL,
  TOKEN_OPERATOR_GRATER,
  TOKEN_OPERATOR_LESS,
  TOKEN_OPERATOR_OR,
  TOKEN_OPERATOR_AND,
  TOKEN_OPERATOR_INC,
  TOKEN_OPERATOR_DEC,
  TOKEN_OPERATOR_NOT,
  TOKEN_OPERATOR_ASSIGNATION,
  TOKEN_OPERATOR_SUM,
  TOKEN_OPERATOR_DIFFERENCE,
  TOKEN_OPERATOR_PRODUCT,
  TOKEN_OPERATOR_RATIO,
  TOKEN_OPERATOR_BIT_OR,
  TOKEN_OPERATOR_BIT_AND,
};

typedef struct {
  int id;
  char *name;
  char* (*chopToken)(char *token_start, char **error);
} Token;

#endif
