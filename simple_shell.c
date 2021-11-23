#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
char **splitter(char fun[]);
int main(void)
{
	size_t bufsize = 200000;
	pid_t pid;
	char *str = malloc(bufsize * sizeof(char));
	char **argv;
	size_t n;
	int status;
	char *command = NULL;
	struct stat st;

	if (str == NULL)
	{
		return (-1);
	}
	printf("#cisfun$ ");
	while (getline(&str, &bufsize, stdin) != -1)
	{
		if (strcmp(str, "exit\n") == 0)
			free(str), exit(0);

		str[strlen(str) - 1] = '\0';
		argv = splitter(str);

		if (stat(argv[0], &st) == 0)
		{
			pid = fork();
		}
		else
		{
			printf("%s: not found\n", argv[0]);
		}
		if (pid != 0)
			wait(&status);
		if (pid == 0)
		{
			execve(argv[0], argv, NULL);
		}
		printf("#cisfun$ ");
	}
	free(str);
	return (0);
}
