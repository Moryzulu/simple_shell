#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/**
 * Main - handle prompt
 * @void: void function
 *
 * Return: Always 0.
 */

char *input;

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
	char *argv[] = {"/bin/ls", "-l", "-a", NULL};

	if (child_pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror(":not found");
		}
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
char **split_input(char *input)
{
	char **command = malloc(8 * sizeof(char *));
        char * separator = " ";
        int neutral = 0;
        char *parsed;
	
	parsed = strtok(input, separator);
	while (parsed != NULL)
        {
		command[neutral] = parsed;
		neutral++;

		parsed = strtok(NULL, separator);
        }
	command[neutral] = NULL;
	return (command);
}
