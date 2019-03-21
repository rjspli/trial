#ifndef _DATACONTROL_H
#define _DATACONTROL_H

void selectInsert();
void selectDelete();
void selectPrint();
void selectEnd();
void insertNode(Node** root, Node* insNode);
Node* searchSameNode(Node** root, int num);
void releaseNode(Node** root);

#endif
