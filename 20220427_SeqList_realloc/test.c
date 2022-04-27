#include "SeqList.h"

void TestSeqList()
{
	SL s1;

	SeqListInit(&s1);

	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);

	SeqListPrint(&s1);

	SeqListPopBack(&s1);
	SeqListPopBack(&s1);

	SeqListPrint(&s1);


	SeqListDestory(&s1);
}

void TestSeqList_2()
{
	SL s1;

	SeqListInit(&s1);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);
	SeqListPrint(&s1);
	
	SeqListPushFront(&s1, 10);
	SeqListPushFront(&s1, 20);
	SeqListPushFront(&s1, 30);
	SeqListPushFront(&s1, 40);
	SeqListPrint(&s1);

	SeqListPopFront(&s1);
	SeqListPopFront(&s1);



	SeqListPrint(&s1);
}


void TestSeqList_3()
{
	SL s1;

	SeqListInit(&s1);

	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPrint(&s1);

	SeqListInsert(&s1, 2, 300);
	SeqListPrint(&s1);

	int pos = SeqListFind(&s1, 4);
	if (pos != -1)
	{
		SeqListInsert(&s1, pos, 40);
	}

	SeqListPrint(&s1);

	SeqListErase(&s1, 1);
	SeqListPrint(&s1);

	SeqListDestory(&s1);

}

void TestMenu()
{
	printf("*******************************\n");
	printf("��ѡ�����Ĳ���:��      ********\n");
	printf("***1. ͷ  ��\t   2. ͷ  ɾ***\n");
	printf("***3. β  ��\t   4. β  ɾ***\n");
	printf("***5. ָ����\t   6. ָ��ɾ***\n");
	printf("***8. ��  ��\t   7. ��  ӡ***\n");
	printf("******    -1. ��   ��    ******\n");
	printf("*******************************\n");

}


// ��д�굥Ԫ����û�����������ɲ˵�����������ԣ�
void Selection()  // ˣ�� ������ û��˼
{
	SL L;
	SeqListInit(&L);
	int input = 0, x;
	while (input != -1)
	{
		TestMenu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��������Ҫͷ��ģ������� -1 ����������-> ");
			scanf("%d", &x);
			while (x != -1)
			{
				SeqListPushFront(&L, x);
				scanf("%d", &x);
			}
			break;

		case 2:
			SeqListPopFront(&L);
			break;

		case 3:
			printf("��������Ҫβ��ģ������� -1 ����������-> ");
			scanf("%d", &x);
			while (x != -1)
			{
				SeqListPushBack(&L, x);
				scanf("%d", &x);
			}
			break;

		case 4:
			SeqListPopBack(&L);
			break;

		case 5:
			break;

		case 6:
			break;

		case 7:
			SeqListPrint(&L);
			break;

		case 8: 
			break;

		default:
			printf("�޴�ѡ����������룺\n");
			break;
		}
	}

	SeqListDestory(&L);
	
}

int main()
{
	//TestSeqList();
	//TestSeqList_2();

	//TestSeqList_3();

	Selection();

	return 0;
}