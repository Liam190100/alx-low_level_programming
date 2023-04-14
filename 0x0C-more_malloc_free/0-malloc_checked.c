#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
  * malloc_checked - memory of the allocation 
  * @b: the size to allocate
  * pointer is to refer to memory 
  * Return: Nothing cause of void 
  */
void *malloc_checked(unsigned int b)
{
	void *p;

	p = malloc(b);

	if (p == NULL)
		exit(98);

	return (p);
}
