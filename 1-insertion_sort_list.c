#include "sort.h"
/**
 * insertion_sort_list - sorts a linked list by insertion sort algorithm
 * @list: Pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *p1 = NULL;
	listint_t *p2 = NULL;
	listint_t *temp = NULL;

	if (!list || !(*list))
		return;


	for (p1 = *(list), p2 = (*list)->next; p2 != NULL;
		 p1 = p1->next, p2 = p2->next)
	{
		if (p1->n > p2->n)
		{
			swap(list, &p1, &p2);
			for (p1 = p1->prev, temp = p1->prev; (p1->prev) != NULL; temp = p1->prev)
			{
				if (p1->n < temp->n)
					swap(list, &temp, &p1);

				else
					break;
			}
			if (p2->prev)
				p1 = p2->prev;
			else
				p2 = p2->next;
		}
	}
}
/**
 * swap - swaps two node then print the result
 * @list: Pointer to the head of the list
 * @p1: First node to swap
 * @p2: second node to swap
 */
void swap(listint_t **list, listint_t **p1, listint_t **p2)
{
	if ((*p1)->prev != NULL)
	{
		(*p1)->prev->next = (*p2);
	}
	else
	{
		*list = *p2;
	}
	if ((*p2)->next != NULL)
	{
		(*p2)->next->prev = (*p1);
	}
	(*p1)->next = (*p2)->next;
	(*p2)->prev = (*p1)->prev;
	(*p1)->prev = (*p2);
	(*p2)->next = (*p1);

	print_list(*list);
}
