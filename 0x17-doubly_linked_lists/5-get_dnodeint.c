#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the nth node dlistint_t linked list.
 * @head: A pointers head list.
 * @index: The index node.
 * Return: The nth node, or NULL if it doesn't exist.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
    unsigned int count = 0;
    dlistint_t *current = head;

    while (current != NULL)
    {
        if (count == index)
            return (current);

        current = current->next;
        count++;
    }

    return (NULL);
}

