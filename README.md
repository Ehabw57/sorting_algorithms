# Sorting Algorithms in C

This repository contains a collection of sorting algorithms implemented in the C programming language. These algorithms are designed to efficiently organize and order elements within arrays or linked lists. Feel free to explore and use these sorting functions in your projects.

Huge thanks to **Maram Milod** for being an invaluable partner in this project. It was a great opportunity working with you 🤝.

## Sorting Algorithms Included:

1. **Bubble Sort:**

   - Function: `void bubble_sort(int *array, size_t size);`
   - Description: A simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.

2. **Insertion Sort (for Douply Linked Lists):**

   - Function: `void insertion_sort_list(listint_t **list);`
   - Description: A sorting algorithm that builds the final sorted array or list one item at a time. It is much less efficient on large lists than more advanced algorithms.

3. **Selection Sort:**

   - Function: `void selection_sort(int *array, size_t size);`
   - Description: A simple sorting algorithm that works by repeatedly selecting the minimum element from the unsorted portion of the array and putting it at the beginning.

4. **Quick Sort:**

   - Function: `void quick_sort(int *array, size_t size);`
   - Description: An efficient, in-place sorting algorithm that uses a divide-and-conquer strategy to sort elements.

5. **Shell Sort:**

   - Function: `void shell_sort(int *array, size_t size);`
   - Description: A variation of insertion sort that allows the exchange of items that are far apart, producing partially sorted arrays that can be efficiently sorted with insertion sort.

6. **Cocktail Shaker Sort (for Douply Linked Lists):**

   - Function: `void cocktail_sort_list(listint_t **list);`
   - Description: A variation of the bubble sort algorithm where the list is sorted by comparing and swapping adjacent elements.

7. **Counting Sort:**

   - Function: `void counting_sort(int *array, size_t size);`
   - Description: A non-comparative sorting algorithm that sorts elements based on their count occurrences.

8. **Merge Sort:**

   - Function: `void merge_sort(int *array, size_t size);`
   - Description: A divide-and-conquer algorithm that divides the input array into two halves, recursively sorts them, and then merges the sorted halves.

9. **Heap Sort:**

   - Function: `void heap_sort(int *array, size_t size);`
   - Description: A comparison-based sorting algorithm that uses a binary heap data structure to build a max-heap and then repeatedly extracts the maximum element.

10. **Radix Sort:**
    - Function: `void radix_sort(int *array, size_t size);`
    - Description: A non-comparative integer sorting algorithm that sorts data with integer keys by grouping keys by individual digits.

## Usage:

To use these sorting functions, simply include the `sort.h` header file in your C program and call the desired sorting function with the appropriate parameters.

```c
#include "sort.h"

int main(void) {
    int array[] = { /* Your array elements here */ };
    size_t size = sizeof(array) / sizeof(array[0]);

    /*call the desired sorting function*/
    bubble_sort(array, size);

    /*Print the sorted array*/
    print_array(array, size);

    return 0;
}
```

Feel free to contribute to this repository by adding new sorting algorithms or optimizing existing ones. Happy sorting! 🚀
