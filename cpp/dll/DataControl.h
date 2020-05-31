#ifndef _DATACONTROL_H
#define _DATACONTROL_H
#include "CommonDeclaration.h"

class DataControl
{
private:
public:
    DataControl();
    int insertNode(Node<Format> *head, Node<Format> *tail, Format data);
    int deleteNode(Node<Format> *head, Node<Format> *tail, int num);
    int printNode(Node<Format> *head, Node<Format> *tail);
    int selectInsert(void);
    int selectDelete();
    int selectPrint(void);
    int selectEnd(void);
    int exeFunction(int num, int &res);
    int (DataControl::*_pf[FUNCTION_COUNT])(void);
};
#endif
