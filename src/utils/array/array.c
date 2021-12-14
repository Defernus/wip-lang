#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "./array.h"

#define ALLOC_MULT 2

struct Array {
  unsigned el_size;
  unsigned length;
  unsigned allocated;
  void *value;
};

Array *createEmptyArray(unsigned reserved, unsigned el_size) {
  void *value = malloc(el_size * reserved);

  Array *result = malloc(sizeof(struct Array));
  result->el_size = el_size;
  result->length = 0;
  result->allocated = reserved;
  result->value = value;

  return result;
}

Array* createArray(unsigned length, unsigned el_size, const void *data) {
  unsigned dataSize = el_size * length;
  void *value = malloc(el_size * length);
  memcpy(value, data, dataSize);

  Array *result = malloc(sizeof(struct Array));
  result->el_size = el_size;
  result->length = length;
  result->allocated = length;
  result->value = value;

  return result;
}
void arrayFree(Array *self) {
  self->allocated = 0;
  self->length = 0;
  free(self->value);
  free(self);
}

void* arrayAt(Array *self, unsigned index) {
  if (index < 0) {
    index = self->length - index;
  }
  if (index < 0 || index >= self->length) {
    return NULL;
  }
  return self->value + (self->el_size * index);
}

bool arraySetElementAt(Array *self, unsigned index, const void *newValue) {
  if (index >= self->length) {
    return false;
  }
  memcpy(self->value + index * self->el_size, newValue, self->el_size);
  return true;
}

const unsigned arrayGetLength(const Array *self) {
  return self->length;
}

// !TODO free mem when more than half is unused
void* arrayPop(Array *self) {
  if (self->length == 0) {
    return NULL;
  }
  --self->length;
  return self->value + (self->el_size * self->length);
}

void arrayPush(Array *self, const void *element) {
  if (self->length < self->allocated) {
    memcpy(self->value + (self->length * self->el_size), element, self->el_size);
    ++self->length;
    return;
  }
  self->value = realloc(self->value, self->el_size * self->length * ALLOC_MULT);
  memcpy(self->value + self->length * self->el_size, element, self->el_size);
  self->allocated = self->length * ALLOC_MULT;
  ++self->length;
}

Array* arrayMap(Array *array, unsigned new_el_size, MapHandler handler, void *self) {
  Array *result = createEmptyArray(array->length, new_el_size);
  result->length = array->length;
  for (int i = 0; i != array->length; ++i) {
    handler(self, result->value + i * new_el_size, arrayAt(array, i), i, array);
  }
  return result;
}

void arrayForEach(Array *array, ForEachHandler handler, void *self) {
  for (int i = 0; i != array->length; ++i) {
    handler(self, arrayAt(array, i), i, array);
  }
}

Array* arrayFilter(Array *array, FilterHandler handler, void *self) {
  Array *result = createEmptyArray(0, array->el_size);
  for (int i = 0; i != array->length; ++i) {
    void *el = arrayAt(array, i);
    if (handler(self, el, i, array)) {
      arrayPush(result, el);
    }
  }
  return result;
}

void* arrayFind(Array *array, FindHandler handler, void *self) {
  for (int i = 0; i != array->length; ++i) {
    void *el = arrayAt(array, i);
    if (handler(self, el, i, array)) {
      return el;
    }
  }
  return NULL;
}

int arrayCount(Array *array, CountHandler handler, void *self) {
  int result = 0;
  for (int i = 0; i != array->length; ++i) {
    void *el = arrayAt(array, i);
    if (handler(self, el, i, array)) {
      ++result;
    }
  }
  return result;
}
