#include <stdio.h>
#include <string.h>
#include "commonType.h"
#include "initAndTerm.h"
#include "dataControl.h"

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
			//TODO
			continue;
		case 2:
			//TODO
			continue;
		case 3:
			//TODO
			continue;
		case 4:
			//TODO
			return 0;
		default:
			printf("다시 선택하세요.\n");
			continue;
		}
	}
	return 0;
}


int main(int argc, char **argv){
	head = createHeadTailNode();
	tail = createHeadTailNode();
	memset(head, '\0', sizeof(node));
	memset(head, '\0', sizeof(node));

	head->next = (elem*)tail;
	head->prev = (elem*)tail;

	tail->next = (elem*)head;
	tail->prev = (elem*)head;

	printMenu();
	return 0;
}
