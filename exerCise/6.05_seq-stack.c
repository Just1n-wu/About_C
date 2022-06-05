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
	printf("初始化...\n");
	
	ps->top = 0;  // 初始化栈顶下标值
	
	if(ps->top == 0)
		printf("初始化完成!\n");
}

bool StackEmpty(SeqStack *ps)
{
	// 非空返回 1 , 空返回 0
	
	// return ps->top <= 0 ? 0 : 1;
	
	return ps->top > 0;
}

int StackPush(SeqStack *ps, DataType x)
{
	// 入栈成功返回 1
	// 入栈失败返回 0
	
	if(ps->top >= MaxStackSize)
	{
		printf("栈中数据已满无法入栈！\n");
		return 0;
	}
		
	else
	{
		printf("入栈操作(栈顶%d): %d <- 入栈 \n", ps->top, x);
		
		ps->stack[ps->top] = x;
		ps->top ++;
		return 1;
	}
}

int StackPop(SeqStack *ps, DataType *x)
{
	// 出栈成功返回 1
	// 出栈失败返回 0
	// 栈顶出栈数据由 x 带回
	
	if(StackEmpty(ps) == 0)
	{
		printf("栈中数据已空无法出栈!\n");
		return 0;
	}
	
	else 
	{
		printf("出栈操作(栈顶%d): %d -> 出栈 \n", ps->top - 1, ps->stack[ps->top - 1]);
		
		// 一定要先 top - 1, 因为进栈操作时 top 已指向下一个位置
		ps->top --;
		*x = ps->stack[ps->top];
		return 1;
	}
	
}

int StackGetTop(SeqStack *ps, DataType *x)
{
	// 与出栈类似
	
	if(StackEmpty(ps) == 0)
	{
		printf("栈中数据已空无法出栈!\n");
		return 0;
	}
	
	else 
	{
		printf("取栈顶(%d) 操作: %d <-> 栈顶 \n", ps->top - 1, ps->stack[ps->top - 1]);
		
		// 一定要 top - 1, 因为进栈操作时 top 已指向下一个位置
		
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
	
	printf("当前栈顶数据元素为: %d\n",  x);
	
	printf("依次出栈的数据元素序列如下: \n");
	while(StackEmpty(&S))
	{
		StackPop(&S, &x);   // 出栈
		arrPop[size++] = x;
		count ++;
		
		//printf("%d ", x);   // 显示数据元素
	}
	
	for(; size > 0; size--)
		printf("%d ", arrPop[count - size]);
	
	return 0;
}