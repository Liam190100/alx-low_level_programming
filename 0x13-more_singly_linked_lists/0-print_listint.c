#include "lists.h"
#include <stdio.h>
#include "string.h"
/**
 * print_listint - prints the number of linked list of the node.
 * @h: linked list is printed.
 *
 * Return:number in the nodes.
 */

size_t print_listint(const listint_t *h)
{
	size_t count = 0;

	while (h != NULL)

	{
		printf("%d\n", h->n);
		count++;
		h = h->next;
	}

	return (count);
}

