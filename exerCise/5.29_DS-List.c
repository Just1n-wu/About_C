#include<stdio.h>
#include<stdlib.h>

typedef int DataType;
typedef struct Node
{
	DataType data;       // 数据域
	struct Node *next;   // 指针域
	
}SLNode;

void ListInit(SLNode **head)
{
	printf("初始化...\n");
	
	*head = (SLNode *)malloc(sizeof(SLNode));   // 申请头节点
	(*head)->next = NULL;                       // 置介绍标记
	
	printf("已申请带头单链！\n");
 
}

int ListLength(SLNode *head)
{
	SLNode *phead = head;   // 有的卷面会申请叫 cur , 道理一样，注意区分
	int size = 0;
	
	// 找最后一个结点
	while(phead->next != NULL)
	{
		phead = phead->next;  // 指向它的直接后继结点
		size ++;
	}
	
	return size;
}

SLNode *BuyListNode(DataType x)
{
	// 创建新节点
	SLNode *newnode = (SLNode *)malloc(sizeof(SLNode));
	if (newnode == NULL)
	{
		printf("申请失败！");
		exit(-1);
	}

	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}

// 带头单链 head 的第 i （0 ≤ i ≤ size） 个结点
// 前 插入一个存放数据元素 x 的结点
int ListInsert(SLNode *head, int i, DataType x)
{
	printf("插入数据 -> %d\n", x);
	
	SLNode *p, *q;
	int j = -1;
	
	p = head;
	
	while(p->next != NULL && j < i - 1)
	{
		// 最终让 p 指向第 i-1 个结点
		p = p->next;
		j++;
	}
	
	if(j != i - 1)
	{
		printf("插入位置有误!\n");
		return 0;
	}
	
	// 申请一个存放数据元素 x 的结点
	q = (SLNode *)malloc(sizeof(SLNode));
	q->data = x;
	
	// 与已有的单链形成联系
	q->next = p->next;   // 将原有头节点中后继结点地址存放在新结点的指针域
	p->next = q;        // 头结点指向新结点的地址，使其关联
	
	return 1;
}

// 删除带头单链 head 的第 i （0 ≤ i ≤ size - 1） 个结点
// 比记录 x 
int ListDelete(SLNode *head, int i, DataType *x)
{
	SLNode *p, *s;
	int j;
	
	p = head;
	j = -1;
	
	while(p->next != NULL 
	&& p->next->next != NULL && j < i - 1)
	{
		// 最终让 p 指向要第 i-1 个结点, 删除 i 结点
		p = p->next;
		j++;
	}
	
	if(j != i - 1)
	{
		printf("输入位置有误!\n");
		return 0;
	}
	
	s = p->next;  // 记录要删除结点， p 为 删除结点的前驱
	*x = s->data;
	
	printf("删除第 %d(%d) 个数据 -> %d \n", i, i + 1, *x);
	
	p->next = p->next->next; // 将删除结点中的下一个后继的地址与当前 p 关联
	free(s);  // 释放 
	
	return 1;
}

// 与删除类似
int ListGetNumber(SLNode *head, int i, DataType *x)
{
	SLNode *p;
	int j;
	
	p = head;
	j = -1;
	
	while(p->next != NULL && j < i)
	{
		p = p->next;
		j ++;
	}
	
	if(j != i)
	{
		printf("位置参数有误\n");
		return 0;
	}
	
	*x = p->data;
	return 1;
}

void ListDestroy(SLNode **head)
{
	printf("销毁单链...");
	
	SLNode *p, *p1;
	
	p = *head;
	
	while(p->next != NULL)
	{
		p1 = p;
		p = p->next;
		free(p1);
	}
	
	*head = NULL;
	
	printf("销毁完成！\n");
}

int main()
{
	SLNode *head;   // 定义一个头指针变量
	
	int x;
	
	ListInit(&head);
	
	// 插入
	for(int i = 0; i < 10; i++)
		ListInsert(head, i, i + 1);
	
	// 删除数据元素 11
	ListDelete(head, 4, &x);
	
	// 显示当前数据
	for(int i = 0; i < ListLength(head); i++)
	{
		ListGetNumber(head, i, &x);   // 取元素
		printf("%d ", x);
	}
	
	
	printf("\n当前带头单链中存在 %d 个结点\n", ListLength(head));
	
	ListDestroy(&head);  // 销毁
}

//  5.29_DS-SList.c
//  单链带头基本功能
//
//  Created by Just1n on 22/29/5.
//  Copyright (c) 2022年 . All rights reserved.