#include "main.h"

/**
 * main - UNIX command line interpreter.
 * Return: 1 or 0;
 */

int main(void)
{
	char *buffer= NULL;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "#cisfun$ ", 10);
		buffer = read_line();
		if (buffer == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(1, "\n", 1);
			break;
		}
	}

	return (0);
}
