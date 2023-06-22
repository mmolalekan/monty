#include "monty.h"

global_t global_var;

/**
 * free_global_var - frees the global variables
 *
 * Return: no return
 */
void free_global_var(void)
{
	free_dlistint(global_var.head);
	free(global_var.buffer);
	fclose(global_var.fd);
}

/**
 * start_global_var - initializes the global variables
 *
 * @fd: file descriptor
 * Return: no return
 */
void start_global_var(FILE *fd)
{
	global_var.lifo = 1;
	global_var.cont = 1;
	global_var.arg = NULL;
	global_var.head = NULL;
	global_var.fd = fd;
	global_var.buffer = NULL;
}

/**
 * check_input - checks if the file exists and if the file can
 * be opened
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: file struct
 */
FILE *check_input(int argc, char *argv[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fd;
	size_t size = 256;
	ssize_t nlines = 0;
	char *lines[2] = {NULL, NULL};

	fd = check_input(argc, argv);
	start_global_var(fd);
	nlines = getline(&global_var.buffer, &size, fd);
	while (nlines != -1)
	{
		lines[0] = strtok(global_var.buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcodes(lines[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", global_var.cont);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				free_global_var();
				exit(EXIT_FAILURE);
			}
			global_var.arg = strtok(NULL, " \t\n");
			f(&global_var.head, global_var.cont);
		}
		nlines = getline(&global_var.buffer, &size, fd);
		global_var.cont++;
	}

	free_global_var();

	return (0);
}