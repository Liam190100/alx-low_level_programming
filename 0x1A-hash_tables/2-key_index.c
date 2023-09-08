#include "hash_tables.h"

/**
 * key_index - Key index
 * @key: The key
 * @size: Size the hash table
 * Return: The key/value of the hash size
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash;

	hash = hash_djb2(key);

	return (hash % size);
}
