#include "monty.h"

/**
 * _swap - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void _swap(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, temp;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	temp = h->n;
	h->n = h->next->n;
	h->next->n = temp;
}


/**
  *_sub- sustration
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void _sub(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int result, nodes;

	temp = *head;
	for (nodes = 0; temp; nodes++)
		temp = temp->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	result = temp->next->n - temp->n;
	temp->next->n = result;
	*head = temp->next;
	free(temp);
}

/**
 * _stack - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void _stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 0;
}

/**
  *_rotr- rotates the stack to the bottom
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void _rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *cpy;

	cpy = *head;
	if (!*head || !(*head)->next)
	{
		return;
	}
	while (cpy->next)
	{
		cpy = cpy->next;
	}
	cpy->next = *head;
	cpy->prev->next = NULL;
	cpy->prev = NULL;
	(*head)->prev = cpy;
	(*head) = cpy;
}

/**
  *_rotl- rotates the stack to the top
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void _rotl(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *tmp = *head, *temp;

	if (!*head || !(*head)->next)
	{
		return;
	}
	temp = (*head)->next;
	temp->prev = NULL;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = temp;
}
