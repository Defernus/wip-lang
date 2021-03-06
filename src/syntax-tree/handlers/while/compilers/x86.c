#include "../data.h"
#include "utils/logger/log-src-error.h"
#include "compiler/x86/compile-utils.h"

int whiles_counter = 0;

void compileWhileX86(ExpressionData *self, bool address, FILE *out_stream) {
  FORBID_ADDRESS_AS_RESULT

  int while_id = whiles_counter++;

  L("while_condition_%d:", while_id);

  ExpressionData *condition = (ExpressionData*) arrayAt(self->child_expressions, 0);

  ExpressionData *body = (ExpressionData*) arrayAt(self->child_expressions, 1);

  expressionCompile(condition, ARCH_X86, false, out_stream);

  L("    pop     rax");
  L("    cmp     rax, 0");
  L("    jz      while_end_%d", while_id);

  expressionCompile(body, ARCH_X86, false, out_stream);
  L("    jmp     while_condition_%d", while_id);
  
  L("while_end_%d:\n", while_id);
}
