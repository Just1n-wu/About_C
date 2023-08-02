#pragma once
# include <iostream>
# include <sstream>
# include "QFLinkNode.hpp"
# include "QFMutableContainer.h"
using namespace std;

template<typename E>
class QFMutableList : public QFMutableContainer<E> {
private:
	QFLinkNode<E>* head;  // 链表中的首节点
	QFLinkNode<E>* tail;  // 链表中的尾节点
	int len;              // 元素的数量

	QFLinkNode<E>* getNode(int index);  // 通过下标获取指定节点

public:
	QFMutableList(); 
	// 重写虚析构函数
	~QFMutableList() override;

	// 在末尾添加一个元素
	void add(E ele) override;
	// 在指定下标位置插入元素
	void add(int index, E ele) override;
	// 按照下标删除元素
	E remove(int index) override;
	// 按照元素进行删除
	bool removeElement(E ele) override;
	// 清空容器
	void clear() override;
	// 通过下标修改元素
	E set(int index, E ele) override;
	// 通过下标获取元素
	E get(int index) override;
	// 容器内排序
	void sort() override;
	// 查找元素出现的下标
	int index(E ele) override;
	// 将容器中的元素拼接成字符串返回
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
	// 目的：在销毁链表的时候，释放每一个节点空间
	clear();
}

template<typename E>
inline void QFMutableList<E>::add(E ele)
{
	// 创建一个新的节点
	QFLinkNode<E>* node = new QFLinkNode<E>(ele);

	// 判断元素的数量
	if (len == 0)
	{
		// 说明链表中没有元素，首节点和尾节点都是nullptr
		this->head = node;
		this->tail = node;
	}
	else
	{
		// 链表中有元素，将node添加到tail之后
		this->tail->next = node; 
		node->prev = this->tail;
		this->tail = node;
	}

	// 更新元素个数
	len++;
}

template<typename E>
inline void QFMutableList<E>::add(int index, E ele)
{
	// 1. 创建一个节点对象
	QFLinkNode<E>* node = new QFLinkNode<E>(ele);

	// 2. 分不同情况
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
		// 通过下标找到需要被插入的节点
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
			// 头删
			head = head->next;
			delete head->prev;
			head->prev = nullptr;
		}
		else if (index == len - 1)
		{
			tmp = tail->ele;
			// 尾删
			tail = tail->prev;
			delete tail->next;
			tail->next = nullptr;
		}
		else
		{
			QFLinkNode<E>* node = getNode(index);
			tmp = node->ele;
			// 指删
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
	// 找到元素所在位置的下标
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
