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

	if (str == NULL)
	{
		return (-1);
	}
	_printf("%s$ ", getcwd(s, 100));
	while (getline(&str, &bufsize, stdin) != -1)
	{
		if (strcmp(str, "exit\n") == 0)
			free(str), exit(0);

		str[strlen(str) - 1] = '\0';
		argv = splitter(str);

		if (strcmp(argv[0], "cd") == 0)
			chdir(argv[1]);
		else
		{
			run(argv);
		}
		_printf("%s$ ", getcwd(s, 100));
	}
	free(str);
	return (0);
}
