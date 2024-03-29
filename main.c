#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

int global;

int main(int argc, char *argv[])
{
	FILE *fp;
	char *filename;
	char line[100];
	char ***elements;
	int num_lines = 0;
	int i, j, k, max_length;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	filename = argv[1];
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	num_lines = number_lines(fp, &max_length);
	rewind(fp);
	elements = (char ***)malloc(num_lines * sizeof(char **));
	if (elements == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	
	for (i = 0; i < num_lines; i++)
	{
		elements[i] = (char **)malloc(2 * sizeof(char *));
		for (j = 0; j < 2; j++)
		{
			elements[i][j] = (char *)malloc((max_length + 1) * sizeof(char));
			if (elements[i][j] == NULL)
			{
				fprintf(stderr, "Memory allocation failed\n");
				exit(EXIT_FAILURE);
			}
		}
		fgets(line, sizeof(line), fp);
		if (line[0] != '\n')
		{
			for (j = 0, k = 0; line[j] != '$'; j++)
			{
				if (line[j] != ' ')
				{
					elements[i][0][k++] = line[j];
				} else break;
			}
			elements[i][0][k] = '\0';
			for (j++, k = 0; line[j] != '\0' && line[j] != '$'; j++)
			{
				if (line[j] != ' ')
				{
					elements[i][1][k++] = line[j];
				}
			}
			elements[i][1][k] = '\0';
		}
	}
	compiler(elements, num_lines);
	free_array(fp, elements, num_lines);
	return (0);
}

