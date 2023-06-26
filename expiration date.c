//옵션1. 유통기한 정보 입력하기
#include<stdio.h>
#pragma warning(disable:4996)
#include <windows.h>
long totalday(int y, int m, int d);
#include<string.h>
#include <stdlib.h>
#include <time.h> //현재 시간을 구하기 위한 헤더파일 참조
long dates ; //전역변수로 선언

void expiration_date() {
    int in_y, in_m, in_d, out_y, out_m, out_d; // in_y ~in_d는 음식을 사온 날짜, out_y~out_d는 유통기한 만료 날짜
    int menuchoice;
    
    char food[10]; //식품명 입력
    time_t timer;
    struct tm* t; //time() 함수를 호출하여 현재의 날짜, 시간을 얻어 time_t변수에 저장
    timer = time(NULL); // 1970년 1월 1일 0시 0분 0초부터 시작하여 현재까지의 초
    t = localtime(&timer); // 포맷팅을 위해 구조체에 넣기

    do {
        FILE* nzg; //list.c
        nzg = fopen("test.txt", "a+"); //list.c
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

        printf("  ****************************************************************\n");
        printf("  *                                                              *\n");
        printf("  *                       유통기한 입력하기                      *\n");
        printf("  *                                                              *\n");
        printf("  ****************************************************************\n\n");

        printf("               식품명 -> ");
        scanf(" %s", &food);
        
        printf("\n               [형식: %d %d %d]\n", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);
        printf("               사온날짜 -> ");
        scanf(" %d %d %d", &in_y, &in_m, &in_d);

        printf("\n               유통기한 -> ");
        scanf("%d %d %d", &out_y, &out_m, &out_d);

        dates = totalday(out_y, out_m, out_d) - totalday(in_y, in_m, in_d);
        if (dates > 3) {
            printf("\n               이 식품의 유통기한은 %ld 일 전 입니다.", dates);
        }
        else if (dates <= 3 && dates > 0) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); //유통기한이 3일 이하로 남았을 때 글자 색을 빨간색으로 설정
            printf("\n               이 식품의 유통기한은 %ld 일 전 입니다.", dates);
        }
        else if (dates == 0) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);  //유통기한이 당일일 때 글자 색을 노란색으로 설정
            printf("\n               유통기한이 오늘까지 입니다.");
        }
        else if (dates < 0) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // 유통기한이 지났을 때 글자 색을 초록색으로 설정
            printf("\n               이미 유통기한이 지난 상품입니다.");
        }

        //옵션 2(목록)에 활용될 txt파일에 해당 내용 
        fputs("  식품명: ", nzg);  //list.c
        fputs(food, nzg);  //list.c
        fputs("\n  사온 날짜: ", nzg);  //list.c
        fprintf(nzg, " %d %d %d", in_y, in_m, in_d);  //list.c
        fputs("\n  유통기한 날짜: ", nzg);  //list.c
        fprintf(nzg, "%d.%d.%d", out_y, out_m, out_d);  //list.c
        fprintf(nzg, "\n  유통기한 %ld일 전", dates);  //list.c
        
        fputs("\n  --------------------------------------------------------\n", nzg);  //list.c

        fclose(nzg);  //list.c

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        printf("\n\n  추가 입력하려면 '1' ,메인메뉴로 돌아가려면 '0'을 입력하세요 -> "); //1이라 되어있지만 숫자 아무거나 ok
        scanf("%d", &menuchoice);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

        system("cls");
    } while (menuchoice != 0);
}

long totalday(int y, int m, int d) {
    int months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int i;
    long total = 0L;
    total = (y - 1) * 365L + (y - 1) / 4 - (y - 1) / 100 + (y - 1) / 400;
    if (!(y % 4) && y % 100 || !(y % 400))
        months[1]++;
    for (i = 0; i < m - 1; i++)
        total += months[i];
    total += d;
    return total;
} //날짜 계산 코드