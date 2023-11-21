#include "sort.h"
/**
 * heapify - function
 * @arr: a
 * @size:  s
 * @i: i
 * @len: l
 */
void heapify(int *arr, size_t size, size_t i, size_t len)
{
	size_t lar = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;
	int temp;

	if (left < size && arr[left] > arr[lar])
		lar = left;
	if (right < size && arr[right] > arr[lar])
		lar = right;
	if (lar != i)
	{
		temp = arr[i];
		arr[i] = arr[lar];
		arr[lar] = temp;
		print_array(arr, len);
		heapify(arr, size, lar, len);
	}
}

/**
 * heap_sort - function
 * @array: array that i need to sort
 * @size: size of array
 */

void heap_sort(int *array, size_t size)
{
	int temp, i;
	size_t len = size;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, len);
	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		heapify(array, i, 0, len);
	}
}
