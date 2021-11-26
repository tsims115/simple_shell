#include "main.h"
/**
 * main - This programs creates a simple shell
 * Return: 0 on success
 */
int main(void)
{
	size_t bufsize = 200000;
	char *str = malloc(bufsize * sizeof(char));
	char **argv;
	char s[100];
	size_t n;
	char *command = NULL;
	int length;

	if (str == NULL)
	{
		return (-1);
	}
	do {
		_printf("%s$ ", getcwd(s, 100));

		length = getline(&str, &bufsize, stdin);
		if (length == EOF)
		{
			_putchar('\n');
			free(str);
			exit(-1);
		}

		if (strcmp(str, "exit\n") == 0)
			free(str), exit(0);

		str[strlen(str) - 1] = '\0';
		argv = splitter(str);

		if (strcmp(argv[0], "cd") == 0)
			chdir(argv[1]);
		else
			run(argv);
	} while (length != -1);
	free(str);
	return (0);
}
