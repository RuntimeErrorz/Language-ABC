#include "chess.h"
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <stdbool.h>

extern qiZi_T board[MAX_ROW][MAX_COL];
extern bool player;
extern bool threat_flag;

int map[19][18] =
{
{'a',0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},//0
{'z',1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//1
{'b',0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},//2
{'z',1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//3
{'c',0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},//4
{'z',1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//5
{'d',0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},//6
{'z',1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//7
{'e',0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},//8
{'z',2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},//9
{'f',0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},//10
{'z',1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//11
{'g',0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},//12
{'z',1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//13
{'h',0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},//14
{'z',1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//15
{'i',0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},//16
{'z',1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//17
{'j',0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0}//18
};

void color(int x) //�ı�������ɫ
{
	if (x >= 0 && x <= 15)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void show(int warning_type)
{
	int i, j;
	system("cls");
	printf("\n");
	color(12);
	switch (warning_type)
	{
	    case 0: printf("\n"); break;
	    case 1: printf("                                        ����������겻�����̷�Χ��,����������\n"); break;
	    case 2: printf("                                            �����Ӷ�������û�������鷳������\n"); break;
	    case 3: printf("                                              ����ϸ���������������\n"); break;
    	case 4: printf("                                              ���𶯶��ֵ��Ӷ����������\n"); break;
    	case 5: printf("                                                �����ܳ��Լ����Ӷ���\n"); break;
    	case 6: printf("                                               ��ȷ�������������߷���\n"); break;
		case 7: printf("                                              ��˧���棬������˼���߷�\n"); break;
	}
	color(7);
	for (i = 18; i >= 0; i--)
	{
		if (i == 9)
		{
			printf("                                         �U     ��  ��          ��  ��    �U\n");
			continue;
		}
		else if (i == 3 || i == 17)
		{
			printf("                                         �U   ��   ��   �� �v �� �u ��   ��   ��   �U\n");
			continue;
		}
		else if (i == 1 || i == 15)
		{
			printf("                                         �U   ��   ��   �� �u �� �v ��   ��   ��   �U\n");
			continue;
		}
		printf("                                      ");
		for (j = 0; j <= 17; j++)
		{
			if (map[i][j] == 0 && board[i / 2][(j - 1) / 2].type != 'k')
			{
				if (board[i / 2][(j - 1) / 2].player == true)
					color(12);
				else
					color(10);
			    switch (board[i / 2][(j - 1) / 2].type)
				{
					case 'b':printf("��"); break;
					case 'p':printf("��"); break;
					case 'c':printf("��"); break;
					case 'm':printf("��"); break;
					case 'j':printf("��"); break;
					case 's':printf("ʿ"); break;
					case 'x':printf("��"); break;
				}
				color(7);
			}
			else if (map[i][j] == 0 && board[i / 2][(j - 1) / 2].type == 'k')
			{
				if (i == 0 && j == 1) printf("�^ ");
				else if (i == 0 && j == 17) printf("�a");
				else if (i == 18 && j == 1) printf("�X ");
				else if (i == 18 && j == 17) printf("�[");
				else if ((i != 0 && i != 18) && j == 1)
				{
					if (i == 8 || i == 10)
						printf("�d ");
					else
						printf("�c ");
				}
				else if ((i != 0 && i != 18) && j == 17)
				{
					if (i == 8 || i == 10)
						printf("�g ");
					else
						printf("�f ");
				}
				else if (i == 2 && j == 9 || i == 16 && j == 9) printf("�w ");
				else if (i == 0 && j != 1) printf("�k ");
				else if (i == 18 && j != 1) printf("�h ");
				else if (i == 8 || i == 10) printf("�T ");
				else printf("�� ");
			}
			else if (map[i][j] == 1)
			{
				if (i == 0 || i == 18) printf("�T ");
				else if (j == 1) printf("�U");
				else if (j == 17) printf(" �U");
				else if (j == 1 || j == 3 || j == 5 || j == 7 || j == 9 || j == 11 || j == 13 || j == 15)
				{
					if (i != 0 && i != 18)
					printf(" ��");
				}
				else if (i == 2 || i == 4 || i == 6 || i == 12 || i == 14 || i == 16)
				{
					if (j != 1 && j != 17) printf("����");
				}
				else if (i == 8 || i == 10) printf("�T�T");
				else printf("  ");
			}
			else
			{
				switch (map[i][j])
				{
				case 'a':
					printf("0  "); break;
				case 'b':
					printf("1  "); break;
				case 'c':
					printf("2  "); break;
				case 'd':
					printf("3  "); break;
				case 'e':
					printf("4  "); break;
				case 'f':
					printf("5  "); break;
				case 'g':
					printf("6  "); break;
				case 'h':
					printf("7  "); break;
				case 'i':
					printf("8  "); break;
				case 'j':
					printf("9  "); break;
				case 'z':
					printf("   "); break;
				}
			}
		}
		if (i == 14)
			printf("                  t����Ͷ�� ");
		else if (i == 12)
			printf("                  s�����浵");
		else if (i == 10)
			printf("                  h��������");
		else if (i == 8)
			printf("                  c��������");
		else if (i == 6)
			printf("                  q�����˳�");

		printf("\n");
	}
	printf("\n                                         0   1   2   3   4   5   6   7   8\n");
}

void show_player(void)
{
	if (player)
	{
		if (threat_flag)
		{
			color(6);
			printf("                                                   ����   ");
			color(12);
			printf("�췽�ִ�\n");
		}
		else
		{
			color(12);
			printf("                                                     �췽�ִ�\n");
		}
		color(7);
		printf("\n                                             ���ÿո��Ӣ�Ķ��ŷָ�����\n");
	}
	else
	{
		if (threat_flag)
		{
			color(6);
			printf("                                                  ����   ");
			color(10);
			printf("�̷��ִ�\n");
		}
		else
		{
			color(10);
			printf("                                                     �̷��ִ�\n");
		}
		color(7);
		printf("\n                                             ���ÿո��Ӣ�Ķ��ŷָ�����\n");
	}
}