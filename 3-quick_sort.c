#include "sort.h"


/**
 * swap - Swaps two values
 * @a: First value to swap
 * @b: Second value to swap
 *
 * Return: void
 */
void swap(int *a, int *b)
{
	int temp_val = *a;
	*a = *b;
	*b = temp_val;
}


/**
 * partition - Swap values of a partition
 * @array: Array to make the partition
 * @size: Size of the array
 * @low: First value of the array
 * @high: Last value of the array
 *
 * Return: The pivot
 */
int partition(int *array, size_t size, int low, int high)
{
	int i, pivot = array[high], greater_val = low - 1;

	for (i = low; i < high; i++)
	{
		if (array[i] <= pivot)
		{
			greater_val++;
			swap(&array[greater_val], &array[i]);

			if (greater_val != i)
				print_array(array, size);
		}
	}

	swap(&array[greater_val + 1], &array[high]);
	if (greater_val + 1 != high)
		print_array(array, size);

	return (greater_val + 1);
}


/**
 * quick_sort_helper - Apply the quick sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 * @low: First value
 * @high: Last value
 *
 * Return: void
 */
void quick_sort_helper(int *array, size_t size, int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, size, low, high);

		quick_sort_helper(array, size, low, pivot - 1);

		quick_sort_helper(array, size, pivot + 1, high);
	}
}


/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the QuickSort algorithm
 * @array: Array to sort
 * @size: Size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_helper(array, size, 0, size - 1);
}
