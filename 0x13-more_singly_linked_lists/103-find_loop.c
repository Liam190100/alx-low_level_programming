#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * find_listint_loop - loops the linked list
 * @head: Search for the linked list
 *
 * Return: Shows the node to loop or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *cat = head;
	listint_t *dog = head;

	if (!head)
		return (NULL);

	while (cat && dog && dog->next)
	{
		dog = dog->next->next;
		cat = cat->next;
		if (dog == cat)
		{
			cat = head;
			while (cat != dog)
			{
				cat = cat->next;
				dog = dog->next;
			}
			return (dog);
		}
	}

	return (NULL);
}

