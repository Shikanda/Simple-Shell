#include "shell.h"

extern char **environ;
int _len(char *s);
#define MAX_COMMAND_LENGTH 256
#define MAX_ARGS 16

/**
*main - entry point for shell
*
*Return: Always 0
*/
int main(void)
{
	char prompt[] = "shell$ ";
	char command[MAX_COMMAND_LENGTH];
	char *args[MAX_ARGS + 1];
	ssize_t n;
	char *token;
	pid_t pid;
	int i;
	int status;

	while (1)
	{
		write(STDIN_FILENO, prompt, _len(prompt));

		n = read(STDIN_FILENO, command, MAX_COMMAND_LENGTH);
		if (n == -1)
		{
			perror("read");
		}
		else if (n == 0)
		{
			write(1, "\n", 1);
		}
		if (command[n - 1] == '\n')
		{
			command[n - 1] = '\0';
		}
		i = 0;
		token = strtok(command, " ");
		while (token != NULL && i < MAX_ARGS)
		{
			args[i] = token;
			token = strtok(NULL, " ");
			i++;
		}
		args[i] =  NULL;

		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			execve(args[0], args, environ);
			perror("shell");
			exit(EXIT_FAILURE);
		}
		else
		{
			if (wait(&status) == -1)
			{
				perror("wait");
				exit(EXIT_FAILURE);
			}
		}
	}
	return (0);
}
/**
*_len - gets length of string
*@s: string
*
*Return: length
*/

int _len(char *s)
{
	int length;

	length = 0;
	while (*s++)
	{
		length++;
	}
	return (length);
}
