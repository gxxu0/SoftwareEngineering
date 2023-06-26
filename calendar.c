//ù ȭ�� - (�޷� �������� �κ�)
#include <time.h>
#include <Windows.h>
#define leapyear(year) ((year)%4==0 && ((year)%100 != 0 || (year)%400 == 0))

void calendar() {
    int fontcoloryellow = 14;
    int fontcolorwhite = 7;

    struct tm* t; //���� ��¥ Ȯ�ο�
    time_t timer;
    timer = time(NULL);
    t = localtime(&timer);

    int i = 0;
    int year = 0, month = 0;
    int day[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    int days, first_date, count;
    days = 0;
    first_date = 0;
    count = 0;

    year = t->tm_year + 1900;
    month = t->tm_mon + 1;

    printf("  *                           %d. %d                 ", year, month);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fontcoloryellow);
    printf("Today    ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fontcolorwhite);
    printf("*\n  *");
    printf("                                                             *\n");
    printf("  *                                                             *");
    printf("\n  *     SUN     MON     TUE     WED     THU     FRI     SAT     *  \n  *");

    days = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
    for (int i = 0; i < month - 1; i++)
    {
        if (i == 1)
        {
            if (leapyear(year))
                day[1] = 29;
            else
                day[1] = 28;
        }
        days += day[i];
    }
    first_date = days % 7; //7�Ͼ� �����ָ� ���޿��� �����޷� �Ѿ �� ù�� ĭ�� ä�� count

    for (int i = 0; i <= first_date; i++)
    {
        printf("\t");
        count++;
    }
    printf("\t");

    for (int i = 1; i <= day[month - 1]; i++)
    {
        if (count >= 7)
        {
            printf("*  ");
            printf("\n");
            printf("  *");
            count = 0;
            printf("\t");

        }
        if (i == t->tm_mday) //���� ��¥�� ��� �����
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fontcoloryellow);
        printf("%d\t", i);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fontcolorwhite);

        count++;

    }

    if (count == 0)
        printf("\t\t\t\t\t\t\t");
    else if (count == 1)
        printf("\t\t\t\t\t\t");
    else if (count == 2)
        printf("\t\t\t\t\t");
    else if (count == 3)
        printf("\t\t\t\t");
    else if (count == 4)
        printf("\t\t\t");
    else if (count == 5)
        printf("\t\t");
    else if (count == 6)
        printf("\t");

    printf("*  ");
    printf("\n");

}