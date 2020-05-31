#ifndef _ELEMENT_H
#define _ELEMENT_H

template <typename T1>
class Element
{
private:
    T1 _data;
    Element<T1> *_prev;
    Element<T1> *_next;
public:
    Element(T1 data);
    T1 getData();
    void setData(T1 data);
    Element<T1>* getPrev();
    Element<T1>* getNext();
    void setPrev(Element<T1> *prev);
    void setNext(Element<T1> *next);
};
#endif
