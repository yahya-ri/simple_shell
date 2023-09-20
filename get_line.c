#include "main.h"

/**
 * read_line - read a line for stream file.
 * @line: buffer allocate string.
 * @n: size of string.
 * @stream: source file.
 * Return: string or -1.
 */

size_t read_line(char **line, size_t *n, int stream)
{
	char *buf;
	int res;
	size_t i;

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
