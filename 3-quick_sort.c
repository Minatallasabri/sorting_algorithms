#include "sort.h"

/**
 * Function: swap_values - Swaps the values of two
 * integer variables using pointers.
 * Parameters:
 * @a: A pointer to the first integer variable.
 * @b: A pointer to the second integer variable.
 */

/* swap values contained inside the pointers */
void swap_values(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}


/**
 * Function: lomuto_logic - Partitions an array based on a pivot.
 * algorithm for quicksort.
 * Parameters:
 * @array: A pointer to the integer array to be partitioned.
 * @size: The size of the array.
 * @start: The starting index of the subarray to be partitioned.
 * @end: The ending index of the subarray to be partitioned.
 * Return: The index of the pivot element after partitioning.
*/

int lomuto_logic(int *array, size_t size, int start, int end)
{
	int *pivot, order, scan ;

	pivot = array + end;
	for (order =  scan =  start; scan < end; scan++)
	{
		if (array[scan] < *pivot)
		{
			if (order < scan)
			{
				swap_values(array + scan, array + order);
				print_array(array, size);
			}
			order++;
		}
	}

	if (array[order] > *pivot)
	{
		swap_values(array + order, pivot);
		print_array(array, size);
	}

	return (order);
}


/**
 * Function: recursive_sort - Recursively implements the quicksort
 * algorithm using Lomuto partitioning.
 * Parameters:
 * @array: A pointer to the integer array to be sorted.
 * @size:  The size of the array.
 * @start: The starting index of the subarray to be sorted.
 * @end:   The ending index of the subarray to be sorted.
 *
 * Returns: Nothing (void).
*/

void recursive_sort(int *array, size_t size, int start, int end)
{
	int slice;

	if (end - start > 0)
	{
		slice = lomuto_logic(array, size, start, end);
		recursive_sort(array, size, start, slice - 1);
		recursive_sort(array, size, slice + 1, end);
	}

}


/**
 * Function: quick_sort - Entry point for the quicksort algorithm,
 * handling initial checks and calls.
 * Parameters:
 * @array: A pointer to the integer array to be sorted.
 * @size:  The size of the array.
 *
 * Returns: Nothing (void).
*/


void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_logic(array, size, 0, size - 1);
}
