#include "main.h"
#include <stdio.h>

/**
 * flip_bits - num the number of bits to change
 * to get from one number to another
 * @n: the number
 * @m: two number
 *
 * Return:change number to bits
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, num = 0;
	unsigned long int current;
	unsigned long int exclusive = n ^ m;

	for (i = 63; i >= 0; i--)
	{
	current = exclusive >> i;
	if (current & 1)
	num++;
	}

	return (num);
}

