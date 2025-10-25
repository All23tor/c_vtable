#ifndef PETS_H
#define PETS_H

#include "Animal.h"

typedef struct Dog {
  Animal base;
} Dog;

void init_dog(Dog*, const char*);
void de_init_dog(Dog*);
const char* bark(const Dog*);
const char* dog_name(const Dog*);

typedef struct Cat {
  Animal base;
  int counter;
} Cat;

void init_cat(Cat*, const char*);
void de_init_cat(Cat*);
const char* meow(Cat*);
const char* cat_name(const Cat*);
int cat_count(const Cat*);

#endif
