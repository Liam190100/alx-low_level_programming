#include <stdlib.h>
#include "dog.h"

/**
  * free_dog -frees memory allocation for struct dog
  * @d:dog to free
  *
  * Return: null
  */
void free_dog(dog_t *d)
{
	if (d== NULL)
	{
		free(d->owner);
		free(d->name);
		free(d);
	}
}
