//옵션2. 목록 보기
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
void list(){
    char buf[100];
    int menuchoice; //메인화면으로 돌아가기

    do {
        FILE* fp = fopen("test.txt", "rt"); //파일 출력
        printf("  ****************************************************************\n");
        printf("  *                                                              *\n");
        printf("  *                        유통기한 목록                         *\n");
        printf("  *                                                              *\n");
        printf("  ****************************************************************\n\n");
        
        for (int i = 0; ; i++){
            if (fgets(buf, sizeof(buf), fp) == NULL)
                break;
            printf("%s", buf);
        }

        printf("\n  메인화면으로 돌아가려면 '0'을 누르세요 : "); //1이라 되어있지만 숫자 아무거나 ok
        scanf("%d", &menuchoice);

        system("cls");
    } while (menuchoice != 0);
    return 0;
}