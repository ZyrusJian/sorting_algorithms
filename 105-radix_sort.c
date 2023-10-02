#include "sort.h"
#include <stdlib.h>

/**
 * radix_sort - sorts an array of integers in ascending orderi
 *		using the LSD radix
 * sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 */

void radix_sort(int *array, size_t size)
{
	int max = 0, exp = 1, i, j;
	int *output = malloc(sizeof(int) * size);

	if (!output)
		return;

	for (i = 0; i < (int)size; i++)
		if (array[i] > max)
			max = array[i];

	while (max / exp > 0)
	{
		int count[10] = {0};

		for (i = 0; i < (int)size; i++)
			count[(array[i] / exp) % 10]++;

		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];

		for (i = size - 1; i >= 0; i--)
		{
			j = (array[i] / exp) % 10;
			output[count[j] - 1] = array[i];
			count[j]--;
		}

		for (i = 0; i < (int)size; i++)
			array[i] = output[i];

		print_array(array, size);
		exp *= 10;
	}

	free(output);
}
