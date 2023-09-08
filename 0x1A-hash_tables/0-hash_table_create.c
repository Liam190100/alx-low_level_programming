#include "hash_tables.h"
/**
 * hash_table_create - Creates a hash table.
 * @size: Size of the table.
 * Return: A points to new table.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned int a = 0;
	hash_table_t *table;


	table = malloc(sizeof(hash_table_t));
	if (table == NULL)
		return (NULL);


	table->size = size;
	table->array = malloc(sizeof(hash_node_t *) * size);
	if (table->array == NULL)
	{
		free(table);
		return (NULL);
	}


	for (a = 0; a < size; a++)
		table->array[a] = NULL;

	return (table);
}
