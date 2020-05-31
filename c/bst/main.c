#include <gtk/gtk.h>
#include <stdio.h>
#include "commonType.h"
#include "initAndTerm.h"
#include "dataControl.h"

#define TOT_MENU_CNT 6
extern THREAD_STATE existThr;

int getSelection(void){
    int selectNum = 0;
    printf("\n");
    printf("1. 출력\n");
    printf("2. 입력\n");
    printf("3. 삭제\n");
    printf("4. 종료\n");
    if (existThr == THREAD_DISABLE) {
        printf("5. 상호통신(비활성중)\n");
    }
    else {
        printf("5. 상호통신(활성중)\n");
        printf("6. 타임아웃(2sec) 테스트\n");
    }
    printf("메뉴선택:");
    scanf("%d", &selectNum);
    while(getchar() != '\n');
    return selectNum;
}

int getData(void){
    int num = 0;

    printf("번호를 입력하세요: ");
    scanf("%d", &num);
    while(getchar() != '\n');
    return num;
}

int main(int argc, char* argv[]){
    gtk_init(NULL, NULL);
    int selNum = 0;
    Node* root = NULL;
    void (*pF[TOT_MENU_CNT])(Node**) = {selectPrint, selectInsert
        , selectDelete, selectEnd, selectInterConnect, selectTransfer };
    int res = -1;
    //while(selNum != TOT_MENU_CNT -1){
    while (1) {
        selNum = getSelection();
        if(selNum > 0 && selNum < (TOT_MENU_CNT+1) ){
            exeFunc(pF, (selNum-1), &root, &res);
            printf("실행결과:%d\n", res);
            if (selNum == 4) {
                break;
            }
        }else{
            printf("다시 선택하세요.\n");
            continue;
        }
    }
    return 0;
}
