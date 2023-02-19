#include "main.h"
/**
 * main - main function covering simple shell
 * functionalities.
 * Return: success (0)
 */

int main()
{
	char *prompt = "sh $ ";
	char *command = NULL;
	size_t n = 0;
	char *s_token;
	pid_t my_pid;
	int status, i;

	while(1)
	{
		/*prints the command prompt, will require to use the write funtion*/
		write(1, prompt, 5);
		getline(&command, &n, stdin);
		s_token = strtok(command, " \n");

		char **arr = malloc(sizeof(char *) * 32);
		arr[0] = s_token;
		
		/*This is handles exit from the shell*/
		if (strcmp(arr[0], "exit") == 0)
			exit (0);

	/* This loop handles command line arg*/
		i = 1;
		while(s_token != NULL)
		{
			s_token = strtok(NULL, " \n");
			arr[i] = s_token;
			i++;
		}


		/*the fork function creates child process*/
		my_pid = fork();

		if (my_pid == -1)
		{
			perror("Error");
		}
		else if(my_pid == 0)
		{
			if (execve(arr[0], arr, NULL))
			{
				/* This code handles errors*/
				perror("./shell");
				return (1);
			}
		}
		else
		{
			wait(&status);
		}
	}
	free(command);

	return (0);
}
