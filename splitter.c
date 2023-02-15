#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int **split_string(char *string)
{
	char *line;
	int i;
	char *word[];
	int j;
	char **result;

	i = 0;

	word = strtok(string, " ");
	while (word != NULL)
	{
		word[i] = word;
		i++;
		word = strtok(NULL, " ");
	}

	result = malloc(i * sizeof(char*));

	for (j = 0; j < 1; j++)
	{
		result[j] = word[j];
	}
	free(result);

	return (result);
}
