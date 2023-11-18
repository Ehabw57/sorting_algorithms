#include "sort.h"
/**
 * shell_sort -  function that sorts an array of integers in
 * ascending order using the Shell sort algorithm,
 * using the Knuth sequence
 *
 * @array: the array that i need to sort
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j, n;
	int tmp;

	if (!size || !array)
		return;
	n = 1;
	while (n < size)
		n = n * 3 + 1;
	n = (n - 1) / 3;
	for (gap = n; gap; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j > gap - 1 &&  array[j - gap] > tmp; j -= gap)
				array[j] = array[j - gap];
			array[j] = tmp;
		}
		print_array(array, size);
	}
}
