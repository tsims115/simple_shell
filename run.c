#include "main.h"
/**
 * run - runs a command entered from the command line
 * @argv: a pointer to a pointer of the commands given from getline
 * Return: 0 on success
 */
int run(char **argv)
{
	struct stat st;
	pid_t pid;
	int status;

	if (stat(argv[0], &st) == 0)
	{
		pid = fork();

		if (pid != 0)
			wait(&status);

		if (pid == 0)
			execve(argv[0], argv, NULL);
	}
	else
	{
		_printf("%s: not found\n", argv[0]);
	}

	return (0);
}
