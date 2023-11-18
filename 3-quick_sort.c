#include "sort.h"
/**
 * swap_int - Swaps Two indexes in the array then print the result
 * @array: array to be sorted
 * @p1: first index to swap
 * @p2: second index to swap
 * @orignal: orginal size of the array
*/
void swap_int(int *array, int *p1, int *p2, size_t orignal)
{
	int tmp;

	if (p1 == p2)
		return;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
	print_array(array, orignal);
}
/**
 * sort - Actual sorting fucntion
 * @start: Start index
 * @size: size of the array
 * @orignal: orignal size of the array
 * @array: Array to be sorted
*/
void sort(int start, size_t size, size_t orignal, int *array)
{
	size_t pivot = size - 1, j;
	int i;

	if (size <= 1)
		return;

	j = start;
	for (i = j - 1; j < pivot; j++)
	{

		if (array[j] > array[pivot])
			continue;

		i++;
		if ((size_t)i != j)
			swap_int(array, &array[j], &array[i], orignal);
	}
	i++;
	swap_int(array, &array[pivot], &array[i], orignal);
	pivot = i;

	if (pivot < size - 1)
	{
		sort(pivot + 1, orignal, orignal, array);
	}
	else if (pivot == (size - 1))
	{
		sort(0, pivot, orignal, array);
	}
}
/**
 * quick_sort - Sorting an given array be quick sort algorthim
 * @array: Array to be sorted
 * @size: Size of the array
*/
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	sort(0, size, size, array);
}
