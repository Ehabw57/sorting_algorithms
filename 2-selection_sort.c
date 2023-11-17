#include "sort.h"
/**
 * selection_sort - function that sorts an array of integers
 * in ascending order using the Selection sort algorithm
 *
 * @array: array that i need to swap
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	unsigned int index;
	int temp;

	if (!array || !size)
		return;

	for (i = 0; i < size - 1; i++)
	{
		index = i;
		for (j = i; j < size; j++)
		{
			if (array[index] > array[j])
			{
				index = j;
			}	
		}
		temp = array[index];
		array[index] = array[i];
		array[i] = temp;
		if (index != i)
			print_array(array, size);
	}
}
