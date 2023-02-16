#include "main.h"

int main(int argc, char **argv)
{
	char *command = NULL;
	size_t n = 0;
	char *s_token;
	pid_t my_pid;
	int status;

	while(1)
	{
		printf("(shell)$ ");
		getline(&command, &n, stdin);
		s_token = strtok(command, "\n");

		char *arr[] = {s_token, NULL};

		my_pid = fork();
		
		if (my_pid == -1)
		{
			perror("Error");
		}
		else if(my_pid == 0)
		{
			execve(arr[0], arr, NULL);
		}
		else
		{
			wait(&status);
		}
	}
	free(command);

	return (0);
}
