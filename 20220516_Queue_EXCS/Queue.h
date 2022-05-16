#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int QDataType;

// 链式队列中结点结构
typedef struct QueueNode
{
	struct QueueNode *next;
	QDataType data;
}QNode;

typedef struct Queue
{
	QNode *head;    // 对头指针
	QNode *tail;    // 队尾指针
	// size_t _size;  // 有效个数
}Queue;

// 初始化队列
void QueueInit(Queue* pq);
// 销毁队列
void QueueDestroy(Queue* pq);

// 队尾入队列
void QueuePush(Queue* pq, QDataType x);
// 队头出队列
void QueuePop(Queue* pq);

// 获取队列头部元素
QDataType QueueFront(Queue* pq);
// 获取队列队尾元素
QDataType QueueBack(Queue* pq);

// 获取队列中有效元素个数
int QueueSize(Queue* pq);
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
bool QueueEmpty(Queue* pq);

