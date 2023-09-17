#include "main.h"

/**
 * read_line - read line for stdin
 * Return: 0 or 1;
 */

char *read_line(void)
{
	char *buf = NULL;
	size_t i;

	i = 1;
	if (getline(&buffer, &buffer_s, stdin) == -1)
	{
		return (0);
	}

	return (buffer);
}
