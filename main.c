#include <stdio.h>
#include <string.h>
#include "commonType.h"
#include "initAndTerm.h"
#include "dataControl.h"
#include "fileLoadWrite.h"

node *head, *tail;

int printMenu(){
	int num;
	while(1) {
		puts("");
		puts("1. 입력");
		puts("2. 삭제");
		puts("3. 출력");
		puts("4. 종료");
		puts("메뉴선택:" );
		scanf("%d", &num);
		while(getchar() != '\n');
		switch(num){
		case 1:
			selectInsert();
			continue;
		case 2:
			selectDelete();
			continue;
		case 3:
			selectPrint();
			continue;
		case 4:
			selectEnd();
			return 0;
		default:
			printf("다시 선택하세요.\n");
			continue;
		}
	}
	return 0;
}

int main(int argc, char *argv[]){
	head = createHeadTailNode();
	tail = createHeadTailNode();
	memset(head, '\0', sizeof(node));
	memset(head, '\0', sizeof(node));

	head->next = (elem *)tail;
	head->prev = (elem *)tail;

	tail->next = (elem *)head;
	tail->prev = (elem *)head;
	
	loadData(head, tail);
	printNode(head, tail);
	printMenu();
	return 0;
}
