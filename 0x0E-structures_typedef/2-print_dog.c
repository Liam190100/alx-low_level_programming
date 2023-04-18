#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
  * print_dog -prints struct of a dog
  * @d: struct a dog to print
  *
  * Return: Null
  */
void print_dog(struct dog *d)
{
	if (d != NULL)
	{
		printf("Name: %s\n", (d->name) ? d->name : "(nil)");
		printf("Age: %f\n", (d->age) ? d->age : 0);
		printf("Owner: %s\n", (d->owner) ? d->owner : "(nil)");
	}
}
