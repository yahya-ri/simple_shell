#include "main.h"
#include <stddef.h>

/**
 * read_line - read line for stdin
 * @line: buffer allocate string.
 * @n: size of string.
 * @stream: source file.
 *
 * Description: function that reads an entire line from stream.
 * Return: Always string  or -1.
 */

int read_line(char **line, size_t *n, int stream)
{
	char *buf = NULL;
	size_t i;
	int res;

	i = 0;
	if (!*line || !*n)
	{
		*n = 120;
		*line = malloc(sizeof(char) * (*n) + 1);
		if (!line)
		{
			perror("allocation failed");
			return (-1);
		}
	}
	res = read(stream, *line, *n);
	while (res > 0)
	{
		buf = *line;
		for (; i < *n; i++)
		{
			if (buf[i] == '\n')
			{
				buf[++i] = 0;
				return (i);
			}
		}
		_realloc(*line, *n, 2 * *n);
		*n *= 2;
		res = read(stream, *line, *n);
	}
	if (i == 0)
		return (-1);
	*line[i] = 0;
	return (i);
}
