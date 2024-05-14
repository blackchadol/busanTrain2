#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
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
#define ACTION_PULL

int main(void)
{

	// 1. ASCII art�� �̿��� ��Ʈ�� �ۼ�




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


	Sleep(3000); // ��Ʈ�� 3�� ���� �� ���α׷� ����



	//2. ����ڷκ��� �������̿� Ȯ�� �Է�.

	int lenght = 0, prob = 0; // �������� ������ Ȯ�������� ���� �� �ʱ�ȭ

	printf("train length(15~50)>> ");
	scanf_s("%d", &lenght);
	if (lenght < LEN_MIN || lenght > LEN_MAX) // ���������� �ִ밪�� �ּҰ� ���� ���� �� ������ ��Ż�� �� ���α׷� ����
	{
		printf("�߸��� �Է��Դϴ�.\n");
		return 0;
	}

	printf("percentile probability 'p'(10~90) >> ");
	scanf_s("%d", &prob);
	if (prob < PROB_MIN || prob > PROB_MAX) // Ȯ���� ���������� ����� ���α׷� ����
	{
		printf("�߸��� �Է��Դϴ�.\n");
		return 0;
	}

	// 3. �Է¹��� ���� �̿��Ͽ� ������ �ʱ� ���� ���

	// 1��, 3���� #�� length �� ��ŭ ��� 
	for (int i = 0; i < 3; ++i)
	{

		if (i == 1) // 2���� #�ϳ� length - 7 ��ŭ�� ��ĭ C ��ĭ2�� Z M # ������ ���
		{
			putchar('#');
			for (int k = 0; k < (lenght - 7); k++)
			{
				putchar(' ');
			}
			putchar('C');
			printf("  ");
			putchar('Z');
			putchar('M');
			putchar('#');
			putchar('\n');
		}
		else {
			for (int j = 0; j < lenght; ++j)
			{
				putchar('#');
			}

			putchar('\n');
		}
	}

	putchar('\n');

	Sleep(2000);

	int h = 0; // (c�� �̵��ϱ� ���� ������ ���̴� ���� h�� ����)
	int z = 0; // (���� �̵��ϱ� ���� ������ ���̴� ���� z�� ���� 
	int turn = 0; // ���� �����̴� �� Ȯ���� ���� ����

	int cSpos = lenght - 6, zSpos = lenght - 3; // �ùΰ� ������ �ʱ���ġ ���� ����
	int cLoc = cSpos, zLoc = zSpos; // ������ �ù� ��ġ�� ���� ��ġ ���庯��
	int preCloc = cSpos, preZloc = zSpos; // ���� ���� �ùΰ� ������ġ ���庯��


	// 4. 4�ʸ��� �ù��̵� �����̵� �� �������� ��� �� �ù�, ������� ���


	while (1)

	{
		++turn; // 1�Ϻ��� ����. 
		int rNum = rand() % 100; // 0~99������ ������ �����ϴ� ����

		// 4.1 �ù�, ���� �̵��� �� ���� h , z �� ����

		if (100 - prob > rNum) // 100-p�� Ȯ���� �ش�� �� ��, �ù��� ������ ��
		{
			++h; // h�� +1
		}

		else // p�� Ȯ�� ��, ���� ������ ��
		{
			if (turn % 2 != 0) // ���� �����̴� �Ͽ� p%�� Ȯ���� �ش�ȴٸ�.	 
			{
				++z; //z�� +1
			}
			// ���� �������� �ʴ� ���̸� ��� ���� ��ȭ ����
		}

		// 4.2 ��ȭ�� h , z�� ���� �̿��� ��ȭ�� ��ġ�� C �� Z ���

		for (int i = 0; i < 3; ++i)

		{

			if (i == 1)
			{

				putchar('#');
				for (int k = 0; k < (lenght - 7 - h); ++k) // ������ ���鿡�� ����� ������ ��ŭ�� ������ ���� ���
				{
					putchar(' ');
				}
				putchar('C');
				for (int a = 0; a < 2 + h - z; ++a) // ����� ������ �ʱ� ������ 2�̰� ����� ������ ��ŭ ������ �� ����ϰ� ���� ������ ��ŭ ������ �� ����Ͽ� ����� ������ ��������. 
				{
					printf(" ");
				}

				putchar('Z');
				for (int j = 0; j < z; ++j) // ���� �������� ������ ��ŭ ���������� �Ÿ�(����) ����			
				{
					printf(" ");
				}
				putchar('M');
				putchar('#');
				putchar('\n');


			}
			else
			{
				for (int j = 0; j < lenght; ++j)
				{
					putchar('#');
				}

				putchar('\n');
			}

		}
		putchar('\n');

		//4.3 ������ġ�� ������ġ�� ���� C�� Z�� ��ġ��ȭ ���

		zLoc = zSpos - z; // ������ġ �ֽ�ȭ (�ʱ� ��ġ���� �þ h�� z �� ���� ���� ������ġ��)
		cLoc = cSpos - h;


		if (cLoc != preCloc) //����� ����������
		{

			printf("citizen: %d -> %d\n", preCloc, cLoc);

		}

		else // ����� �������� �ʾ�����
		{

			printf("citizens : stay %d\n", cLoc);


		}

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

		preCloc = cLoc; // ���� �Ͽ� ����ϱ� ���� ������ġ ���� �ֽ�ȭ 
		preZloc = zLoc;


		//4.4 ������ ������ ������ ���� �ƿ�Ʈ�� �ۼ�

		if (cLoc - zLoc == -1) // ������ ��ġ�� ����� ��ġ ���� ���� ���� �� �ƿ�Ʈ�� 
		{
			printf("\n\n\n\n\n");
			printf("GAME OVER!\nCitizen(s) has(have) been attacked by a zombie\n\n\n\n\n\n\n");
			Sleep(2000);
			break;
		}

		if (cLoc == 1) //  ����� ������ ù�� ° ĭ�� �������� �� �ƿ�Ʈ��
		{
			printf("\n\n\n\n\n");
			printf("SUCCESS! citizen(s) escaped to the next train\n\n\n\n\n\n\n");
			Sleep(2000);
			break;
		}

		Sleep(4000);
	}

	return 0;
}
