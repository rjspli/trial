#ifndef _COMMONTYPE_H
#define _COMMONTYPE_H

typedef struct _data{
	int num;
}Data;

typedef struct _node{
	struct _node* left;
	struct _node* right;
	Data* data;
}Node;

#endif
