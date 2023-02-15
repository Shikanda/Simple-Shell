#include <stdio.h>
#include <unistd.h>
#include "main.h"

int main(int ac, char **av)
{
	char **arg =  av;

	while (*arg)
	{
		printf("%s\n", *arg++);
	}
	return (0);
}
