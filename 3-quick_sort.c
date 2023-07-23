#include "sort.h"

/**
 * swap - swaps two elements
 * @xp: first element
 * @yp: second element
 * Return: void
 */
void swap(int *xp, int *yp)
{
    int temp;

    temp = *xp;
    *xp = *yp;
    *yp = temp;
}

/**
 * partition - implement the Lomuto partition scheme.
 * @array: array of integers
 * @l_idx: the start point
 * @u_idx: the end point
 * Return: the pivot
 */
int partition(int *array, size_t l_idx, size_t u_idx, size_t size)
{
    int pivot;
    size_t start, end;

    pivot = array[l_idx];
    start = l_idx;
    end = u_idx;
    while (start < end)
    {
        while (array[start] <= pivot)
            start++;

        while (array[end] >= pivot)
            end--;

        if (start < end)
        {
            swap(&array[start], &array[end]);
            print_array(array, size);
        }
    }

    swap(&array[l_idx], &array[end]);
    print_array(array, size);
    return end;
}

/**
 * quickSort - sortes the element in an array using the Lomuto partition
 * @array: array to be sorted
 * @l_idx: the start point
 * @u_idx: the end point
 * Return: void
 */
void quickSort(int *array, size_t l_idx, size_t u_idx, size_t size)
{
    size_t loc;

    if (l_idx < u_idx)
    {
        loc = partition(array, l_idx, u_idx, size);
        quickSort(array, l_idx, loc - 1, size);
        quickSort(array, loc + 1, u_idx, size);
    }
}

/**
 * quick_sort - calls the function quickSort
 * @array: array of integers to be sorted
 * @size: the length of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;
    quickSort(array, 0, size - 1, size);
}
