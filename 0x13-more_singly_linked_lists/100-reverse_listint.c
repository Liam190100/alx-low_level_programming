#include "lists.h"
#include <stdlib.h>

/**
 * reverse_listint - Reverses a listint_t linked list recursively
 * @head: Double points the head node of list
 *
 * Return: A points node of reversed list
 */

listint_t *reverse_listint(listint_t **head)
{
	if (*head == NULL || (*head)->next == NULL)
	{
	return (*head);
	}
	listint_t *temp = reverse_listint(&(*head)->next);
	(*head)->next->next = *head;
	(*head)->next = NULL;
	*head = temp;
	return (temp);
}

