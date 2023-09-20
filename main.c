#include "main.h"

/**
 * main - UNIX command line interpreter.
 * @ac: argument count.
 * @av: vector argument.
 * Return: 1 or 0;
 */

int main(int ac __attribute__((unused)), char **av)
{
	char *buffer;
	char **token = NULL;
	int ret = 0;
	size_t size = 0;

	while (1)
	{
		buffer = NULL;

		if (isatty(STDIN_FILENO))
			write(1, "#cisfun$ ", 10);

		ret = read_line(&buffer, &size, STDIN_FILENO);

		if (ret > 0 && (buffer[0] == 0 || buffer[0] == '\n'))
			continue;

		else if (ret == -1 || _strcmp(buffer, "exit\n") == 0)
		{
			free(buffer);
			exit(1);
		}

		token = str_tok(buffer, " \t\n");

		if (!token)
		{
			free(buffer);
			free(token);
			exit(1);
		}

		else if (token[0])
		{
			token[0] = path_handler(token[0]);
			cmd_Exec(token, av);
		}
		free(buffer);
		free(token);
	}
	return (0);
}
