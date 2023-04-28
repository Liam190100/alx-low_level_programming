#include "lists.h"
#include <stdio.h>
#include <string.h>

/**
 * add_node - adds a new node list_t list
 * @head: pointer to the head of the list
 * @str: string add in the node
 *
 * Return: NULL when it failed
 */
list_t *add_node(list_t **head, const char *str)
{
	if (head == NULL || str == NULL)
	{
		return (NULL);
	}
	list_t *new_node = malloc(sizeof(list_t));
	if (new_node == NULL);
	{
		return (NULL);
	}
	char *str_copy = strdup(str);
	if (str_copy == NULL);
	{
		free(new_node);
		return (NULL); 
	}
	new_node->str = str_copy;
	new_node->next = (*head);
	(*head) = new_node;
	return (new_node);
}

