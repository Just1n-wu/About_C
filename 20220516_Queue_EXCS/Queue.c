#include "Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);

	// 将对头队尾初始化， 定义其下标值
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
	// 尾插，更新 tail 指向新的 tail
	// tail 和 head 都为空

	assert(pq);
	
	QNode *newnode = (QNode *)malloc(sizeof(QNode));
	newnode->data = x;
	newnode->next = NULL;

	if (pq->head == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else  // tail->next 指向 新结点的地址，并成为新的 tail
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}

void QueuePop(Queue* pq)
{
	assert(pq);

	assert(!QueueEmpty(pq));   // 判空!! 判空为假即为真！！

	QNode *next = pq->head->next;
	free(pq->head); // free 的不是指针本身，而是指针指向的空间
	pq->head = next;

	// 避免野指针
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

	return pq->head == NULL;  // 逻辑判断: 为空即真，否者为假
}
