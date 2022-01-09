#ifndef TOKEN_H
#define TOKEN_H

#define TOKEN_LITERAL_STRING              0
#define TOKEN_LITERAL_FLOAT               1
#define TOKEN_LITERAL_INT                 2
#define TOKEN_FUNCTION_ARROW              3
#define TOKEN_BRACKET_OPEN                4
#define TOKEN_BRACKET_CLOSE               5
#define TOKEN_KEYWORD                     6
#define TOKEN_IDENTIFIER                  7
#define TOKEN_SEPARATOR_EXPRESSION        8
#define TOKEN_WHITE_SPACE                 9
#define TOKEN_SEPARATOR                   10
#define TOKEN_OPERATOR_NOT_EQUALS_STRICT  11
#define TOKEN_OPERATOR_EQUALS_STRICT      12
#define TOKEN_OPERATOR_NOT_EQUALS         13
#define TOKEN_OPERATOR_EQUALS             14
#define TOKEN_OPERATOR_GRATER_OR_EQUAL    15
#define TOKEN_OPERATOR_LESS_OR_EQUAL      16
#define TOKEN_OPERATOR_GRATER             17
#define TOKEN_OPERATOR_LESS               18
#define TOKEN_OPERATOR_OR                 19
#define TOKEN_OPERATOR_AND                20
#define TOKEN_OPERATOR_INC                21
#define TOKEN_OPERATOR_DEC                22
#define TOKEN_OPERATOR_NOT                23
#define TOKEN_OPERATOR_ASSIGNATION        24
#define TOKEN_OPERATOR_SUM                25
#define TOKEN_OPERATOR_DIFFERENCE         26
#define TOKEN_OPERATOR_PRODUCT            27
#define TOKEN_OPERATOR_RATIO              28
#define TOKEN_OPERATOR_BIT_OR             29
#define TOKEN_OPERATOR_BIT_AND            30

#define TOKEN_COMMENT                     31

typedef struct {
  int id;
  char *name;
  char* (*chopToken)(char *token_start, char **error);
} Token;

#endif
