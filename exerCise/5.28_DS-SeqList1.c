#include<stdio.h>
#include<stdbool.h>
#include<assert.h>

#define MaxSize 100

typedef int DateType;

typedef struct SqList
{
	DateType list[MaxSize];
	int size;
}sql;

bool ListEmpty(sql *ps)
{
	// 0. 表正常
	// 1. 为空或者表满
	return ps->size < 0 || ps->size >= MaxSize;
}

// 判断 i 值是否有效
bool ListCHeck_i(sql *ps, int i)
{
	/*if(i < 0 || i > ps->size)
	{
		printf("%d 已超出范围!!", i);
		return false;
	}
	
	else 
		return true;*/
	
	return i >= 0 && i <= ps->size;
}

void ListInit(sql *ps)
{
	printf("初始化...\n");
	ps->size = 0;
	if(!ListEmpty(ps))
		printf("初始化完成!\n");
}

void ListInsert(sql *ps, int i, DateType x)
{
	assert(ListCHeck_i(ps, i));
	
	printf("插入数据 -> %d\n", x);
	
	if(!ListEmpty(ps))
	{
		int j;
		for(j = ps->size; j > i; j--)
		{
			ps->list[j] = ps->list[j - 1];
		}
		
		ps->list[i] = x;
		ps->size++;
	}
	
	else
		printf("表满！\n");
}

int ListLength(sql *ps)
{
	return ps->size;
}

void ListDelete(sql *ps, int i, DateType *x)
{
	assert(ListCHeck_i(ps, i));
	
	printf("删除第 %d(%d) 个数据\n", i, i + 1);
	
	if(!ListEmpty(ps) && ps->size > 0)
	{
		int j;
		
		*x = ps->list[i];
		
		for(j = i + 1; j <= ps->size - 1; j++)
		{
			ps->list[j - 1] = ps->list[j];
		}
		
		ps->size--;
	}
	
	else
		printf("表中无数据!\n");
}

int ListGetNumber(sql *ps, int i, DateType *x)
{
	assert(ListCHeck_i(ps, i));
	
	*x = ps->list[i];
	
	printf("已取第 %d(%d) 个数据 : %d \n", i, i + 1, *x);
	
	return 1;
}

int main()
{
	int x, num;
	sql L;
	
	ListInit(&L);
	
	ListInsert(&L, 0, 1);
	ListInsert(&L, 1, 2);
	ListInsert(&L, 2, 3);
	ListInsert(&L, 3, 3);
	
	ListDelete(&L, 3, &x);
	
	ListInsert(&L, 3, 4);
	ListGetNumber(&L, 3, &num);
	
	printf("\n\n-----------------\n");
	printf("表情况: %s \n当前已有 %d 个元素\n-----------------\n\n", 
		 ListEmpty(&L) ? "已满" : "空闲", ListLength(&L));
	
	getchar();
}