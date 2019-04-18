#include "Element.h"

template <typename T1>
Element<T1>::Element(T1 data) :_data(data), _prev(NULL), _next(NULL)
{

}
template <typename T1>
T1 Element<T1>::getData()
{
	return _data;
}
template <typename T1>
void Element<T1>::setData(T1 data)
{
	_data = data;
}
template <typename T1>
Element<T1>* Element<T1>::getPrev()
{
	return _prev;
}
template <typename T1>
Element<T1>* Element<T1>::getNext()
{
	return _next;
}
template <typename T1>
void Element<T1>::setPrev(Element<T1> *prev)
{
	_prev = prev;
}
template <typename T1>
void Element<T1>::setNext(Element<T1> *next)
{
	_next = next;
}