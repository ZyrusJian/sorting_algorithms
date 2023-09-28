#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: Pointer to the head of the doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *index, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		index = current->prev;
		while (index != NULL && index->n > current->n)
		{
			temp = current->next;
			if (temp != NULL)
				temp->prev = index;
			index->next = temp;
			current->next = index;
			current->prev = index->prev;
			if (index->prev != NULL)
				index->prev->next = current;
			index->prev = current;
			index = current->prev;
			if (index == NULL)
				*list = current;
			print_list(*list);
		}
		current = current->next;
	}
}
