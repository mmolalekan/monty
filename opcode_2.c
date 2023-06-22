#include "monty.h"

/**
 * queue - sets the format of the data to a queue (FIFO)
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void queue(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	global_var.lifo = 0;
}

/**
 * stack - sets the format fo the data to a stack (LIFO)
 *
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void stack(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	global_var.lifo = 1;
}

/**
 * add - adds the top two elements of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void add(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *temp = NULL;

	temp = *doubly;

	for (; temp != NULL; temp = temp->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", cline);
		free_global_var();
		exit(EXIT_FAILURE);
	}

	temp = (*doubly)->next;
	temp->n += (*doubly)->n;
	pop(doubly, cline);
}

/**
 * nop - doesn't do anythinhg
 *
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void nop(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;
}

/**
 * sub - subtracts the top element to the second top element of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void sub(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *temp = NULL;

	temp = *doubly;

	for (; temp != NULL; temp = temp->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", cline);
		free_global_var();
		exit(EXIT_FAILURE);
	}

	temp = (*doubly)->next;
	temp->n -= (*doubly)->n;
	pop(doubly, cline);
}
