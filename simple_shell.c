#include "main.h"
/**
 * env - prints current environment
 */
void env(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
		_printf("%s\n", environ[i]);
}
/**
 * main - This programs creates a simple shell
 * @ac: ac
 * @av: av
 * Return: 0 on success
 */
int main(int ac __attribute__((unused)), char **av)
{
	size_t bufsize = 2097152;
	char *str = malloc(bufsize * sizeof(char));
	char **argv;
	path_list *HEAD = create_path_list();
	int length, errcount = 0;

	if (str == NULL)
		free(str), free_list(HEAD), exit(-1);
	do {
		if (isatty(STDIN_FILENO))
			_printf("$ ");
		length = getline(&str, &bufsize, stdin);
		if (length == EOF)
		{
			if (!(isatty(STDIN_FILENO)))
				_printf("$");
			printf("\n");
			free(str);
			free_list(HEAD);
			exit(0);
			if (argv != NULL)
				free(argv);
		}
		if (str[_strlen(str) - 1] == '\n')
			str[_strlen(str) - 1] = '\0';
		argv = splitter(str);
		if (_strcmp(argv[0], "exit") == 0)
			free(str), free(argv), free_list(HEAD), exit(0);
		if (_strcmp(argv[0], "env") == 0)
			env();
		else
			if (HEAD != NULL)
				errcount = run(av, errcount, argv, HEAD);
			else
				printf("PATH not found\n");
		free(argv);
	} while (length != -1);
	return (0);
}
