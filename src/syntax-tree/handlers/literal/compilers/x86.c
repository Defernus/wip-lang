#include "../data.h"
#include "utils/logger/log-src-error.h"
#include "compiler/x86/compile-utils.h"

unsigned str_counter = 0;

static void compilePointerLiteral(ExpressionData *self, FILE *out_stream) {
  int str_id = str_counter++;
  L("    jmp     string_literal_end_%d", str_id);

  fprintf(out_stream, "string_literal_%d db ", str_id);

  char *current_char = (char*) self->value;
  while (*current_char) {

    fprintf(out_stream, "%d, ", *current_char);
    ++current_char;
  }
  fprintf(out_stream, "0\n");
  
  L("string_literal_end_%d:", str_id);
  L("    push    string_literal_%d", str_id);
}

void compileLiteralX86(ExpressionData *self, bool address, FILE *out_stream) {
  FORBID_ADDRESS_AS_RESULT

  char err[100];

  switch (self->result_type.type_id)
  {
  case TYPE_ID_INT:
    L("    push    %d", *(int*) self->value);
    break;
  case TYPE_ID_POINTER:
    compilePointerLiteral(self, out_stream);
    break;
  default:
    sprintf(err, "literals with type of %s is not implemented yet\n", getTypeName(&(self->result_type)));
    throwSourceError(err, self->token);
  }
}
