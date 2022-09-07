#include "sort.h"


/**
 * change_prev_node - Swaps the position of the current node,
 * with the previous
 * @prev_node: Pointer to the previous node
 *
 * Return: void
 */
void change_prev_node(listint_t *prev_node)
{
	listint_t *next_node = NULL;

	next_node = prev_node->prev;
	prev_node->next->prev = next_node;
	next_node->next = prev_node->next;
	prev_node->next = prev_node->prev;
	prev_node->prev = prev_node->prev->prev;

	if (next_node->prev != NULL)
		next_node->prev->next = prev_node;

	next_node->prev = prev_node;
}


/**
 * get_first_node - Gets a reference to the first node of
 * doubly linked list
 * @list: Doubly linked list
 *
 * Return: A pointer to the first node
 */
listint_t *get_first_node(listint_t **list)
{
	listint_t *current = *list;

	while (current->prev != NULL)
		current = current->prev;

	return (current);
}


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
			print_list(get_first_node(&current));
			prev_node = current->prev;
			while (prev_node != NULL && prev_node->prev != NULL)
			{
				if (prev_node->n < prev_node->prev->n)
				{
					change_prev_node(prev_node);
					print_list(get_first_node(&current));
				}
				else
					prev_node = prev_node->prev;
			}
		}
		else
			current = current->next;
	}
	*list = get_first_node(list);
}
