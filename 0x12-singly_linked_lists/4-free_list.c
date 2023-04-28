#include <stdlib.h>
#include "lists.h"

/**
 * free_list - Frees a list_t list.
 * @head: Pointer to the list_t list to be freed.
 * The function also frees memory allocated for the string in each node.
 */
void free_list(list_t *head)
{
	list_t *temp;

	while (head != NULL)
	{
	temp = head->next;
	free(head->str);
	free(head);
	head = temp;
	}
}

