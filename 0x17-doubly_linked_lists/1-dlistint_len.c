#include <stdio.h>
#include "lists.h"
/**
 * dlistint_len - Return the number of elements in a linked
 *@h: pointer to the list head
 *Return:the node
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t num = 0;

	while (h != NULL)
	{
		h = h->next;
		num++;
	}

	return (num);
}
