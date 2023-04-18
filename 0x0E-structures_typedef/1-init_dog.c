#include "dog.h"

/**
  * init_dog - Initializes a variable of type dog
  * @d: pointer to struct dog to initialize
  * @name: name to initialize
  * @age: The age of the dog.
  * @owner: The owner of the dog.
  *
  * Return: Nothing
  */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != NULL)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
