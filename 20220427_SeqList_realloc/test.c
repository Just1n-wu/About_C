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
	printf("请选择您的操作:》      ********\n");
	printf("***1. 头  插\t   2. 头  删***\n");
	printf("***3. 尾  插\t   4. 尾  删***\n");
	printf("***5. 指定插\t   6. 指定删***\n");
	printf("***8. 查  找\t   7. 打  印***\n");
	printf("******    -1. 退   出    ******\n");
	printf("*******************************\n");

}


// 先写完单元测试没有问题后，再完成菜单（不方便调试）
void Selection()  // 耍猴 无意义 没意思
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
			printf("请输入你要头插的（以输入 -1 结束）数据-> ");
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
			printf("请输入你要尾插的（以输入 -1 结束）数据-> ");
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
			printf("无此选项，请重新输入：\n");
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