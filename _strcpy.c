#include "main.h"
/**
 * _strcpy- copies source array to dest array
 * @dest: destination array variable pointer
 * @src: source array variable pointer
 * Return: char
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
