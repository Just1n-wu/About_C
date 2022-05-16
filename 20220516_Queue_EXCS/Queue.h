#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int QDataType;

// ��ʽ�����н��ṹ
typedef struct QueueNode
{
	struct QueueNode *next;
	QDataType data;
}QNode;

typedef struct Queue
{
	QNode *head;    // ��ͷָ��
	QNode *tail;    // ��βָ��
	// size_t _size;  // ��Ч����
}Queue;

// ��ʼ������
void QueueInit(Queue* pq);
// ���ٶ���
void QueueDestroy(Queue* pq);

// ��β�����
void QueuePush(Queue* pq, QDataType x);
// ��ͷ������
void QueuePop(Queue* pq);

// ��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* pq);
// ��ȡ���ж�βԪ��
QDataType QueueBack(Queue* pq);

// ��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* pq);
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
bool QueueEmpty(Queue* pq);

