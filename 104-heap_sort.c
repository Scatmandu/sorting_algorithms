#include "sort.h"
/**
 * swap - swaps values
 * @a: int to be swapped
 * @b: int to be swapped
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * heapify - heapifies
 * @arr: array to heapify
 * @n: int to be compared
 * @i: int to be compared
 * @size: of array
 */
void heapify(int *arr, int n, int i, int size)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest])
		largest = left;

	if (right < n && arr[right] > arr[largest])
		largest = right;

	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);
		print_array(arr, size);
		heapify(arr, n, largest, size);
	}
}
/**
 * heap_sort - implements sift-down heap sort
 * @array: array to be sorted
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	int k;

	for (k = size / 2 - 1; k >= 0; k--)
		heapify(array, size, k, size);
	for (k = size - 1; k >= 0; k--)
	{
		swap(&array[0], &array[k]);
		if (k > 0)
			print_array(array, size);
		heapify(array, k, 0, size);
	}
}
