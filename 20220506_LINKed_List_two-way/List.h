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

// 初始化
LTNode *ListInit();
// 打印
void ListPrint(LTNode *phead);
// 销毁
void ListDestroy(LTNode *phead);

// 尾插
void ListPushBack(LTNode *phead, LTDateType x);
// 尾删
void ListPopBack(LTNode *phead);

// 头插
void ListPushFront(LTNode *phead, LTDateType x);
// 头删
void ListPopFront(LTNode *phead);



// 查找
LTNode *ListFind(LTNode *phead, LTDateType x);
// 中间插
void ListInsert(LTNode *pos, LTDateType x);
// 中间删
void ListErase(LTNode *pos);
