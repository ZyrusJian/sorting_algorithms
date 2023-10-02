#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge - merges two subarrays of an array
 * @array: array to sort
 * @left: left index of the subarray
 * @mid: middle index of the subarray
 * @right: right index of the subarray
 * @tmp: temporary array to store the sorted subarray
 */

void merge(int *array, int left, int mid, int right, int *tmp)
{
	int i = left, j = mid + 1, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid - left + 1);
	printf("[right]: ");
	print_array(array + mid + 1, right - mid);

	while (i <= mid && j <= right)
	{
		if (array[i] <= array[j])
			tmp[k++] = array[i++];
		else
			tmp[k++] = array[j++];
	}

	while (i <= mid)
		tmp[k++] = array[i++];
	while (j <= right)
		tmp[k++] = array[j++];

	for (i = left, k = 0; i <= right; i++, k++)
		array[i] = tmp[k];

	printf("[Done]: ");
	print_array(array + left, right - left + 1);
}

/**
 * merge_sort_helper - sorts an array of integers in ascending order using the
 *                     Merge sort algorithm
 * @array: array to sort
 * @left: left index of the subarray
 * @right: right index of the subarray
 * @tmp: temporary array to store the sorted subarray
 */

void merge_sort_helper(int *array, int left, int right, int *tmp)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;
		merge_sort_helper(array, left, mid, tmp);
		merge_sort_helper(array, mid + 1, right, tmp);
		merge(array, left, mid, right, tmp);
	}
}

/**
 * merge_sort - sorts an array of integers in ascending order using the
 *              Merge sort algorithm
 * @array: array to sort
 * @size: size of the array
 */

void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (!array || size < 2)
		return;

	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return;

	merge_sort_helper(array, 0, size - 1, tmp);

	free(tmp);
}