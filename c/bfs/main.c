#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commonType.h"
#include "initAndTerm.h"
#include "dataControl.h"

#define TOT_MENU_CNT 5
int vertexCreatedCnt = 0, vertexCnt = 0;
extern LQType *Q;

int getSelection(void){
    int selectNum = 0;

    printf("\n");
    printf("1. input total vertex count\n");
    printf("2. input vertex and that of near vertex\n");
    printf("3. delete near vertex of vertex\n");
    printf("4. print vertex and bfs result\n");
    printf("5. end\n");
    printf("select menu: ");
    scanf("%d", &selectNum);
    while(getchar() != '\n');

    return selectNum;
}
int exeFunc(void (**pF)(graphType**), int sel, graphType** graph, int *ret){
    pF[sel](graph);
    *ret = 0;
    return 0;
}
void selectInputVertexCnt(graphType **graph) {
    int i = 0;

    printf(" current Vertex Count : %d\n", vertexCreatedCnt);
    insertTotalVertex(&vertexCreatedCnt);
    createBFSGraph(*graph, vertexCreatedCnt);

    for (i = 0; i < vertexCreatedCnt; i++) {
        insertEachVertex(*graph, i, vertexCreatedCnt);
    }
}
void selectInputNearListOfVertex(graphType **graph){
    int *tempVl;
    int i = 0;
    vertexCnt = 0;

    if ((*graph)->n == 0) {
        printf(" !!!there is no vertex count\n");
        return;
    }
    createVertexList(&tempVl, vertexCreatedCnt);
    vertexCnt = requestTargetVertex(1);
    if ((*graph)->nearListHead[vertexCnt] != NULL) {
        eraseNearListOfVertex(*graph, vertexCnt);
    }
    inputVertexList(&tempVl, vertexCreatedCnt, vertexCnt);
    sortNearList(&tempVl, vertexCreatedCnt);
    for(i=0; i < vertexCreatedCnt; i++){
        if(tempVl[i] != -1){
            insertEachEdge(*graph, vertexCnt, tempVl[i]);
        }
    }
    releaseVertexList(&tempVl);
}
void selectDeleteNearListOfVertex(graphType **graph) {
    int i = 0;
    vertexCnt = 0;

    if ((*graph)->n == 0) {
        printf(" !!!there is no vertex count\n");
        return;
    }
    vertexCnt = requestTargetVertex(2);
    deleteNearList(*graph, vertexCnt);
}
void selectPrint(graphType **graph) {
    vertexCnt = 0;

    if ((*graph)->n == 0) {
        printf(" !!!there is no vertex count\n");
        return;
    }
    printNearList(*graph);
    while (vertexCnt < vertexCreatedCnt) {
        checkExistAcrossEdge(*graph, vertexCnt, vertexCreatedCnt);
        vertexCnt++;
    }
    bfsNearList(*graph, 0);
}
void selectEnd(graphType **graph){
    releaseNearListHead(*graph, vertexCreatedCnt);
    releaseBFSGraph(*graph);
    free(*graph);
}
int main(int argc, char *argv[]){
    graphType *graph;
    int selNum = 0, res = -1;

    graph = (graphType*)malloc(sizeof(graphType));
    memset(graph, '\0', sizeof(graph));
    void (*pF[TOT_MENU_CNT])(graphType**) = {selectInputVertexCnt
        , selectInputNearListOfVertex, selectDeleteNearListOfVertex, selectPrint, selectEnd};
    while(selNum != TOT_MENU_CNT){
        selNum = getSelection();
        if(selNum > 0 && selNum < (TOT_MENU_CNT+1) ){
            exeFunc( pF, (selNum-1), &graph, &res );
            printf(" execute result: %d\n", res);
        }else{
            printf(" !!!select menu again\n");
            continue;
        }
    }

    return 0;
}
