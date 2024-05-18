/*1-1 �λ��� 1�� ������ ���� �� #define ��� �߰� ����. 
  1-2 �Լ��۾�����, ascii art ��Ʈ�� �۾��� ������� �Է��� �޴� �۾��� �Լ���
  1-3 ���� ���� �����迭 ���� �� 'C'�� 'Z', 'M'�� ��ġ�� ������ ������ִ� �Լ� ����  */

/*2-1 �������� �����߰� �� 1���� ������ �Լ� ���Ǹ� main �Լ� �Ʒ������� �ű�.
  2-2 100-p�� Ȯ���� �� ���� ��츦 Ȯ���ϰ� �������� ���
  2-3 aggro �� ���� �Լ� �߰�*/


#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
// �������
#define LEN_MIN 15 // ��������
#define LEN_MAX 50
#define STM_MIN 0 //������ ü��
#define STM_MAX 5
#define PROB_MIN 10 // Ȯ��
#define PROB_MAX 90
#define AGGRO_MIN 0// ��׷� ����
#define AGGRO_MAX 5

// ������ �̵� ����
#define MOVE_LEFT 1
#define MOVE_STAY 0

// ������ ���� ���
#define ATK_NONE 0
#define ATK_CITIZEN 1
#define ATK_DONGSEOK 2

// ������ �ൿ
#define ACTION_REST 0
#define ACTION_PROVOKE 1
#define ACTION_PULL 2

char g_trainList[LEN_MAX + 1]; // ���ڿ��� �������� NULL�̱� ������ +1

void AsciiArt(void);
int getLenght(void);
int getStamina(void);
int getProb(void);
void printTrain(int,int,int,int);
int verifyAggro(int);
int verifyStamina(int);
int getMmove(int, int);

void AsciiArt(void)  //  ASCII art�� �̿��� ��Ʈ�� ����Լ�
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

int getLenght(void)     //  �������� �Է��� �޴� �Լ�
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

int getStamina(void)      // stm �Է��� �޴� �Լ�
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

int getProb(void)     //  Ȯ�� �Է��� �޴� �Լ�
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

void printTrain(int cLoc, int zLoc, int mLoc, int length) // �������� ����Լ�
{

	for (int k = 0; k < length + 1; k++) // ���� ���� �迭���� ��� �������� �ʱ�ȭ �� �� ���� null���ڷ� ���ڿ� ����˸�
	{
		g_trainList[k] = ' ';
	}
	g_trainList[length] = '\0';

	for (int i = 0; i < 3; i++)
	{
		if (i == 1) // 2���� C , Z , M ��ġ ��  ���
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

int getMmove(int zLoc, int mLoc) // �������� move left �Ǵ� move stay �Է��� �ް� �����ϴ� �Լ�
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

	// 1. ASCII ART ���
	AsciiArt();

	// 2. ����� �Է� �ޱ� �� �����������
	int length = 0, prob = 0, stm = 0; // ��������, Ȯ��, ���¹̳� ���� ���� �� �ʱ�ȭ.
	int cLoc, zLoc, mLoc;

	length = getLenght();
	stm = getStamina();
	prob = getProb();

	cLoc = length - 6;
	zLoc = length - 3;
	mLoc = length - 2;

	printTrain(cLoc, zLoc, mLoc, length);

	printf("\n\n\n");

	//3. ���� �̵� phase.
	int turn = 0;
	int preStm = stm;
	int cAggro = 1;
	int mAggro = 1;
	int preZloc = zLoc, preCloc = cLoc, preMloc = mLoc;
	int precAggro = cAggro, premAggro = mAggro;
	int mMove; // �������� move left or move stay ���� ��� ����
	int zombiePull = 0; // �������� action pull �ߴ��� 
	int mAction = 0; // ������ �ൿ 
	srand((unsigned int)time(NULL));


	while (1)
	{
		++turn; //1�Ϻ��� ����. 
		int rNum = rand() % 100; // 0~99������ ������ �����ϴ� ����

		//3.1 Ȯ������ �ù���ġ, ������ġ �ֽ�ȭ �� ���� ���� ���//
		if (100 - prob > rNum) // 100 - p�� Ȯ��
		{
			cLoc -= 1;
			++cAggro;
			cAggro = verifyAggro(cAggro);

		}

		else // p�� Ȯ��
		{
			--cAggro;
			cAggro = verifyAggro(cAggro);
			if (turn % 2 != 0 && zombiePull != 1) // Ȧ���Ͽ� �������� PULL�� ���� �ʾ��� ���� ������. 
			{
				if (cAggro > mAggro && zLoc - cLoc != 1)// �ù��� ��׷ΰ� �� ������ �������� ���� �� �ù������� ������
					--zLoc;
				else if (cAggro <= mAggro && mLoc - zLoc != 1) // �������� ��׷ΰ� �� ������ �������� ���� �� ������ ������ ������.
					++zLoc;
			}
		}

		printTrain(cLoc, zLoc, mLoc, length);
		printf("\n\n");

		//3.2 ��ȭ�� �ùΰ� ������ ��ġ�� ��׷θ� ������� ��� ���//
		if (cLoc != preCloc) //����� ����������
		{
			printf("citizen: %d -> %d  (aggro: %d -> %d)\n", preCloc, cLoc, precAggro, cAggro);
		}

		else // ����� �������� �ʾ�����
		{
			printf("citizens : stay %d  (aggro: %d -> %d)\n", cLoc, precAggro, cAggro);
		}

		if (zombiePull == 1) // �������� ���� �������
		{
			printf("zombie stay %d (cannot move >> madongseok pulled)\n", zLoc);
			putchar('\n');
		}

		else
		{
			if (zLoc == preZloc) //  ���� �������� �ʾ��� ��
			{
				if (turn % 2 == 0) // ���� �������� ���ϴ� ���̸�
				{

					printf("zombie stay %d (cannot move)\n", zLoc);
					putchar('\n');
				}
				else // ���� ������ �� �ִ� �Ͽ� �� �����̸�
				{

					printf("zombie stay %d\n", zLoc);
					putchar('\n');
				}
			}
			else // ���� ����������
			{
				printf("zombie: %d -> %d\n", preZloc, zLoc);
				putchar('\n');
			}
		}

		// 3.3 ������ ������ �Է� �� ��ġ �ֽ�ȭ �� ���� �����.

		mMove = getMmove(zLoc, mLoc);
		mLoc -= mMove;
		printf("\n\n");
		printTrain(cLoc, zLoc, mLoc, length);
		printf("\n\n\n");



		//3.4 ������ ��ġ ��ȭ �� ��׷� ���׹̳� ��ȭ ���
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

		//4. �ൿ phase 

		// 4.1 �ù� �ൿ phase
		if (cLoc == 1)
		{
			printf("YOU WIN! citizen(s) escaped to the next train!!");
			break;
		}
		else
		{
			printf("citidens does nothing\n");
		}




		//4.2 �����ൿ

		if (zLoc - cLoc == 1)//����� ��� ����
		{
			if (mLoc - zLoc == 1)// �������� ���ÿ� ����
			{
				if (cAggro > mAggro)// C ��׷ΰ� M ��׷κ��� ������ ���ӿ���
				{
					printf("GAME OVER! Citizen(s) has(have) been attacked by a zombie\n");
				}

				else// ������ ����
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

		else if (mLoc - zLoc == 1) // ���� ������ ����
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

		//4.3 ������ �ൿ

		if (mLoc - zLoc != 1) // �������� �ʴٸ�
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

		else // �����ϸ�
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
		//4.5 ���� �� ���� ������ ���� �� ����

		preMloc = mLoc, preCloc = cLoc, preZloc = zLoc;
		premAggro = mAggro, precAggro = cAggro;
		preStm = stm;


	}

	return 0;
}

