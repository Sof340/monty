#include "monty.h"



/**
 * push - function used to push data into the stack.
 * @stack: pointer to the pointer of the stack.
 * @line_number: unsigned integer ,the number of the line we are at.
 */

void push(stack_t **stack, unsigned int line_number)
{
	if (global == 0 || sizeof(global) != sizeof(int))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	add_nodeint(stack, global);
}

/**
 * pall - function used to print all there is in the stack top to bottom.
 * @stack: pointer to the pointer of the stack.
 * @line_number: unsigned integer ,the number of the line we are at.
 */

void pall(stack_t **stack, unsigned int line_number)
{
	if (global != 0)
	{
		fprintf(stderr, "L%d: usage: pall\n", line_number);
		exit(EXIT_FAILURE);
	}
	print_stackt(*stack);
}

