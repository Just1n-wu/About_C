#pragma once
#include "QFMutableList.hpp"

template<typename T>
class QFMutableList;

// 节点类
template<typename E>
class QFLinkNode {
	// 友元类
	friend class QFMutableList<E>;
private:
	E ele;                 // 存储的元素
	QFLinkNode<E>* prev;   // 上一个节点地址
	QFLinkNode<E>* next;   // 下一个节点地址

public:
	QFLinkNode(E ele);
};

template<typename E>
inline QFLinkNode<E>::QFLinkNode(E ele)
{
	this->ele = ele;
	prev = nullptr;
	next = nullptr;
}
