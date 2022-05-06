#include "List.h"

void TestList1()
{
	LTNode *pList = ListInit();

	for (int i = 1; i < 5;)
	{
		//ListPushBack(pList, i++);
		ListPushFront(pList, i++);
	}

	ListPrint(pList);

	ListPopBack(pList);
	ListPopFront(pList);
	
	ListPrint(pList);

	ListDestroy(pList);
	pList = NULL;
}

int main()
{
	TestList1();

	return 0;
}