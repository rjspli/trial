#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commonType.h"
#include "initAndTerm.h"
#include "dataControl.h"
#include "fileLoadWrite.h"

extern node *head, *tail;

int exeFunc(int (**pF)(void), int sel, int *ret){
	pF[sel]();
	*ret = 0;
	return 0;
}

int insertNode(node *head, node *tail, elem data){
	elem *newNode, *list;
	list = (elem *)head;

	while(list->next != (elem *)tail){
		list = list->next;
		if(list->num == data.num){
			printf("입력 실패 했습니다.(같은 번호존재)\n");
			return 0;
		}
	}
	newNode = (elem *)malloc(sizeof(elem));
	memset(newNode, '\0', sizeof(elem));

	newNode->prev = list;
	newNode->next = (elem *)tail;
	strncpy(newNode->name, data.name, sizeof(newNode->name));
	newNode->age = data.age;
	newNode->num = data.num;
	head->cnt++;
	tail->cnt++;

	list->next = newNode;
	tail->prev = newNode;
	return 0;
}

int deleteNode(node *head, node *tail, int num){
	elem *list;
	list = head->next;
	while(list != (elem *)tail){
		if(list->num == num){
			list->next->prev = list->prev;
			list->prev->next = list->next;
			head->cnt = head->cnt-1;
			tail->cnt = tail->cnt-1;
			free(list);
			return 0;
		}
		list = list->next;
	}
	printf("삭제할 번호가 없습니다.\n");
	return 0;
}

int printNode(node *head, node *tail){
	elem *list;
	list = head->next;
	printf("|번호|이름|나이|\n");
	while(list != (elem*)tail){
		printf("|%d|%s|%d|\n"
		, list->num, list->name, list->age);
		list = list->next;
	}
	return 0;
}

int selectInsert(){
	elem data;
	printf("번호를 입력하세요: ");
	if(scanf("%d", &data.num) == 0){
	}
	while(getchar() != '\n');

	printf("이름을 입력하세요 (제한글자수 %d): "
		, (int)sizeof(data.name)-1);
	if(fgets(data.name, sizeof(data.name), stdin) == 0){
	}
	if(data.name[strlen(data.name)-1] == '\n'){
		data.name[strlen(data.name)-1] = '\0';
	}
	fflush(stdin);

	printf("나이를 입력하세요: ");
	if(scanf("%d", &data.age) == 0){
	}
	while(getchar() != '\n');
	insertNode(head, tail, data);

	return 0;
}

int selectDelete(){
	int num;
	printf("번호를 입력하세요: ");
	if(scanf("%d", &num) == 0){
	}
	deleteNode(head, tail, num);
	return 0;
}

int selectPrint(){
	printNode(head, tail);
	return 0;
}

int selectEnd(){
	saveData(head, tail);
	releaseNode(head, tail);
	return 0;
}
