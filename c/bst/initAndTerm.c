#include <stdio.h>
#include <stdlib.h>
#include "commonType.h"
#include "initAndTerm.h"

int exeFunc(void (**pF)(Node**), int sel, Node** root, int *ret){
	pF[sel](root);
	*ret = 0;
	return 0;
}

Data* createData(int num){
	Data* temp = (Data*) malloc(sizeof(Data));
	temp->num = num;

	return temp;
}

Node* createNode(int num){
	Node* temp = NULL;
	Data* dataAddr = NULL;

	temp = (Node*) malloc(sizeof(Node));
	dataAddr = createData(num);

	temp->data = dataAddr;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}
