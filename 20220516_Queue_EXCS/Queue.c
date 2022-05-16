#include "Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);

	// ����ͷ��β��ʼ���� �������±�ֵ
	pq->head = NULL;
	pq->tail = NULL;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);

	QNode *cur = pq->head;
	while (cur != NULL)
	{
		QNode *next = cur->next;
		free(cur);
		cur = next;
	}

	pq->head = pq->tail = NULL;
}

void QueuePush(Queue* pq, QDataType x)
{
	// β�壬���� tail ָ���µ� tail
	// tail �� head ��Ϊ��

	assert(pq);
	
	QNode *newnode = (QNode *)malloc(sizeof(QNode));
	newnode->data = x;
	newnode->next = NULL;

	if (pq->head == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else  // tail->next ָ�� �½��ĵ�ַ������Ϊ�µ� tail
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}

void QueuePop(Queue* pq)
{
	assert(pq);

	assert(!QueueEmpty(pq));   // �п�!! �п�Ϊ�ټ�Ϊ�棡��

	QNode *next = pq->head->next;
	free(pq->head); // free �Ĳ���ָ�뱾������ָ��ָ��Ŀռ�
	pq->head = next;

	// ����Ұָ��
	if (pq->head == NULL)
		pq->tail = NULL;  
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);

	assert(!QueueEmpty(pq));

	return pq->head->data;
}

QDataType QueueBack(Queue* pq)
{
	assert(pq);

	assert(!QueueEmpty(pq));

	return pq->tail->data;
}

int QueueSize(Queue* pq)
{
	assert(pq);

	int count = 0;
	QNode *cur = pq->head;
	while (cur)
	{
		count++;
		cur = cur->next;
	}

	return count;
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->head == NULL;  // �߼��ж�: Ϊ�ռ��棬����Ϊ��
}
