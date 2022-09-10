#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
/**
 * main - void
 *
 * Return: void 
 */ 
int main()
{
	while (1)
	{
		printf("->");
		char *input = read_cmd ();
		char **commands = seperator_cmd (input);

		if (commands[0] != NULL)
		{
			execute_cmd (commands);
		}

		printf("\n%s", input);

		free (input);
		free (commands);
	}
}
/**
 * read_cmd - void
 *
 * Return: input
 */ 
char* read_cmd()
{
	char *input = NULL;
	size_t size = 0;

	getline (&input, &size, stdin);
	return (input);

}
/**
 * seperator_cmd - function to read input command
 * @input - function argument
 *
 * Return - commands
 */ 
char** seperator_cmd(char *input)
{
	int len = 0, maximum = 20;
	char **commands = malloc(maximum *sizeof(char*));
	char *seperator = "\n";
	char *cmd = strtok(input, seperator);
	
	while (cmd != NULL)
	{
		commands[len] = cmd;
		len++;
		
		if (len >= maximum)
		{
			maximum = (int) (maximum * 1.5);
			commands = realloc(commands, maximum * sizeof(char*));
		}
		cmd = strtok(NULL, seperator);	
	}
	commands[len] = NULL;
	return commands;
}
/**
 * execute_cmd - function to execute the commands
 * @arg - function arguments
 *
 * Return - void
 */
int execute_cmd(char **arg)
{
	pid_t baby = fork(); 

	if (baby ==0)
	{
		execve(arg[0], arg, NULL);
		perror("wrong arguments!");
		exit (1);
	}
	else if (baby > 0)
	{
		int status;

		do {
			waitpid (baby, &status, WUNTRACED);
		} 
		while (!WIFEXITED(status) && ! WIFSIGNALED(status));       	
	}
	else 
	{
		perror(":not found");
	}
	return (0);
}
