#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Format.h"
#include "Element.hpp"
#include "Node.hpp"
#include "DataControl.h"
#include "InitAndTerm.h"
#include "UsageException.h"
using namespace std;
extern Node<Format> *head, *tail;
extern InitAndTerm *cInt;

DataControl::DataControl()
{
    _pf[0] = &DataControl::selectInsert;
    _pf[1] = &DataControl::selectDelete;
    _pf[2] = &DataControl::selectPrint;
    _pf[3] = &DataControl::selectEnd;
}
int DataControl::insertNode(Node<Format> *head, Node<Format> *tail, Format data) {
    Element<Format> *newNode, *list;

    list = head->getNext();
    while (list != static_cast<Element<Format>*>(tail)) {
        if ( (list->getData()).getNum() == data.getNum() ) {
            cout << "input fail. same number exist." << endl;
            return 0;
        }
        list = list->getNext();
    }

    Format _data(data.getNum(), data.getAge(), data.getName());
    newNode = new Element<Format>(_data);

    newNode->setPrev(tail->getPrev());
    newNode->setNext(static_cast<Element<Format>*>(tail));

    if (head->getCnt() == 0) {
        head->setNext(newNode);
    }

    tail->getPrev()->setNext(newNode);
    tail->setPrev(newNode);

    head->setCnt(head->getCnt() + 1);
    tail->setCnt(tail->getCnt() + 1);
    return 0;
}
int DataControl::deleteNode(Node<Format> *head, Node<Format> *tail, int num) {
    Element<Format> *list;
    list = head->getNext();
    while (list != static_cast<Element<Format>*>(tail)) {
        if ((list->getData()).getNum() == num) {
            if( list->getPrev() == static_cast<Element<Format>*>(head) ){
                static_cast<Node<Format>*>( list->getPrev() )->setNext(list->getNext());
            }else {
                list->getPrev()->setNext(list->getNext());
            }
            if (list->getNext() == static_cast<Element<Format>*>(tail)) {
                static_cast<Node<Format>*>( list->getNext() )->setPrev(list->getPrev());
            }else {
                list->getNext()->setPrev(list->getPrev());
            }
            head->setCnt(head->getCnt() - 1);
            tail->setCnt(tail->getCnt() - 1);
            delete list;
            return 0;
        }
        list = list->getNext();
    }
    cout << "no match number" << endl;
    return 0;
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
int DataControl::selectInsert(void) {
    int _num = 0, _age = 0;
    char _tempName[NAME_LENGTH] = { '\0', };
    char c[1] = { '\0', };
    ERROR_TYPE ERRMSG = STATE_OK;
    try{
        Format data(-1, -1, c);
        cout << "input number: " << endl;
        scanf("%d", &_num);
        while (getchar() != '\n');
        if(_num < 0){
            ERRMSG = MINUS_NUMBER;
            throw UsageException(ERRMSG);
        }

        cout << "input name (limit length under " << NAME_LENGTH - 1 << "): " << endl;
        fgets(_tempName, sizeof(_tempName), stdin);
        if (_tempName[strlen(_tempName) - 1] == '\n') {
            _tempName[strlen(_tempName) - 1] = '\0';
        }
        fflush(stdin);
        if(strlen(_tempName) > NAME_LENGTH){
            ERRMSG = LENGTH_OVER;
            throw UsageException(ERRMSG);
        }
        cout << "input age: " << endl;
        scanf("%d", &_age);
        while (getchar() != '\n');
        if(_age < 0 ){
            ERRMSG = MINUS_NUMBER;
            throw UsageException(ERRMSG);
        }
        data.setMember(_num, _age, _tempName);
        insertNode(head, tail, data);
    }
    catch(UsageException& err){
        err.ShowErrorInfo();
    }
    return 0;
}
int DataControl::selectDelete() {
    int num;
    cout << "input number for delete: " << endl;
    if (scanf("%d", &num) == 0) {
    }
    deleteNode(head, tail, num);
    return 0;
}
int DataControl::selectPrint(void) {
    printNode(head, tail);
    return 0;
}
int DataControl::selectEnd(void) {
    cInt->saveData(head, tail);
    cInt->releaseNode(head, tail);
    return 0;
}
int DataControl::exeFunction(int num, int &res)
{
    (this->*_pf[num])();
    res = 0;
    return 0;
}
