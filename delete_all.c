//�ɼ�3. ��� �ʱ�ȭ
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void delete_all()
{
    FILE* nzg;
    int menuchoice; 

    do {
        nzg = fopen("test.txt", "w"); // ���� ���� ����鼭 ���� �������� ����

        fclose(nzg);
        printf("  ****************************************************************\n");
        printf("  *                                                              *\n");
        printf("  *                   ������� ��� �ʱ�ȭ                       *\n");
        printf("  *                                                              *\n");
        printf("  ****************************************************************\n\n");
        printf("\n             ��Ͽ� �ִ� ��� �����͸� �ʱ�ȭ�߽��ϴ�.\n\n");

        printf("             ���� ȭ������ ���ư����� '0'�� �Է��ϼ��� : "); //1�̶� �Ǿ������� ���� �ƹ��ų� ok
        scanf("%d", &menuchoice);

        system("cls");
    } while (menuchoice != 0);

    return 0;
}