#include "lists.h"

/**
 * print_listint - print will print linked list
 * @h: linked list print as the element
 *
 * Return: the nodes number
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


