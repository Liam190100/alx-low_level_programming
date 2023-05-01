#include "lists.h"
#include <stdlib.h>
/**
 * free_listint - It freees the listint_t list.
 * @head: The pointer points  head of listint_t list.
 */
void free_listint(listint_t *head)
{
	listint_t *temp;

	while (head != NULL)
	{
	temp = head;
	head = head->next;
	free(temp);
	}
}

