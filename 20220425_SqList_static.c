#define _CRT_SECURE_NO_WARNINGS 1
#define MAXSIZE 10    // 定义最大长度

#include <stdio.h>
#include <stdbool.h>

typedef int DataType; // 自定义数据类型

typedef struct SqList
{
	DataType list[MAXSIZE];  // 用静态的数组存放数据元素
	int size;                // 当前存储的数据元素个数 且满足 size <= MAXSIZE
}St;

// 初始化
void InitSqList(St *L)
{
	/*for (int i = 0; i < MAXSIZE; i++)
		L->list[i] = 0;*/                   // 也可将表中数据都清零，否则会遗留有 脏数据

	L->size = 0;    // 初始元素个数为 0
}

// 打印
void PrintSqlist(St *L)
{
	int i = 0;
	// 只访问数据，可不传地址，如果 i < MAXSIZE, 可能会出现脏数据
	for (i = 0; i < L->size; i++)   
		printf("%d ", L->list[i]);
	putchar('\n');
}

// 判断是否有空间
bool IsSqlist(St *L)
{
	// 1 可存;  2 已满
	return L->size < MAXSIZE && L->size >= 0 ? true : false;
}

// 插入    i 为插入的位置，x 为插入的数据 
int InsertSqlist(St *L, int i, DataType x)
{

	// 插入条件  \
	1.  i 满足 >= 0 && < MAXSIZE  \
	2.  插入成功返回 0， 失败返回 -1

	int j = 0;
	if(IsSqlist(L) && (i >= 0) && (i < MAXSIZE))
	{
		for (j = L->size; j >= i; j--)
			L->list[j] = L->list[j - 1];  // 将已有元素后移

		L->list[i] = x;
		L->size++;

		return 0;
	}

	else
	{
		printf("元素已满(%d) 或 下标(%d)不存在!\n", IsSqlist(L), i);
		return -1;
	}
	
}

// 删除    i 为删除的位置，x 为删除的数据
void DeleteSqList(St *L, int i)
{
	int j = 0;
	if (L->size > 0 && (i >= 0) && (i < MAXSIZE))
	{
		DataType x = L->list[i];   // 记录删除的值
		for (j = i; j < L->size - 1; j++)   // 前移现有元素
			L->list[j] = L->list[j + 1];
		L->size--;
		printf("已删除下标 %d 位置, 该值为%d\n", i, x);
	}

	else
		printf("表中无数据(%d) 或 下标(%d)不存在!\n", IsSqlist(L), i);
}

// 查找    x 为查找的数据
int FindSqList(St *L, DataType x)
{
	int index = 0;
	if (L->size > 0 && L->size <= MAXSIZE)   // 考虑为满的情况
	{
		for (; index < L->size; index++)
			if (x == L->list[index])
				break;
	}
	else
	{
		printf("该表中不存在该值!\n");
		return -1;
	}
	return index;
}
 
// 修改  i 为修改的位置，x 为修改的数据
void ReviseSqList(St *L, int i, DataType x)
{
	int j = 0;
	if (L->size > 0 && L->size <= MAXSIZE     // 考虑为满的情况
	&& (i >= 0) && (i < MAXSIZE))             // 下标 i >= 0 && i < max
		L->list[i] = x;
	else
		printf("输入的位置不合法!\n");
		
}


int main()
{
	St L;
	InitSqList(&L);  // 需要修改其值，取地址
	for (int i = 0; i < MAXSIZE; i++)
		InsertSqlist(&L, i, i);
	InsertSqlist(&L, 0, 10);
	InsertSqlist(&L, 10, 0);
	DeleteSqList(&L, 2);
	InsertSqlist(&L, 10, 0);
	InsertSqlist(&L, 0, 10);

	PrintSqlist(&L);

	int id = FindSqList(&L, 6);
	printf("该元素下标为:%d\n", id);

	ReviseSqList(&L, 8, 10);
	PrintSqlist(&L);



	return 0;
}




