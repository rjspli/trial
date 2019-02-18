#ifndef _COMMONTYPE_H
#define _COMMONTYPE_H

typedef struct _elem {
    struct _elem *prev;
    struct _elem *next;
    char name[21];
    int age;
    int num;
} elem;

typedef struct _node {
    elem *prev;
    elem *next;
    int cnt;
} node;

#endif
