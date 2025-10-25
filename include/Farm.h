#ifndef FARM_H
#define FARM_H

#include "Animal.h"

typedef struct Cow {
  Animal base;
  char* moo;
} Cow;

void init_cow(Cow*, const char*);
void de_init_cow(Cow*);
const char* moo(Cow*);
const char* cow_name(const Cow*);

typedef struct Pig {
  Animal base;
} Pig;

void init_pig(Pig*, const char*);
void de_init_pig(Pig*);
const char* squeal(const Pig*);
const char* pig_name(const Pig*);

#endif
