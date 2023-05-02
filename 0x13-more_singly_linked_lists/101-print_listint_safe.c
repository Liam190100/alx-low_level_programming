#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * print_listint_safe - Print listint_t linked list with loop
 * @head: Points to head of node list
 *
 * Return: The nodes in the list of that number
 */

size_t looped_listint_len(const listint_t *head)
{
	const listint_t *dog, *cat;
	size_t nodes = 1;

	if (head == NULL || head->next == NULL)
	return (0);

	dog = head->next;
	cat = (head->next)->next;

	while (cat)
	{
	if (dog == cat)
	{
	dog = head;
	while (dog != cat)
	{
	nodes++;
	dog = dog->next;
	cat = cat->next;
	}

	dog = dog->next;
	while (dog != cat)
	{
	nodes++;
	dog = dog->next;
	}

	return (nodes);
	}

	dog = dog->next;
	cat = (cat->next)->next;
	}
	return (0);
}

/**
 * print_listint_safe - Prints a listint_t list safely.
 * @head: A points to head of listint_t list.
 *
 * Return: The nodes inlist.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes, index = 0;

	nodes = looped_listint_len(head);

	if (nodes == 0)
	{
	for (; head != NULL; nodes++)
	{
	printf("[%p] %d\n", (void *)head, head->n);
	head = head->next;
	}
	}

	else
	{
	for (index = 0; index < nodes; index++)
	{
	printf("[%p] %d\n", (void *)head, head->n);
	head = head->next;
	}

	printf("-> [%p] %d\n", (void *)head, head->n);
	}

	return (nodes);
}

