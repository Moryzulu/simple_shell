#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * Main - handle prompt
 * @void: void function
 *
 * Return: Always 0.
 */
int main(void)
{
	char *input;
	size_t size;

	while (input != NULL)
	{

		printf("#ciscool& ");
		input = (char *) malloc(size);
		getline(&input, &size, stdin);

		printf("%s", input);
	}
	return (0);
}
/**
 * my_fwe - fork, wait and execve example
 * @void: void function
 *
 * Return: Always 0.
 */
int my_fwe(void)
{
	pid_t child_pid = fork();
	char *args[20];

	if (child_pid == 0)
	{
		execvp(args[0], args);
		perror(":not found");
		exit(1);
	}
	else if (child_pid > 0)
	{
		int status;
	do {
		waitpid(child_pid, &status, WUNTRACED);
	} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	else
	{
		perror(":not found");
	}
	return (0);

}

