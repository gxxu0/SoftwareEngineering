//�ɼ� 4.�˻��ϱ� ���
#include <stdio.h>
#include <stdlib.h> //for exit(1)
#include <string.h>
void find(){
	FILE* nzg;
	nzg = fopen("test.txt", "r"); //list.c
	char buffer[256];
	char word[256]; //�˻��� ��ǰ �Է�
	int line_num = 0;
	int menuchoice; //����ȭ������ ���ư���

	printf("  ****************************************************************\n");
	printf("  *                                                              *\n");
	printf("  *                       ������� �˻��ϱ�                      *\n");
	printf("  *                                                              *\n");
	printf("  ****************************************************************\n\n");
	printf("    �˻��� ��ǰ�� �Է��ϼ��� : ");
	scanf("%s", &word);

	do {
		while (fgets(buffer, 300, nzg)) {
				line_num++;

				if (strstr(buffer, word)){ //���ڿ� ã���ִ� �Լ�
					printf("\n  %s",  buffer);
					for (int i = line_num; i < line_num + 4 ; i++){
						if (fgets(buffer, 300, nzg) == NULL)
							break;
					printf("  %s", buffer);

					}
				}
		}
		fclose(nzg);

		printf("\n  ����ȭ������ ���ư����� '0'�� �������� : "); 
		scanf("%d", &menuchoice);

		system("cls");

	} while (menuchoice != 0);
	
	return 0;
}

