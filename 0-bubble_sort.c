#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sort.h"
/**
 * bubble_sort - Swap two given nodes bubble sort.
 *
 * @array: an array
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
int temp;
bool swapped = false;
size_t a = 0, d = 0;
if (array == NULL || !size)
{
return;
}
do {
swapped = false;
for (a = 1; a < size ; a++)
{
if (array[a - 1] > array[a])
{
temp = array[a - 1];
array[a - 1] = array[a];
array[a] = temp;
swapped = true;
print_array(array, size);
}
}
d++;
} while (swapped);
}
