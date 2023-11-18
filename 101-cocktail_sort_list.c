#include "sort.h"
/**
 * forward - Get the last node of a linked list
 * @head: Head of the linked list
 * Return: Pointer to the last node of the list
 */
listint_t *forward(listint_t *head)
{
	while (head->next != NULL)
		head = head->next;
	return (head);
}
/**
 * swap_list - Swaps two nodes in the list
 * @list: Pointer to the head of the list
 * @p1: First node to swap
 * @p2: Second node to swap
 */
void swap_list(listint_t **list, listint_t **p1, listint_t **p2)
{
	listint_t *tmp = NULL;

	if ((*p1)->prev != NULL)
		(*p1)->prev->next = (*p2);

	if ((*p2)->next != NULL)
		(*p2)->next->prev = (*p1);

	(*p1)->next = (*p2)->next;
	(*p2)->prev = (*p1)->prev;
	(*p1)->prev = (*p2);
	(*p2)->next = (*p1);
	if ((*p2)->prev == NULL)
		*list = *p2;
	print_list(*list);
	tmp = (*p1);
	(*p1) = (*p2);
	(*p2) = tmp;
}
/**
 * cocktail_sort_list - Sorts a linked list by shaker sort
 * @list: Head of the list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *l = NULL, *r = NULL;
	listint_t *f = NULL, *b = NULL;

	if (!list || !(*list))
		return;

	l = (*list), r = forward(*list);
	while (l != r && l->next != r)
	{
		for (b = l, f = b->next; b != r; b = b->next, f = f->next)
			if (b->n > f->n)
			{
				if (f == r)
					r = r->prev;
				swap_list(list, &b, &f);
			}

		for (f = b->prev; b != l; b = b->prev, f = f->prev)
			if (f->n > b->n)
			{
				if (f == l)
					l = l->next;
				swap_list(list, &f, &b);
			}

		l = l->next;
		r = r->prev;
	}
}
