#include <stdlib.h>
#include "monty.h"

/**
 * number_lines - function that counts the number of lines in a file.
 * @fp: pointer to the file.
 * @max_length: integer representing length of the biggest word in the file.
 * Return: number of lines.
 */

int number_lines(FILE *fp, int *max_length)
{
	int length_element, num_lines, j;
	char line[100];

	num_lines = 0;
	while (fgets(line, sizeof(line), fp) != NULL)
	{
		if (line[0] != '\n')
		{
			num_lines++;
			length_element = 0;
			for (j = 0; line[j] != '$'; j++)
			{
				if (line[j] != ' ')
				{
					length_element++;
				}
			}
			if (length_element > *max_length)
			{
				*max_length = length_element;
			}
		}
	}
	return (num_lines);
}

/**
 * free_array - function that frees the array where the lines of the file are.
 * @fp: pointer to the file.
 * @elements: pointer to the pointer to the pointer of the array.
 * @num_lines: integer representing the number of lines in the file.
 * Return: nothing.
 */
void free_array(FILE *fp, char ***elements, int num_lines)
{
	int i, j;

	for (i = 0; i < num_lines; i++)
	{
		for (j = 0; j < 2; j++)
		{
			free(elements[i][j]);
		}
		free(elements[i]);
	}
	free(elements);
	fclose(fp);
}

