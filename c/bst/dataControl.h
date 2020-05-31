#ifndef _DATACONTROL_H
#define _DATACONTROL_H

void selectInsert(Node** root);
void selectDelete(Node** root);
void selectPrint(Node** root);
void selectEnd(Node** root);
void selectInterConnect();
void createThread();
void* threadFunc(void* ptr);
void threadCleanUp(void *cleanUpArg);
void printNode(Node** root);
void insertNode(Node** root, Node* insNode);
void deleteNode(Node** root, int num);
void releaseNode(Node** root);
Node* searchSameNode(Node** root, int num);

void selectTransfer();
int transferData();
gboolean cbTransferData(gpointer num);
#endif
