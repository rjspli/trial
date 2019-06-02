#include <stdio.h>
#include <stdlib.h>
#include "commonType.h"
#include "initAndTerm.h"
#include "dataControl.h"
#include <mcheck.h>

int main(int argc, char *argv[]){
	mtrace();
	graphType *graph;
	int *tempVl;
	int i = 0;
	int vertexCreatedCnt = 0, vertexCnt = 0;

	graph = (graphType*)malloc(sizeof(graphType));
	
	insertTotalVertex(&vertexCreatedCnt);

	createBFSGraph(graph, vertexCreatedCnt);

	for(i=0; i< vertexCreatedCnt; i++){
		insertEachVertex(graph,i, vertexCreatedCnt);
	}

	createVertexList(&tempVl, vertexCreatedCnt);

	while(vertexCnt < vertexCreatedCnt){
		inputVertexList(&tempVl, vertexCreatedCnt, vertexCnt);
		sortNearList(&tempVl, vertexCreatedCnt);
		for(i=0; i < vertexCreatedCnt; i++){
			if(tempVl[i] != -1){
				insertEachEdge(graph, vertexCnt, tempVl[i]);
			}
		}
		vertexCnt++;
	}

	releaseVertexList(&tempVl);

	printNearList(graph);

	bfsNearList(graph, 0);
	
	releaseNearListHead(graph, vertexCreatedCnt);
	
	releaseBFSGraph(graph);
	
	free(graph);
	return 0;
	muntrace();
}
