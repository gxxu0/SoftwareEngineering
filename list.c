//�ɼ�2. ��� ����
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
void list(){
    char buf[100];
    int menuchoice; //����ȭ������ ���ư���

    do {
        FILE* fp = fopen("test.txt", "rt"); //���� ���
        printf("  ****************************************************************\n");
        printf("  *                                                              *\n");
        printf("  *                        ������� ���                         *\n");
        printf("  *                                                              *\n");
        printf("  ****************************************************************\n\n");
        
        for (int i = 0; ; i++){
            if (fgets(buf, sizeof(buf), fp) == NULL)
                break;
            printf("%s", buf);
        }

        printf("\n  ����ȭ������ ���ư����� '0'�� �������� : "); //1�̶� �Ǿ������� ���� �ƹ��ų� ok
        scanf("%d", &menuchoice);

        system("cls");
    } while (menuchoice != 0);
    return 0;
}