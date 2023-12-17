#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers
 * in ascending order using Bubble Sort
 * @array: Pointer to the array to be sorted
 * @size: Number of elements in the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i,j;
	int temp; /* Temporary variable */

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			/*
			* if the number in the left is bigger than number
			* in the right swap positions
			*/
		if(array[j] > array[j + 1])
		{	
			/* Swap positions */
			temp = array[j];
			array[j] = array[j + 1];
			array[j + 1] = temp;
			print_array(array, size);
		}
	}
	
	}

}
