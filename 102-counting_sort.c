#include "sort.h"
#include <stdlib.h>

/**
 */
int key(int *array, size_t size)
{
	int n = array[size - 1];

	while (size-- > 0)
	{
		if (n < array[size])
			n = array[size];
	}
	return (n);
}
/**
 */
void counting_sort(int *array, size_t size)
{
	int k, *count, *copy, i;

	if (!array || size <= 1)
		return;

	copy = malloc(sizeof(int) * size);
	if (!copy)
		return;

	k = key(array, size) + 1;
	count = malloc(sizeof(int) * k);
		if (!count)
		{
			free(copy);
			return;
		}

	for (i = 0; i < k; i++)
		count[i] = 0;

	for (i = 0; i < (int) size; i++)
		count[array[i]]++;

	for (i = 1; i < k; i++)
		count[i] += count[i - 1];

	print_array(count, k);
	for (i = 0; i < (int) size; i++)
		copy[count[array[i]] - 1] = array[i], count[array[i]]--;

	for (i = 0; i < (int) size; i++)
		array[i] = copy[i];

	free(count);
	free(copy);
}
