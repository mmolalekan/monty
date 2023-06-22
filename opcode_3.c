#include "monty.h"

/**
 * DIV - divides the second element by the top element of the stack
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void DIV(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *temp = NULL;

	temp = *doubly;

	for (; temp != NULL; temp = temp->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", cline);
		free_global_var();
		exit(EXIT_FAILURE);
	}

	if ((*doubly)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", cline);
		free_global_var();
		exit(EXIT_FAILURE);
	}

	temp = (*doubly)->next;
	temp->n /= (*doubly)->n;
	pop(doubly, cline);
}

/**
 * mul - multiplies the top element to the second top element of the stack
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void mul(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *temp = NULL;

	temp = *doubly;

	for (; temp != NULL; temp = temp->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", cline);
		free_global_var();
		exit(EXIT_FAILURE);
	}

	temp = (*doubly)->next;
	temp->n *= (*doubly)->n;
	pop(doubly, cline);
}

/**
 * mod - computes the rest of the division of the second element
 * by the top element of the stack
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void mod(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *temp = NULL;

	temp = *doubly;

	for (; temp != NULL; temp = temp->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", cline);
		free_global_var();
		exit(EXIT_FAILURE);
	}

	if ((*doubly)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", cline);
		free_global_var();
		exit(EXIT_FAILURE);
	}

	temp = (*doubly)->next;
	temp->n %= (*doubly)->n;
	pop(doubly, cline);
}

/**
 * pchar - print the char value of the first element
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void pchar(stack_t **doubly, unsigned int cline)
{
	if (doubly == NULL || *doubly == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", cline);
		free_global_var();
		exit(EXIT_FAILURE);
	}
	if ((*doubly)->n < 0 || (*doubly)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", cline);
		free_global_var();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*doubly)->n);
}

/**
 * pstr - prints the string of the stack
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void pstr(stack_t **doubly, unsigned int cline)
{
	stack_t *temp;
	(void)cline;

	temp = *doubly;

	while (temp && temp->n > 0 && temp->n < 128)
	{
		printf("%c", temp->n);
		temp = temp->next;
	}

	printf("\n");
}