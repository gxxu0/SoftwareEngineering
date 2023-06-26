//�ɼ�1. ������� ���� �Է��ϱ�
#include<stdio.h>
#pragma warning(disable:4996)
#include <windows.h>
long totalday(int y, int m, int d);
#include<string.h>
#include <stdlib.h>
#include <time.h> //���� �ð��� ���ϱ� ���� ������� ����
long dates ; //���������� ����

void expiration_date() {
    int in_y, in_m, in_d, out_y, out_m, out_d; // in_y ~in_d�� ������ ��� ��¥, out_y~out_d�� ������� ���� ��¥
    int menuchoice;
    
    char food[10]; //��ǰ�� �Է�
    time_t timer;
    struct tm* t; //time() �Լ��� ȣ���Ͽ� ������ ��¥, �ð��� ��� time_t������ ����
    timer = time(NULL); // 1970�� 1�� 1�� 0�� 0�� 0�ʺ��� �����Ͽ� ��������� ��
    t = localtime(&timer); // �������� ���� ����ü�� �ֱ�

    do {
        FILE* nzg; //list.c
        nzg = fopen("test.txt", "a+"); //list.c
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

        printf("  ****************************************************************\n");
        printf("  *                                                              *\n");
        printf("  *                       ������� �Է��ϱ�                      *\n");
        printf("  *                                                              *\n");
        printf("  ****************************************************************\n\n");

        printf("               ��ǰ�� -> ");
        scanf(" %s", &food);
        
        printf("\n               [����: %d %d %d]\n", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);
        printf("               ��³�¥ -> ");
        scanf(" %d %d %d", &in_y, &in_m, &in_d);

        printf("\n               ������� -> ");
        scanf("%d %d %d", &out_y, &out_m, &out_d);

        dates = totalday(out_y, out_m, out_d) - totalday(in_y, in_m, in_d);
        if (dates > 3) {
            printf("\n               �� ��ǰ�� ��������� %ld �� �� �Դϴ�.", dates);
        }
        else if (dates <= 3 && dates > 0) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); //��������� 3�� ���Ϸ� ������ �� ���� ���� ���������� ����
            printf("\n               �� ��ǰ�� ��������� %ld �� �� �Դϴ�.", dates);
        }
        else if (dates == 0) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);  //��������� ������ �� ���� ���� ��������� ����
            printf("\n               ��������� ���ñ��� �Դϴ�.");
        }
        else if (dates < 0) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // ��������� ������ �� ���� ���� �ʷϻ����� ����
            printf("\n               �̹� ��������� ���� ��ǰ�Դϴ�.");
        }

        //�ɼ� 2(���)�� Ȱ��� txt���Ͽ� �ش� ���� 
        fputs("  ��ǰ��: ", nzg);  //list.c
        fputs(food, nzg);  //list.c
        fputs("\n  ��� ��¥: ", nzg);  //list.c
        fprintf(nzg, " %d %d %d", in_y, in_m, in_d);  //list.c
        fputs("\n  ������� ��¥: ", nzg);  //list.c
        fprintf(nzg, "%d.%d.%d", out_y, out_m, out_d);  //list.c
        fprintf(nzg, "\n  ������� %ld�� ��", dates);  //list.c
        
        fputs("\n  --------------------------------------------------------\n", nzg);  //list.c

        fclose(nzg);  //list.c

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        printf("\n\n  �߰� �Է��Ϸ��� '1' ,���θ޴��� ���ư����� '0'�� �Է��ϼ��� -> "); //1�̶� �Ǿ������� ���� �ƹ��ų� ok
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
} //��¥ ��� �ڵ�