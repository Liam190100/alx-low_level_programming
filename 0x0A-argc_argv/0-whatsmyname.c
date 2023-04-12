#include "main.h"
#include <stdio.h>

/**
  * main - Prints its name, followed by a new line.
  * @argc: argument count
  * @argv: arguments
  *
  * Return:0
  */
int main(int argc, char *argv[])
{
	(void) argc;
	printf("%s\n", *argv);

	return (0);
}
