#include "SList.h"

/*线性表优缺对比：
一、顺序表
优点：
1.支持随机访问。

缺陷：
1.空间不够了，需要扩容，扩容是有消耗的。
2.头部或者中间位置插入删除，需要挪动数据，而挪动数据也是有一定消耗。
3.避免频繁扩容，一次一般都是按倍数去括（2倍），可能存在一定空间浪费。


二、链表
优点：
1.按需申请空间，不用了就释放空间（更合理的使用空间）。
2.头部中间插入删除数据，不需要挪动数据
3.不存在空间浪费。

缺点：
1.每存一个数据，都要存一个指针去链接后面的数据节点
2.不支持随机访问（用下标直接访问第 i 个）。

逻辑结构：想象出来的，更加形象，方便理解。
物理结构：在内存中实实在在如何存储的。
*/

void TestSList1()
{
	SLTNode *pList = NULL;
	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);

	SListPrint(pList);

	SListPushFront(&pList, 1);
	SListPushFront(&pList, 2);
	SListPushFront(&pList, 3);
	SListPushFront(&pList, 4);

	SListPrint(pList);
}

void TestSList2()
{
	SLTNode *pList = NULL;
	SListPushFront(&pList, 1);
	SListPushFront(&pList, 2);
	SListPushFront(&pList, 3);
	SListPushFront(&pList, 4);

	SListPrint(pList);

	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPopFront(&pList);

	SListPrint(pList);

}

void TestSList3()
{
	SLTNode *pList = NULL;
	SListPushFront(&pList, 1);
	SListPushFront(&pList, 2);
	SListPushFront(&pList, 3);
	SListPushFront(&pList, 2);
	SListPushFront(&pList, 4);
	SListPushFront(&pList, 2);
	SListPushFront(&pList, 1);
	SListPushFront(&pList, 2);
	SListPushFront(&pList, 2);
	SListPushFront(&pList, 4);
	SListPushFront(&pList, 2);
	SListPrint(pList);

	SLTNode *pos = SListFind(pList, 2);
	/*SLTNode *pos2 = NULL;
	if (pos != NULL)
	{
		pos2 = SListFind(pos->next, 2);
	}*/
	int i = 1;
	while (pos)
	{
		printf("%d个pos节点:%p->%d\n", i++, pos, pos->data);
		pos = SListFind(pos->next, 2);
	}

	// 修改  3 -> 30
	pos = SListFind(pList, 3);
	if (pos)
	{
		pos->data = 30;
	}
	SListPrint(pList);
}

void TestSList4()
{
	SLTNode *pList = NULL;
	SListPushFront(&pList, 1);
	SListPushFront(&pList, 2);
	SListPushFront(&pList, 3);
	SListPushFront(&pList, 4);

	SListPrint(pList);

	SLTNode *pos = SListFind(pList, 3);
	if (pos)
	{
		SListInsert(&pList, pos, 30);
	}
	SListPrint(pList);

	pos = SListFind(pList, 1);
	if (pos)
	{
		SListInsert(&pList, pos, 100);
	}

	pos = SListFind(pList, 4);
	if (pos)
	{
		SListInsert(&pList, pos, 50);
	}
	SListPrint(pList);
}

int main()
{
	//TestSList1();
	//TestSList2();
	//TestSList3();
	TestSList4();
	return 0;
}


