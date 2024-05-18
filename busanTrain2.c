/*1-1 부산헹 1의 내용을 복제 후 #define 상수 추가 선언. 
  1-2 함수작업시작, ascii art 인트로 작업과 사용자의 입력을 받는 작업을 함수로
  1-3 열차 상태 전역배열 선언 및 'C'와 'Z', 'M'의 위치로 열차를 출력해주는 함수 제작  */

/*2-1 난수생성 구문추가 및 1에서 제작한 함수 정의를 main 함수 아랫단으로 옮김.
  2-2 100-p의 확률과 그 외의 경우를 확인하고 열차상태 출력*/


#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
// 상수선언
#define LEN_MIN 15 // 기차길이
#define LEN_MAX 50
#define STM_MIN 0 //마동석 체력
#define STM_MAX 5
#define PROB_MIN 10 // 확률
#define PROB_MAX 90
#define AGGRO_MIN 0// 어그로 범위
#define AGGRO_MAX 5

// 마동석 이동 방향
#define MOVE_LEFT 1
#define MOVE_STAY 0

// 좀비의 공격 대상
#define ATK_NONE 0
#define ATK_CITIZEN 1
#define ATK_DONGSEOK 2

// 마동석 행동
#define ACTION_REST 0
#define ACTION_PROVOKE 1
#define ACTION_PULL 2

char g_trainList[LEN_MAX + 1]; // 문자열의 마지막은 NULL이기 때문에 +1

void AsciiArt(void);
int getLenght(void);
int getStamina(void);
int getProb(void);
void printTrain(int,int,int,int);



int main(void)
{
	
	// 1. ASCII ART 출력
	AsciiArt(); 

	// 2. 사용자 입력 받기 및 열차상태출력
	int length = 0, prob = 0, stm = 0; // 열차길이, 확률, 스태미너 변수 선언 및 초기화.
	int cLoc, zLoc, mLoc;

	length = getLenght();
	stm = getStamina();
	prob = getProb();

	cLoc = length - 6;
	zLoc = length - 3;
	mLoc = length - 2;

	printTrain(cLoc, zLoc, mLoc, length);

	printf("\n\n\n");

	//3. 열차 이동 phase.
	int turn = 0;
	int cAggro = 1;
	int mAggro = 1;
	int preZloc = zLoc, preCloc = cLoc;
	srand((unsigned int)time(NULL));
	
	while (1)
	{
		++turn; //1턴부터 시작. 
		int rNum = rand() % 100; // 0~99까지의 난수를 저장하는 변수

		if (100 - prob > rNum)
		{
			cLoc -= 1;
		}

		else
		{
			zLoc -= 1;
		}

		printTrain(cLoc, zLoc, mLoc, length);
		printf("\n\n");

	}


//	int h = 0; // (c가 이동하기 위해 공백을 줄이는 변수 h을 선언)
//	int z = 0; // (좀비가 이동하기 위해 공백을 줄이는 변수 z를 선언 
//	int turn = 0; // 좀비가 움직이는 턴 확인을 위한 변수
//
//	int cSpos = lenght - 6, zSpos = lenght - 3; // 시민과 좀비의 초기위치 저장 변수
//	int cLoc = cSpos, zLoc = zSpos; // 현재의 시민 위치와 좀비 위치 저장변수
//	int preCloc = cSpos, preZloc = zSpos; // 이전 턴의 시민과 좀비위치 저장변수
//
//
//	// 4. 4초마다 시민이동 좀비이동 후 열차상태 출력 및 시민, 좀비상태 출력
//
//
//	while (1)
//
//	{
//		++turn; // 1턴부터 시작. 
//		int rNum = rand() % 100; // 0~99까지의 난수를 저장하는 변수
//
//		// 4.1 시민, 좀비가 이동할 때 마다 h , z 값 증가
//
//		if (100 - prob > rNum) // 100-p의 확률에 해당될 때 즉, 시민이 움직일 때
//		{
//			++h; // h값 +1
//		}
//
//		else // p의 확률 즉, 좀비가 움직일 떄
//		{
//			if (turn % 2 != 0) // 좀비가 움직이는 턴에 p%의 확률이 해당된다면.	 
//			{
//				++z; //z값 +1
//			}
//			// 좀비가 움직이지 않는 턴이면 어떠한 값의 변화 없음
//		}
//
//		// 4.2 변화된 h , z의 값을 이용해 변화된 위치의 C 와 Z 출력
//
//		for (int i = 0; i < 3; ++i)
//
//		{
//
//			if (i == 1)
//			{
//
//				putchar('#');
//				for (int k = 0; k < (lenght - 7 - h); ++k) // 원래의 공백에서 사람이 움직인 만큼의 공백을 빼고 출력
//				{
//					putchar(' ');
//				}
//				putchar('C');
//				for (int a = 0; a < 2 + h - z; ++a) // 사람과 좀비의 초기 공백은 2이고 사람이 움직인 만큼 공백을 더 출력하고 좀비가 움직인 만큼 공백을 덜 출력하여 사람과 좀비의 간격조절. 
//				{
//					printf(" ");
//				}
//
//				putchar('Z');
//				for (int j = 0; j < z; ++j) // 좀비가 왼쪽으로 움직인 만큼 마동석과의 거리(공백) 증가			
//				{
//					printf(" ");
//				}
//				putchar('M');
//				putchar('#');
//				putchar('\n');
//
//
//			}
//			else
//			{
//				for (int j = 0; j < lenght; ++j)
//				{
//					putchar('#');
//				}
//
//				putchar('\n');
//			}
//
//		}
//		putchar('\n');
//
//		//4.3 이전위치와 현재위치를 통해 C와 Z의 위치변화 출력
//
//		zLoc = zSpos - z; // 현재위치 최신화 (초기 위치에서 늘어난 h와 z 의 값을 빼면 현재위치임)
//		cLoc = cSpos - h;
//
//
//		if (cLoc != preCloc) //사람이 움직였으면
//		{
//
//			printf("citizen: %d -> %d\n", preCloc, cLoc);
//
//		}
//
//		else // 사람이 움직이지 않았으면
//		{
//
//			printf("citizens : stay %d\n", cLoc);
//
//
//		}
//
//		if (zLoc == preZloc) //  좀비가 움직이지 않았을 때
//		{
//			if (turn % 2 == 0) // 좀비가 움직이지 못하는 턴이면
//			{
//
//				printf("zombie stay %d (cannot move)\n", zLoc);
//				putchar('\n');
//			}
//			else // 좀비가 움직일 수 있는 턴에 못 움직이면
//			{
//
//				printf("zombie stay %d\n", zLoc);
//				putchar('\n');
//			}
//		}
//		else // 좀비가 움직였으면
//		{
//			printf("zombie: %d -> %d\n", preZloc, zLoc);
//			putchar('\n');
//		}
//
//		preCloc = cLoc; // 다음 턴에 사용하기 위해 이전위치 변수 최신화 
//		preZloc = zLoc;
//
//
//		//4.4 게임이 끝나는 조건을 통한 아웃트로 작성
//
//		if (cLoc - zLoc == -1) // 좀비의 위치가 사람의 위치 옆에 도달 했을 때 아웃트로 
//		{
//			printf("\n\n\n\n\n");
//			printf("GAME OVER!\nCitizen(s) has(have) been attacked by a zombie\n\n\n\n\n\n\n");
//			Sleep(2000);
//			break;
//		}
//
//		if (cLoc == 1) //  사람의 기차의 첫번 째 칸에 도달했을 때 아웃트로
//		{
//			printf("\n\n\n\n\n");
//			printf("SUCCESS! citizen(s) escaped to the next train\n\n\n\n\n\n\n");
//			Sleep(2000);
//			break;
//		}
//
//		Sleep(4000);
//	}
//
//
// 	return 0;
 }

 void AsciiArt(void)  //  ASCII art를 이용한 인트로 출력함수
 {
	 printf("                 ()\n");
	 printf("                 ()\n");
	 printf("                 ()       ____.______._____\n");
	 printf("	      .--.  ---- - | _ - a:f - |\n");
	 printf("	  __ || ___ | [_]| |. | #  | .[].[].[].. |\n");
	 printf("	   o)__ | _ | .. |= | _ | -| ___________ |\n");
	 printf("	  __ < (__(*)_(*)_~_____~(*)____(*)_____\n");
	 printf("          ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n");

	 printf("                 TRAIN TO BUSAN\n");
	 printf("\n\n\n\n");
 }

 int getLenght(void)      //  기차길이 입력을 받는 함수
 {
	 int nInput;
	 while (1)
	 {
		 printf("train lenght(15~50)>>");
		 scanf_s("%d", &nInput);
		 if (nInput >= LEN_MIN && nInput <= LEN_MAX)
		 {
			 break;
		 }

	 }
	 return nInput;
 }

 int getStamina(void)      // stm 입력을 받는 함수
 {
	 int nInput;
	 while (1)
	 {
		 printf("madongseok stamina(0~5)>>");
		 scanf_s("%d", &nInput);
		 if (nInput >= STM_MIN && nInput <= STM_MAX)
		 {
			 break;
		 }

	 }
	 return nInput;
 }

 int getProb(void)      //  확률 입력을 받는 함수
 {
	 int nInput;
	 while (1)
	 {
		 printf("percentile probability 'p'(10~90) >> ");
		 scanf_s("%d", &nInput);
		 if (nInput >= PROB_MIN && nInput <= PROB_MAX)
		 {
			 break;
		 }

	 }
	 return nInput;
 }

 void printTrain(int cLoc, int zLoc, int mLoc, int length) // 열차상태 출력함수
 {

	 for (int k = 0; k < length + 1; k++)
	 {
		 g_trainList[k] = ' ';
	 }
	 g_trainList[length] = '\0';

	 for (int i = 0; i < 3; i++)
	 {
		 if (i == 1)
		 {
			 g_trainList[0] = '#';
			 g_trainList[length - 1] = '#';
			 g_trainList[cLoc] = 'C';
			 g_trainList[zLoc] = 'Z';
			 g_trainList[mLoc] = 'M';
			 printf("%s\n", g_trainList);
		 }

		 else
		 {
			 for (int j = 0; j < length; j++)
			 {
				 putchar('#');
			 }
			 putchar('\n');
		 }
	 }
 }

