#include "sort.h"
/**
 * merger - merged two sorted arrays into a single sorted array.
 * @left: Pointer to the first sorted array.
 * @right: Pointer to the second sorted array.
 * @size1: Size of the first array.
 * @size2: Size of the second array.
 * Return: A dynamically allocated array containing the merged elements.
 *                  The caller is responsible for freeing the memory.
 */
int *merger(int *left, int *right, size_t size1, size_t size2)
{
	size_t i = 0, j = 0, s;
	int *merged = NULL;

	merged = malloc((sizeof(int) * (size1 + size2)));
	if (!merged)
		return (NULL);

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, size1);
	printf("[right]: ");
	print_array(right, size2);

	for (s = 0; s < (size1 + size2); s++)
	{
		if ((i < size1 && left[i] <= right[j]) || j >= size2)
		{
			merged[s] = left[i];
			i++;
		}
		else
		{
			merged[s] = right[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_array(merged, size1 + size2);

	return (merged);
}
/**
 * merge_sort - Sorts an array using the merge sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *merged = NULL, *left = NULL, *right = NULL;
	size_t i;

	if (!array || size <= 1)
		return;

	left = &array[0];
	right = &array[size / 2];

	merge_sort(left, size / 2);
	merge_sort(right, size - (size / 2));

	merged = merger(left, right, size / 2, size - (size / 2));
	if (!merged)
		return;

	for (i = 0; i < size; i++)
		array[i] = merged[i];

	free(merged);
}
