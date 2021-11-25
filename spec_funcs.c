#include "main.h"
#include <stdarg.h>
#include <limits.h>
/**
 * _spec_pct - prints a % char when the % specifier is used
 * @args: not used for this function
 * Return: 1
 */
int _spec_pct(va_list *args)
{
        (void)(args);

        _putchar('%');
        return (1);
}

/**
 * print_min - prints int_min
 * Return: i
 */
int print_min(void)
{
	int i;
	char *int_min = "-2147483648";

	i = 0;
	while (*int_min != '\0')
	{
		_putchar(*int_min);
		i++;
		int_min++;
	}
	return (i);
}

/**
 * _spec_di - prints integer and returns how many character printed
 * @args: number to print
 * Return: number of characters printed.
 */
int _spec_di(va_list *args)
{
	int i;
	char s[13];
	char *stra;
	int stri = va_arg(*args, int);

	if (stri == INT_MIN)
	{
		i = print_min();
		return (i);
	}
	stra = _itoa(stri, s, 10);

	i = 0;
	while (stra[i] != '\0')
	{
		_putchar(stra[i]);
		i++;
	}
	return (i);
}
/**
 * _spec_c - returns a string with a character in it
 * @args: input character variable
 * Return: 1
 */
int _spec_c(va_list *args)
{
	_putchar(va_arg(*args, int));

return (1);
}

/**
 * _spec_s - takes input string and copies it to new pointer
 * @args: input string variable
 * Return: number of characters printed
 */
int _spec_s(va_list *args)
{
	char *ptr_str = va_arg(*args, char *);
	int x = 0;

	if (!ptr_str)
		ptr_str = "(null)";
	while (ptr_str[x] != '\0')
	{
		_putchar(ptr_str[x]);
		x++;
	}
return (x);
}
