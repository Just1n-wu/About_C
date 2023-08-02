#pragma once
#include "QFMutableList.hpp"

template<typename T>
class QFMutableList;

// �ڵ���
template<typename E>
class QFLinkNode {
	// ��Ԫ��
	friend class QFMutableList<E>;
private:
	E ele;                 // �洢��Ԫ��
	QFLinkNode<E>* prev;   // ��һ���ڵ��ַ
	QFLinkNode<E>* next;   // ��һ���ڵ��ַ

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
