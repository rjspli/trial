#include "Node.h"

template <typename T>
Node<T>::Node(T data) : _prev(NULL), _next(NULL), _cnt(0), Element<T>(data)
{

}
template <typename T>
void Node<T>::setPrev(Element<T> *prev)
{
	_prev = prev;
}
template <typename T>
void Node<T>::setNext(Element<T> *next)
{
	_next = next;
}
template <typename T>
void Node<T>::setCnt(int cnt)
{
	_cnt = cnt;
}

template <typename T>
Element<T>* Node<T>::getPrev()
{
	return _prev;
}
template <typename T>
Element<T>* Node<T>::getNext()
{
	return _next;
}
template <typename T>
int Node<T>::getCnt()
{
	return _cnt;
}