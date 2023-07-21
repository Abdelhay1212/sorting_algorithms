#include "sort.h"
#include <stdbool.h>

/**
 * bubble_sort - sorts an array of integers using the Bubble sort algorithm
 * @array: array to be sorted
 * @size: the size of the array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	bool swapped;

	for (i = 0; i < size - 1; i++)
	{
		swapped = false;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				int tmp;

				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;

				swapped = true;
				print_array(array, size);
			}
		}

		if (swapped == false)
		break;
	}
}
