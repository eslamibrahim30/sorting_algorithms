#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap_cons_nodes - Swap two given nodes in a doubly linked list.
 *
 * @ptr1: the first node.
 * @ptr2: the second node.
 * @head: the head of the linked list.
 */
void swap_cons_nodes(listint_t **head, listint_t *ptr1, listint_t *ptr2)
{
	if (ptr2->next != NULL)
		ptr2->next->prev = ptr1;
	ptr1->next = ptr2->next;
	ptr2->next = ptr1;
	if (ptr1->prev != NULL)
		ptr1->prev->next = ptr2;
	else
		*head = ptr2;
	ptr2->prev = ptr1->prev;
	ptr1->prev = ptr2;
}

/**
 * insertion_sort_list - Sorts a list of integers in ascending
 * order using the insertion sort alogrithm.
 *
 * @list: The given list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *ptr1 = NULL;
	listint_t *ptr2 = NULL;

	if (list == NULL || *list == NULL)
		return;
	ptr1 = *list;
	if (ptr1->next == NULL)
		return;
	ptr2 = ptr1->next;
	while (ptr2 != NULL)
	{
		ptr1 = ptr2;
		while (ptr1->prev != NULL && ptr1->prev->n > ptr1->n)
		{
			swap_cons_nodes(list, ptr1->prev, ptr1);
			print_list(*list);
		}
		ptr2 = ptr2->next;
	}
}
