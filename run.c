#include "main.h"
/**
 * run - runs a command entered from the command line
 * @av: av input from main, used for program name
 * @errcount: how many errors have been caught
 * @argv: a pointer to a pointer of the commands given from getline
 * @HEAD: head of linked list
 * Return: 0 on success
 */
int run(char **av, int errcount, char **argv, path_list *HEAD)
{
	struct stat st;
	pid_t pid;
	int status, flag = 0, check = _strchr(argv[0], '/');
	char *tmp_path = NULL;
	path_list *node = HEAD;

	if (stat(argv[0], &st) == 0 && st.st_mode & S_IXUSR && check == 1)
	{
		flag = 1;
		pid = fork();
		if (pid == -1)
			perror("Fork failed\n");
		pid == 0 ? execve(argv[0], argv, NULL) : wait(&status);
	}
	else
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
				if (pid != 0)
					wait(&status);
				if (pid == 0)
					execve(argv[0], argv, environ);
				free(tmp_path);
				break;
			}
			free(tmp_path);
			node = node->next;
		}
	if (flag == 0)
		errcount++,	printf("%s: %d: %s: not found\n", av[0], errcount, argv[0]);
	return (errcount);
}
