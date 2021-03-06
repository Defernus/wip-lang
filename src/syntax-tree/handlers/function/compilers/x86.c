#include "utils/logger/log-src-error.h"
#include "compiler/x86/compile-utils.h"
#include "../data.h"

void compileFunctionX86(ExpressionData *self, bool address, FILE *out_stream) {
  FORBID_ADDRESS_AS_RESULT

  FunctionTypeData *func_type_data = (FunctionTypeData*) self->result_type.data;

  // !TODO move function definitions to the end
  L("\n    jmp     %s_end", self->scope_label);

  L("%s:", self->scope_label);
  L("    push    rbp");
  L("    mov     rbp, rsp");

  unsigned size = getTypeSize(&(func_type_data->result_type));
  for (MapItterator *i = mapBegin(self->variables); !mapItteratorIsEnded(i); mapItteratorNext(i)) {
    VariableData *arg = (VariableData*) mapItteratorGet(i).value;

    size += getTypeSize(&(arg->type));
  }

  L("    sub     rsp, %d", size);

  ExpressionData *body = arrayAt(self->child_expressions, 0);

  expressionCompile(body, ARCH_X86, false, out_stream);
  

  L("    mov     rsp, rbp");
  L("    pop     rbp");
  L("    ret");

  L("%s_end:\n", self->scope_label);

  L("    push    rbp");
  L("    push    %s", self->scope_label);
}
