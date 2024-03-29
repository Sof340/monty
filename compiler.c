#include "monty.h"
#include <string.h>
/**
 * compiler - function that executes the commandes.
 * @elements: array containing our opcodes and inputs.
 * @num_lines: integer representing the number of lines in the array.
 * Return: nothing.
 */

void compiler(char ***elements, int num_lines)
{
	stack_t *stack;
	instruction_t instructions[2];
	int i, j;
	unsigned int n_line;

	instructions[0].opcode = "push";
	instructions[0].f = push;
	instructions[1].opcode = "pall";
	instructions[1].f = pall;

	n_line = 0;
	stack = NULL;
	for (i = 0 ; i < num_lines; i++)
	{
		n_line++;
		for (j = 0; j < 2; j++)
		{
			if (strcmp(instructions[j].opcode, elements[i][0]) == 0)
			{
				global = atoi(elements[i][1]);
				if (strcmp(instructions[j].opcode, "push") == 0)
				{
					push(&stack, n_line);
				} else if (strcmp(instructions[j].opcode, "pall") == 0)
				{
					pall(&stack, n_line);
				}
			}
		}
	}
}
