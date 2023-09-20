#include "main.h"

/**
 * word_count - count words.
 * @str: string.
 * Return: how many words.
 */

int word_count(char *str)
{
	int nbr;
	int i;

	i = 0;
	nbr = 0;
	while (str[i] == ' ' && str[i])
		i++;
	while (str[i])
	{
		if ((str[i] != ' ') && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			nbr++;
		i++;
	}
	return (nbr);
}

/**
 * str_tok - tokenize a string based on a deli.
 * @str: input string.
 * @delim: deli used for tokenization.
 * Return: array or NULL.
 */

char **str_tok(char *str, const char *delim)
{
	char **table = NULL;
	int i = 0;
	int size = 0;
	char *token = NULL;

	size = word_count(str);
	table = malloc(sizeof(char) * (size + 1));
	if (!table)
	{
		perror("allocation failed");
		return (NULL);
	}
	token = strtok(str, delim);
	while (token != NULL)
	{
		table[i++] = token;
		token = strtok(NULL, delim);
	}
	table[i] = NULL;
	return (table);
}

