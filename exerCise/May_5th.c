#define _CRT_SECURE_NO_WARNINGS 1


//一、计算10的阶乘
#include<stdio.h>

// 1.正常写法
int main()
{
	int i, sum = 1;
	for (i = 1; i <= 10; i++)
		sum *= i;
	printf("%d\n", sum);
}

// 2.函数调用
int function(int x)
{
	int i = 1, s = 1; 
	for (; i <= x;)
		s *= i++;
	return s;
}

int main()
{
	int acm = function(10);
	printf("%d\n", acm);
}

// 3.递归写法
int fun(int x)
{
	return x == 1 || x == 0 ? 1 : x * fun(x - 1);
}

int main()
{
	printf("%d\n", fun(10));
}


// 二、计算10以内的阶乘之和  4027913
#include<stdio.h>
int function(int x)
{
	int i = 1, s = 1;
	for (; i <= x;)
		s *= i++;
	return s;
}

int main()
{
	int i = 1, sum = 0;
	for (; i <= 10; i++)
		sum += function(i);
	printf("%d\n", sum);

	return 0;
}

// 三、选择排序 + 二分查找
#include<stdio.h>

void select_sort(int *arr, int len)
{
	int i, j, temp;
	for (i = 0; i < len - 1; i++)
	{
		int index = i;
		for (j = i + 1; j < len; j++)
		{
			if (arr[j] < arr[index])
				index = j;
		}
		if (i != index)
		{
			temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;
		}
	}
}

int main()
{
	int arr[] = { 3, 8, 1, 6, 5, 4, 7, 2, 9, 0 };
	int length = sizeof(arr) / sizeof(*arr);
	select_sort(arr, length);

	int left = 0;
	int right = length - 1;
	int find_num = 8;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (find_num > arr[mid])       // 0 1 2 3      4       5 6 7 8 9
			left = mid + 1;
		else if (find_num < arr[mid])
			right = mid - 1;
		else
		{
			printf("元素下标为:%d\n", mid);
			break;
		}

		if (left > right)
			printf("FAIL!!");
	}
	return 0;
}


// 四、辗转相除法->最大公约数, 最小公倍数
// 最小公倍数 = 两者之积 / 最大公倍数
#include<stdio.h>

int gcd(int m, int n)
{
	return n ? gcd(n, m % n) : m;
}

int main()
{
	int a, b;
	int c = 0, result;
	printf("请输入两个数a,b :");
	scanf("%d,%d", &a, &b);
	result = a * b;
	c = gcd(a, b);
	/*while (a % b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	printf("%d, %d\n", b, result / b);*/
	printf("%d, %d\n", c, result / c);
	return 0;
}




