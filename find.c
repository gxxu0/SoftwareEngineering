//옵션 4.검색하기 기능
#include <stdio.h>
#include <stdlib.h> //for exit(1)
#include <string.h>
void find(){
	FILE* nzg;
	nzg = fopen("test.txt", "r"); //list.c
	char buffer[256];
	char word[256]; //검색할 상품 입력
	int line_num = 0;
	int menuchoice; //메인화면으로 돌아가기

	printf("  ****************************************************************\n");
	printf("  *                                                              *\n");
	printf("  *                       유통기한 검색하기                      *\n");
	printf("  *                                                              *\n");
	printf("  ****************************************************************\n\n");
	printf("    검색할 상품을 입력하세요 : ");
	scanf("%s", &word);

	do {
		while (fgets(buffer, 300, nzg)) {
				line_num++;

				if (strstr(buffer, word)){ //문자열 찾아주는 함수
					printf("\n  %s",  buffer);
					for (int i = line_num; i < line_num + 4 ; i++){
						if (fgets(buffer, 300, nzg) == NULL)
							break;
					printf("  %s", buffer);

					}
				}
		}
		fclose(nzg);

		printf("\n  메인화면으로 돌아가려면 '0'을 누르세요 : "); 
		scanf("%d", &menuchoice);

		system("cls");

	} while (menuchoice != 0);
	
	return 0;
}

