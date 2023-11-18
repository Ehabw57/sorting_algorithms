#include "sort.h"
/**
 * swap_int - Swaps two integers in an array
 * @p1: first index to swap
 * @p2: second index to swap
 */
void swap_int(int *p1, int *p2)
{
	int tmp;

	if (p1 == p2)
		return;

	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
/**
 * partition - Partitioning function for quicksort
 * @array: Original array
 * @start: Start index
 * @end: End index
 * @size: Size of the array
 * Return: Pivot index
 */
int *partition(int *array, int *start, int *end, size_t size)
{
	int *pivot = end, *j = start, *i = NULL;

	for (i = j - 1; j < end; j++)
	{
		if (*j > *pivot)
			continue;
		i++;
		swap_int(j, i);
		if (i != j)
			print_array(array, size);
	}

	i++;
	swap_int(pivot, i);
	if (i != pivot)
		print_array(array, size);

	pivot = i;
	return (pivot);
}
/**
 * recursive_quick_sort - Recursive function for quicksort
 * @array: Array to be sorted
 * @start: Start index
 * @end: End index
 * @size: Size of the array
 */
void recursive_quick_sort(int *array, int *start, int *end, size_t size)
{
	int *pivot;

	if (start >= end)
		return;

	pivot = partition(array, start, end, size);

	recursive_quick_sort(array, start, pivot - 1, size);
	recursive_quick_sort(array, pivot + 1, end, size);
}
/**
 * quick_sort - Sorting an array using the quicksort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	recursive_quick_sort(array, array, array + size - 1, size);
}
