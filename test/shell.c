#include "shell.h"
/**
 * main - executes the whole program.
 * Return: sucess (0).
 *
 */

int main(void)
{
	char *prompt = "shell$ ";
	char *command;
	char **cmd;


	while (1)
	{
		write(1, prompt, 7);

		command = input_command();
		cmd = command_args(command);
		exec_command(cmd);

		free(command);
		free(cmd);
	}

	return (0);
}
