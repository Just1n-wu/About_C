#include "SList.h"

SLTNode *BuyListNode(SLTDateType x)
{
	// 创建新节点
	SLTNode *newnode = (SLTNode *)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		printf("申请失败！");
		exit(-1);
	}

	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}

void SListPrint(SLTNode *phead)
{
	SLTNode *cur = phead;  // 类似于游标
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;    // 指向下一个节点的地址
	}

	printf("NULL\n");
}

void SListPushBack(SLTNode **pphead, SLTDateType x)
{
	SLTNode *newnode = BuyListNode(x);  // 创建新节点

	if (*pphead == NULL)  // 表中没有节点则无需找到尾节点，直接将新节点赋给 头节点(phead)
	{
		*pphead = newnode;
	}
	else
	{
		// 找到尾节点
		SLTNode *tail = *pphead;
		while (tail->next != NULL)
			tail = tail->next;

		tail->next = newnode;
	}

	/* #注意： 由于需要改变的是 *pList，所以需要用二级指针来接收,
			如果传一级指针只是一份临时拷贝，不会修改其值。
	   比如：实参是 int 要改变实参，要传 int*  函数里面解引用操作去改变。
	   总结：通过指针去改变指向空间的内容，传一级指针；改变指针的指向，传二级指针。  */
}

void SListPushFront(SLTNode **pphead, SLTDateType x)
{
	SLTNode *newnode = BuyListNode(x);

	newnode->next = *pphead;
	*pphead = newnode;
}

void SListPopBack(SLTNode **pphead)
{
	if (*pphead == NULL) // assert(*pphead != NULL)
	{
		printf("IS NULL！！");
		return;
	}

	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}

	else
	{
		SLTNode *prev = NULL;
		SLTNode *tail = *pphead;

		//while (tail->next->next)
		//	tail = tail->next;

		//free(tail->next);  // 删除最后一个节点
		//tail->next = NULL;

		 // 找尾
		//while (tail->next != NULL)
		while (tail->next)  // 类似隐式转换， 0 就是假，非0 就是真
		{
			prev = tail;
			tail = tail->next;
		}

		free(tail);  // 删除最后一个节点
		tail = NULL;

		prev->next = NULL; // #注意: 要记录上一个节点 否则会存在野指针，也会导致上一个节点依旧指向这个节点，存在非法访问。
	}
}

void SListPopFront(SLTNode **pphead)
{
	if (*pphead == NULL) 
	{
		printf("IS NULL！！");
		return;
	}
	// assert(*pphead);

	else
	{
		SLTNode *head = (*pphead)->next;
		free(*pphead);
		*pphead = head;
	}
}

SLTNode *SListFind(SLTNode *phead, SLTDateType x)
{
	SLTNode *cur = phead;
	while (cur)
	{
		if (cur->data == x)
			return cur;
		else
			cur = cur->next;
	}

	return NULL;
}

void SListInsert(SLTNode **pphead, SLTNode *pos, SLTDateType x)
{
	SLTNode *newnode = BuyListNode(x);

	if (*pphead == pos)  // 意为头插
	{
		newnode->next = *pphead;
		*pphead = newnode;
	}

	else
	{
		// 找到 pos 位置的前一个位置
		SLTNode *posPrev = *pphead;
		while (posPrev->next != pos)
		{
			posPrev = posPrev->next;
		}

		posPrev->next = newnode;
		newnode->next = pos;
	}
}

void SListInsertAfter(SLTNode *pos, SLTDateType x)
{
	SLTNode *newnode = BuyListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SListErase(SLTNode **pphead, SLTNode *pos)
{
	if (*pphead == pos)
	{
		/**pphead = pos->next;
		free(pos);*/

		SListPopFront(pphead);
	}

	else
	{
		SLTNode *prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}

		prev->next = pos->next;
		free(pos);
		// pos = NULL;
	}
}

void SListEraseAfter(SLTNode *pos)
{
	assert(pos->next);

	SLTNode *next = pos->next;
	pos->next = next->next;
	free(next);
	// next = NULL;
}

void SListDestroy(SLTNode **pphead)
{
	assert(pphead);

	//free(*pphead);  只会释放头节点

	SLTNode *cur = *pphead;
	while (cur)
	{
		SLTNode *next = cur->next;
		free(cur);

		cur = next;
	}

	*pphead = NULL;
}
