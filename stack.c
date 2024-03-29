#include "monty.h"

/**
 * print_stackt - prints all elements of a listint_t list
 * @h: pointer to head of list
 * Return: number of nodes
 */
size_t print_stackt(const stack_t *h)
{
    const stack_t *current;
    unsigned int n; /* number of nodes */

    current = h;
    n = 0;
    while (current != NULL)
    {
        printf("%i\n", current->n);
        current = current->next;
        n++;
    }

    return (n);
}

/**
 * add_nodeint - adds a new node at the end of a listint_t list
 * @head: pointer to pointer of first node of listint_t list
 * @n: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */
stack_t *add_nodeint(stack_t **head, int n)
{
    stack_t *new;
    stack_t *current;

    current = *head;

    new = malloc(sizeof(stack_t));
    if (new == NULL)
        return (NULL);

    new->n = n;
    new->next = NULL;

    if (*head == NULL)
        *head = new;
    else
    {
        while (current->next != NULL)
            current = current->next;
        current->next = new;
    }

    return (new);
}

/**
 * free_stack - frees a listint_t list
 * @head: pointer to list to be freed
 * Return: void
 */
void free_stack(stack_t *head)
{
    stack_t *current;

    while (head != NULL)
    {
        current = head;
        head = head->next;
        free(current);
    }
}

