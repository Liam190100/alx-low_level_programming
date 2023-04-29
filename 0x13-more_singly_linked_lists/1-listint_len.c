#include "lists.h"
#include <stdio.h>
/**
 * listint_len - print linked lists
 * @h: linked list that print listint_t to traverse the number
 * Return: nodes
 */
size_t listint_len(const listint_t *h)
{
	size_t num = 0;

	while (h != NULL)
	{
		num++;
		h = h->next;
	}

	return (number);
}

