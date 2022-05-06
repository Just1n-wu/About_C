#include "List.h"

LTNode *ListInit()
{
	// 哨兵位的头节点
	LTNode *phead = (LTNode *)malloc(sizeof(LTNode));    // 作为哨兵位的头节点, 不存储有效数据
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

LTNode *BuyListNode(LTDateType x)
{
	LTNode *newnode = (LTNode *)malloc(sizeof(LTNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;

	return newnode;
}

void ListDestroy(LTNode *phead)
{
	assert(phead);

	LTNode *cur = phead->next;
	while (cur != phead)
	{
		LTNode *next = cur->next;
		free(cur);
		cur = next;
	}

	free(phead);
	// phead = NULL;
}

void ListPrint(LTNode *phead)
{
	assert(phead);

	LTNode *cur = phead->next;
	while (cur != phead)
	{
		printf("%d <--> ", cur->data);
		cur = cur->next;
	}

	if (phead->next != phead)
		printf("%d", cur->next->data);
	else
		printf("NULL");
	putchar('\n');
}

void ListPushBack(LTNode *phead, LTDateType x)
{
	assert(phead);

	LTNode *tail = phead->prev;
	LTNode *newnode = BuyListNode(x);

	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;

	// ListInsert(phead, x);
}

void ListPopBack(LTNode *phead)
{
	assert(phead);
	assert(phead->next != phead);   // 当头指向自己的时候，链表为空，表中无数据已无法删除

	LTNode *tail = phead->prev;
	LTNode *tailPrev = tail->prev;
	free(tail);

	tailPrev->next = phead;
	phead->prev = tailPrev;

	// ListErase(phead->prev);
}

void ListPushFront(LTNode *phead, LTDateType x)
{
	assert(phead);

	LTNode *newnode = BuyListNode(x);
	LTNode *next = phead->next;

	phead->next = newnode;
	newnode->prev = phead;

	newnode->next = next;
	next->prev = newnode;

	// ListInsert(phead->next, x);


}

void ListPopFront(LTNode *phead)
{
	assert(phead);
	// 链表为空，拒绝头删
	assert(phead->next != phead);

	LTNode *next = phead->next;
	LTNode *nextNext = next->next;

	phead->next = nextNext;
	nextNext->prev = phead;

	free(next);

	// ListErase(phead->next);
}

LTNode *ListFind(LTNode *phead, LTDateType x)
{
	assert(phead);

	LTNode *cur = phead->next;
	while (cur != phead)
	{
		if (cur->data = x)
		{
			return cur;
		}

		cur = cur->next;
	}

	return NULL;
}

// pos 位置之前插入, 可以复用代替头插尾插
void ListInsert(LTNode *pos, LTDateType x)
{
	assert(pos);

	LTNode* posPrev = pos->prev;
	LTNode* newnode = BuyListNode(x);

	// posPrev newnode pos
	posPrev->next = newnode;
	newnode->prev = posPrev;
	newnode->next = pos;
	pos->prev = newnode;
}

// 删除 pos 位置
void ListErase(LTNode *pos)
{
	assert(pos);

	LTNode *posPrev = pos->prev;
	LTNode *posNext = pos->next;

	posPrev->next = posNext;
	posNext->prev = posPrev;

	free(pos);
	// pos = NULL;
}
