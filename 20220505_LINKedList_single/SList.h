#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDateType;

typedef struct SListNode
{
	SLTDateType data;          // 数据域  存放数据
	struct SListNode* next;    // 指针域  指向下一个节点地址，最后一个置为 NULL(空)
}SLTNode;

// 打印
void SListPrint(SLTNode *phead);
// 创建新节点
SLTNode *BuyListNode(SLTDateType x);

// 尾插
void SListPushBack(SLTNode **pphead, SLTDateType x);
// 头插
void SListPushFront(SLTNode **pphead, SLTDateType x);

// 尾删
void SListPopBack(SLTNode **pphead);
// 头删
void SListPopFront(SLTNode **pphead);

// 查找 & 修改
SLTNode *SListFind(SLTNode *phead, SLTDateType x);
// 中间插入  在pos位置之前去插入一个节点    O(n)
void SListInsert(SLTNode **pphead, SLTNode *pos, SLTDateType x);
// 在pos后面插入                          O(1)
void SListInsertAfter(SLTNode *pos, SLTDateType x);
// 中间删除                               O(n)
void SListErase(SLTNode **pphead, SLTNode *pos);
// 后面删除
void SListEraseAfter(SLTNode *pos);

// 销毁
void SListDestroy(SLTNode **pphead);
