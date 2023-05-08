#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to POSIX standard output
 * @filename: The name of the file to read
 * @letters: The number of letters to read and print
 *
 * Return: The actual number of letters read and printed,
 *         or 0 if the file cannot be opened or read,
 *         or if write fails or does not write the expected amount of bytes
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t v;
	ssize_t u;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	u = read(fd, buf, letters);
	v = write(STDOUT_FILENO, buf, u);

	free(buf);
	close(fd);
	return (v);
}

