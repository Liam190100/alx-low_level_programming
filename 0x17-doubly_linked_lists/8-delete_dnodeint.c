#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes index node
 * index of list.
 * @head: pointer to head list
 * @index: index element
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *num_node = *head;
	size_t size = 0;

	if (!*head)
	{
		return (-1);
	}
	while (num_node)
	{
		size++;
		num_node = num_node->next;
	}
	if (size < index + 1)
	{
		return (-1);
	}
	num_node = *head;
	if (!index)
	{
		*head = num_node->next;
		if (num_node->next)
		{
			num_node->next->prev = NULL;
		}
		num_node->next = NULL;
		free(num_node);
		return (1);
	}
	while (index--)
	{
		num_node = num_node->next;
	}
	num_node->prev->next = num_node->next;
	if (num_node->next)
	{
		num_node->next->prev = num_node->prev;
	}
	free(num_node);
	return (1);
}
