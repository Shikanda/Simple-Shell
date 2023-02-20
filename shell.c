#include "shell.h"
/**
 * main - executes the whole program.
 * @argc: arg count.
 * @argv: arg vector.
 * Return: sucess (0).
 *
 */

int main(int argc, char **argv)
{
	char *prompt = "shell$ ";
	char *command, **cmd;

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
