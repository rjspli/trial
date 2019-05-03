#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include "Format.h"
#include "Element.hpp"
#include "Node.hpp"
#include "InitAndTerm.h"
#include "DataControl.h"
using namespace std;
extern DataControl *cDct;

int InitAndTerm::printMenu()
{
	int num, res;

	while(1) {
		puts("");
		puts("1.insert");
		puts("2.print");
		puts("3.close");
		printf("menu select: ");
		scanf("%d", &num);
		while (getchar() != '\n');
		puts("");
		if (num > 0 && num < (FUNCTION_COUNT+1)) {
			cDct->exeFunction((num - 1), res);
			cout << "execute result: " << res << endl;
		}else{
			cout << "please select agin." << endl;
			continue;
		}
		if (num == FUNCTION_COUNT) {
			return 0;
		}
	}
	return 0;
}
void InitAndTerm::loadData(Node<Format> *head, Node<Format> *tail) {
	FILE *fp;
	int num = -1, age = -1, cnt=0;
	char tempName[NAME_LENGTH] = { '\0', };
	Element<Format> *oldData, *newData;
	const char *savedFile = "file.txt";
	if ((fp = fopen(savedFile, "r")) == NULL) {
		cout << "load file not Exist" << endl;
		return;
	}
	char c[1] = { '\0', };
	Format data(-1, -1, c);
	newData = new Element<Format>(data);
	head->setNext(newData);
	newData->setPrev(static_cast<Element<Format>*>(head));

	while (fscanf(fp, "%d %s %d", &num
		, tempName, &age) != EOF) {
		data.setMember(num, age, tempName);

		newData->setData(data);
		cnt++;
		head->setCnt(cnt);
		tail->setCnt(cnt);
		oldData = newData;

		newData = new Element<Format>(data);
		oldData->setNext(newData);
		newData->setPrev(oldData);
	}

	if (head->getCnt() == 0) {
		head->setNext(static_cast<Element<Format>*>(tail));
		tail->setPrev(static_cast<Element<Format>*>(head));
	} else {
		oldData->setNext(static_cast<Element<Format>*>(tail));
		tail->setPrev(oldData);
	}

	delete newData;
	fclose(fp);
}
void InitAndTerm::saveData(Node<Format> *head, Node<Format> *tail) {
	FILE *fp;
	Element<Format> *list;
	const char *fileName = "file.txt";
	if ((fp = fopen(fileName, "wt")) == NULL) {
		cout << "file write error" << endl;
		return;
	}
	list = head->getNext();
	while (list != static_cast<Element<Format>*>(tail)) {
		fprintf(fp, "%d %s %d\n", list->getData().getNum(),
			list->getData().getName(), list->getData().getAge() );
		list = list->getNext();
	}
	fclose(fp);
}
Node<Format>* InitAndTerm::createHeadTailNode()
{
	char dummyName[10] = "dummy";
	Format data(-1, -1, dummyName);
	Node<Format>* dummy = new Node<Format>(data);
	return dummy;
}
int InitAndTerm::releaseNode(Node<Format> *head, Node<Format> *tail)
{
	Element<Format> *list, *oldData;
	list = head->getNext();

	while (list != static_cast<Element<Format>*>(tail)) {
		oldData = list;
		list = list->getNext();
		delete oldData;
	}

	delete head;
	delete tail;
	return 0;
}