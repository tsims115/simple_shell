#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>
#include "main.h"

/**
 * _strlen - returns length of given string not including the null byte
 * @s: given string to get length
 * Return: Length of s
 */

int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}
/**
 * _strcmp - compares two strings and returns 0 if there is a match
 * @s1: first string pointer
 * @s2: second string pointer
 * Return: diff
 */
int _strcmp(char s1, char *s2)
{
	int diff = 1;

	while (*s2 != '\0')
	{
		if (s1 == *s2)
		{
			diff = 0;
		}
		s2++;
	}
	return (diff);
}

/**
 *_get_function - finds a match for the specifier and associates it with a
 *                function.
 * @s: input variable character to check for
 * Return: fun[i].funct if spec is found
 */
int (*_get_function(char s))(va_list * args)
{
	function_t fun[] = {
		{"c", _spec_c},
		{"s", _spec_s},
		{"d", _spec_di},
		{"i", _spec_di},
		{"%", _spec_pct},
		{NULL, NULL}
	};
	int i = 0;

	if (!s)
	{
		exit(99);
	}
	while (fun[i].spec != NULL)
	{
		if (_strcmp(s, fun[i].spec) == 0)
		{
			return (fun[i].funct);
		}
		i++;
	}
return (NULL);
}

/**
 * _printf - prints a formatted string to output
 * @format: input string to format and print
 * Return: total, the total number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int (*func)(va_list *); /* funct ptr to find funct for spec */
	int x = 0;  /* input incrementer variable */
	int tot = 0;  /* length of output string */

	va_start(args, format);
	if (!format)
	{
		return (-1);
	}
	while (format && format[x])
	{
		if (format[x] == '%')
		{
			x++;
			func = _get_function(format[x]);
			if (func != NULL)
			{
				tot += func(&args);
			}
			else
			{
				tot +=	_putchar('%');
				tot += _putchar(format[x]);
			}
			x++;
		}
		else
		{
			tot += _putchar(format[x]);
			x++;
		}
	}
	va_end(args);
return (tot);
}
