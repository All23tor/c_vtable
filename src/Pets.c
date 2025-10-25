#include "Pets.h"

const char *virtual_bark(Animal *this) { return bark((Dog *)this); }
void virtual_de_init_dog(Animal *this) { return de_init_dog((Dog *)this); }
const AnimalVTable VDog[] = {{virtual_bark, virtual_de_init_dog}};

void init_dog(Dog *this, const char *name) {
  init_animal(&this->base, VDog, name);
}
void de_init_dog(Dog *this) {}
const char *bark(const Dog *this) { return "woof"; }
const char *dog_name(const Dog *this) { return animal_name(&this->base); }

const char *meows[] = {"meow", "meoow", "meooow"};

const char *virtual_meow(Animal *this) { return meow((Cat *)this); }
void virtual_de_init_cat(Animal *this) { return de_init_cat((Cat *)this); }
const AnimalVTable VCat[] = {{virtual_meow, virtual_de_init_cat}};

void init_cat(Cat *this, const char *name) {
  init_animal(&this->base, VCat, name);
  this->counter = 0;
}
void de_init_cat(Cat *this) {}

const char *meow(Cat *this) {
  this->counter++;
  this->counter = this->counter % 3;
  return meows[this->counter];
}
const char *cat_name(const Cat *this) { return animal_name(&this->base); }
int cat_count(const Cat *this) { return this->counter; }
