#include "main.h"

int run_path(char **argv, int status, path_list *HEAD)
{
	struct stat st;
	pid_t pid;
	path_list *node = HEAD;
	char *tmp_path;
	int flag = 0;

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
	return (flag);
}
