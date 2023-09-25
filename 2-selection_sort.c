#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * selection_sort - Swap two given nodes selection sort.
 *
 * @array: an array
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
int temp;
size_t a = 0, d = 0, min = 0;
if (array == NULL || size < 2)
{
return;
}
for (; a < size - 1; a++)
{
min = a;
for (d = a + 1; d < size; d++)
{
if (array[d] < array[min])
{
min = d;
}
}
if (min != a)
{
temp = array[a];
array[a] = array[min];
array[min] = temp;
print_array(array, size);
}
}
}
