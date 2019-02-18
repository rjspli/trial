#ifndef _DATACONTROL_H
#define _DATACONTROL_H

int insertNode(node *head, node *tail, elem data);
int deleteNode(node *head, node *tail, int num);
int printNode(node *head, node *tail);
int selectInsert();
int selectDelete();
int selectPrint();
int selectEnd();

#endif
