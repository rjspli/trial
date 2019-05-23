#include <stdio.h>
#include <stdlib.h>
#include "commonType.h"
#include "dataControl.h"

int insertTotalVertex(int *vCnt) {
	printf("Input total vertex count\n");
	while (1) {
		printf(" ");
		scanf("%d", vCnt);
		while (getchar() != '\n');
		if (*vCnt <= 10 && *vCnt >= 1) {
			break;
		}
		else {
			printf("Total vertex must be maximum 10.\n");
			continue;
		}
	}
	return 0;
}
int insertEachVertex(graphType *g, int v, int totalCnt) {
	if (((g->n) + 1) > totalCnt) {
		printf("\n over vertex\n");
		return 0;
	}
	g->n++;
	return 0;
}
int inputVertexList(int **vList, int totalCnt, int vCnt) {
	int i = 0, lNum = 0, convDest = 0;
	char dest;
	for (i = 0; i < totalCnt; i++) {
		(*vList)[i] = -1;
	}
	lNum = 0;
	while (lNum < totalCnt) {
		printf("Input near vertex of \"%c\" [ex) a enter]. When input \"~\" , then terminate input of vertex group. \n", vCnt + 97);
		printf(" ");
		scanf("%c", &dest);
		while (getchar() != '\n');
		convDest = (int)dest - 97;
		if (convDest == 29) {
			break;
		}
		if (isSameDest(vList, totalCnt, convDest)) {
			printf("Already input near vertex.\n");
			continue;
		}
		else {
			(*vList)[lNum] = convDest;
			lNum++;
		}
	}
	return 0;
}
int isSameDest(int **compVlist, int totalCnt, int dest) {
	int i = 0, result = 0;

	for (i = 0; i < totalCnt; i++) {
		if ((*compVlist)[i] == dest) {
			result = 1;
		}
	}
	return result;
}
int sortNearList(int **vList, int totalCnt) {
	int *tempSort = (int*)malloc(sizeof(int)*totalCnt);
	int i, j, min, temp;
	for (i = 0; i < totalCnt - 1; i++) {
		min = i;
		for (j = i + 1; j < totalCnt; j++) {
			if ((*vList)[j] < (*vList)[min])
				min = j;
		}
		temp = (*vList)[i];
		(*vList)[i] = (*vList)[min];
		(*vList)[min] = temp;
	}
	for (i = 0; i < totalCnt; i++) {
		tempSort[i] = (*vList)[i];
	}
	for (i = 0; i < totalCnt; i++) {
		(*vList)[i] = tempSort[totalCnt - (i + 1)];
	}
	for (i = 0; i < totalCnt; i++) {
		printf("%d(%c) ", (*vList)[i], (*vList)[i] + 97);
	}
	printf("\n");
	free(tempSort);
	return 0;
}
int insertEachEdge(graphType *g, int groupV, int v) {
	graphNode* node;
	if (groupV >= g->n || v > g->n) {
		printf("\n no match vertex\n");
		return 0;
	}
	node = (graphNode *)malloc(sizeof(graphNode));
	node->vertex = v;
	node->link = g->nearListHead[groupV];
	g->nearListHead[groupV] = node;
	return 0;
}
int printNearList(graphType* g) {
	int i;
	graphNode* p;
	printf("\n");
	for (i = 0; i < g->n; i++) {
		printf(" vertex list of %c ", i + 97);
		p = g->nearListHead[i];
		while (p) {
			printf(" -> %c", p->vertex + 97);
			p = p->link;
		}
		printf("\n");
	}
	return 0;
}