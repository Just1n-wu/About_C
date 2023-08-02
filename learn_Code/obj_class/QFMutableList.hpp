#pragma once
# include <iostream>
# include <sstream>
# include "QFLinkNode.hpp"
# include "QFMutableContainer.h"
using namespace std;

template<typename E>
class QFMutableList : public QFMutableContainer<E> {
private:
	QFLinkNode<E>* head;  // �����е��׽ڵ�
	QFLinkNode<E>* tail;  // �����е�β�ڵ�
	int len;              // Ԫ�ص�����

	QFLinkNode<E>* getNode(int index);  // ͨ���±��ȡָ���ڵ�

public:
	QFMutableList(); 
	// ��д����������
	~QFMutableList() override;

	// ��ĩβ���һ��Ԫ��
	void add(E ele) override;
	// ��ָ���±�λ�ò���Ԫ��
	void add(int index, E ele) override;
	// �����±�ɾ��Ԫ��
	E remove(int index) override;
	// ����Ԫ�ؽ���ɾ��
	bool removeElement(E ele) override;
	// �������
	void clear() override;
	// ͨ���±��޸�Ԫ��
	E set(int index, E ele) override;
	// ͨ���±��ȡԪ��
	E get(int index) override;
	// ����������
	void sort() override;
	// ����Ԫ�س��ֵ��±�
	int index(E ele) override;
	// �������е�Ԫ��ƴ�ӳ��ַ�������
	string str() override;

	int length() override;
};

template<typename E>
inline QFLinkNode<E>* QFMutableList<E>::getNode(int index)
{
	QFLinkNode <E>* p = head;
	for (int i = 0; i < index; i++)
	{
		p = p->next;
	}
	return p;
}

template<typename E>
inline QFMutableList<E>::QFMutableList()
{
	head = nullptr;
	tail = nullptr;

	len = 0;
}

template<typename E>
inline QFMutableList<E>::~QFMutableList()
{
	// Ŀ�ģ������������ʱ���ͷ�ÿһ���ڵ�ռ�
	clear();
}

template<typename E>
inline void QFMutableList<E>::add(E ele)
{
	// ����һ���µĽڵ�
	QFLinkNode<E>* node = new QFLinkNode<E>(ele);

	// �ж�Ԫ�ص�����
	if (len == 0)
	{
		// ˵��������û��Ԫ�أ��׽ڵ��β�ڵ㶼��nullptr
		this->head = node;
		this->tail = node;
	}
	else
	{
		// ��������Ԫ�أ���node��ӵ�tail֮��
		this->tail->next = node; 
		node->prev = this->tail;
		this->tail = node;
	}

	// ����Ԫ�ظ���
	len++;
}

template<typename E>
inline void QFMutableList<E>::add(int index, E ele)
{
	// 1. ����һ���ڵ����
	QFLinkNode<E>* node = new QFLinkNode<E>(ele);

	// 2. �ֲ�ͬ���
	if (index == 0)
	{
		node->next = head;
		head->prev = node;
		head = node;

		len++;
	}

	else if (index == len)
	{
		node->prev = tail;
		tail->next = node;
		tail = node;

		len++;
	}

	else
	{
		// ͨ���±��ҵ���Ҫ������Ľڵ�
		QFLinkNode<E>* target = getNode(index);

		target->prev->next = node;
		node->prev = target->prev;

		node->next = target;
		target->prev = node;

		len++;
	}
}

template<typename E>
inline E QFMutableList<E>::remove(int index)
{
	E tmp;

	if (len == 1) 
	{
		tmp = head->ele;
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		if (index == 0)
		{
			tmp = head->ele;
			// ͷɾ
			head = head->next;
			delete head->prev;
			head->prev = nullptr;
		}
		else if (index == len - 1)
		{
			tmp = tail->ele;
			// βɾ
			tail = tail->prev;
			delete tail->next;
			tail->next = nullptr;
		}
		else
		{
			QFLinkNode<E>* node = getNode(index);
			tmp = node->ele;
			// ָɾ
			node->prev->next = node->next;
			node->next->prev = node->prev;

			delete node;
		}
	}

	len--;

	return tmp;
}

template<typename E>
inline bool QFMutableList<E>::removeElement(E ele)
{
	// �ҵ�Ԫ������λ�õ��±�
	int index_ele = index(ele); 

	if (index_ele == -1)
	{
		return false;
	}

	remove(index_ele);
	return true;
}

template<typename E>
inline void QFMutableList<E>::clear()
{
	if (head != NULL)
	{
		QFLinkNode<E>* p1 = head;
		QFLinkNode<E>* p2 = p1->next;

		/*while (p2->next != nullptr)*/
		while (p2 != nullptr)
		{
			delete p1;
			p1 = p2;
			p2 = p2->next;
		}

		delete p1;

		head = nullptr;
		tail = nullptr;

		len = 0;
	}
}

template<typename E>
inline E QFMutableList<E>::set(int index, E ele)
{
	QFLinkNode<E>* node = getNode(index);
	E tmp = node->ele;
	node->ele = ele;
	
	return tmp;
}

template<typename E>
inline E QFMutableList<E>::get(int index)
{
	QFLinkNode<E>* node = getNode(index);

	return node->ele;
}

template<typename E>
inline void QFMutableList<E>::sort()
{
	for (int i = 0 ; i < len - 1; i++)
	{
		QFLinkNode<E>* node = head;
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (node->ele > node->next->ele)
			{
				E tmp = node->ele;
				node->ele = node->next->ele;
				node->next->ele = tmp;
			}
			node = node->next;
		}
	}
}

template<typename E>
inline int QFMutableList<E>::index(E ele)
{
	QFLinkNode<E>* node = head;
	for (int i = 0; i < len; i++)
	{
		if (ele == node->ele)
		{
			return i; 
		}
		node = node->next;
	}

	return -1;
}

template<typename E>
inline string QFMutableList<E>::str()
{
	if (len == 0)
	{
		return "[]";
	}
	ostringstream oss;
	oss << "[";
	QFLinkNode<E>* node = head;
	for (int i = 0; i < len - 1; i++)
	{
		oss << node->ele << " -> ";
		node = node->next;
	}
	oss << node->ele << "]";

	return oss.str();
}

template<typename E>
inline int QFMutableList<E>::length()
{
	return len;
}
