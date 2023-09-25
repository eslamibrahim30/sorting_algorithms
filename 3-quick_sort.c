#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap_int - swap the values of two variables
 * @a: the first variable address
 * @b: the second variable address
 */
void swap_int(int *a, int *b)
{
	int temp = *b;

	*b = *a;
	*a = temp;
}

/**
 * partition - Divides array into two partitions
 *
 * @array: the given array to be partitioned.
 * @size: the size of the given array.
 * @lo: the index of first element in the array.
 * @hi: the index of last element in the array.
 *
 * Return: the pivot index.
 */
int partition(int *array, size_t size, int lo, int hi)
{
	int pivot = array[hi];
	int i = lo - 1;
	int j = 0;

	for (j = lo; j < hi; j++)
	{
		if (array[j] <= pivot)
		{
			i = i + 1;
			swap_int(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	swap_int(&array[i + 1], &array[hi]);
	print_array(array, size);
	return (i + 1);
}

/**
 * quicksort - an algorithm to sort a given array using
 * the quick sort algorithms.
 *
 * @array: the given array.
 * @size: the size of the given array.
 * @lo: the index of the first element in the partition to be sorted.
 * @hi: the index of the last element in the partition to be sorted.
 */
void quicksort(int *array, size_t size, int lo, int hi)
{
	int p = 0;

	if (lo >= hi || lo < 0)
		return;
	p = partition(array, size, lo, hi);
	quicksort(array, size, lo, p - 1);
	quicksort(array, size, p + 1, hi);
}

/**
 * quick_sort - Sorts an array  of integers in ascending order
 * using the Quick sort algorithm.
 *
 * @array: The given array to be sorted
 * @size: the size of the given array.
 */
void quick_sort(int *array, size_t size)
{
	quicksort(array, size, 0, size - 1);
}
