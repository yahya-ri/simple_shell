#include "main.h"
#include <stddef.h>

/**
 * main - UNIX command line interpreter.
 * Return: 1 or 0;
 */

int main(void)
{
	char *buffer = NULL;
	int ret = 0;
	size_t size = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "#cisfun$ ", 10);
		ret = read_line(&buffer, &size, STDIN_FILENO);

		if (ret == -1)
		{
			free(buffer);
			exit(1);
		}
		if (buffer == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(1, "\n", 1);
			break;
		}
	}

	return (0);
}
