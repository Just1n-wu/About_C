#include<stdio.h>
#include<stdbool.h>

#define MaxStackSize 10

typedef int DataType;
typedef struct Stack
{
	DataType stack[MaxStackSize];
	int top;   
} SeqStack;

void StackInit(SeqStack *ps)
{
	printf("��ʼ��...\n");
	
	ps->top = 0;  // ��ʼ��ջ���±�ֵ
	
	if(ps->top == 0)
		printf("��ʼ�����!\n");
}

bool StackEmpty(SeqStack *ps)
{
	// �ǿշ��� 1 , �շ��� 0
	
	// return ps->top <= 0 ? 0 : 1;
	
	return ps->top > 0;
}

int StackPush(SeqStack *ps, DataType x)
{
	// ��ջ�ɹ����� 1
	// ��ջʧ�ܷ��� 0
	
	if(ps->top >= MaxStackSize)
	{
		printf("ջ�����������޷���ջ��\n");
		return 0;
	}
		
	else
	{
		printf("��ջ����(ջ��%d): %d <- ��ջ \n", ps->top, x);
		
		ps->stack[ps->top] = x;
		ps->top ++;
		return 1;
	}
}

int StackPop(SeqStack *ps, DataType *x)
{
	// ��ջ�ɹ����� 1
	// ��ջʧ�ܷ��� 0
	// ջ����ջ������ x ����
	
	if(StackEmpty(ps) == 0)
	{
		printf("ջ�������ѿ��޷���ջ!\n");
		return 0;
	}
	
	else 
	{
		printf("��ջ����(ջ��%d): %d -> ��ջ \n", ps->top - 1, ps->stack[ps->top - 1]);
		
		// һ��Ҫ�� top - 1, ��Ϊ��ջ����ʱ top ��ָ����һ��λ��
		ps->top --;
		*x = ps->stack[ps->top];
		return 1;
	}
	
}

int StackGetTop(SeqStack *ps, DataType *x)
{
	// ���ջ����
	
	if(StackEmpty(ps) == 0)
	{
		printf("ջ�������ѿ��޷���ջ!\n");
		return 0;
	}
	
	else 
	{
		printf("ȡջ��(%d) ����: %d <-> ջ�� \n", ps->top - 1, ps->stack[ps->top - 1]);
		
		// һ��Ҫ top - 1, ��Ϊ��ջ����ʱ top ��ָ����һ��λ��
		
		*x = ps->stack[ps->top - 1];
		
		return 1;
	}
}

int main()
{
	SeqStack S;
	int x, size = 0, count = 0;
	int arrPop[MaxStackSize];
	
	StackInit(&S);
	
	for(int i = 0; i < 10; i++)
		StackPush(&S, i + 1);
	
	StackGetTop(&S, &x);
	
	printf("��ǰջ������Ԫ��Ϊ: %d\n",  x);
	
	printf("���γ�ջ������Ԫ����������: \n");
	while(StackEmpty(&S))
	{
		StackPop(&S, &x);   // ��ջ
		arrPop[size++] = x;
		count ++;
		
		//printf("%d ", x);   // ��ʾ����Ԫ��
	}
	
	for(; size > 0; size--)
		printf("%d ", arrPop[count - size]);
	
	return 0;
}