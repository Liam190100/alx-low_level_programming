#include "lists.h"
#include <stdlib.h>

/**
 * free_listint2 - It frees a listint_t head to NULL.
 * @head: Its pointer points to head of the listint_t list.
 */
void free_listint2(listint_t **head)
{
	listint_t *temp;

	if (head == NULL)
	return;

	while (*head != NULL)
	{
	temp = *head;
	*head = (*head)->next;
	free(temp);
	}
}

