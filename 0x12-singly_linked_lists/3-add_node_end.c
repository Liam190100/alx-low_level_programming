#include <stdio.h>
#include "lists.h"
/**
 * add_node_end - Adds a new node at list_t list.
 * @head: Pointer to the pointer to the head node of the list.
 * @str: String in list node.
 *
 * Return: NULL when failed.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	if (head == NULL || str == NULL)
	return (NULL);

	list_t *new_node = malloc(sizeof(list_t));

	if (new_node == NULL)
	return (NULL);

	char *str_copy = strdup(str);

	if (str_copy == NULL)
	{
	free(new_node);
	return (NULL);
	}

	new_node->str = str_copy;
	new_node->next = NULL;

	if (*head == NULL)
	{
	*head = new_node;
	}
	else
	{
	list_t *last_node = *head;

	while (last_node->next != NULL)
	{
	last_node = last_node->next;
	}
	last_node->next = new_node;
	}

	return (new_node);
}
