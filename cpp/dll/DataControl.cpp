#include <iostream>
#include <cstdlib>
#include "Format.h"
#include "Element.hpp"
#include "Node.hpp"
#include "DataControl.h"
#include "InitAndTerm.h"
using namespace std;
extern Node<Format> *head, *tail;
extern InitAndTerm *cInt;

DataControl::DataControl()
{
	_pf[0] = &DataControl::selectPrint;
	_pf[1] = &DataControl::selectEnd;
}
int DataControl::printNode(Node<Format> *head, Node<Format> *tail) {
	Element<Format> *list;
	list = head->getNext();
	cout << "|num|name|age|" << endl;
	while (list != static_cast<Element<Format>*>(tail)) {
		list->getData().showData();
		list = list->getNext();
	}
	return 0;
}
int DataControl::selectPrint(void) {
	printNode(head, tail);
	return 0;
}
int DataControl::selectEnd(void) {
	cInt->releaseNode(head, tail);
	return 0;
}
int DataControl::exeFunction(int num, int &res)
{
	(this->*_pf[num])();
	res = 0;
	return 0;
}
