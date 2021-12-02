#include "main.h"
/**
 * run - runs a command entered from the command line
 * @av: av input from main, used for program name
 * @count: how many errors have been caught
 * @argv: a pointer to a pointer of the commands given from getline
 * @HEAD: head of linked list
 * Return: 0 on success
 */
int run(char **av, int count, char **argv, path_list *HEAD)
{
	struct stat st;
	pid_t pid;
	int status, exit_status, check = _strchr(argv[0], '/');

	if (stat(argv[0], &st) == 0 && st.st_mode & S_IXUSR && check == 1)
	{
		pid = fork();
		if (pid == -1)
			perror("Fork failed\n");
		pid == 0 ? execve(argv[0], argv, NULL) : wait(&status);
		(WIFEXITED(status)) ? (exit_status = WEXITSTATUS(status)) :
		(exit_status = 127);
	}
		else
			exit_status = run_path(av, count, argv, HEAD);

	return (exit_status);
}
