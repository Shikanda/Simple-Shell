#include "main.h"

/**
*splitter - reallocs old pinter to a newer one
*@tok_str: string to br tokenized
*@delim: char * of delimiters
*
*Return: vector to be used in execve
 */
char **splitter(char *tok_str, char *delim)
{
	size_t count;
	char *token;
	char *tmp;
	char **tokens;

	count = 0;
	tmp = _strdup(tok_str);
	if (!tmp)
		return (NULL);
	token = strtok(tmp, delim);
	while (token)
	{
		count++;
		token = strtok(NULL, delim);
	}
	free(tmp);
	tokens = malloc(sizeof(char *) * (count + 1));

	if (!tokens)
		return (NULL);

	token = strtok(tok_str, delim);

	for (count = 0; token; count++)
	{
		tokens[count] = token;
		token = strtok(NULL, delim);
	}
	tokens[count] = NULL;
	return (tokens);
}
