#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge - Merges two sub-arrays of an array
 *
 * @array: Array containing the sub-arrays to merge
 * @size: Size of the array
 * @left: Pointer to the left sub-array
 * @left_size: Size of the left sub-array
 * @right: Pointer to the right sub-array
 * @right_size: Size of the right sub-array
 */

void merge(int *array, size_t size, int *left, size_t left_size,
		int *right, size_t right_size)
{
	int i = 0, j = 0, k = 0;
	int *output = malloc(sizeof(int) * size);

	if (!output)
		return;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	while (i < (int)left_size && j < (int)right_size)
	{
		if (left[i] <= right[j])
			output[k++] = left[i++];
		else
			output[k++] = right[j++];
	}

	while (i < (int)left_size)
		output[k++] = left[i++];

	while (j < (int)right_size)
		output[k++] = right[j++];

	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	printf("[Done]: ");
	print_array(output, size);

	free(output);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using the
 *              Merge sort algorithm
 *
 * @array: Array to sort
 * @size: Size of the array
 */

void merge_sort(int *array, size_t size)
{
	size_t mid = size / 2, i;
	int *left, *right;

	if (!array || size < 2)
		return;

	left = array;
	right = array + mid;

	merge_sort(left, mid);
	merge_sort(right, size - mid);

	merge(array, size, left, mid, right, size - mid);
}
