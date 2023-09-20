#include "main.h"
extern char **environ;

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
 * path_handler - check if a command file exist or not.
 * @command:command name.
 *
 * Return: Always string of command full path or NULL
 */
char *path_handler(char *command)
{
	char *tmp = NULL;
	char *tkn = NULL;
	char *full_command = NULL;
	char *path = NULL;
	struct stat st;

	if (stat(command, &st) == 0)
	{
		return (command);
	}
	path = _getenv("PATH");
	tmp = _strdup(path);
	tkn = strtok(tmp, ":");
	while (tkn)
	{
		full_command = malloc(_strlen(tkn) + 1 + _strlen(command) + 1);
		if (!full_command)
		{
			free(tmp);
			return (NULL);
		}
		_strcpy(full_command, tkn);
		_strcat(full_command, "/");
		_strcat(full_command, command);

		if (stat(full_command, &st) == 0)
		{
			free(tmp);
			return (full_command);
		}
		free(full_command);
		tkn = strtok(NULL, ":");
	}
	free(tmp);
	return (NULL);
}

/**
 * cmd_Exec - execution of a file (command line).
 * @token: table of command.
 * @av: programme name
 *
 * Return: if command exist return 1 if not 0.
 */

int cmd_Exec(char **token, char **av)
{
	pid_t pid;
	int stat;

	pid = fork();
	if (pid == 0)
	{
		if (execve(token[0], token, environ) == -1)
		{
			write(1, av[0], _strlen(av[0]));
			write(1, ": No such file or directory\n", 29);
		}
		exit(1);
	}
	else
		wait(&stat);
	return (stat);
}
