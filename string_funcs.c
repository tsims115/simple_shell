#include "main.h"
/**
 * _strdup - allocates space in memory and copies given string to it
 * @str: string to copy in
 * Return: a pointer to allocated memory / NULL if str = NULL / insufficent mem
 */

char *_strdup(char *str)
{
	int i;
	char *ps;
	int len = 0;

	if (str == NULL)
		return (NULL);
	while (str[len] != '\0')
		len++;
	len++;
	ps = malloc(len * sizeof(char));
	if (ps == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
		ps[i] = str[i];
	return (ps);
}

/**
 * _strcat - concatenates two strings together
 * @dest: stores the concatenated strings
 * @src: string to add on to dest
 *
 * Return: A pointer pointing to dest string
 *
 */

char *_strcat(char *dest, char *src)
{
	int len = 0;
	int i = 0;

	while (*(dest + len) != '\0')
	{
		len++;
	}
	for (i = 0; *(src + i) != '\0'; i++)
	{
		*(dest + len) = *(src + i);
		len++;
	}

	*(dest + len) = *(src + i);
	return (dest);
}

/**
 * _strchr - locates a character in a string
 * @s: string to look in
 * @c: character to locate
 * Return: Pointer to first occurrence of character c in s or NULL if not found
 */

int _strchr(char *s, char c)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == c)

			return (1);
		i++;
	}
	return (0);
}
