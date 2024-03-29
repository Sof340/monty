#include "monty.h"

int global;

void push(stack_t **stack, unsigned int line_number)
{
	if (global == 0 || sizeof(global) != sizeof(int))
	{
		printf("L%d: usage: push",line_number);
		exit(EXIT_FAILURE);
	}
	add_nodeint(stack, global);
}

void pall(stack_t **stack, unsigned int line_number)
{
	if (global != 0)
        {
                printf("L%d: usage: pall",line_number);
                exit(EXIT_FAILURE);
        }
	print_stackt(*stack);
}

