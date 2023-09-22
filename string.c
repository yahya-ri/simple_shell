#include "main.h"
/**
* _strcmp - compares tow String.
* @s1: str1 value.
* @s2: str2 value.
*
* Description: function that compares two strings.
* Return: int value positive or negative.
*/

int _strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

/**
 * _strlen - count char in each word.
 * @str: string in.
 *
 * Description: function that returns the length of a string.
 * Return: nbr of string or 0;
 */
size_t _strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] && str)
		i++;
	return (i);
}

/**
* _strcat - Concatenates two strings.
* @dest: Destination value.
* @src: source string.
*
* Description : function that concatenates two strings.
* Return: full String dest + src.
*/

char *_strcat(char *dest, char *src)
{
	int i;

	i = 0;
	while (dest[i])
		i++;
	while (*src)
		dest[i++] = *src++;
	dest[i] = '\0';
	return (dest);
}

/**
* _strcpy - cpy string
* @dest: dest String.
* @src: src String.
*
* Description: function that copies the string
* pointed to by src, including the terminating
* null byte (\0), to the buffer pointed to by dest.
* Return: String dest value.
*/
char *_strcpy(char *dest, char *src)
{
	int i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * _strdup - returns a pointer to a newly allocated space.
 * @str: string to copy
 *
 * Description:function that returns a pointer to a newly allocated space in
 * memory, which contains a copy of the string given as a parameter.
 * Return: NULL or str pointer.
 */
char *_strdup(char *str)
{
	char *ptr;
	unsigned int i;

	i = 0;
	if (!str)
		return (NULL);
	ptr = malloc(sizeof(char) * _strlen(str) + 1);
	if (!ptr)
		return (NULL);
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}
