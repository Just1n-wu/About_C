#include "SeqList.h"


// 打印
void SeqListPrint(SL *ps)
{
	for (int i = 0; i < ps->size; i++)
		printf("%d ", ps->a[i]);
	putchar('\n');
}


// 初始化
void SeqListInit(SL *ps)   // SeqListInsert
{
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}


// 扩容
void SeqListCheckCapacity(SL *ps)
{
	// 如果没有空间或者空间不足，扩容！
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;    // 2 倍扩容
		SLDataType *tmp = (SLDataType *)
			// realloc 与 （malloc）相比： 给的不应该是数据个数，应该是字节数
			realloc(ps->a, sizeof(SLDataType) * newcapacity);
		if (tmp == NULL)
		{
			printf("REALLOC IS FAIL !!!");
			exit(-1);
		}

		ps->a = tmp;
		ps->capacity = newcapacity;
	}

}


// 尾插
void SeqListPushBack(SL *ps, SLDataType x)
{ 
	// 1. 表中没有空间
	// 2. 空间不足，需要扩容
	// 3. 空间足够，直接插入

	SeqListCheckCapacity(ps);
	
	ps->a[ps->size] = x;
	ps->size++;

	// 等价于 ->   SeqListInsert(ps, ps->size, x);

}


// 尾删
void SeqListPopBack(SL *ps)
{

	/*if (ps->size > 0)   
	{
	 // ps->a[ps->size - 1] = 0;   可以不写
		ps->size--;
	}*/

	assert(ps->size > 0);  // 断言直接报错： 条件为假，程序中止。
	ps->size--;

	// 等价于 ->   SeqListErase(ps, ps->size - 1);
}


// 头插
void SeqListPushFront(SL *ps, SLDataType x)
{
	SeqListCheckCapacity(ps);

	// 挪动数据：后移
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}

	ps->a[0] = x;
	ps->size++;

	// 等价于 ->   SeqListInsert(ps, 0, x);
}


// 头删
void SeqListPopFront(SL *ps)
{
	assert(ps->size > 0);  // 与尾删一样，有数据才删除。

	// 数据前移
	int begin = 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		begin++;
	}
	
	ps->size--;

	// 等价于 ->   SeqListErase(ps, 0);
}


// 查找，返回 x 位置的下标， 没有返回 -1
int SeqListFind(SL *ps, SLDataType x)
{
	for (int index = 0; index < ps->size; index++)
	{
		if (ps->a[index] == x)
		{
			return index;
		}
	}

	return -1;
}


// 指定插入
void SeqListInsert(SL *ps, int pos, SLDataType x)
{
	/*if (pos > ps->size || pos < 0)
	{
		printf("POS invalid !!\n");
		return;
	}*/

	// 比较直接
	assert(pos >= 0 && pos <= ps->size);   // 条件为假，程序直接中止。为真，执行下一句。

	SeqListCheckCapacity(ps);

	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}

	ps->a[pos] = x;
	ps->size++;

}


// 指定删除
void SeqListErase(SL *ps, int pos)
{
	assert(pos >= 0 && pos < ps->size);  // 不能删除 size 当前位置数据，此时没有数据

	int begin = pos + 1;
	while (begin < ps->size - 1)
	{
		ps->a[begin - 1] = ps->a[begin];
		begin++;
	}

	ps->size--;
}


// 空间销毁，防止内存泄露
void SeqListDestory(SL *ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}