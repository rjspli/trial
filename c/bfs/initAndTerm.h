#ifndef _INITPROGRAM_H_
#define _INITPROGRAM_H_

int createBFSGraph(graphType *g, int totalCnt);
int releaseBFSGraph(graphType *g);
int createVertexList(int **vList, int totalCnt);
int releaseVertexList(int **vList);

#endif