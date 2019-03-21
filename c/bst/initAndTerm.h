#ifndef _INITPROGRAM_H_
#define _INITPROGRAM_H_

Node* createNode(int num);
Data* createData(int num);
int exeFunc(void (**pF)(Node**), int sel, Node** root, int *ret);

#endif
