//메인 프로그램 
#include <stdio.h>
#include <Windows.h>
extern void calendar(void);
extern void expiration_date(void);

int main(void) {
    int opt; //사용자 선택 옵션
    int backtomain = 0; //메인화면으로 가기

mainmenu:
    printf("  ***************************************************************\n");
    printf("  *                                                             *\n");
    printf("  *                   냉장고 유통기한 프로그램                  *\n");
    printf("  *                                                             *\n");
    printf("  ***************************************************************\n");

    calendar();
    printf("  ***************************************************************\n\n\n");

    printf("                1. 유통기한 정보 입력하기\n\n"); //옵션 1
    printf("                2. 유통기한 목록 보기\n\n"); //옵션 2
    printf("                3. 유통기한 목록 초기화\n\n"); //옵션 3
    printf("                4. 검색하기\n\n"); //옵션4
    printf("                5. 끝내기\n\n"); //끝내기 옵션
    printf("                원하는 기능을 선택하세요 : ");
    scanf("%d", &opt);
    system("cls");

    switch (opt) {
    case 1:
        // 1. 유통기한 정보 입력하기
        expiration_date();
        goto mainmenu;
        break;

    case 2:
        // 2. 목록으로 보기
        list();
        goto mainmenu;
        break;

    case 3:
        // 초기화
        delete_all();
        goto mainmenu;
        break;

    case 4://검색하기 기능
        find();
        goto mainmenu;
        break;

    case 5:
        exit(1);
    default:
        goto mainmenu;
    }
    return 0;
}