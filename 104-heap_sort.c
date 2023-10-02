#include "sort.h"

/**
 * sift_down - repair the heap whose root element is at index 'start'
 * @array: array to sort
 * @start: root index
 * @end: last index
 * @size: size of the array
 */

void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start, child, swap;

	while (root * 2 + 1 <= end)
	{
		child = root * 2 + 1;
		swap = root;

		if (array[swap] < array[child])
			swap = child;

		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;

		if (swap != root)
		{
			int temp = array[root];

			array[root] = array[swap];
			array[swap] = temp;
			print_array(array, size);
			root = swap;
		}
		else
			return;
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order using the
 *             sift-down heap sort algorithm
 * @array: array to sort
 * @size: size of the array
 */

void heap_sort(int *array, size_t size)
{
	int i, temp;

	for (i = (size - 2) / 2; i >= 0; i--)
		sift_down(array, i, size - 1, size);

	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		sift_down(array, 0, i - 1, size);
	}
}
