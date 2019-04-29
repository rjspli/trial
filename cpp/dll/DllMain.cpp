#include <iostream>
#include <cstdlib>
#include "Format.h"
#include "Element.hpp"
#include "Node.hpp"
#include "InitAndTerm.h"
#include "DataControl.h"
using namespace std;
Node<Format> *head, *tail;
InitAndTerm *cInt;
DataControl *cDct;

int main(int argc, char *argv[]){
	cInt = new InitAndTerm();
	cDct = new DataControl();

	head = cInt->createHeadTailNode();
	tail = cInt->createHeadTailNode();

	head->setNext(static_cast<Element<Format>*>(tail));
	head->setPrev(static_cast<Element<Format>*>(tail));

	tail->setNext(static_cast<Element<Format>*>(head));
	tail->setPrev(static_cast<Element<Format>*>(head));

	cInt->loadData(head, tail);
	cDct->printNode(head, tail);
	cInt->printMenu();
	delete cInt; delete cDct;
	return 0;
}