#include <stdio.h>
#include <stdlib.h>
#include "commonType.h"
#include "dataControl.h"
#include "initAndTerm.h"

LQType *Q;
extern int vertexCreatedCnt;

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
            printf(" !!!Total vertex must be over 0.\n");
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
int requestTargetVertex(int type) {
    char destVertex;
    int convVertex = 0;

    if(type == 1)
        printf("input one vertex to insert near list(ex. a). existed vertex will be overwrited.: ");
    else
        printf("input one vertex to insert near list(ex. a).");
    scanf("%c", &destVertex);
    while (getchar() != '\n');
    convVertex = (int)destVertex - 97;

    return convVertex;
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
            if(isNotExistAnyVertex(vList, totalCnt)){
                printf(" !!!Least 1 vertex should be inserted\n");
                continue;
            }else{
                break;
            }
        }
        if (isSameDest(vList, totalCnt, convDest)) {
            printf(" !!!Already input near vertex.\n");
            continue;
        }
        else {
            (*vList)[lNum] = convDest;
            lNum++;
        }
    }
    return 0;
}
int isNotExistAnyVertex(int **compVlist, int totalCnt){
    int i = 0, result = 1;
    int *tempVlist = *compVlist;

    for(i = 0; i < totalCnt; i++){
        if(tempVlist[i] != -1){
            result = 0;
        }
    }
    return result;
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
int deleteNearList(graphType *g, int groupV) {
    int i = 0, lNum = 0, convDest = 0;
    char dest;
    graphNode *curP = NULL, *nextP = NULL;

    nextP = g->nearListHead[groupV];
    if (nextP != NULL) {
        printf("Input one near vertex of \"%c\" to delete [ex) a enter]. \n", groupV + 97);
        printf(" ");
        scanf("%c", &dest);
        while (getchar() != '\n');
        convDest = (int)dest - 97;
        if (nextP->vertex == convDest) {
            curP = nextP;
            nextP = curP->link;
            g->nearListHead[groupV] = nextP;
            free(curP);
        }
        while (nextP) {
            curP = nextP;
            nextP = curP->link;
            if (nextP != NULL && nextP->vertex == convDest) {
                curP->link = nextP->link;
                free(nextP);
                nextP = curP->link;
            }
        }
    }
    else {
        printf(" !!!list is empty\n");
    }

    return 0;
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
int eraseNearListOfVertex(graphType *g, int groupV) {
    graphNode *curP = NULL, *nextP = NULL;
    nextP = g->nearListHead[groupV];
    while (nextP) {
        curP = nextP;
        nextP = curP->link;
        free(curP);
    }
    g->nearListHead[groupV] = NULL;
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
int checkExistAcrossEdge(graphType *g, int groupV, int totalVertex){
    int targetV = groupV;
    int exist = 0;
    graphNode* p = 	g->nearListHead[groupV];
    graphNode* tempP;

    while(p){
        tempP = g->nearListHead[p->vertex];
        exist = vertexAcrossEdge(&tempP, groupV);
        if(exist != 1){
            printf(" !! check vertex %c. There is not exist %c \n", p->vertex + 97, groupV + 97);
        }
        p = p->link;
    }

    return 0;
}
int vertexAcrossEdge(graphNode** tempV, int groupVnum){
    int existResult = 0;
    graphNode* tempP = *tempV;
    while(tempP){
        if(tempP->vertex == groupVnum){
            existResult = 1;
        }
        tempP = tempP->link;
    }
    return existResult;
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
int isQueueEmpty(LQType *LQ){
    if(LQ->front == NULL){
        printf("\n !!!Queue empty.\n");
        return 1;
    }
    else{
        return 0;
    }
}
int enQueue(LQType *LQ, int v){
    queueNode *newNode = (queueNode *)malloc(sizeof(queueNode));
    newNode->n = v;
    newNode->link = NULL;
    if(LQ->front == NULL){
        LQ->front = newNode;
        LQ->rear = newNode;
    }else{
        LQ->rear->link = newNode;
        LQ->rear = newNode;
    }
    return 0;
}
int deQueue(LQType *LQ){
    queueNode *oldNode = LQ->front;
    int v;
    if(isQueueEmpty(LQ)){
        return 0;
    }else{
        v = oldNode->n;
        LQ->front = LQ->front->link;
        if(LQ->front == NULL){
            LQ->rear = NULL;
        }
        free(oldNode);
        return v;
    }
}
int bfsNearList(graphType *g, int v){
    graphNode *GN;
    int i = 0;

    Q = createLQ();
    g->visited[v] = TRUE;
    printf("\n%c ", v+65);
    enQueue(Q, v);
    while(!isQueueEmpty(Q) ){
        v = deQueue(Q);
        for( GN = g->nearListHead[v];GN;GN=GN->link ){
            if(!g->visited[GN->vertex]){
                g->visited[GN->vertex] = TRUE;
                printf("%c ", GN->vertex+65);
                enQueue(Q, GN->vertex);
            }
        }
    }
    for (i = 0; i < vertexCreatedCnt; i++) {
        g->visited[i] = FALSE;
    }
    releaseLQ(&Q);
    return 0;
}
