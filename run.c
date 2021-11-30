#include "main.h"
/**
 * run - runs a command entered from the command line
 * @argv: a pointer to a pointer of the commands given from getline
 * @HEAD: head of linked list
 * Return: 0 on success
 */
int run(char **argv, path_list *HEAD)
{
	struct stat st;
	pid_t pid;
	int status;
	char *tmp_path = NULL;
	int flag = 0;
	path_list *node = HEAD;
	int check = _strchr(argv[0], '/');

	if (stat(argv[0], &st) == 0 && st.st_mode & S_IXUSR && check == 1)
	{
		flag = 1;
		pid = fork();
		if (pid != 0)
			wait(&status);
		if (pid == 0)
			execve(argv[0], argv, NULL);
	}
	else
	{
		while (node != NULL)
		{
			tmp_path = _strdup(node->path);
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
				break;
			}
			free(tmp_path);
			node = node->next;
		}
	}
	if (flag == 0)
		printf("%s: not found\n", argv[0]);
	return (0);
}
