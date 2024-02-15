#include "main.h"
/**
 * env_handler - envirement variable.
 * @buffer: buffer to free in case.
 * @token: table has env variable.
 *
 */

void env_handler(char *buffer, char **token)
{
	unsigned int i;

	i = -1;
	free(buffer);
	free(token);
	while (environ[++i])
	{
		write(1, environ[i], _strlen(environ[i]));
		write(1, "\n", 1);
	}
}


/**
 * _getenv - get value of env.
 * @name: name of env.
 * Return: pointer to the value of the specified env or NULL.
 */


char *_getenv(const char *name)
{
	size_t i;
	size_t j;

	i = 0;
	while (environ[i])
	{
		j = 0;
		if (environ[i][j] == name[j])
		{
			while (name[j])
			{
				if (name[j] != environ[i][j])
				{
					break;
				}
				j++;
			}
			if (name[j] == 0)
			{
				return (&environ[i][j]);
			}
		}
		i++;
	}
	return (NULL);
}

/**
 * print_error - Print Error and args.
 * @av: programme name.
 * @cmd: command name.
 *
 */

void print_error(char **av, char *cmd)
{
	write(2, av[0], _strlen(av[0]));
	write(2, ": 1: ", 5);
	write(2, cmd, _strlen(cmd));
	write(2, ": not found\n", 12);
}
/**
 * path_handler - check if a command file exist or not.
 * @command:command name.
 *
 * Return: Always string of command full path or NULL
 */
char *path_handler(char *command)
{
	char *path;
	char *tkn, *tmp, *full_command = NULL;

	path = _getenv("PATH");
	if (path == NULL || *path == '\0')
	{
		if (access(command, X_OK) == 0)
			return (command);
		else
			return (NULL);
	}
	tmp = _strdup(path);
	if (tmp == NULL)
		return (NULL);

	tkn = strtok(tmp, ":");
	while (tkn != NULL)
	{
		size_t full_commandLen = _strlen(tkn) + _strlen(command) + 2;

		full_command = malloc(full_commandLen);

		if (full_command == NULL)
		{
			free(tmp);
			return (NULL);
		}
		sprintf(full_command, "%s/%s", tkn, command);

		if (access(full_command, X_OK) == 0)
		{
			free(tmp);
			return (full_command);
		}
		free(full_command);
		tkn = strtok(NULL, ":");
	}
	free(tmp);
	return (command);
}

/**
 * cmd_Exec - execution of a file (command line).
 * @token: table of command.
 *
 * Return: if command exist return 1 if not 0.
 */

int cmd_Exec(char **token)
{
	pid_t pid;
	int stat;

	stat = 0;
	if (!token[0])
		return (127);
	pid = fork();
	if (pid == 0)
	{
		execve(token[0], token, environ);
		return (0);
	}
	else
	{
		wait(&stat);
		if (WIFEXITED(stat))
			stat = WEXITSTATUS(stat);
	}
	return (stat);
}
