#include <stdio.h>
#include <string.h>
#include "commonType.h"
#include "initAndTerm.h"
#include "dataControl.h"
#include "fileLoadWrite.h"

node *head, *tail;

int printMenu(){
	int num;
	int (*pF[4])();
	int res = -1;
	pF[0] = selectInsert;
	pF[1] = selectDelete;
	pF[2] = selectPrint;
	pF[3] = selectEnd;
	while(1) {
		puts("");
		puts("1. 입력");
		puts("2. 삭제");
		puts("3. 출력");
		puts("4. 종료");
		printf("메뉴선택:" );
		scanf("%d", &num);
		while(getchar() != '\n');
		puts("");
		if(num > 0 && num < 5){
			exeFunc(pF, (num-1), &res);
			printf("실행결과:%d\n", res);
		}else{
			printf("다시 선택하세요.\n");
			continue;
		}
		if(num == 4){
			return 0;
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
