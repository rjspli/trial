#ifndef _DATACONTROL_H_
#define _DATACONTROL_H_

int insertTotalVertex(int *vCnt);
int insertEachVertex(graphType *g, int v, int totalCnt);
int inputVertexList(int **vList, int totalCnt, int vCnt);
int isSameDest(int **compVlist, int totalCnt, int dest);
int sortNearList(int **vList, int totalCnt);
int insertEachEdge(graphType *g, int groupV, int v);
int printNearList(graphType* g);
int isQueueEmpty(LQType *LQ);
int enQueue(LQType *LQ, int v);
int deQueue(LQType *LQ);
int bfsNearList(graphType *g, int v);
#endif
