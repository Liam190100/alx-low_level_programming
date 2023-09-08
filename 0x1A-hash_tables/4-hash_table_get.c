#include "hash_tables.h"

/**
 * hash_table_get - Retrieves the value associated with a key in a hash table.
 * @ht: A pointer to the hash table.
 * @key: The key to get the value for.
 * Return: If the key cannot be found - NULL. Otherwise - the value associated with the key in ht.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *node;
	unsigned long int index;

	/* Check if the parameters are valid */
	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);

	/* Ensure the index is within the valid range */
	if (index >= ht->size)
		return (NULL);

	/* Search for the key in the linked list at the calculated index */
	node = ht->array[index];
	while (node && strcmp(node->key, key) != 0)
		node = node->next;

	/* Return the value if the key was found, otherwise return NULL */
	return ((node == NULL) ? NULL : node->value);
}

