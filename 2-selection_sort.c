#include "sort.h"
/**
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	unsigned int index;
	int temp;

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
