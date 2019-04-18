#ifndef _DATACONTROL_H
#define _DATACONTROL_H

void selectInsert();
void selectDelete();
void selectPrint();
void selectEnd();
void printNode(Node** root);
void insertNode(Node** root, Node* insNode);
void deleteNode(Node** root, int num);
void releaseNode(Node** root);
Node* searchSameNode(Node** root, int num);

#endif