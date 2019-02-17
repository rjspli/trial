#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commonType.h"
#include "initAndTerm.h"

node *createHeadTailNode(){
	node *dummy;
	dummy = (node*)malloc(sizeof(node));
	memset(dummy, '\0', sizeof(node));
	return dummy;
}

int releaseNode(node *head, node *tail){
    elem *list, *oldData;

    list = head->next;
    while( list != (elem *)tail){
        oldData = list;
        list = list->next;
        free(oldData);
    }
    free(head);
    free(tail);
    return 0;
}
