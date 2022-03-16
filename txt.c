#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
	int data;             // ������
	struct node *next;    // ָ����
};

// ����ָ���ڵ���������������ͷ�ڵ��ַ��
struct node *create(int count)
{
	struct node *head = malloc(sizeof(struct node));   //  ʹ�� malloc ����һ�� node �Ķ��ڴ��С
	if (head == NULL)   // (!head)
	{
		return NULL;
	}

	head->data = 1;
	head->next = NULL;

	struct node *tail = head;    // �α�  ��ָ�� head��Ȼ��ÿ����㴴��֮�� tail ָ�����ÿ����� p���������Ա�֤ tail ����ʼ�ձ���Ϊ���һ�����
	for (int i = 0; i < count; i++)
	{
		struct node *p;     
		do
			p = malloc(sizeof(struct node));    // ���� struct node *  ����һ����ֵַ   ��Ҫһ��������ͣ������ǽ���ָ������
		while (p == NULL);

		p->data = 0;
		p->next = NULL;

		tail->next = p;    // (*tail).next = p;  ������һ�����
		tail = p;         // tail �����ֵ���ĵ� p �ϣ���ԭ��ָ�� head ��ָ�� p
	} 

	return head;
}

void visit(struct node *node)
{
	printf("%d ", node->data);
}

void printNewLine(void)
{
	putchar('\n');
}

// ��ȡ����ĳ��ȡ�
int getLength(struct node head)
{
	int count = 1;
	struct node *p = head.next;
	while (p->next != NULL)
	{
		count++;
		p = p->next;
	}

	return count;
}

// ��ĳ���ڵ�׷�ӵ�ָ��������
void appen(struct node *list, struct node *pNode)
{
	struct node *p = list;
	while (p->next != NULL)
	{
		p = p->next;
	}

	p->next = pNode;
	pNode->next = NULL;
}

// �����б�
void traversea(struct node *list, void (*visitor)(struct node *), void(*onEnding)(void))
{
	struct node *p = list;
	while (p->next != NULL)
	{
		(*visitor)(p);

		p = p->next;
	}

	(*onEnding)();
}

// ȡ��ָ���������±꣩�Ľڵ���Ϣ�����ص�ǰҪ���ҽڵ�ĵ�ַ��
struct node *getIndexOf(struct node *list, int index)
{
	if (index == 0)
		return list;   // �൱�� head

	struct node *p = list;  // �α� ָ��ͷ��ַ
		for (int i = 0; i < index; i++)
		{
			p = p->next;
		}

		return p;
}

// ����ĳ���ڵ㵽ָ��������
void insert(struct node *list, int index, struct node *pNode)
{
	struct node *p = getIndexOf(list, index);
	struct node *q = p->next;
	p->next = pNode;
	pNode->next = q;
}

// ɾ�����һ���ڵ�
struct node *removeTail(struct node *list)
{
	int length = getLength(*list);
	struct node *pTail = getIndexOf(list, length - 2);
	struct ndde *returnNode = pTail->next;

	pTail->next = NULL;
	return returnNode;
}

// ɾ���м�ĳ���ڵ㣬������ָ��
struct node *removeAt(struct node *list, int index)
{
	struct node *p, *q, *r;
	q = getIndexOf(list, index - 1);
	p = q->next;
	r = q->next->next;  // r = p->next

	q->next = r;
	return p;
}

// �ͷ�����ʹ�õĿռ��ڴ档
void dispose(struct node *list)
{
	struct node *p = list, *q = p;
	while (p->next != NULL)   // (p->next)
	{
		p = p->next;
		if(q != NULL)
			free(q);
		q = q->next;
	}
}

int main(void)
{	
	struct node *pHead = create(5);
	if (pHead == NULL)
	{
		printf("Linked List Creation Failed��");
		return 0;
	}

	int length = getLength(*pHead);
	printf("%d\n", length);

	traversea(pHead, &visit, &printNewLine);

	getIndexOf(pHead, 3)->data = 2;

	traversea(pHead, &visit, &printNewLine);

}