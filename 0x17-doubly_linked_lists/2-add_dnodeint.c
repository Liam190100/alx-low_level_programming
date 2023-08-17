#include <stdlib.h>
#include "lists.h"

/**
 * add_dnodeint - Add a new node at dlistint_t list.
 * @head: A pointer to head of list.
 * @n: The value to be stored in the new node.
 * Return: new element, or NULL if it failed.
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node = malloc(sizeof(dlistint_t));

	if (new_node == NULL)
	return (NULL);

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;

	if (*head != NULL)
	(*head)->prev = new_node;

	*head = new_node;

	return (new_node);
}

