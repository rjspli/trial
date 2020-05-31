#ifndef _NODE_H
#define _NODE_H

template <typename T>
class Node : public Element<T>
{
private:
    Element<T> *_prev;
    Element<T> *_next;
    int _cnt;
public:
    Node(T data);
    void setPrev(Element<T> *prev);
    void setNext(Element<T> *next);
    void setCnt(int cnt);
    Element<T>* getPrev();
    Element<T>* getNext();
    int getCnt();
};
#endif
