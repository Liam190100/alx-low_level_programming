#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - Print listint_t linked list with loop
 * @head: Points to head of node list
 *
 * Return: The nodes in the list of that number
 */

size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current = head, *prev;
	size_t count = 0;

	while (current != NULL)
	{
	printf("[%p] %d\n", (void *)current, current->n);
	count++;

	prev = current;
	current = current->next;

	if (prev <= current)
	{
	printf("-> [%p] %d\n", (void *)current, current->n);
	count++;
	break;
	}
	}

	return (count);
}

