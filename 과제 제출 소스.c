/*
컴퓨터프로그래밍 평가과제(배점 25점)
학과 : 컴퓨터공학과
학번 : 202101797
이름 : 손성원

과제 주제 : 코로나 확진 기록일지
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int jindan1();


struct st {
	char str1[10][10];
	int str2[10][10];
};

int main()
{
	struct st st1;
	struct st* pst1;
	pst1 = &st1;
	
	(*pst1).str1[0][0] = jindan1();
	char diary[100] = " ";
	printf("환자의 정보를 다음과 같이 입력해주세요. \n이름 월 일 요일: ");
	scanf("%s %d %d %s", &(*pst1).str1[1], &(*pst1).str2[0][0], &(*pst1).str2[0][1], &(*pst1).str1[2]);
	printf("오늘의 증상과 간단한 소감을 말씀해 주세요. (엔터를 사용하면 기록 중단)\n->");
	scanf(" %[^\n]", diary);
	
	FILE* f;
	f = fopen("covid19 writting.txt", "a");

	if (f == NULL)
	{
		printf("파일이 정상적으로 열리지 않았습니다");
		exit(0);
	}


	else
	{
		printf("파일이 정상적으로 열렸습니다.\n");
	}

	fprintf(f, "작성자이름: %s 작성요일: %d월 %d일 %s\n", (*pst1).str1[1], (*pst1).str2[0][0], (*pst1).str2[0][1], (*pst1).str1[2]);
	fprintf(f, "오늘의 소감: %s\n", diary);
	

	fclose(f);
	printf("%d월 %d일의 일지 작성이 완료 되었습니다.", (*pst1).str2[0][0], (*pst1).str2[0][1]);
	return 0;
}
int jindan1()
{
	char j;
	printf("코로나에 확진되었습니까? \n(확진자면 o 아니면 x를 입력하시오.) : ");
	while (1)
	{
		scanf("%c", &j);
		if (j == 'o')
		{
			printf("확진자기록 일지 작성을 시작합니다.");
			break;
		}
		else if (j == 'x')
		{
			printf("확진자가 아니기에 작성을 취소합니다.");
			exit(0);
		}
		else
		{
			printf("잘못된 입력입니다. 다시 입력하세요: ");
			continue;
		}
	}
	return j;


}

