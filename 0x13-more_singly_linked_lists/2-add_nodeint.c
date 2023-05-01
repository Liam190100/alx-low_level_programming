#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint - Adds a new node at listint_t list.
 * @head: Its point the head to listint_t list.
 * @n: The new node is entered
 *
 * Return:  NULL if it failed.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node;

	if (head == NULL)
	return (NULL);

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
	return (NULL);

	new_node->n = n;
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}

