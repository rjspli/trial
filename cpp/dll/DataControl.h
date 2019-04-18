#ifndef _DATACONTROL_H
#define _DATACONTROL_H
#include "CommonDeclaration.h"

class DataControl
{
private:
public:
	DataControl();
	int printNode(Node<Format> *head, Node<Format> *tail);
	int selectPrint(void);
	int selectEnd(void);
	int exeFunction(int num, int &res);
	int (DataControl::*_pf[FUNCTION_COUNT])(void);
};
#endif
