#include "main.h"
/**
 * run_path - if no slash is found in argv[0], this function looks for it
 * @av: name of file
 * @count: number of commands run
 * @argv: commands passed
 * @HEAD: linked list for PATH
 * Return: the exit_status
 */
int run_path(char **av, int count, char **argv, path_list *HEAD)
{
	struct stat st;
	pid_t pid;
	path_list *node = HEAD;
	int flag = 0, exit_status = 0, status;
	char *tmp_path = NULL;

	while (node != NULL)
	{
		tmp_path = malloc(_strlen(node->path) + _strlen(argv[0]) + 2);
		_strcpy(tmp_path, node->path);
		_strcat(tmp_path, "/");
		_strcat(tmp_path, argv[0]);
		if ((stat(tmp_path, &st) == 0) && (st.st_mode & S_IXUSR))
		{
			flag = 1;
			argv[0] = tmp_path;
			pid = fork();
			pid == 0 ? execve(argv[0], argv, environ) : wait(&status);
			free(tmp_path);
			break;
		}
		free(tmp_path);
		node = node->next;
	}

	if (WIFEXITED(status))
		exit_status = WEXITSTATUS(status);

	if (flag == 0)
		exit_status = 127, printf("%s: %d: %s: not found\n", av[0], count, argv[0]);

	return (exit_status);
}
