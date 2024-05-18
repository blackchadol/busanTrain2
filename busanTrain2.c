/*1-1 �λ��� 1�� ������ ���� �� #define ��� �߰� ����. 
  1-2 �Լ��۾�����, ascii art ��Ʈ�� �۾��� ������� �Է��� �޴� �۾��� �Լ���
  1-3 ���� ���� �����迭 ���� �� 'C'�� 'Z', 'M'�� ��ġ�� ������ ������ִ� �Լ� ����  */

/*2-1 �������� �����߰� �� 1���� ������ �Լ� ���Ǹ� main �Լ� �Ʒ������� �ű�.
  2-2 100-p�� Ȯ���� �� ���� ��츦 Ȯ���ϰ� �������� ���*/


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
	int cAggro = 1;
	int mAggro = 1;
	int preZloc = zLoc, preCloc = cLoc;
	srand((unsigned int)time(NULL));
	
	while (1)
	{
		++turn; //1�Ϻ��� ����. 
		int rNum = rand() % 100; // 0~99������ ������ �����ϴ� ����

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


//	int h = 0; // (c�� �̵��ϱ� ���� ������ ���̴� ���� h�� ����)
//	int z = 0; // (���� �̵��ϱ� ���� ������ ���̴� ���� z�� ���� 
//	int turn = 0; // ���� �����̴� �� Ȯ���� ���� ����
//
//	int cSpos = lenght - 6, zSpos = lenght - 3; // �ùΰ� ������ �ʱ���ġ ���� ����
//	int cLoc = cSpos, zLoc = zSpos; // ������ �ù� ��ġ�� ���� ��ġ ���庯��
//	int preCloc = cSpos, preZloc = zSpos; // ���� ���� �ùΰ� ������ġ ���庯��
//
//
//	// 4. 4�ʸ��� �ù��̵� �����̵� �� �������� ��� �� �ù�, ������� ���
//
//
//	while (1)
//
//	{
//		++turn; // 1�Ϻ��� ����. 
//		int rNum = rand() % 100; // 0~99������ ������ �����ϴ� ����
//
//		// 4.1 �ù�, ���� �̵��� �� ���� h , z �� ����
//
//		if (100 - prob > rNum) // 100-p�� Ȯ���� �ش�� �� ��, �ù��� ������ ��
//		{
//			++h; // h�� +1
//		}
//
//		else // p�� Ȯ�� ��, ���� ������ ��
//		{
//			if (turn % 2 != 0) // ���� �����̴� �Ͽ� p%�� Ȯ���� �ش�ȴٸ�.	 
//			{
//				++z; //z�� +1
//			}
//			// ���� �������� �ʴ� ���̸� ��� ���� ��ȭ ����
//		}
//
//		// 4.2 ��ȭ�� h , z�� ���� �̿��� ��ȭ�� ��ġ�� C �� Z ���
//
//		for (int i = 0; i < 3; ++i)
//
//		{
//
//			if (i == 1)
//			{
//
//				putchar('#');
//				for (int k = 0; k < (lenght - 7 - h); ++k) // ������ ���鿡�� ����� ������ ��ŭ�� ������ ���� ���
//				{
//					putchar(' ');
//				}
//				putchar('C');
//				for (int a = 0; a < 2 + h - z; ++a) // ����� ������ �ʱ� ������ 2�̰� ����� ������ ��ŭ ������ �� ����ϰ� ���� ������ ��ŭ ������ �� ����Ͽ� ����� ������ ��������. 
//				{
//					printf(" ");
//				}
//
//				putchar('Z');
//				for (int j = 0; j < z; ++j) // ���� �������� ������ ��ŭ ���������� �Ÿ�(����) ����			
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
//		//4.3 ������ġ�� ������ġ�� ���� C�� Z�� ��ġ��ȭ ���
//
//		zLoc = zSpos - z; // ������ġ �ֽ�ȭ (�ʱ� ��ġ���� �þ h�� z �� ���� ���� ������ġ��)
//		cLoc = cSpos - h;
//
//
//		if (cLoc != preCloc) //����� ����������
//		{
//
//			printf("citizen: %d -> %d\n", preCloc, cLoc);
//
//		}
//
//		else // ����� �������� �ʾ�����
//		{
//
//			printf("citizens : stay %d\n", cLoc);
//
//
//		}
//
//		if (zLoc == preZloc) //  ���� �������� �ʾ��� ��
//		{
//			if (turn % 2 == 0) // ���� �������� ���ϴ� ���̸�
//			{
//
//				printf("zombie stay %d (cannot move)\n", zLoc);
//				putchar('\n');
//			}
//			else // ���� ������ �� �ִ� �Ͽ� �� �����̸�
//			{
//
//				printf("zombie stay %d\n", zLoc);
//				putchar('\n');
//			}
//		}
//		else // ���� ����������
//		{
//			printf("zombie: %d -> %d\n", preZloc, zLoc);
//			putchar('\n');
//		}
//
//		preCloc = cLoc; // ���� �Ͽ� ����ϱ� ���� ������ġ ���� �ֽ�ȭ 
//		preZloc = zLoc;
//
//
//		//4.4 ������ ������ ������ ���� �ƿ�Ʈ�� �ۼ�
//
//		if (cLoc - zLoc == -1) // ������ ��ġ�� ����� ��ġ ���� ���� ���� �� �ƿ�Ʈ�� 
//		{
//			printf("\n\n\n\n\n");
//			printf("GAME OVER!\nCitizen(s) has(have) been attacked by a zombie\n\n\n\n\n\n\n");
//			Sleep(2000);
//			break;
//		}
//
//		if (cLoc == 1) //  ����� ������ ù�� ° ĭ�� �������� �� �ƿ�Ʈ��
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

 int getLenght(void)      //  �������� �Է��� �޴� �Լ�
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

 int getProb(void)      //  Ȯ�� �Է��� �޴� �Լ�
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

