#include "shell.h"
/**
 * command_args - handles the flags(command args).
 * @command: input commands.
 *
 * Return: command strings.
 *
 */
char **command_args(char *command)
{
	char **args = malloc(sizeof(char *) * 64);
	char *stkn;
	int i = 0;

	stkn = strtok(command, " \n");

	while (stkn)
	{
		args[i] = stkn;
		i++;
		stkn = strtok(NULL, " \n");
	}
	args[i] = NULL;

	return (args);
}
