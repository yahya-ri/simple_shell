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
	int ret = 0, exit_cmd = 0;
	size_t size = 0;

	while (1)
	{
		buffer = NULL;
		if (isatty(STDIN_FILENO))
			write(1, "#cisfun$ ", 10);
		ret = getline(&buffer, &size, stdin);

		if (ret > 0 && (buffer[0] == 0 || buffer[0] == '\n'))
			continue;
		else if (ret == -1 || _strcmp(buffer, "exit\n") == 0)
		{
			free(buffer);
			exit(exit_cmd);
		}
		token = _strtok(buffer, " \t\n");

		if (_strcmp(buffer, "env") == 0)
		{
			env_handler(buffer, token);
			continue;
		}
		if (!token)
		{
			free(buffer);
			exit(exit_cmd);
		}
		if (token[0])
		{
			token[0] = path_handler(token[0], av);
			exit_cmd = cmd_Exec(token);
		}
		free(buffer);
		free(token);
	}
	return (0);
}
