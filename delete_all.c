//옵션3. 목록 초기화
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void delete_all()
{
    FILE* nzg;
    int menuchoice; 

    do {
        nzg = fopen("test.txt", "w"); // 기존 내용 지우면서 쓰기 전용으로 열기

        fclose(nzg);
        printf("  ****************************************************************\n");
        printf("  *                                                              *\n");
        printf("  *                   유통기한 목록 초기화                       *\n");
        printf("  *                                                              *\n");
        printf("  ****************************************************************\n\n");
        printf("\n             목록에 있던 모든 데이터를 초기화했습니다.\n\n");

        printf("             메인 화면으로 돌아가려면 '0'을 입력하세요 : "); //1이라 되어있지만 숫자 아무거나 ok
        scanf("%d", &menuchoice);

        system("cls");
    } while (menuchoice != 0);

    return 0;
}