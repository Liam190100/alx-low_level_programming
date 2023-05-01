#include "lists.h"

/**
 * print_listint - Prints will show listint_t list.
 * @h: A pointer to the head of the listint_t list.
 *
 * Return: The nodes in the listint_t list.
 */
size_t print_listint(const listint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
	printf("%d\n", h->n);
	h = h->next;
	count++;
	}

	return (count);
}

