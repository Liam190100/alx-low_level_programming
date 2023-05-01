#include "lists.h"
#include <stdio.h>
/**
 * listint_len - print linked lists
 * @h: linked list that print listint_t to traverse the number
 * Return: nodes of listint_t list
 */
size_t listint_len(const listint_t *h)
{
    size_t count = 0;

    while (h != NULL)
    {
        count++;
        h = h->next;
    }

    return (count);
}
