#include "shell.h"

/**
 * exec_command - creates achild process
 * and executes it before the parent process.
 * @args: input command arguements.
 * Return: success.
 */

int exec_command(char **args)
{
	int status;
	pid_t my_pid;

	if (args[0] == NULL)
	{
		return (1);
	}

	if (strcmp(args[0], "exit") == 0)
	{
		/* free(args[0]); */
		free(args);
		exit(0);
	}

	my_pid = fork();

	if (my_pid == 0)
	{
		if ((execve(args[0], args, NULL) == -1))
		{
			perror("Error");
			exit(1);
		}
	}
	else if (my_pid == -1)
	{
		perror("Error");
		exit(1);
	}
	else
	{
		wait(&status);
	}

	return (1);
}
