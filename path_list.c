#include "main.h"

path_list *create_path_list()
{
	path_list *HEAD = NULL;
	path_list *new_node;
	path_list *last;
	char *path;
	int i = 0;

	while (environ[i])
	{
		if (strcmp(strtok(environ[i], "="), "PATH") == 0)
		{
			while ((path = strtok(NULL, ":")))
			{
				new_node = malloc(sizeof(path_list));
				new_node->path = strdup(path);
				new_node->next = NULL;
				if (HEAD == NULL)
				{
					HEAD = new_node;
					new_node = NULL;
					continue;
				}
				last = HEAD;
				while (last->next != NULL)
					last = last->next;
				last->next = new_node;
				new_node = NULL;
			}
		}
		i++;
	}
	return (HEAD);
}

/**
 * free_list - frees the path list linked list
 * @HEAD: head of linked list to free
 */

void free_list(path_list *HEAD)
{
	path_list *node;

	while (HEAD)
	{
		node = HEAD->next;
		free(HEAD->path);
		free(HEAD);
		HEAD = node;
	}
}
