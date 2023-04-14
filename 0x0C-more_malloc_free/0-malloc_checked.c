#include <stdlib.h> 
#include "main.h"
/**
 * Memory on  function that allocates memory
 * @b: number memory of bytes to allocates
 *
 * Return:a pointer allocate memory
 *status value is equal to 98.
 */
void *malloc_checked(unsigned int b)
{
	char *p;

	p = malloc(b);
	if (p == NULL)
		exit(98);
	return (p);
}

