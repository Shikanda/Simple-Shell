#include "main.h"

int main(int argc, char **argv)
{
	char *command = NULL;
	size_t n = 0;
	char *s_token;
	pid_t my_pid;
	int status, i = 0;

	while(1)
	{
		printf("(shell)$ ");
		getline(&command, &n, stdin);
		s_token = strtok(command, " \n");

		char **arr = malloc(sizeof(char *) * 32);
		arr[0] = s_token;


		while(s_token != NULL)
		{
			s_token = strtok(NULL, " \n");
			arr[i] = s_token;
			i++;
		}


		my_pid = fork();
		
		if (my_pid == -1)
		{
			perror("Error");
		}
		else if(my_pid == 0)
		{
			if (execve(arr[0], arr, NULL))
			{
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
