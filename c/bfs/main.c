#include <stdio.h>
#include <stdlib.h>
#include "commonType.h"
#include "initAndTerm.h"
#include "dataControl.h"

#define TOT_MENU_CNT 2

int getSelection(void){
	int selectNum = 0;
	printf("\n");
	printf("1. input graph\n");
	printf("2. end\n");
	printf("select menu:");
	scanf("%d", &selectNum);
	while(getchar() != '\n');
	return selectNum;
}
int exeFunc(void (**pF)(graphType**), int sel, graphType** graph, int *ret){
    pF[sel](graph);
    *ret = 0;
    return 0;
}
void selectInput(graphType **graph){

	int *tempVl;
	int i = 0;
	int vertexCreatedCnt = 0, vertexCnt = 0;

	insertTotalVertex(&vertexCreatedCnt);

    createBFSGraph(*graph, vertexCreatedCnt);

    for(i=0; i< vertexCreatedCnt; i++){
        insertEachVertex(*graph, i, vertexCreatedCnt);
    }

    createVertexList(&tempVl, vertexCreatedCnt);

    while(vertexCnt < vertexCreatedCnt){
        inputVertexList(&tempVl, vertexCreatedCnt, vertexCnt);
        sortNearList(&tempVl, vertexCreatedCnt);
        for(i=0; i < vertexCreatedCnt; i++){
            if(tempVl[i] != -1){
                insertEachEdge(*graph, vertexCnt, tempVl[i]);
            }
        }
        vertexCnt++;
    }

    releaseVertexList(&tempVl);

    printNearList(*graph);

    vertexCnt = 0;
    while(vertexCnt < vertexCreatedCnt){
        checkExistAcrossEdge(*graph, vertexCnt, vertexCreatedCnt);
        vertexCnt++;
    }

    bfsNearList(*graph, 0);

    releaseNearListHead(*graph, vertexCreatedCnt);

    releaseBFSGraph(*graph);

}
void selectEnd(graphType **graph){
	free(*graph);
}
int main(int argc, char *argv[]){
	graphType *graph;
	
	graph = (graphType*)malloc(sizeof(graphType));
	
	int selNum = 0, res = -1;
	void (*pF[TOT_MENU_CNT])(graphType**) = {selectInput, selectEnd};
	while(selNum != TOT_MENU_CNT){
		selNum = getSelection();
		if(selNum > 0 && selNum < (TOT_MENU_CNT+1) ){
			exeFunc( pF, (selNum-1), &graph, &res );
			printf(" execute result: %d\n", res);
		}else{
			printf("다시 선택하세요.\n");
			continue;
		}
	}

	return 0;
}
