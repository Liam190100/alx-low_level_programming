#include "lists.h"
#include <stdlib.h>

/**
 * sum_listint - Returns the sum of all the data  of a listint_t linked list.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The sum of all the data of the listint_t list.
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *current = head;

	while (current != NULL)
	{
	sum += current->n;
	current = current->next;
	}

	return (sum);
}

