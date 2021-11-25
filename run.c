#include "main.h"
int run(char **argv)
{
	struct stat st;
	pid_t pid;
	int status;

	if (stat(argv[0], &st) == 0)
	{
		pid = fork();
	}
	else
	{
		_printf("%s: not found\n", argv[0]);
	}
	if (pid != 0)
		wait(&status);
	if (pid == 0)
	{
		execve(argv[0], argv, NULL);
	}

	return (0);
}
