#include <stdio.h>
#include <stdlib.h>
#include "commonType.h"
#include "fileLoadWrite.h"

void loadData(node *head, node *tail){
	FILE *fp;
	elem *oldData, *newData;
	const char *f = "file.txt";
	if((fp=fopen(f,"r"))==NULL ){
		printf("load file not Exist\n");
		return;
	}
	newData = (elem *)malloc(sizeof(elem));
	head->next = newData;
	newData->prev = (elem *)head;

	while(fscanf(fp, "%d %s %d", &newData->num
			, newData->name, &newData->age) != EOF) {
		head->cnt++;
		tail->cnt++;
		oldData = newData;
		newData = (elem *)malloc(sizeof(elem));
		oldData->next = newData;
		newData->prev = oldData;
	}
	if(head->cnt == 0){
		head->next = (elem*)tail;
	}else{
		oldData->next = (elem *)tail;
		tail->prev = oldData;
	}
	free(newData);
	fclose(fp);
}

void saveData(node *head, node *tail){
	FILE *fp;
	elem *list;
	const char *f = "file.txt";
	if((fp = fopen(f, "wt")) == NULL){
		printf("file write error\n");
		return;
	}
	list = head->next;
	while(list != (elem *)tail){
		fprintf(fp, "%d %s %d\n", list->num, list->name, list->age);
		list = list->next;
	}
	fclose(fp);
}
