#include "hash_tables.h"

/**
 * shash_table_create - Create a sorted hash table.
 * @size: The size of the array.
 *
 * Return: A pointer to the new hash table, or NULL on failure.
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
 * create_node - Create a new node with the given key and value.
 * @key: The key to store in the node.
 * @value: The value associated with the key.
 *
 * Return: A pointer to the new node, or NULL on failure.
 */
shash_node_t *create_node(const char *key, const char *value)
{
	shash_node_t *new;

	new = malloc(sizeof(shash_node_t));
	if (new == NULL)
		return (NULL);

	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(new);
		return (NULL);
	}

	new->value = strdup(value);
	if (new->value == NULL)
	{
		free(new->key);
		free(new);
		return (NULL);
	}

	new->next = NULL;
	new->sprev = NULL;
	new->snext = NULL;

	return (new);
}

/**
 * insert_node - Insert a new node into a sorted linked list.
 * @ht: The hash table.
 * @new: The new node to insert.
 */
void insert_node(shash_table_t *ht, shash_node_t *new)
{
	shash_node_t *current;

	if (ht->shead == NULL)
	{
		ht->shead = new;
		ht->stail = new;
		return;
	}

	current = ht->shead;
	while (current != NULL && strcmp(current->key, new->key) < 0)
		current = current->snext;

	if (current == NULL)
	{
		new->sprev = ht->stail;
		ht->stail->snext = new;
		ht->stail = new;
		return;
	}

	if (current == ht->shead)
	{
		new->snext = ht->shead;
		ht->shead->sprev = new;
		ht->shead = new;
		return;
	}

	new->sprev = current->sprev;
	new->snext = current;
	current->sprev->snext = new;
	current->sprev = new;
}

/**
 * shash_table_set - Add or update an element in the sorted hash table.
 * @ht: The hash table to add or update.
 * @key: The key to add or update.
 * @value: The value associated with the key.
 *
 * Return: 1 on success, 0 on failure.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *new, *current;

	if (ht == NULL || key == NULL || value == NULL || strlen(key) == 0)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	current = ht->array[index];

	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
		{
			free(current->value);
			current->value = strdup(value);
			return (current->value != NULL);
		}
		current = current->next;
	}

	new = create_node(key, value);
	if (new == NULL)
		return (0);

	new->next = ht->array[index];
	ht->array[index] = new;
	insert_node(ht, new);

	return (1);
}

/**
 * shash_table_get - Retrieve the value associated with a key.
 * @ht: The hash table to search.
 * @key: The key to search for.
 *
 * Return: The value associated with the key, or NULL if not found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *current;

	if (ht == NULL || key == NULL || strlen(key) == 0)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	current = ht->array[index];

	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
			return (current->value);
		current = current->next;
	}

	return (NULL);
}

/**
 * shash_table_print - Print the sorted hash table in ascending order.
 * @ht: The hash table to print.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *current;
	int flag = 0;

	if (ht == NULL)
		return;

	printf("{");
	current = ht->shead;

	while (current != NULL)
	{
		if (flag == 1)
			printf(", ");
		printf("'%s': '%s'", current->key, current->value);
		flag = 1;
		current = current->snext;
	}

	printf("}\n");
}

/**
 * shash_table_print_rev - Print the sorted hash table in descending order.
 * @ht: The hash table to print.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *current;
	int flag = 0;

	if (ht == NULL)
		return;

	printf("{");
	current = ht->stail;

	while (current != NULL)
	{
		if (flag == 1)
			printf(", ");
		printf("'%s': '%s'", current->key, current->value);
		flag = 1;
		current = current->sprev;
	}

	printf("}\n");
}

/**
 * shash_table_delete - Delete a sorted hash table.
 * @ht: The hash table to delete.
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *current, *tmp;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		current = ht->array[i];
		while (current != NULL)
		{
			tmp = current->next;
			free(current->key);
			free(current->value);
			free(current);
			current = tmp;
		}
	}

	free(ht->array);
	free(ht);
}

