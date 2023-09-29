#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 *
 * @list: Pointer to the head of the list
 * @node1: Pointer to the first node to swap
 * @node2: Pointer to the second node to swap
 *
 * Return: void
 */

void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next)
		node2->next->prev = node1;
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Cocktail Shaker sort algorithm.
 *
 * @list: Pointer to the head of the list
 *
 * Return: void
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *start = *list, *end = NULL;
	int swapped = 0;

	if (!list || !*list || !(*list)->next)
		return;

	while (swapped || end == NULL)
	{
		swapped = 0;
		while (start->next != end)
		{
			if (start->n > start->next->n)
			{
				swap_nodes(list, start, start->next);
				print_list(*list);
				swapped = 1;
			}
			else
				start = start->next;
		}
		end = start;
		while (end->prev != NULL)
		{
			if (end->n < end->prev->n)
			{
				swap_nodes(list, end->prev, end);
				print_list(*list);
				swapped = 1;
			}
			else
				end = end->prev;
		}
	}
}
