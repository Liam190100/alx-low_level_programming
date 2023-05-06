#include "main.h"
#include <stdio.h>

/**
 * putchar_number - prints the binary representation of a decimal number
 *
 * @n: the number to print in binary
 */
void print_binary(unsigned long int n)
{
	int i, count = 0;
	unsigned long int current;

	for (i = 63; i >= 0; i--)
	{
	current = n >> i;

	if (current & 1)

	{
	_putchar('1');
	count++;
	}
	else if (count)

	_putchar('0');
	}
	if (!count)

	_putchar('0');
}

