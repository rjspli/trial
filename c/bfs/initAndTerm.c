#include <stdio.h>
#include <stdlib.h>
#include "commonType.h"
#include "initAndTerm.h"

int createBFSGraph(graphType *g, int totalCnt) {
	int v;
	g->n = 0;
	g->nearListHead = (graphNode**)malloc(sizeof(graphNode*)*totalCnt);
	g->visited = (int*)malloc(sizeof(int)*totalCnt);
	for (v = 0; v < totalCnt; v++) {
		g->nearListHead[v] = NULL;
		g->visited[v] = FALSE;
	}
	return 0;
}
int releaseBFSGraph(graphType *g) {
	free(g->nearListHead);
	free(g->visited);
	return 0;
}
int releaseNearListHead(graphType *g, int totalCnt){
	int v;
	graphNode *curP=NULL, *nextP=NULL;
	for(v = 0;v < totalCnt; v++){
		nextP = g->nearListHead[v];
		while(nextP){
			curP = nextP;
			nextP = curP->link;
			free(curP);
		}
	}
}
int createVertexList(int **vList, int totalCnt) {
	*vList = (int*)malloc(sizeof(int)*totalCnt);
	return 0;
}
int releaseVertexList(int **vList) {
	free(*vList);
	return 0;
}
LQType* createLQ(){
	LQType *LQ;
	LQ = (LQType *)malloc(sizeof(LQType));
	LQ->front = NULL;
	LQ->rear = NULL;
	return LQ;
}
int releaseLQ(LQType **LQ){
	free(*LQ);
	return 0;
}
