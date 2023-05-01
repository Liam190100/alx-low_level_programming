#include "lists.h"
#include <stdio.h>

/**
 * print_listint - prints number of lists of elements.
 * @h: linked list is to be print on the listint_t.
 *
 * Return: the number of nodes in the linkeed list.
 */
size_t print_listint(const listint_t *h)
{
	size_t num = 0;

	while (h)

	{
		printf("%d\n", h->n);
		num++;
		h = h->next;
	}

	return (num);
}

