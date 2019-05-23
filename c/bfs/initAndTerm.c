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
int createVertexList(int **vList, int totalCnt) {
	*vList = (int*)malloc(sizeof(int)*totalCnt);
	return 0;
}
int releaseVertexList(int **vList) {
	free(*vList);
	return 0;
}