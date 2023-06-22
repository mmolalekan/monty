#include "monty.h"

/**
 * rotl - rotates the first element to the bottom and  the second to the top
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void rotl(stack_t **doubly, unsigned int cline)
{
	stack_t *temp1 = NULL;
	stack_t *temp2 = NULL;
	(void)cline;

	if (*doubly == NULL)
		return;

	if ((*doubly)->next == NULL)
		return;

	temp1 = (*doubly)->next;
	temp2 = *doubly;

	for (; temp2->next != NULL; temp2 = temp2->next)
		;

	temp1->prev = NULL;
	temp2->next = *doubly;
	(*doubly)->next = NULL;
	(*doubly)->prev = temp2;
	*doubly = temp1;
}

/**
 * rotr - reverse the stack
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */
void rotr(stack_t **doubly, unsigned int cline)
{
	stack_t *temp = NULL;
	(void)cline;

	if (*doubly == NULL)
		return;

	if ((*doubly)->next == NULL)
		return;

	temp = *doubly;

	for (; temp->next != NULL; temp = temp->next)
		;

	temp->prev->next = NULL;
	temp->next = *doubly;
	temp->prev = NULL;
	(*doubly)->prev = temp;
	*doubly = temp;
}
