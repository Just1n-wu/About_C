#include "Stack.h"

void StackPrint(ST *ps)
{
	printf("ջ�����ݣ�");

	assert(ps);

	// ����ջ������, δ��ջ
	for (int i = 0; i < ps->top; i++)
		printf("%d ", ps->a[i]);

	putchar('\n');
}

void StackInit(ST *ps)
{
	assert(ps);

	printf("��ʼ��..\n");

	ps->a = NULL;

	// top Ҳ���Գ�ʼ��Ϊ -1, ������ѡ��
	// top = 0 ��ζ�� top ָ��ջ�����ݵ���һ��   �ȷ���++
	// top = -1 ��ζ�� top ָ��ջ������         ��++�ٷ�
	ps->top = ps->capacity = 0;
}

void StackDestroy(ST *ps)
{
	printf("** ���� **\n");

	assert(ps);

	free(ps->a);

	ps->a = NULL;
	ps->capacity = ps->top = 0;
}

void StackPush(ST *ps, STDataType x)
{
	printf("**  %d <- ѹջ **\n", x);

	assert(ps);

	// ����
	// 1. ��һ�γ�ʼ��Ŀռ�  2. �ռ�����֮��Ŀռ�
	if (ps->top == ps->capacity)
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType *tmp = realloc(ps->a, sizeof(STDataType) * newCapacity);

		assert(tmp);  // �ж�����Ŀռ��Ƿ�Ϊ��  -->> if(tmp == NULL)

		ps->a = tmp;
		ps->capacity = newCapacity;
	}

	ps->a[ps->top] = x;
	ps->top++;
}

void StackPop(ST *ps)
{
	printf("  -->> ��ջ \n");

	assert(ps);

	assert(!StackEmpty(ps));  // if(ps->top > 0) �ж�ջ���Ƿ������ݿ�ɾ

	ps->top--;
}

STDataType StackTop(ST *ps)
{
	printf("ջ�� ->  ");

	assert(ps);

	assert(!StackEmpty(ps));   // assert(ps->top > 0);   if(ps->top > 0) �ж�ջ���Ƿ�������

	return ps->a[ps->top - 1];
}

int StackSize(ST *ps)
{
	assert(ps);

	return ps->top; // ��ʼ top ָ��ջ�����ݵ���һ�� 
}

bool StackEmpty(ST *ps)
{
	// true : Ϊ��
	// false : ��Ϊ��
	assert(ps);

	return ps->top == 0;   // return ps->top == 0 ? true : false;
}