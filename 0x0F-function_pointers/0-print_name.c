#include "function_pointers.h"
#include <stdio.h>
/**
 * print_name - print name as is 
 * @name: name of the strings
 * @f: pointer to the name
 * Return: Always 0(Success)
 **/
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name);
}

