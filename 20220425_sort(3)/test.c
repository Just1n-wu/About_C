#include "Sort.h"

int main()
{
	int arr_b[] = { 3, 8, 1, 6, 5, 4, 7, 2, 9, 0 };
	int arr_s[] = { 3, 8, 1, 6, 5, 4, 7, 2, 9, 0 };
	int arr_i[] = { 3, 8, 1, 6, 5, 4, 7, 2, 9, 0 };
	int length = sizeof(arr_i) / sizeof(*arr_i);

	bubble_sort(arr_b, length);
	select_sort(arr_s, length);
	insert_sort(arr_i, length);

	Print(arr_b, length);
	Print(arr_s, length);
	Print(arr_i, length);

}