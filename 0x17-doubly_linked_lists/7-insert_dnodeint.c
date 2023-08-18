#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node .
 * @h: A pointer head list.
 * @idx: The index where the new node is added .
 * @n: The value to new node.
 * Return: The new node, or NULL if it failed.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *tmp = *h, *new;

	if (idx == 0)
	{
		return (add_dnodeint(h, n));
	}
	for (; idx != 1; idx--)
	{
		tmp = tmp->next;
		if (!tmp)
		{
			return (NULL);
		}
	}
	if (!tmp->next)
	{
		return (add_dnodeint_end(h, n));
	}
	new = malloc(sizeof(dlistint_t));

	if (!new)
	{
		return (NULL);
	}
	new->n = n;
	new->prev = tmp;
	new->next = tmp->next;
	tmp->next->prev = new;
	tmp->next = new;
	return (new);
}
