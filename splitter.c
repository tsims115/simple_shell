#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char ** splitter(char fun[])
{
  char **holder;
  int i = 0; //
  long int length = strlen(fun);
  char *temp;

/*strtok must take an array of chars not a pointer*/
/* the length of original string is not enough double is*/
  holder = malloc(sizeof(char) * (length * 2));
  /*strtok has to be split to the same var so create temp*/
  temp = strtok(fun, " ");
  holder[i] = temp;
  while(temp != NULL)
  {
    i++;
    temp = strtok(NULL, " ");
    holder[i] = temp;
  }

  return(holder);
}
