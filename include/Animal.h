#ifndef ANIMAL_H
#define ANIMAL_H

typedef struct AnimalVTable AnimalVTable;

typedef struct Animal {
  const AnimalVTable* vtable;
  char* name;
} Animal;

struct AnimalVTable {
  const char* (*cry)(Animal*); // Virtual method
  void (*de_init)(Animal*);    // Virtual destructor
};

// Constructor
void init_animal(Animal*, const AnimalVTable*, const char*);
// Destructor
void de_init_animal(Animal* this);
// Getter
const char* animal_name(const Animal* this);
// Virtual method
const char* animal_cry(Animal* this);

#endif
