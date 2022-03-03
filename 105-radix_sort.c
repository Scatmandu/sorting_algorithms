#include "sort.h"
/**
 * get_max - returns largest number in array
 * @array: array to parse
 * @n: size of array
 * Return: largest element from array
 */
int get_max(int *array, int n)
{
	int i;
	int max = array[0];

	for (i = 1; i < n; i++)
		if (array[i] > max)
		max = array[i];
	return (max);
}
/**
 * count - sorts elements
 * @array: array to be sorted
 * @size: size of array
 * @buff: buffer
 * @lsd: least significant digit
 */
void count(int *array, size_t size, int *buff, int lsd)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	if (array == NULL || size < 2)
	{
		return;
	}
	for (i = 0; i < size; i++)
	{
		count[(array[i] / lsd) % 10]++;
	}
	for (i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}
	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[count[(array[i] / lsd) % 10] - 1] = array[i];
		count[(array[i] / lsd) % 10]--;
	}

	for (i = 0; i < size; ++i)
		array[i] = buff[i];
}
/**
 * radix_sort - sorts array of ints using radix sort
 * @array: array to be sorted
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	int max = get_max(array, size);
	int *temp, LSD;

	if (array == NULL || size < 2)
		return;
	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;
	for (LSD = 1; max / LSD > 0; LSD *= 10)
	{
		count(array, size, temp, LSD);
		print_array(array, size);
	}
	free(temp);
}
