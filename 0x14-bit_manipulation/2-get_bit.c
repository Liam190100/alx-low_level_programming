#include "main.h"
#include <stdio.h>

/**
 * get_bit - returns bit in index at decimal number
 * @n: number to search
 * @index: the bit value of the index
 *
 * Return: the bit of that value
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_val;

	if (index > 63)
	return (-1);

	bit_val = (n >> index) & 1;

	return (bit_val);
}

