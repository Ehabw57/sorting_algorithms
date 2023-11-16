#include "sort.h"

/**
 * bubble_sort - function that sorts an array
 * of integers in ascending order using the Bubble sort algorithm
 *
 * @array: the sorted array
 * @size: number of element of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	if (!array || !size)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < (size - i); j++)
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
	}
}
