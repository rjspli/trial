#include <stdio.h>
#include <stdlib.h>
#include "commonType.h"
#include "dataControl.h"
#include "initAndTerm.h"

extern int getData(void);

void selectPrint(){

}

void selectInsert(Node** root){
	int num = 0;
	Node* insNode = NULL;
	Node* checkNode = NULL;

	num = getData();
	checkNode = searchSameNode(root, num);
	if(checkNode != NULL){
		printf("\n존재하는 번호입니다.\n");
		return;
	}

	insNode = createNode(num);
	insertNode(root, insNode);
}

void selectDelete(){

}

void selectEnd(Node** root){
	releaseNode(root);
}

void insertNode(Node** root, Node* insNode){
	Node* temp = *root;
	if(temp == NULL){
		*root = insNode;
		return;
	}

	if(temp->data->num > insNode->data->num){
		insertNode(&(temp->left), insNode);
	}else if(temp->data->num < insNode->data->num){
		insertNode(&(temp->right), insNode);
	}else{
		return;
	}
}

Node* searchSameNode(Node** root, int num){
	Node* temp = *root;
	if(temp == NULL){
		return NULL;
	}

	if(temp->data->num == num){
		return temp;
	}else if(temp->data->num > num){
		searchSameNode( &(temp->left), num);
	}else{
		searchSameNode( &(temp->right), num);
	}
}

void releaseNode(Node** root){
	if(*root == NULL) return;
	releaseNode(&((*root)->left));
	releaseNode(&((*root)->right));

	free((*root)->data);
	free(*root);
}
