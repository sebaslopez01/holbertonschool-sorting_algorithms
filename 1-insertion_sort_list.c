#include "sort.h"


/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order unsing the insertion sort algorithm
 * @list: Doubly linked list to sort
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *next_node = NULL, *prev_node = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = *list;
	while (current != NULL)
	{
		if (current->next != NULL && current->n > current->next->n)
		{
			next_node = current->next;
			if (next_node->next != NULL)
				next_node->next->prev = current;
			current->next = current->next->next;
			if (current->prev != NULL)
				current->prev->next = next_node;
			next_node->next = current;
			next_node->prev = current->prev;
			current->prev = next_node;

			prev_node = current->prev;
			while (prev_node != NULL && prev_node->prev != NULL)
			{
				if (prev_node->n < prev_node->prev->n)
				{
					next_node = prev_node->prev;
					prev_node->next->prev = next_node;
					next_node->next = prev_node->next;
					prev_node->next = prev_node->prev;
					prev_node->prev = prev_node->prev->prev;
					if (next_node->prev != NULL)
						next_node->prev->next = prev_node;
					next_node->prev = prev_node;
				}
				else
					prev_node = prev_node->prev;
			}
		}
		else
			current = current->next;
	}
}
