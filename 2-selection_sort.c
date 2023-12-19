#include "sort.h"
/**
 * selection_sort - sorts an array of integers in ascending
 * order using the Selection sort algorithm
 *
 * @array: Array of integers
 * @size: Size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_list;
	int temp; /*Temporary variable */

	if (array == NULL || size < 2)
	{
		return;
	}

	for (i = 0; i < size; i++)
	{
		min_list = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_list])
				min_list = j;
		}
		if (min_list != i)
		{
			temp = array[i];
			array[i] = array[min_list];
			array[min_list] = temp;
			print_array(array, size);
		}
	}
}
