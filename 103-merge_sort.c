#include "sort.h"


void merge_sort(int *array, size_t size)
{
    size_t i = 0;
    int *temp = NULL;

    if (array == NULL || size < 2)
        return;
    temp = malloc(sizeof(int) * size);
    if (temp == NULL)
        return;
    for (i = 0; i < size; i++)
        temp[i] = array[i];
    actual_merge(array, temp, 0, size);
    free(temp);
}

void sub_sort(int *array, int *temp, size_t left, size_t mid, size_t right)
{
	size_t i = left, j = mid, k = left;
	printf("Merging...\n");
	printf("[left]: ");

	print_array(temp + left, mid - left);
	printf("[right]: ");

	print_array(temp + mid, right - mid);

		while (k < right)
		{
			if (i < mid && (j >= right || temp[i] <= temp[j]))
			{
				array[k] = temp[i];
				i++;
			}
			else
			{
				array[k] = temp[j];
				j++;
			}
			k++;
		}
	printf("[Done]: ");

	print_array(array + left, right - left);
}

void actual_merge(int *array, int *temp, size_t left, size_t right)
{
	size_t mid = 0, i = left;

	if (right - left < 2)
	{
		return;
	}

	mid = (left + right) / 2;

	actual_merge(array, temp, left, mid);
	actual_merge(array, temp, mid, right);

	sub_sort(array, temp, left, mid, right);

	while (i < right)
	{
		temp[i] = array[i];
		i++;
	}
}