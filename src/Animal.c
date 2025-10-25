#include "Animal.h"
#include <stdlib.h>
#include <string.h>

void init_animal(Animal *this, const AnimalVTable *vtable, const char *name) {
  char *name_copy = NULL;
  if (name != NULL) {
    name_copy = malloc(strlen(name) + 1);
    strcpy(name_copy, name);
  }

  *this = (Animal){vtable, name_copy};
}

void de_init_animal(Animal *this) {
  this->vtable->de_init(this);
  free(this->name);
}

const char *animal_name(const Animal *this) { return this->name; }
const char *animal_cry(Animal *this) { return this->vtable->cry(this); }
