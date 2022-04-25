#include "Sort.h"

void swap(int *a, int *b)  // ΩªªªŒª÷√
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Print(int *arr, int length) // ¥Ú”°
{
	for (int i = 0; i < length; i++)
		printf("%d ", arr[i]);
	putchar('\n');
}

void bubble_sort(int arr[], int length)  // √∞≈›
{
	int i, j;
	for (i = 0; i < length - 1; i++)
	{
		for (j = 0; j < length - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])  // …˝–Ú
				swap(&arr[j], &arr[j + 1]);
		}
	}
}

void select_sort(int arr[], int length)  // —°‘Ò
{
	int i, j, index;
	for (i = 0; i < length - 1; i++)
	{
		index = i;
		for (j = i + 1; j < length; j++)
			if (arr[j] < arr[index])  // …˝–Ú
				index = j;
		if (i != index)
			swap(&arr[i], &arr[index]);
	}
}

void insert_sort(int arr[], int length)  // ≤Â»Î
{
	int i, j, temp;
	for (i = 1; i < length; i++)
	{
		temp = arr[i];
		for (j = i; j > 0 && arr[j - 1] > temp; j--)
			arr[j] = arr[j - 1];
		arr[j] = temp;
	}
}