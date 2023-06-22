#include "monty.h"

/**
 *add_dnodeint_end - add a node at the end of the doubly link list
 *@head: entry point
 *@n: data to store
 *Return: a doubly linked list
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *newNode, *temp;

	if (head == NULL)
		return (NULL);
	newNode = malloc(sizeof(stack_t));
	if (!newNode)
	{
		dprintf(2, "Error: malloc failed\n");
		free_global_var();
		exit(EXIT_FAILURE);
	}
	newNode->n = n;

	if (*head == NULL)
	{
		newNode->next = *head;
		newNode->prev = NULL;
		*head = newNode;
		return (*head);
	}
	temp = *head;
	while (temp->next)
		temp = temp->next;
	newNode->next = temp->next;
	newNode->prev = temp;
	temp->next = newNode;
	return (temp->next);
}

/**
 *add_dnodeint - add a node at the begining of the doubly link list
 *@head: entry point
 *@n: data to store
 *Return: a doubly linked list
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *newNode;

	if (head == NULL)
		return (NULL);
	newNode = malloc(sizeof(stack_t));
	if (!newNode)
	{
		dprintf(2, "Error: malloc failed\n");
		free_global_var();
		exit(EXIT_FAILURE);
	}
	newNode->n = n;

	if (*head == NULL)
	{
		newNode->next = *head;
		newNode->prev = NULL;
		*head = newNode;
		return (*head);
	}
	(*head)->prev = newNode;
	newNode->next = (*head);
	newNode->prev = NULL;
	*head = newNode;
	return (*head);
}

/**
 * free_dlistint - frees the doubly linked list
 *
 * @head: head of the list
 * Return: no return
 */
void free_dlistint(stack_t *head)
{
	stack_t *temp;

	while ((temp = head) != NULL)
	{
		head = head->next;
		free(temp);
	}
}
