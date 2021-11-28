#include "main.h"
/**
 * run - runs a command entered from the command line
 * @argv: a pointer to a pointer of the commands given from getline
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

	while (node != NULL)
	{
		tmp_path = strdup(node->path);
		strcat(tmp_path, "/");
		strcat(tmp_path, argv[0]);
		if (stat(tmp_path, &st) == 0)
		{
			flag = 1;
			argv[0] = tmp_path;
			pid = fork();

			if (pid != 0)
				wait(&status);

			if (pid == 0)
				execve(argv[0], argv, NULL);
			break;
		}
		free(tmp_path);
		node = node->next;
	}
	if (flag == 0)
		printf("%s: not found\n", argv[0]);

	return (0);
}
