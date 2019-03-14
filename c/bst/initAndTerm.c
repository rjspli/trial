#include <stdio.h>
#include "commonType.h"
#include "initAndTerm.h"

int exeFunc(void (**pF)(Node**), int sel, Node** root, int *ret){
	pF[sel](root);
	*ret = 0;
	return 0;
}

