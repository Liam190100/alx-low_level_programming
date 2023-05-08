#include <stdlib.h>
#include "main.h"
#include <unistd.h>

/**
 * append_text_to_file - Appends text content to a file
 * @filename: The name of the file
 * @text_content: The content to append to the file
 *
 * Return: (1 on success), (-1 on failure)
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int a, count = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (count = 0; text_content[count];)
			count++;
	}

	a = open(filename, O_WRONLY | O_APPEND);
	a = write(a, text_content, count);

	if (a == -1 || a == -1)
		return (-1);

	close(a);

	return (1);
}

