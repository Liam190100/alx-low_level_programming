#include "hash_tables.h"
/* Include the necessary header file */

/**
 * shash_table_create - Creates a new sorted hash table.
 * @size: The size of the new hash table.
 *
 * Return: If memory allocation fails, return NULL.
 *         Otherwise, return a pointer to the new hash table.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = calloc(size, sizeof(shash_node_t *));
	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * shash_table_set - Adds an element to the sorted hash table.
 * @ht: The sorted hash table to add to.
 * @key: The key to add.
 * @value: The value to add.
 *
 * Return: If memory allocation fails or if the key already exists,
 *         return 0. Otherwise, return 1.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int i;
	shash_node_t *node_cp = NULL, *temp_node = NULL;
	shash_node_t *current;

	if (ht == NULL || key == NULL || value == NULL)
		return (0);

	i = hash_djb2((const unsigned char *)key) % ht->size;

	node_cp = malloc(sizeof(shash_node_t));
	if (node_cp == NULL)
		return (0);

	node_cp->key = strdup(key);
	node_cp->value = strdup(value);
	node_cp->next = NULL;

	if (ht->array[i] == NULL)
	{
		ht->array[i] = node_cp;
	}
	else
	{
		temp_node = ht->array[i];
		while (temp_node->next != NULL)
		{
			if (strcmp(temp_node->key, key) == 0)
			{
				free(node_cp->key);
				free(node_cp->value);
				free(node_cp);
				free(temp_node->value);
				temp_node->value = strdup(value);
				return (1);
			}
			temp_node = temp_node->next;
		}
		temp_node->next = node_cp;
	}

	if (ht->shead == NULL || strcmp(key, ht->shead->key) < 0)
	{
		node_cp->sprev = NULL;
		node_cp->snext = ht->shead;
		if (ht->shead != NULL)
			ht->shead->sprev = node_cp;
		ht->shead = node_cp;
		if (ht->stail == NULL)
			ht->stail = node_cp;
	}
	else
	{
		current = ht->shead;
		while (current->snext != NULL && strcmp(key, current->snext->key) > 0)
			current = current->snext;

		node_cp->sprev = current;
		node_cp->snext = current->snext;
		current->snext = node_cp;
		if (node_cp->snext != NULL)
			node_cp->snext->sprev = node_cp;
		else
		{
			ht->stail = node_cp;
		}
	}
	return (1);
}

/**
 * shash_table_get - Retrieves the value associated with a key.
 * @ht: The sorted hash table to search.
 * @key: The key to search for.
 *
 * Return: If the key is found, return the associated value.
 *         Otherwise, return NULL.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *temp_node = NULL;
	unsigned long int i;

	if (ht == NULL || key == NULL)
		return (NULL);

	i = hash_djb2((const unsigned char *)key) % ht->size;
	temp_node = ht->array[i];

	while (temp_node != NULL)
	{
		if (strcmp(temp_node->key, key) == 0)
			return (temp_node->value);

		temp_node = temp_node->next;
	}
	return (NULL);
}

/**
 * shash_table_print - Prints the sorted hash table in ascending order.
 * @ht: The sorted hash table to print.
 *
 * Return: Void.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *current = NULL;

	if (ht == NULL)
		return;

	current = ht->shead;
	while (current != NULL)
	{
		printf("{'%s': '%s'}\n", current->key, current->value);
		current = current->snext;
	}
}

/**
 * shash_table_print_rev - Prints the sorted hash table in descending order.
 * @ht: The sorted hash table to print.
 *
 * Return: Void.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *current = NULL;

	if (ht == NULL)
		return;

	current = ht->stail;
	while (current != NULL)
	{
		printf("{'%s': '%s'}\n", current->key, current->value);
		current = current->sprev;
	}
}

/**
 * shash_table_delete - Frees allocated memory for the sorted hash table.
 * @ht: The sorted hash table to delete.
 *
 * Return: Void.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *current = NULL, *temp_node = NULL;
	unsigned long int i, table_size;

	if (ht == NULL)
		return;

	table_size = ht->size;

	for (a = 0; a < table_size; a++)
	{
		current = ht->array[i];
		while (current != NULL)
		{
			temp_node = current->next;
			free(current->key);
			free(current->value);
			free(current);
			current = temp_node;
		}
	}
	free(ht->array);
	free(ht);
}

