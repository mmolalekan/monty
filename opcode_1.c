#include "monty.h"

/**
 * push - pushes an element to the stack
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */
void push(stack_t **doubly, unsigned int cline)
{
	int n, j;

	if (!global_var.arg)
	{
		dprintf(2, "L%u: ", cline);
		dprintf(2, "usage: push integer\n");
		free_global_var();
		exit(EXIT_FAILURE);
	}

	for (j = 0; global_var.arg[j] != '\0'; j++)
	{
		if (!isdigit(global_var.arg[j]) && global_var.arg[j] != '-')
		{
			dprintf(2, "L%u: ", cline);
			dprintf(2, "usage: push integer\n");
			free_global_var();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(global_var.arg);

	if (global_var.lifo == 1)
		add_dnodeint(doubly, n);
	else
		add_dnodeint_end(doubly, n);
}

/**
 * pall - prints all values on the stack
 * @doubly: head of the linked list
 * @cline: line numbers
 * Return: no return
 */
void pall(stack_t **doubly, unsigned int cline)
{
	stack_t *temp;
	(void)cline;

	temp = *doubly;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - prints the value at the top of the stack
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */
void pint(stack_t **doubly, unsigned int cline)
{
	(void)cline;

	if (*doubly == NULL)
	{
		dprintf(2, "L%u: ", cline);
		dprintf(2, "can't pint, stack empty\n");
		free_global_var();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*doubly)->n);
}

/**
 * pop - removes the top element of the stack
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */
void pop(stack_t **doubly, unsigned int cline)
{
	stack_t *temp;

	if (doubly == NULL || *doubly == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", cline);
		free_global_var();
		exit(EXIT_FAILURE);
	}
	temp = *doubly;
	*doubly = (*doubly)->next;
	free(temp);
}

/**
 * swap - swaps the top two elements of the stack
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */
void swap(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *temp = NULL;

	temp = *doubly;

	for (; temp != NULL; temp = temp->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", cline);
		free_global_var();
		exit(EXIT_FAILURE);
	}

	temp = *doubly;
	*doubly = (*doubly)->next;
	temp->next = (*doubly)->next;
	temp->prev = *doubly;
	(*doubly)->next = temp;
	(*doubly)->prev = NULL;
}
