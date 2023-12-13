#include "search_algos.h"
#include <stdio.h>
#include <math.h>

/**
 * jump_search - Finds the first occurrence of a value in a sorted array
 * using jump search with a step size of the square root of 2.
 * @array: Array of integer values (must be sorted in ascending order)
 * @size: Size of the array
 * @value: Integer value to find
 * Return: The first index of the value found, or -1 if not found
 */

int jump_search(int *array, size_t size, int value)
{
	size_t a, b;
	int found = -1;
	size_t jump = sqrt(size);

	if (!array)
		return (found);

	/* Jump step */
	for (a = 0; a < size && array[a] < value; a += jump)
		printf("Value checked array[%lu] = [%i]\n", a, array[a]);

	printf("Value found between indexes [%lu] and [%lu]\n", a - jump, a);

	for (b = a - jump; b < size; b++)
	{
		printf("Value checked array[%lu] = [%i]\n", b, array[b]);
		if (array[b] == value)
			return (b);
	}

	return (found);
}
