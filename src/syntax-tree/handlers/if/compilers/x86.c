#include "../data.h"
#include "utils/logger/log-src-error.h"
#include "compiler/x86/compile-utils.h"

int ifs_counter = 0;

void compileIfX86(ExpressionData *self, bool address, FILE *out_stream) {
  FORBID_ADDRESS_AS_RESULT
  int current_if_id = ifs_counter++;

  ExpressionData *condition = (ExpressionData*) arrayAt(self->child_expressions, 0);

  ExpressionData *body = (ExpressionData*) arrayAt(self->child_expressions, 1);

  expressionCompile(condition, ARCH_X86, false, out_stream);

  L("    pop     rax");
  L("    cmp     rax, 0");
  L("    jz      if_else_%d", current_if_id);

  expressionCompile(body, ARCH_X86, false, out_stream);
  L("    jmp     if_end_%d", current_if_id);
  
  L("if_else_%d:\n", current_if_id);

  if (arrayGetLength(self->child_expressions) > 2) {
    ExpressionData *else_body = (ExpressionData*) arrayAt(self->child_expressions, 2);
    expressionCompile(else_body, ARCH_X86, false, out_stream);
  }

  L("if_end_%d:\n", current_if_id);
}
