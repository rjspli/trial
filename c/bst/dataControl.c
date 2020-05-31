#include <stdio.h>
#include <stdlib.h>
#include "commonType.h"
#include "dataControl.h"
#include "initAndTerm.h"
#include <pthread.h>

extern int getData(void);
pthread_t pThread;
THREAD_STATE existThr = THREAD_DISABLE;

void selectPrint(Node** root){
    printf("\n|번호|\n");
    printNode(root);
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

void selectDelete(Node** root){
    int num = 0;
    Node* checkNode = NULL;
    num = getData();
    checkNode = searchSameNode(root, num);
    if(checkNode == NULL){
        printf("\n없는 번호입니다.\n");
        return;
    }
    deleteNode(root, num);
}

void selectEnd(Node** root){
    releaseNode(root);
}

void selectInterConnect() {
    createThread();
}

void createThread() {
    int param = 0;
    int thrCreateRes = 0;

    if (existThr == THREAD_ENABLE) {
        existThr = THREAD_DISABLE;
    }
    else {
        thrCreateRes = pthread_create(&pThread, NULL
                , threadFunc, (void*)&param);
        pthread_detach(pThread);
        existThr = THREAD_ENABLE;
    }
}

void* threadFunc(void* threadFuncArg) {
    int cleanUpParam = 0;

    pthread_cleanup_push(threadCleanUp, (void *)&cleanUpParam);
    while (1) {
        if (existThr == THREAD_DISABLE) {
            break;
        }
    }
    pthread_exit(NULL);
    pthread_cleanup_pop(0);
}

void threadCleanUp(void *cleanUpArg) {
    printf("\n %s %d\n",__FUNCTION__, *((int*)cleanUpArg));
}

void printNode(Node** root){
    Node* temp = *root;
    if(temp == NULL){
        printf("\n");
        return;
    }
    if(temp->left != NULL){
        printNode(&(temp->left));
    }
    printf("|%d|\n", temp->data->num);
    if(temp->right != NULL){
        printNode(&(temp->right));
    }
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

void deleteNode(Node** root, int num){
    Node* temp = *root;
    Node *p, *child, *parent, *replace, *replace_parent;

    parent = NULL;
    p = temp;
    while( (p != NULL)&&(p->data->num != num) ){
        parent = p;
        if(p->data->num > num) p = p->left;
        else p = p->right;
    }
    if((p->left == NULL)&&(p->right == NULL)){
        if(parent != NULL){
            if(parent->left == p) parent->left = NULL;
            else parent->right = NULL;
        }else{
            temp = NULL;
            *root = temp;
        }
    }else if((p->left == NULL) || (p->right == NULL)){
        if(p->left != NULL) child = p->left;
        else child = p->right;

        if(parent != NULL){
            if(parent->left = p ) parent->left=child;
            else parent->right = child;
        }else{
            temp = child;
            *root = temp;
        }
    }else{
        replace_parent = p;
        replace = p->left;
        while(replace->right != NULL){
            replace_parent = replace;
            replace = replace->right;
        }
        if(replace_parent->left == replace)
            replace_parent->left = replace->left;
        else
            replace_parent->right = replace->left;
        p->data->num = replace->data->num;
        p = replace;
    }
    free(p->data);
    free(p);
}

void releaseNode(Node** root){
    if(*root == NULL) return;
    releaseNode(&((*root)->left));
    releaseNode(&((*root)->right));

    free((*root)->data);
    free(*root);
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
