//���� ���α׷� 
#include <stdio.h>
#include <Windows.h>
extern void calendar(void);
extern void expiration_date(void);

int main(void) {
    int opt; //����� ���� �ɼ�
    int backtomain = 0; //����ȭ������ ����

mainmenu:
    printf("  ***************************************************************\n");
    printf("  *                                                             *\n");
    printf("  *                   ����� ������� ���α׷�                  *\n");
    printf("  *                                                             *\n");
    printf("  ***************************************************************\n");

    calendar();
    printf("  ***************************************************************\n\n\n");

    printf("                1. ������� ���� �Է��ϱ�\n\n"); //�ɼ� 1
    printf("                2. ������� ��� ����\n\n"); //�ɼ� 2
    printf("                3. ������� ��� �ʱ�ȭ\n\n"); //�ɼ� 3
    printf("                4. �˻��ϱ�\n\n"); //�ɼ�4
    printf("                5. ������\n\n"); //������ �ɼ�
    printf("                ���ϴ� ����� �����ϼ��� : ");
    scanf("%d", &opt);
    system("cls");

    switch (opt) {
    case 1:
        // 1. ������� ���� �Է��ϱ�
        expiration_date();
        goto mainmenu;
        break;

    case 2:
        // 2. ������� ����
        list();
        goto mainmenu;
        break;

    case 3:
        // �ʱ�ȭ
        delete_all();
        goto mainmenu;
        break;

    case 4://�˻��ϱ� ���
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