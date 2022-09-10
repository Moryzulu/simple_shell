#include <stdio.h>
#include <stdlib.h>
/**
 * main - void
 *
 * Return: void
 */
int main(void)
{
	char *input;
	size_t *size;

	printf("#");
	input = (char *) malloc(size);
	getline(&input, &size, stdin);
	printf("%s", input);

	return (0);
}
