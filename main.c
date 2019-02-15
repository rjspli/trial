#include <stdio.h>

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
	printMenu();
	return 0;
}
