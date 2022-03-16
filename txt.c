#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
	int data;             // 数据域。
	struct node *next;    // 指针域。
};

// 创建指定节点数的链表，并返回头节点地址。
struct node *create(int count)
{
	struct node *head = malloc(sizeof(struct node));   //  使用 malloc 建立一个 node 的堆内存大小
	if (head == NULL)   // (!head)
	{
		return NULL;
	}

	head->data = 1;
	head->next = NULL;

	struct node *tail = head;    // 游标  先指向 head，然后每个结点创建之后 tail 指向后面每个结点 p，这样可以保证 tail 可以始终保持为最后一个结点
	for (int i = 0; i < count; i++)
	{
		struct node *p;     
		do
			p = malloc(sizeof(struct node));    // 不是 struct node *  它是一个地址值   需要一个结点类型，而不是结点的指针类型
		while (p == NULL);

		p->data = 0;
		p->next = NULL;

		tail->next = p;    // (*tail).next = p;  关联下一个结点
		tail = p;         // tail 自身的值更改到 p 上，从原本指向 head 到指向 p
	} 

	return head;
}

void visit(struct node *node)
{
	printf("%d ", node->data);
}

void printNewLine(void)
{
	putchar('\n');
}

// 获取链表的长度。
int getLength(struct node head)
{
	int count = 1;
	struct node *p = head.next;
	while (p->next != NULL)
	{
		count++;
		p = p->next;
	}

	return count;
}

// 将某个节点追加到指定链表里
void appen(struct node *list, struct node *pNode)
{
	struct node *p = list;
	while (p->next != NULL)
	{
		p = p->next;
	}

	p->next = pNode;
	pNode->next = NULL;
}

// 遍历列表
void traversea(struct node *list, void (*visitor)(struct node *), void(*onEnding)(void))
{
	struct node *p = list;
	while (p->next != NULL)
	{
		(*visitor)(p);

		p = p->next;
	}

	(*onEnding)();
}

// 取出指定索引（下标）的节点信息，返回当前要查找节点的地址。
struct node *getIndexOf(struct node *list, int index)
{
	if (index == 0)
		return list;   // 相当于 head

	struct node *p = list;  // 游标 指向头地址
		for (int i = 0; i < index; i++)
		{
			p = p->next;
		}

		return p;
}

// 插入某个节点到指定链表里
void insert(struct node *list, int index, struct node *pNode)
{
	struct node *p = getIndexOf(list, index);
	struct node *q = p->next;
	p->next = pNode;
	pNode->next = q;
}

// 删除最后一个节点
struct node *removeTail(struct node *list)
{
	int length = getLength(*list);
	struct node *pTail = getIndexOf(list, length - 2);
	struct ndde *returnNode = pTail->next;

	pTail->next = NULL;
	return returnNode;
}

// 删除中间某个节点，由索引指定
struct node *removeAt(struct node *list, int index)
{
	struct node *p, *q, *r;
	q = getIndexOf(list, index - 1);
	p = q->next;
	r = q->next->next;  // r = p->next

	q->next = r;
	return p;
}

// 释放链表使用的空间内存。
void dispose(struct node *list)
{
	struct node *p = list, *q = p;
	while (p->next != NULL)   // (p->next)
	{
		p = p->next;
		if(q != NULL)
			free(q);
		q = q->next;
	}
}

int main(void)
{	
	struct node *pHead = create(5);
	if (pHead == NULL)
	{
		printf("Linked List Creation Failed。");
		return 0;
	}

	int length = getLength(*pHead);
	printf("%d\n", length);

	traversea(pHead, &visit, &printNewLine);

	getIndexOf(pHead, 3)->data = 2;

	traversea(pHead, &visit, &printNewLine);

}