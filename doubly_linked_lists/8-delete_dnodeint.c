#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - deletes the node at a given index
 * @head: pointer to the head of the list
 * @index: index of the node to delete (starting from 0)
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	temp = *head;

	/* Delete head node */
	if (index == 0)
	{
		*head = temp->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(temp);
		return (1);
	}

	while (temp != NULL)
	{
		if (i == index)
		{
			if (temp->next != NULL)
				temp->next->prev = temp->prev;

			if (temp->prev != NULL)
				temp->prev->next = temp->next;

			free(temp);
			return (1);
		}
		i++;
		temp = temp->next;
	}

	return (-1);
}
