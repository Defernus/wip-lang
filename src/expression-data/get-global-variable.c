#include <stdlib.h>

#include "./expression-data.h"
#include "syntax-tree/handlers/function/data.h"

#define GLOBAL_VAR_PRINT_INT "printInt"

Map *global_variables;

static void definePrintInt() {
  FunctionTypeData *type_data = malloc(sizeof(FunctionTypeData));

  type_data->args = newArray(
    VariableData,
    (VariableData) {
      .name = "value",
      .scope_offset = 0,
      .type = (TypeDefinition) {
        .type_id = TYPE_ID_INT,
        .data = NULL,
        .is_constant = true,
      },
    },
  );
  setVoidType(&(type_data->result_type));

  mapSet(global_variables, GLOBAL_VAR_PRINT_INT, &(VariableData) {
    .name = GLOBAL_VAR_PRINT_INT,
    .scope_offset = 0,
    .type = (TypeDefinition) {
      .data = type_data,
      .is_constant = true,
      .type_id = TYPE_ID_FUNCTION,
    },
  });
}

VariableData *getGlobalVariable(char *name) {
  if (global_variables == NULL) {
    global_variables = createMap(sizeof(VariableData));
    definePrintInt();
  }

  return mapGet(global_variables, name);
}
