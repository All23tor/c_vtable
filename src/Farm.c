#include "Farm.h"
#include "Animal.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char *virtual_moo(Animal *this) { return moo((Cow *)this); }
void virtual_de_init_cow(Animal *this) { de_init_cow((Cow *)this); }
const AnimalVTable VCow[] = {{virtual_moo, virtual_de_init_cow}};

void init_cow(Cow *this, const char *name) {
  init_animal(&this->base, VCow, name);
  this->moo = malloc(3);
  this->moo[0] = 'm';
  this->moo[1] = 'o';
  this->moo[2] = '\0';
}

void de_init_cow(Cow *this) { free(this->moo); }

const char *moo(Cow *this) {
  char *old_moo = this->moo;
  int old_length = strlen(old_moo);
  this->moo = malloc(old_length + 2);
  strcpy(this->moo, old_moo);
  this->moo[old_length] = 'o';
  this->moo[old_length + 1] = '\0';
  free(old_moo);

  return this->moo;
}
const char *cow_name(const Cow *this) { return animal_name(&this->base); }

const char *pig_squeals[] = {"oink",       "oink oink",   "OINK!",
                             "oink!",      "snort",       "grumph",
                             "oink-snort", "oinkity oink"};

const char *virtual_squeal(Animal *this) { return squeal((Pig *)this); }
void virtual_de_init_pig(Animal *this) { de_init_pig((Pig *)this); }
const AnimalVTable VPig[] = {{virtual_squeal, virtual_de_init_pig}};

void init_pig(Pig *this, const char *name) {
  init_animal(&this->base, VPig, name);
  static int seeded = 0;
  if (!seeded) {
    srand((unsigned)time(NULL));
    seeded = 1;
  }
}

void de_init_pig(Pig *this) {}
const char *squeal(const Pig *this) {
  int idx = rand() % sizeof(pig_squeals) / sizeof(pig_squeals[0]);
  return pig_squeals[idx];
}

const char *pig_name(const Pig *this) { return animal_name(&this->base); }
