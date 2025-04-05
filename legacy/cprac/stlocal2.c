#include <stdio.h>

void find_PW();
void find_ID();

char title[10] = "Quiz";
static int count_service = 0;

int main()
{
	int service;
	do {
		printf("\n <<< 1. ID 찾기 2. PW 찾기 3. 종료하기  >>> \n");
		printf("원하는 서비스 번호를 입력하세요.(1~3)");
		scanf("%d", &service);

		switch (service) {
		case 1 : {
				find_ID();
				break;
			}
		case 2 : {
				find_PW();
				break;
			}
		}
	} while (service != 3);
	return 0;
}

void find_ID()
{
	static int count_ID = 0;

	count_ID++;
	count_service++;
	printf("\n 총 전체 서비스 요청 %d번 중 %d회째 ID찾기 요청입니다. \n", count_service, count_ID);
}

void find_PW()
{
	static int count_PW = 0;

	count_PW++;
	count_service++;
	printf("\n 총 전체 서비스 요청 %d번 중 %d회째 비밀번호 찾기 요청입니다. \n", count_service, count_PW);
}
