#include "Stack.h"

void test_Stack_1()
{
	ST st;
	StackInit(&st);

	for(int i = 1; i < 4; i++)
		StackPush(&st, i);

	/*for (int i = 1; i < 2; i++)
		StackPop(&st);*/

	//printf("%d\n", StackTop(&st));

	StackPush(&st, 9);
	StackPush(&st, 5);
	StackPush(&st, 7);

	StackPrint(&st);

	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}

	StackDestroy(&st);
}

int main()
{
	test_Stack_1();
	return 0;
}