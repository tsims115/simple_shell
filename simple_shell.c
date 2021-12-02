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
	char *str = malloc(bufsize * sizeof(char)), *tmp = str;
	char **argv;
	path_list *HEAD = create_path_list();
	int length, count = 0, exit_status = 0;

	if (str == NULL)
		free(str), free_list(HEAD), exit(-1);
	do {
		if (isatty(STDIN_FILENO))
			_printf("$ ");
		length = getline(&str, &bufsize, stdin);
		count++;
		if (length == EOF)
		{
			if (isatty(STDIN_FILENO))
				_printf("\n");
			free(tmp), free_list(HEAD), exit(0);
		}
		if (_strcmp(str, "\n") == 0)
			continue;
		else
		{
			if (str[_strlen(str) - 1] == '\n')
				str[_strlen(str) - 1] = '\0';
			while (*str == ' ')
				str++;
			if (_strcmp(str, " ") == 0)
				continue;
			else
			{
				argv = splitter(str);
				if (_strcmp(argv[0], "exit") == 0)
					free(tmp), free(argv), free_list(HEAD), exit(exit_status);
				exit_status = runCommand(av, count, argv, HEAD);
			}
		}
		free(argv);
	} while (length != -1);
	return (0);
}
/**
 * runCommand - runs the command given in argv
 * @av: filename
 * @count: number of times commands have been entered
 * @argv: commands given
 * @HEAD: linked list for PATH
 * Return: exit_status
 */
int runCommand(char **av, int count, char **argv, path_list *HEAD)
{
	int exit_status;

	if (_strcmp(argv[0], "env") == 0)
		env();
	else
		if (HEAD != NULL)
			exit_status = run(av, count, argv, HEAD);
		else
			_printf("PATH not found\n");

	return (exit_status);
}
