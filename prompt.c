#include "main.h"
int prompt()
{
	char *buffer;
	size_t bufsize;
	ssize_t x;

	buffer = (char *)malloc(bufsize * sizeof(char));
	do {
		printf("#cisfun$ ");
		x = getline(&buffer, &bufsize, stdin);
		if (x == EOF)
		{
			putchar('\n');
			break;
		}
		if (strcmp(buffer, "exit\n") == 0)
			break;
		if (strcmp(buffer, "placeholder\n") == 0)
			printf("No such file or directory\n");
	}	while (x != -1);

	free(buffer);

	return (0);
}
