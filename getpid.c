#include <stdio.h>
#include <unistd.h>
#include "main.h"

int main(void)
{
	pid_t parent_pid;

	parent_pid = getppid();

	printf("parent PID: %d\n", parent_pid);

	return (0);
}
