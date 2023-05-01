#include "lists.h"
#include <stdlib.h>

/**
 * pop_listint - Deletes node of listint_t list and replace its data.
 * @head: A pointer that points to listint_t list.
 *
 * Return: 0 if the node list is empty.
 */
int pop_listint(listint_t **head)
{
	int data;
	listint_t *temp;

	if (head == NULL || *head == NULL)
	return (0);

	temp = *head;
	data = temp->n;
	*head = temp->next;
	free(temp);

	return (data);
}

