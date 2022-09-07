#include "sort.h"


/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the slection sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;
	int temp_val;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}


		if (min_idx != i)
		{
			temp_val = array[min_idx];
			array[min_idx] = array[i];
			array[i] = temp_val;
			print_array(array, size);
		}
	}
}
