#include "Stack.h"

void StackPrint(ST *ps)
{
	printf("栈中数据：");

	assert(ps);

	// 访问栈中数据, 未出栈
	for (int i = 0; i < ps->top; i++)
		printf("%d ", ps->a[i]);

	putchar('\n');
}

void StackInit(ST *ps)
{
	assert(ps);

	printf("初始化..\n");

	ps->a = NULL;

	// top 也可以初始化为 -1, 看个人选择
	// top = 0 意味着 top 指向栈顶数据的下一个   先放再++
	// top = -1 意味着 top 指向栈顶数据         先++再放
	ps->top = ps->capacity = 0;
}

void StackDestroy(ST *ps)
{
	printf("** 销毁 **\n");

	assert(ps);

	free(ps->a);

	ps->a = NULL;
	ps->capacity = ps->top = 0;
}

void StackPush(ST *ps, STDataType x)
{
	printf("**  %d <- 压栈 **\n", x);

	assert(ps);

	// 扩容
	// 1. 第一次初始后的空间  2. 空间满了之后的空间
	if (ps->top == ps->capacity)
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType *tmp = realloc(ps->a, sizeof(STDataType) * newCapacity);

		assert(tmp);  // 判断申请的空间是否为空  -->> if(tmp == NULL)

		ps->a = tmp;
		ps->capacity = newCapacity;
	}

	ps->a[ps->top] = x;
	ps->top++;
}

void StackPop(ST *ps)
{
	printf("  -->> 出栈 \n");

	assert(ps);

	assert(!StackEmpty(ps));  // if(ps->top > 0) 判断栈中是否有数据可删

	ps->top--;
}

STDataType StackTop(ST *ps)
{
	printf("栈顶 ->  ");

	assert(ps);

	assert(!StackEmpty(ps));   // assert(ps->top > 0);   if(ps->top > 0) 判断栈中是否还有数据

	return ps->a[ps->top - 1];
}

int StackSize(ST *ps)
{
	assert(ps);

	return ps->top; // 初始 top 指向栈顶数据的下一个 
}

bool StackEmpty(ST *ps)
{
	// true : 为空
	// false : 不为空
	assert(ps);

	return ps->top == 0;   // return ps->top == 0 ? true : false;
}