#include <stdio.h>
#include "commonType.h"
#include "initAndTerm.h"
#include "dataControl.h"

extern node *head, *tail;

int selectEnd(){
	releaseNode(head, tail);
	return 0;
}
