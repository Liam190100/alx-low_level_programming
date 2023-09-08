#include "hash_tables.h"
/**
 * hash_table_set - Adds or updates an element in the hash table.
 * @ht: The hash table to add or update the key/value pair in.
 * @key: The key for the element.
 * @value: The value associated with the key.
 * Return: 1 if successful, 0 otherwise.
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *new_node, *current_node;

	/* Check if the parameters are valid */
	if (ht == NULL || key == NULL || value == NULL || strlen(key) == 0)
		return (0);

	/* Get the index for the key using key_index function */
	index = key_index((const unsigned char *)key, ht->size);

	current_node = ht->array[index];
	while (current_node != NULL)
	{
		/* If the key already exists, update its value */
		if (strcmp(current_node->key, key) == 0)
		{
			free(current_node->value);
			current_node->value = strdup(value);
			if (current_node->value == NULL)
				return (0);
			return (1);
		}
		current_node = current_node->next;
	}

	/* Allocate memory for a new node */
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);

	/* Copy the key and value into the new node */
	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (0);
	}
	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (0);
	}

	/* Add the new node to the beginning of the linked list at the index */
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}

