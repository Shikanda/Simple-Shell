#include "shell.h"

/**
 * input_command - gets the input from user.
 *
 * Return: command string.
 *
 */
char *input_command()
{
	char *command = NULL;
	size_t n = 0;

	getline(&command, &n, stdin);

	return (command);
}
