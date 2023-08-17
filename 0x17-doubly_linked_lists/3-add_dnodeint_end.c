#include <stdlib.h>
#include "lists.h"

/**
 * add_dnodeint_end - Add a new node at the end of a dlistint_t list.
 * @head: A pointer head of list.
 * @n:  value  stored in new node.
 * Return: new element, or NULL if it failed.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
    dlistint_t *new_node = malloc(sizeof(dlistint_t));
    dlistint_t *num = *head;

    if (new_node == NULL)
        return (NULL);

    new_node->n = n;
    new_node->next = NULL;

    if (*head == NULL)
    {
        new_node->prev = NULL;
        *head = new_node;
        return (new_node);
    }

    while (num->next != NULL)
    {
        num = num->next;
    }

    new_node->prev = num;
    num->next = new_node;

    return (new_node);
}

