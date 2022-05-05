#include "SList.h"

SLTNode *BuyListNode(SLTDateType x)
{
	// �����½ڵ�
	SLTNode *newnode = (SLTNode *)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		printf("����ʧ�ܣ�");
		exit(-1);
	}

	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}

void SListPrint(SLTNode *phead)
{
	SLTNode *cur = phead;  // �������α�
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;    // ָ����һ���ڵ�ĵ�ַ
	}

	printf("NULL\n");
}

void SListPushBack(SLTNode **pphead, SLTDateType x)
{
	SLTNode *newnode = BuyListNode(x);  // �����½ڵ�

	if (*pphead == NULL)  // ����û�нڵ��������ҵ�β�ڵ㣬ֱ�ӽ��½ڵ㸳�� ͷ�ڵ�(phead)
	{
		*pphead = newnode;
	}
	else
	{
		// �ҵ�β�ڵ�
		SLTNode *tail = *pphead;
		while (tail->next != NULL)
			tail = tail->next;

		tail->next = newnode;
	}

	/* #ע�⣺ ������Ҫ�ı���� *pList��������Ҫ�ö���ָ��������,
			�����һ��ָ��ֻ��һ����ʱ�����������޸���ֵ��
	   ���磺ʵ���� int Ҫ�ı�ʵ�Σ�Ҫ�� int*  ������������ò���ȥ�ı䡣
	   �ܽ᣺ͨ��ָ��ȥ�ı�ָ��ռ�����ݣ���һ��ָ�룻�ı�ָ���ָ�򣬴�����ָ�롣  */
}

void SListPushFront(SLTNode **pphead, SLTDateType x)
{
	SLTNode *newnode = BuyListNode(x);

	newnode->next = *pphead;
	*pphead = newnode;
}

void SListPopBack(SLTNode **pphead)
{
	if (*pphead == NULL) // assert(*pphead != NULL)
	{
		printf("IS NULL����");
		return;
	}

	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}

	else
	{
		SLTNode *prev = NULL;
		SLTNode *tail = *pphead;

		//while (tail->next->next)
		//	tail = tail->next;

		//free(tail->next);  // ɾ�����һ���ڵ�
		//tail->next = NULL;

		 // ��β
		//while (tail->next != NULL)
		while (tail->next)  // ������ʽת���� 0 ���Ǽ٣���0 ������
		{
			prev = tail;
			tail = tail->next;
		}

		free(tail);  // ɾ�����һ���ڵ�
		tail = NULL;

		prev->next = NULL; // #ע��: Ҫ��¼��һ���ڵ� ��������Ұָ�룬Ҳ�ᵼ����һ���ڵ�����ָ������ڵ㣬���ڷǷ����ʡ�
	}
}

void SListPopFront(SLTNode **pphead)
{
	if (*pphead == NULL) 
	{
		printf("IS NULL����");
		return;
	}
	// assert(*pphead);

	else
	{
		SLTNode *head = (*pphead)->next;
		free(*pphead);
		*pphead = head;
	}
}

SLTNode *SListFind(SLTNode *phead, SLTDateType x)
{
	SLTNode *cur = phead;
	while (cur)
	{
		if (cur->data == x)
			return cur;
		else
			cur = cur->next;
	}

	return NULL;
}

void SListInsert(SLTNode **pphead, SLTNode *pos, SLTDateType x)
{
	SLTNode *newnode = BuyListNode(x);

	if (*pphead == pos)  // ��Ϊͷ��
	{
		newnode->next = *pphead;
		*pphead = newnode;
	}

	else
	{
		// �ҵ� pos λ�õ�ǰһ��λ��
		SLTNode *posPrev = *pphead;
		while (posPrev->next != pos)
		{
			posPrev = posPrev->next;
		}

		posPrev->next = newnode;
		newnode->next = pos;
	}
}

void SListInsertAfter(SLTNode *pos, SLTDateType x)
{
	SLTNode *newnode = BuyListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SListErase(SLTNode **pphead, SLTNode *pos)
{
	if (*pphead == pos)
	{
		/**pphead = pos->next;
		free(pos);*/

		SListPopFront(pphead);
	}

	else
	{
		SLTNode *prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}

		prev->next = pos->next;
		free(pos);
		// pos = NULL;
	}
}

void SListEraseAfter(SLTNode *pos)
{
	assert(pos->next);

	SLTNode *next = pos->next;
	pos->next = next->next;
	free(next);
	// next = NULL;
}

void SListDestroy(SLTNode **pphead)
{
	assert(pphead);

	//free(*pphead);  ֻ���ͷ�ͷ�ڵ�

	SLTNode *cur = *pphead;
	while (cur)
	{
		SLTNode *next = cur->next;
		free(cur);

		cur = next;
	}

	*pphead = NULL;
}
