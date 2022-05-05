#include "SList.h"

/*���Ա���ȱ�Աȣ�
һ��˳���
�ŵ㣺
1.֧��������ʡ�

ȱ�ݣ�
1.�ռ䲻���ˣ���Ҫ���ݣ������������ĵġ�
2.ͷ�������м�λ�ò���ɾ������ҪŲ�����ݣ���Ų������Ҳ����һ�����ġ�
3.����Ƶ�����ݣ�һ��һ�㶼�ǰ�����ȥ����2���������ܴ���һ���ռ��˷ѡ�


��������
�ŵ㣺
1.��������ռ䣬�����˾��ͷſռ䣨�������ʹ�ÿռ䣩��
2.ͷ���м����ɾ�����ݣ�����ҪŲ������
3.�����ڿռ��˷ѡ�

ȱ�㣺
1.ÿ��һ�����ݣ���Ҫ��һ��ָ��ȥ���Ӻ�������ݽڵ�
2.��֧��������ʣ����±�ֱ�ӷ��ʵ� i ������

�߼��ṹ����������ģ��������󣬷�����⡣
����ṹ�����ڴ���ʵʵ������δ洢�ġ�
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
		printf("%d��pos�ڵ�:%p->%d\n", i++, pos, pos->data);
		pos = SListFind(pos->next, 2);
	}

	// �޸�  3 -> 30
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


