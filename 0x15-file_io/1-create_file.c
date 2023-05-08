#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * create_file - Creates a file and writes content to it
 * @filename: The name of file to create
 * @text_content: write to the file
 *
 * Return: (1 on success), (-1 on failure)
 */
int create_file(const char *filename, char *text_content)
{
	int c;
	int name;
	int g;

	if (!filename)
		return (-1);

	c = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (c == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (name = 0; text_content[name]; name++)
		;

	g = write(c, text_content, name);

	if (g == -1)
		return (-1);

	close(c);

	return (1);
}

