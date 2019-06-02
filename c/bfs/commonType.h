#ifndef _COMMONTYPE_H
#define _COMMONTYPE_H

#define FALSE 0
#define TRUE 1

typedef struct _graphNode{
	int vertex;
	struct _graphNode* link;
} graphNode;

typedef struct _graphType{
	int n;
	graphNode** nearListHead;
	int* visited;
} graphType;

typedef struct _queueNode{
	int n;
	struct _queueNode *link;
} queueNode;

typedef struct _LQType{
	queueNode *front, *rear;
} LQType;
#endif
