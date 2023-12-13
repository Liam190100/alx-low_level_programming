#include "search_algos.h"
#include <stdio.h>


/**
 * print_array - Prints elements of an array from a starting to an ending index
 * @array: Array to print
 * @start: Starting index
 * @end: Ending index
 * Return: void
 */

void print_array(int *array, size_t start, size_t end)
{
	if (!array)
		return;

	while (start < end)
		printf("%i, ", array[start++]);

	printf("%i\n", array[start]);
}

/**
 * binary_search - Finds a specific value in a sorted array using binary search
 * @array: Array of integer values (must be sorted in ascending order)
 * @size: Size of the array
 * @value: Integer value to find
 * Return: Index of the value if found, -1 otherwise
 */

int binary_search(int *array, size_t size, int value)
{
	size_t low, mid, high;

	if (!array)
		return (-1);

	low = 0;
	high = size - 1;
	mid = low + (high - low) / 2;

	while (low <= high)
	{
		printf("Searching in array: ");
		print_array(array, low, high);

		if (low == high)
		{
			if (array[low] == value)
				return (low);
			else
				return (-1);
		}

		if (array[mid] < value)
			low = mid + 1;
		else if (array[mid] > value)
			high = mid - 1;
		else
			return (mid);

		mid = low + (high - low) / 2;
	}

	return (-1);
}
