#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>
#include <limits.h>
/**
 * struct function - structure to find the correct function for a specifier
 * @spec: The specifier in question
 * @funct: The function associated with the specifier
 */
typedef struct function
{
	char *spec;
	int (*funct)(va_list *);
} function_t;

int run(char **argv);
char **splitter(char fun[]);
int prompt();
int _putchar(char c);
int _printf(const char *format, ...);
int _spec_c(va_list *args);
int _spec_s(va_list *args);
int _spec_di(va_list *args);
int _spec_pct(va_list *args);
int _strcmp(char *s1, char *s2);
int _strccmp(char s1, char *s2);
int _strlen(char *s);
int (*_get_function(char s))(va_list *args);
void reverse(char str[], int length);
char *_itoa(int n, char *str, int base);


#endif
