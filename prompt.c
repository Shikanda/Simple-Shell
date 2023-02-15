#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(void)/*reads the line and prints $ sign*/
{
	char *line;
	size_t length;

	length = 0;
	line = malloc(sizeof(char) * length);

	printf("$ ");
	getline(&line, &length, stdin);
	printf("%s", line);

	free(line);

	return (0);
}
