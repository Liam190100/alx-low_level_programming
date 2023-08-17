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
	dlistint_t *new_node, *temp = *h;
	unsigned int count = 0;

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
	return (NULL);

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (idx == 0)
	{
	new_node->next = *h;
	if (*h != NULL)
	(*h)->prev = new_node;
	*h = new_node;
	return (new_node);
	}

	while (temp != NULL)
	
	if (count == idx - 1)
	{
	new_node->next = temp->next;
	}
	if (temp->next != NULL)
	{
		temp->next->prev = new_node;
		temp->next = new_node;
		new_node->prev = temp;
		return (new_node);
	
	count++;
	temp = temp->next;
	}

	free(new_node); /* If insertion is not possible */
	return (NULL);
}

