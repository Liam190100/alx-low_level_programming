#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * add_nodeint_end - Adds a node to listint_t list.
 * @head: Its point to the head then listint_t list.
 * @n: The new node is add in the value
 *
 * Return: NULL if it failed.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node, *temp;

	if (head == NULL)
	return (NULL);

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
	return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	*head = new_node;
	else
	{
	temp = *head;
	while (temp->next != NULL)
	temp = temp->next;
	temp->next = new_node;
	}

	return (new_node);
}

