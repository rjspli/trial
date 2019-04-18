#ifndef _INITANDTERM_H
#define _INITANDTERM_H
#include "CommonDeclaration.h"

class InitAndTerm
{
private:
public:
	void loadData(Node<Format> *head, Node<Format> *tail);
	int printMenu();
	Node<Format>* createHeadTailNode();
	int releaseNode(Node<Format> *head, Node<Format> *tail);
};
#endif