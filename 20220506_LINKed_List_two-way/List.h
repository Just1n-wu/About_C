#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

// STL
typedef int LTDateType;

typedef struct ListNode
{
	LTDateType data;
	struct ListNode *next;
	struct ListNode *prev;
}LTNode;

// ��ʼ��
LTNode *ListInit();
// ��ӡ
void ListPrint(LTNode *phead);
// ����
void ListDestroy(LTNode *phead);

// β��
void ListPushBack(LTNode *phead, LTDateType x);
// βɾ
void ListPopBack(LTNode *phead);

// ͷ��
void ListPushFront(LTNode *phead, LTDateType x);
// ͷɾ
void ListPopFront(LTNode *phead);



// ����
LTNode *ListFind(LTNode *phead, LTDateType x);
// �м��
void ListInsert(LTNode *pos, LTDateType x);
// �м�ɾ
void ListErase(LTNode *pos);
