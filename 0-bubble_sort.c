#include "sort.h"


/**
 * bubble_sort - Sorts an array of integers in ascending order
 * using the BUbble Sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, is_swap = 0;
	int temp_val;

	while (1)
	{
		for (i = 0; i < size; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp_val = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp_val;

				is_swap = 1;
			}
		}

		if (!is_swap)
			break;

		is_swap = 0;
	}
}