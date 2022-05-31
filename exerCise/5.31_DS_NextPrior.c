#include<stdio.h>
#include<stdlib.h>

typedef int DataType;

typedef struct Node
{
	DataType data;     // 数据域
	struct Node *next;  // 后继结点指针域
	struct Node *prior; // 前驱结点指针域
} DLNode;

void ListInit(DLNode **head)
{
	printf("双链初始化(带头循环双链)...\n");
	
	*head = (DLNode *)malloc(sizeof(DLNode));  // 开辟头结点的内存空间
	(*head)->prior = *head;   // 构成前驱指针循环链表
	(*head)->next = *head;    // 构成后继指针循环链表
	
	if(*head != NULL)
	{
		printf("带头循环双链已生成!\n");
	}
}

// 在带头结点的双向循环链表 head 的第 i (0 ≤ i ≤ size) 个结点前
// 插入一个数据元素 x
int ListInsert(DLNode *head, int i, DataType x)
{
	printf("在第 %d(%d) 个位置插入数据 -> %d\n", i, i + 1, x);
	
	DLNode *p, *s;
	int j = 0;
	
	p = head->next;
	
	// 寻找第 i 个结点
	while(p != head && j < i)  // 最后一个结点与头节点关联
	{
		p = p->next;
		j ++;
	}
	
	if(j != i)
	{
		printf("元素位置 %d(%d) 参数错误!!\n", i, i + 1);
		return 0;
	}
	
	s = (DLNode *)malloc(sizeof(DLNode));  // 开辟插入结点的内存空间
	if(s)
	{
		s->data = x;    // 赋值到开辟好的空间
		// 进行插入
		s->prior = p->prior; // 将原来p所指向前驱的结点地址给到 s 的前驱
		p->prior->next = s;  // 将原来p所指向前驱的结点的后继与当前插入结点 s 关联
		s->next = p;
		p->prior = s;  // 前驱后继关联，形成双向链表
		
		return 1;
	}
	
}

// 在带头结点的双向循环链表 head 的第 i (0 ≤ i ≤ size - 1) 个结点
// 删除一个数据元素 x
int ListDelete(DLNode *head, int i, DataType *x)
{
	DLNode *p;
	int j = 0;

	p = head->next;
	
	while(p->next != head && j < i)
	{
		p = p->next;
		j ++;
	}
	
	if(j != i)
	{
		printf("元素位置 %d(%d) 参数错误!!\n", i, i + 1);
		return 0;
	}
	
	printf("删除第 %d(%d) 个数据 -> %d \n", i, i + 1, *x);
	
	*x = p->data;
	
	p->prior->next = p->next;  // 将删除结点的 p 的后继给到删除结点 p 的前驱结点的下一个结点的地址
	p->next->prior = p->prior; // 将删除结点的 p 的前驱给到删除结点 p 的后继结点的上一个结点的地址
	
	free(p);
	return 1;
}

int ListLength(DLNode *head)
{
	DLNode *p = head;    // p 指向头指针
	int size = 0;
	
	while(p->next != head)
	{
		p = p->next;
		size ++;
	}
	
	return size;
}

void ListDestroy(DLNode **head)
{
	printf("销毁带头双链...\n");
	
	DLNode *p1, *p2;
	int i = 0,
	n = ListLength(*head);
	
	p1 = *head;
	
	for(; i < n + 1; i++)
	{
		p2 = p1;
		p1 = p1->next;
		
		free(p2); 
	}
	
	*head = NULL;  // 头节点也需要置为空
	
	printf("销毁完成!\n");
}


int main()
{
	DLNode *L;
	
	ListInit(&L);
	
	ListInsert(L, 0, 10);
}


//  5.31_DS-NextPrior.c
//  双链带头循环基本功能
//
//  Created by Just1n on 22/31/5.
//  Copyright (c) 2022年 . All rights reserved.