#include "monty.h"

/**
 * opcode_choice - selects the correct opcode to perform
 * @choice: opcode passed
 * Return: pointer to the function that executes the opcode
 */
void (*opcode_choice(char *choice))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct_pair[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"queue", queue},
		{"stack", stack},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"mul", mul},
		{"div", DIV},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	int i;
	for (i = 0; instruct_pair[i].opcode; i++)
	{
		if (strcmp(instruct_pair[i].opcode, choice) == 0)
			break;
	}

	return (instruct_pair[i].f);
}