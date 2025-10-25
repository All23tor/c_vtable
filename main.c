#include "Farm.h"
#include "Pets.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Animal *animal_factory(const char *animal, const char *name) {
  if (strcmp(animal, "Dog") == 0) {
    Dog *my_dog = malloc(sizeof(Dog));
    init_dog(my_dog, name);
    return &my_dog->base;
  }
  if (strcmp(animal, "Cat") == 0) {
    Cat *my_cat = malloc(sizeof(Cat));
    init_cat(my_cat, name);
    return &my_cat->base;
  }
  if (strcmp(animal, "Cow") == 0) {
    Cow *my_cow = malloc(sizeof(Cow));
    init_cow(my_cow, name);
    return &my_cow->base;
  }
  if (strcmp(animal, "Pig") == 0) {
    Pig *my_pig = malloc(sizeof(Pig));
    init_pig(my_pig, name);
    return &my_pig->base;
  }
  return NULL;
}

void test_dynamic_animal(const char *animal, const char *name) {
  Animal *my_pet = animal_factory(animal, name);

  printf("\nThe animal's name is %s\n", animal_name(my_pet));
  for (int i = 0; i < 6; ++i)
    printf("%s says %s!\n", animal_name(my_pet), animal_cry(my_pet));

  de_init_animal(my_pet);
  free(my_pet);
}

int main(void) {
  test_dynamic_animal("Dog", "Fido");
  test_dynamic_animal("Cat", "Michi");
  test_dynamic_animal("Cow", "Lulu");
  test_dynamic_animal("Pig", "Napoleon");
}
