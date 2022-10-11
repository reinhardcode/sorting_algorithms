#include "sort.h"

/**
 * counting_sort - sorts an array using the counting sort algo
 * @array: the array to be sorted
 * @size: size of the array
 *
 * Return: None
 */

void counting_sort(int *array, size_t size)
{
	int *new_arr, *count;
	int i, max;

	new_arr = malloc(sizeof(int) * size);
	if (!array)
	{
		free(new_arr);
		return;
	}

	max = array[0];
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	count = malloc(sizeof(int) * (max + 1));
	for (i = 0; i <= max; ++i)
		count[i] = 0;

	if (!count)
	{
		free(new_arr);
		return;
	}

	/*Store the count of each element*/
	for (i = 0; i < (int)size; i++)
		count[array[i]]++;

	/*Store the cumulative count of the array*/
	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	/*Print the counting array*/
	print_array(count, max + 1);

	/*Find the index of each element of the original array in the
	count array and place them in the new_arr*/
	for(i = size - 1; i >= 0; i--)
	{
		new_arr[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	/*Copy sorted elements into original array*/
	for (i = 0; i < (int)size; ++i)
		array[i] = new_arr[i];

	free(count);
	free(new_arr);
}
