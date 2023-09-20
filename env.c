#include "main.h"
#include <stdio.h>
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
	write(2, ": 1:", 5);
	write(2, cmd, _strlen(cmd));
	write(2, ": not found\n", 12);
}
/**
 * path_handler - check if a command file exist or not.
 * @command:command name.
 * @av:programme name.
 *
 * Return: Always string of command full path or NULL
 */
char *path_handler(char *command, char **av)
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
		full_command = NULL;
		tkn = strtok(NULL, ":");
	}
	free(tmp);
	if (!full_command)
		print_error(av, command);
	return (NULL);
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

	if (!token[0])
		return (127);
	pid = fork();
	if (pid == 0)
	{
		execve(token[0], token, environ);
		exit(1);
	}
	else
	{
		wait(&stat);
		if (WIFEXITED(stat))
			stat = WEXITSTATUS(stat);
	}
	return (stat);
}
