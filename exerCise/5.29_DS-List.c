#include<stdio.h>
#include<stdlib.h>

typedef int DataType;
typedef struct Node
{
	DataType data;       // ������
	struct Node *next;   // ָ����
	
}SLNode;

void ListInit(SLNode **head)
{
	printf("��ʼ��...\n");
	
	*head = (SLNode *)malloc(sizeof(SLNode));   // ����ͷ�ڵ�
	(*head)->next = NULL;                       // �ý��ܱ��
	
	printf("�������ͷ������\n");
 
}

int ListLength(SLNode *head)
{
	SLNode *phead = head;   // �еľ��������� cur , ����һ����ע������
	int size = 0;
	
	// �����һ�����
	while(phead->next != NULL)
	{
		phead = phead->next;  // ָ������ֱ�Ӻ�̽��
		size ++;
	}
	
	return size;
}

SLNode *BuyListNode(DataType x)
{
	// �����½ڵ�
	SLNode *newnode = (SLNode *)malloc(sizeof(SLNode));
	if (newnode == NULL)
	{
		printf("����ʧ�ܣ�");
		exit(-1);
	}

	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}

// ��ͷ���� head �ĵ� i ��0 �� i �� size�� �����
// ǰ ����һ���������Ԫ�� x �Ľ��
int ListInsert(SLNode *head, int i, DataType x)
{
	printf("�������� -> %d\n", x);
	
	SLNode *p, *q;
	int j = -1;
	
	p = head;
	
	while(p->next != NULL && j < i - 1)
	{
		// ������ p ָ��� i-1 �����
		p = p->next;
		j++;
	}
	
	if(j != i - 1)
	{
		printf("����λ������!\n");
		return 0;
	}
	
	// ����һ���������Ԫ�� x �Ľ��
	q = (SLNode *)malloc(sizeof(SLNode));
	q->data = x;
	
	// �����еĵ����γ���ϵ
	q->next = p->next;   // ��ԭ��ͷ�ڵ��к�̽���ַ������½���ָ����
	p->next = q;        // ͷ���ָ���½��ĵ�ַ��ʹ�����
	
	return 1;
}

// ɾ����ͷ���� head �ĵ� i ��0 �� i �� size - 1�� �����
// �ȼ�¼ x 
int ListDelete(SLNode *head, int i, DataType *x)
{
	SLNode *p, *s;
	int j;
	
	p = head;
	j = -1;
	
	while(p->next != NULL 
	&& p->next->next != NULL && j < i - 1)
	{
		// ������ p ָ��Ҫ�� i-1 �����, ɾ�� i ���
		p = p->next;
		j++;
	}
	
	if(j != i - 1)
	{
		printf("����λ������!\n");
		return 0;
	}
	
	s = p->next;  // ��¼Ҫɾ����㣬 p Ϊ ɾ������ǰ��
	*x = s->data;
	
	printf("ɾ���� %d(%d) ������ -> %d \n", i, i + 1, *x);
	
	p->next = p->next->next; // ��ɾ������е���һ����̵ĵ�ַ�뵱ǰ p ����
	free(s);  // �ͷ� 
	
	return 1;
}

// ��ɾ������
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
		printf("λ�ò�������\n");
		return 0;
	}
	
	*x = p->data;
	return 1;
}

void ListDestroy(SLNode **head)
{
	printf("���ٵ���...");
	
	SLNode *p, *p1;
	
	p = *head;
	
	while(p->next != NULL)
	{
		p1 = p;
		p = p->next;
		free(p1);
	}
	
	*head = NULL;
	
	printf("������ɣ�\n");
}

int main()
{
	SLNode *head;   // ����һ��ͷָ�����
	
	int x;
	
	ListInit(&head);
	
	// ����
	for(int i = 0; i < 10; i++)
		ListInsert(head, i, i + 1);
	
	// ɾ������Ԫ�� 11
	ListDelete(head, 4, &x);
	
	// ��ʾ��ǰ����
	for(int i = 0; i < ListLength(head); i++)
	{
		ListGetNumber(head, i, &x);   // ȡԪ��
		printf("%d ", x);
	}
	
	
	printf("\n��ǰ��ͷ�����д��� %d �����\n", ListLength(head));
	
	ListDestroy(&head);  // ����
}

//  5.29_DS-SList.c
//  ������ͷ��������
//
//  Created by Just1n on 22/29/5.
//  Copyright (c) 2022�� . All rights reserved.