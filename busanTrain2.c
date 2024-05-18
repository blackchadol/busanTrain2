/*1-1 부산헹 1의 내용을 복제 후 #define 상수 추가 선언. 
  1-2 함수작업시작, ascii art 인트로 작업과 사용자의 입력을 받는 작업을 함수로
  1-3 열차 상태 전역배열 선언 및 'C'와 'Z', 'M'의 위치로 열차를 출력해주는 함수 제작  */

/*2-1 난수생성 구문추가 및 1에서 제작한 함수 정의를 main 함수 아랫단으로 옮김.
  2-2 100-p의 확률과 그 외의 경우를 확인하고 열차상태 출력
  2-3 aggro 값 검증 함수 추가*/


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
int verifyAggro(int);
int verifyStamina(int);
int getMmove(int, int);

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

int getLenght(void)     //  기차길이 입력을 받는 함수
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

int getProb(void)     //  확률 입력을 받는 함수
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

	for (int k = 0; k < length + 1; k++) // 열차 상태 배열에서 모두 공백으로 초기화 한 후 끝에 null문자로 문자열 종료알림
	{
		g_trainList[k] = ' ';
	}
	g_trainList[length] = '\0';

	for (int i = 0; i < 3; i++)
	{
		if (i == 1) // 2열에 C , Z , M 배치 후  출력
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
int verifyAggro(int aggro)
{
	if (aggro > AGGRO_MAX)
	{
		aggro -= 1;
	}

	else if (aggro < 0)
	{
		aggro += 1;
	}

	return aggro;

}

int getMmove(int zLoc, int mLoc) // 마동석의 move left 또는 move stay 입력을 받고 검증하는 함수
{
	int move;
	while (1)
	{
		if (mLoc - zLoc == 1)
		{
			printf("madongseok move(0:stay)>> ");
			scanf_s("%d", &move);
			if (move == MOVE_STAY)
			{
				break;
			}

			else
			{
				continue;
			}
		}

		else
		{
			printf("madongseok move(0:stay, 1:left)>> ");
			scanf_s("%d", &move);

			if (move == MOVE_LEFT || move == MOVE_STAY)
			{
				break;
			}

			else
			{
				continue;
			}
		}
	}

	return move;

}

int verifyStamina(int stm)
{
	if (stm > STM_MAX)
		--stm;
	else if (stm < STM_MIN)
		++stm;
	return stm;
}




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
	int preStm = stm;
	int cAggro = 1;
	int mAggro = 1;
	int preZloc = zLoc, preCloc = cLoc, preMloc = mLoc;
	int precAggro = cAggro, premAggro = mAggro;
	int mMove; // 마동석의 move left or move stay 값을 담는 변수
	int zombiePull = 0; // 마동석이 action pull 했는지 
	int mAction = 0; // 마동석 행동 
	srand((unsigned int)time(NULL));


	while (1)
	{
		++turn; //1턴부터 시작. 
		int rNum = rand() % 100; // 0~99까지의 난수를 저장하는 변수

		//3.1 확률별로 시민위치, 좀비위치 최신화 및 열차 상태 출력//
		if (100 - prob > rNum) // 100 - p의 확률
		{
			cLoc -= 1;
			++cAggro;
			cAggro = verifyAggro(cAggro);

		}

		else // p의 확률
		{
			--cAggro;
			cAggro = verifyAggro(cAggro);
			if (turn % 2 != 0 && zombiePull != 1) // 홀수턴에 마동석이 PULL을 하지 않았을 때만 움직임. 
			{
				if (cAggro > mAggro && zLoc - cLoc != 1)// 시민의 어그로가 더 높지만 인접하지 않을 때 시민쪽으로 움직임
					--zLoc;
				else if (cAggro <= mAggro && mLoc - zLoc != 1) // 마동석의 어그로가 더 높지만 인접하지 않을 때 마동석 쪽으로 움직임.
					++zLoc;
			}
		}

		printTrain(cLoc, zLoc, mLoc, length);
		printf("\n\n");

		//3.2 변화된 시민과 좀비의 위치와 어그로를 기반으로 결과 출력//
		if (cLoc != preCloc) //사람이 움직였으면
		{
			printf("citizen: %d -> %d  (aggro: %d -> %d)\n", preCloc, cLoc, precAggro, cAggro);
		}

		else // 사람이 움직이지 않았으면
		{
			printf("citizens : stay %d  (aggro: %d -> %d)\n", cLoc, precAggro, cAggro);
		}

		if (zombiePull == 1) // 마동석이 좀비를 당겼으면
		{
			printf("zombie stay %d (cannot move >> madongseok pulled)\n", zLoc);
			putchar('\n');
		}

		else
		{
			if (zLoc == preZloc) //  좀비가 움직이지 않았을 때
			{
				if (turn % 2 == 0) // 좀비가 움직이지 못하는 턴이면
				{

					printf("zombie stay %d (cannot move)\n", zLoc);
					putchar('\n');
				}
				else // 좀비가 움직일 수 있는 턴에 못 움직이면
				{

					printf("zombie stay %d\n", zLoc);
					putchar('\n');
				}
			}
			else // 좀비가 움직였으면
			{
				printf("zombie: %d -> %d\n", preZloc, zLoc);
				putchar('\n');
			}
		}

		// 3.3 마동석 움직임 입력 및 위치 최신화 및 열차 재출력.

		mMove = getMmove(zLoc, mLoc);
		mLoc -= mMove;
		printf("\n\n");
		printTrain(cLoc, zLoc, mLoc, length);
		printf("\n\n\n");



		//3.4 마동석 위치 변화 및 어그로 스테미너 변화 출력
		if (mMove == MOVE_LEFT)
		{
			++mAggro;
			mAggro = verifyAggro(mAggro);
			printf("madongseok %d -> %d", preMloc, mLoc);
		}
		else if (mMove == MOVE_STAY)
		{
			--mAggro;
			mAggro = verifyAggro(mAggro);
			printf("madongseok: stay %d", mLoc);
		}

		if (mAggro != premAggro)
		{
			printf("(aggro %d -> %d, stamina: %d)\n\n", premAggro, mAggro, stm);
		}
		else
		{
			printf("(aggro: %d, stamina: %d)\n\n", mAggro, stm);
		}

		premAggro = mAggro, precAggro = cAggro;

		//4. 행동 phase 

		// 4.1 시민 행동 phase
		if (cLoc == 1)
		{
			printf("YOU WIN! citizen(s) escaped to the next train!!");
			break;
		}
		else
		{
			printf("citidens does nothing\n");
		}




		//4.2 좀비행동

		if (zLoc - cLoc == 1)//좀비와 사람 인접
		{
			if (mLoc - zLoc == 1)// 마동석도 동시에 인접
			{
				if (cAggro > mAggro)// C 어그로가 M 어그로보다 높으면 게임오버
				{
					printf("GAME OVER! Citizen(s) has(have) been attacked by a zombie\n");
				}

				else// 마동석 공격
				{
					--stm;
					printf("Zombie attacked madongseok (aggro: %d vs %d, madongseok stamina: %d->%d)\n", cAggro, mAggro, preStm, stm);
					if (stm == STM_MIN)
					{
						printf("GAME OVER!. madongseok killed by zombie");
						break;
					}
				}
			}
			else
			{
				printf("GAME OVER! Citizen(s) has(have) been attacked by a zombie\n");
			}
		}

		else if (mLoc - zLoc == 1) // 좀비가 마동석 공격
		{
			--stm;
			printf("Zombie attacked madongseok (madongseok stamina: %d->%d)\n", preStm, stm);
			if (stm == STM_MIN)
			{
				printf("GAME OVER!. madongseok killed by zombie");
				break;
			}


		}

		else
		{
			printf("zombie attacked nobody\n");
		}

		preStm = stm;

		//4.3 마동석 행동

		if (mLoc - zLoc != 1) // 인접하지 않다면
		{
			while (1)
			{
				printf("madongseok action (0.rest 1.provoke)>> ");
				scanf_s("%d", &mAction);
				if (mAction == ACTION_REST || mAction || ACTION_PROVOKE)
				{
					break;
				}
			}

		}

		else // 인접하면
		{
			while (1)
			{
				printf("madongseok action (0.rest 1.provoke, 2.pull)>> ");
				scanf_s("%d", &mAction);
				if (mAction == ACTION_REST || mAction || ACTION_PROVOKE || mAction == ACTION_PULL)
				{
					break;
				}
			}
			printf("\n\n");

		}
		switch (mAction)
		{
		case ACTION_REST:
		{
			--mAggro;
			mAggro = verifyAggro(mAggro);
			++stm;
			stm = verifyStamina(stm);
			printf("madongseok rests...\n");
			printf("madongseok: %d (aggro %d -> %d, stamina: %d -> %d)\n", mLoc, premAggro, mAggro, preStm, stm);
			zombiePull = 0;
			break;
		}
		case ACTION_PROVOKE:
		{
			mAggro = AGGRO_MAX;
			printf("madongseok provoked zombie...\n");
			printf("madongseok: %d (aggro %d -> %d, stamina: %d)\n", mLoc, premAggro, mAggro, stm);
			zombiePull = 0;
			break;
		}
		case ACTION_PULL:
		{
			mAggro += 2;
			mAggro = verifyAggro(mAggro);
			--stm;
			stm = verifyStamina(stm);

			int randomNum = rand() % 100;
			if (100 - prob > randomNum)
			{
				printf("madongseok pulled zombie... Next turn, it can't move\n");
				zombiePull = 1;

			}
			else
			{
				printf("madongseok failed to pull zombie\n");
				zombiePull = 0;
			}
			printf("madongseok: %d (aggro %d -> %d, stamina: %d -> %d)\n", mLoc, premAggro, mAggro, preStm, stm);
			break;
		}
		}

		printf("\n\n\n");
		//4.5 이전 값 저장 변수에 현재 값 대입

		preMloc = mLoc, preCloc = cLoc, preZloc = zLoc;
		premAggro = mAggro, precAggro = cAggro;
		preStm = stm;


	}

	return 0;
}

