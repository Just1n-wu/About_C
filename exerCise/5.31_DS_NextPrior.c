#include<stdio.h>
#include<stdlib.h>

typedef int DataType;

typedef struct Node
{
	DataType data;     // ������
	struct Node *next;  // ��̽��ָ����
	struct Node *prior; // ǰ�����ָ����
} DLNode;

void ListInit(DLNode **head)
{
	printf("˫����ʼ��(��ͷѭ��˫��)...\n");
	
	*head = (DLNode *)malloc(sizeof(DLNode));  // ����ͷ�����ڴ�ռ�
	(*head)->prior = *head;   // ����ǰ��ָ��ѭ������
	(*head)->next = *head;    // ���ɺ��ָ��ѭ������
	
	if(*head != NULL)
	{
		printf("��ͷѭ��˫��������!\n");
	}
}

// �ڴ�ͷ����˫��ѭ������ head �ĵ� i (0 �� i �� size) �����ǰ
// ����һ������Ԫ�� x
int ListInsert(DLNode *head, int i, DataType x)
{
	printf("�ڵ� %d(%d) ��λ�ò������� -> %d\n", i, i + 1, x);
	
	DLNode *p, *s;
	int j = 0;
	
	p = head->next;
	
	// Ѱ�ҵ� i �����
	while(p != head && j < i)  // ���һ�������ͷ�ڵ����
	{
		p = p->next;
		j ++;
	}
	
	if(j != i)
	{
		printf("Ԫ��λ�� %d(%d) ��������!!\n", i, i + 1);
		return 0;
	}
	
	s = (DLNode *)malloc(sizeof(DLNode));  // ���ٲ�������ڴ�ռ�
	if(s)
	{
		s->data = x;    // ��ֵ�����ٺõĿռ�
		// ���в���
		s->prior = p->prior; // ��ԭ��p��ָ��ǰ���Ľ���ַ���� s ��ǰ��
		p->prior->next = s;  // ��ԭ��p��ָ��ǰ���Ľ��ĺ���뵱ǰ������ s ����
		s->next = p;
		p->prior = s;  // ǰ����̹������γ�˫������
		
		return 1;
	}
	
}

// �ڴ�ͷ����˫��ѭ������ head �ĵ� i (0 �� i �� size - 1) �����
// ɾ��һ������Ԫ�� x
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
		printf("Ԫ��λ�� %d(%d) ��������!!\n", i, i + 1);
		return 0;
	}
	
	printf("ɾ���� %d(%d) ������ -> %d \n", i, i + 1, *x);
	
	*x = p->data;
	
	p->prior->next = p->next;  // ��ɾ������ p �ĺ�̸���ɾ����� p ��ǰ��������һ�����ĵ�ַ
	p->next->prior = p->prior; // ��ɾ������ p ��ǰ������ɾ����� p �ĺ�̽�����һ�����ĵ�ַ
	
	free(p);
	return 1;
}

int ListLength(DLNode *head)
{
	DLNode *p = head;    // p ָ��ͷָ��
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
	printf("���ٴ�ͷ˫��...\n");
	
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
	
	*head = NULL;  // ͷ�ڵ�Ҳ��Ҫ��Ϊ��
	
	printf("�������!\n");
}


int main()
{
	DLNode *L;
	
	ListInit(&L);
	
	ListInsert(L, 0, 10);
}


//  5.31_DS-NextPrior.c
//  ˫����ͷѭ����������
//
//  Created by Just1n on 22/31/5.
//  Copyright (c) 2022�� . All rights reserved.