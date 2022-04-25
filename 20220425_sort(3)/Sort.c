#include "Sort.h"

void swap(int *a, int *b)  // ����λ��
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Print(int *arr, int length) // ��ӡ
{
	for (int i = 0; i < length; i++)
		printf("%d ", arr[i]);
	putchar('\n');
}

void bubble_sort(int arr[], int length)  // ð��
{
	int i, j;
	for (i = 0; i < length - 1; i++)
	{
		for (j = 0; j < length - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])  // ����
				swap(&arr[j], &arr[j + 1]);
		}
	}
}

void select_sort(int arr[], int length)  // ѡ��
{
	int i, j, index;
	for (i = 0; i < length - 1; i++)
	{
		index = i;
		for (j = i + 1; j < length; j++)
			if (arr[j] < arr[index])  // ����
				index = j;
		if (i != index)
			swap(&arr[i], &arr[index]);
	}
}

void insert_sort(int arr[], int length)  // ����
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