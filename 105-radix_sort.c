#include "sort.h"
/**
 * count_sort - Sorts an array of integers using the Counting Sort algorithm
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array
 * @div: Divisor used to select signifcant digit for sorting.
 */
void count_sort(int *array, size_t size, size_t div)
{
	int *count, *copy, i, idx;

	copy = malloc(sizeof(int) * size);
	if (!copy)
		return;

	count = calloc(10, sizeof(int));
	if (count == NULL)
	{
		free(copy);
		return;
	}
	for (i = 0; i < (int)size; i++)
		copy[i] = 0;

	for (i = 0; i < (int)size; i++)
	{
		idx = array[i] / div;
		count[idx % 10]++;
	}

	for (i = 1; i <= 9; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		idx = array[i] / div;
		copy[count[idx % 10] - 1] = array[i];
		count[idx % 10]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = copy[i];

	free(copy);
	free(count);
}
/**
 * radix_sort - Sorts an array of integers using the Radix Sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max = 0, i;
	size_t div = 1;

	if (!array || size < 2)
		return;

	for (i = 0; i < (int)size; i++)
		if (array[i] > max)
			max = array[i];

	while (max / div > 0)
	{
		count_sort(array, size, div);
		div *= 10;
		print_array(array, size);
	}
}
