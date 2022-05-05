#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDateType;

typedef struct SListNode
{
	SLTDateType data;          // ������  �������
	struct SListNode* next;    // ָ����  ָ����һ���ڵ��ַ�����һ����Ϊ NULL(��)
}SLTNode;

// ��ӡ
void SListPrint(SLTNode *phead);
// �����½ڵ�
SLTNode *BuyListNode(SLTDateType x);

// β��
void SListPushBack(SLTNode **pphead, SLTDateType x);
// ͷ��
void SListPushFront(SLTNode **pphead, SLTDateType x);

// βɾ
void SListPopBack(SLTNode **pphead);
// ͷɾ
void SListPopFront(SLTNode **pphead);

// ���� & �޸�
SLTNode *SListFind(SLTNode *phead, SLTDateType x);
// �м����  ��posλ��֮ǰȥ����һ���ڵ�    O(n)
void SListInsert(SLTNode **pphead, SLTNode *pos, SLTDateType x);
// ��pos�������                          O(1)
void SListInsertAfter(SLTNode *pos, SLTDateType x);
// �м�ɾ��                               O(n)
void SListErase(SLTNode **pphead, SLTNode *pos);
// ����ɾ��
void SListEraseAfter(SLTNode *pos);

// ����
void SListDestroy(SLTNode **pphead);
