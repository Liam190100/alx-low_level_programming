#include "search_algos.h"
#include <stdio.h>

/**
 * linear_search - array of integers using the Linear search algorithm
 * @array: integer array
 * @size: array size
 * @value: The integer value
 * Return: return the integer
 */
int linear_search(int *array, size_t size, int value)
{
	size_t a;
	int found = -1;

	if (!array)
		return (found);

	for (a = 0; a < size; a++)
	{
		printf("Value checked array[%lu] = [%d]\n", a, array[a]);
		if (array[a] == value)
		{
			found = a;
			break;
		}
	}

	return (found);
}
