#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct usb_s - variables -args, file, line file_content
 * @arg: value
 * @file: pointer to monty file
 * @file_content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct usb_s
{
	char *arg;
	FILE *file;
	char *file_content;
	int lifi;
}  usb_t;

extern usb_t bus;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t get_stdin(char **lineptr, int file);
char  *clean_content(char *content);
void push(stack_t **head, unsigned int number);
void pall(stack_t **head, unsigned int number);
void pint(stack_t **head, unsigned int number);
int exec(char *content, stack_t **head, unsigned int counter, FILE *file);
void free_stack(stack_t *head);
void pop(stack_t **head, unsigned int counter);
void swap(stack_t **head, unsigned int counter);
void add(stack_t **head, unsigned int counter);
void nop(stack_t **head, unsigned int counter);
void sub(stack_t **head, unsigned int counter);
void div(stack_t **head, unsigned int counter);
void mul(stack_t **head, unsigned int counter);
void mod(stack_t **head, unsigned int counter);
void pchar(stack_t **head, unsigned int counter);
void pstr(stack_t **head, unsigned int counter);
void rotl(stack_t **head, unsigned int counter);
void rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
void add_node(stack_t **head, int n);
void add_queue(stack_t **head, int n);
void queue(stack_t **head, unsigned int counter);
void stack(stack_t **head, unsigned int counter);

#endif
