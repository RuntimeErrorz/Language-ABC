#define _CRT_SECURE_NO_WARNINGS
#include "chess.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


extern bool player;
extern bool threat_flag;
extern qiZi_T board[MAX_ROW][MAX_COL];
extern locate_T list[2][12]; //0:�ڣ�1:��    list[][0]�̶��ǽ�
extern int step;

void initialize(void)
{
	player = true; //�췽����
	threat_flag = false; //һ��ʼ��Ȼ�����ܽ���
	step = 0;
	//��ʼ��board
	for(int i=0;i<=9;i++)
		for (int j = 0; j <= 8; j++) //�Ȱ����̳�ʼ��Ϊ��
		{
			board[i][j].player = true;
			board[i][j].type = 'k';
		}
	for (int i = 0; i <=8; i+=2) //��ʼ����
	{
		board[3][i].player = true; //�췽��
		board[3][i].type = 'b';
		board[6][i].player = false; //�ڷ���
		board[6][i].type = 'b';
	}

	board[2][1].player = true; //�췽��
	board[2][1].type = 'p';
	board[2][7].player = true;
	board[2][7].type = 'p';
	board[7][1].player = false; //�ڷ���
	board[7][1].type = 'p';
	board[7][7].player = false;
	board[7][7].type = 'p';

	board[0][0].player = true; //�췽��
	board[0][0].type = 'c';
	board[0][8].player = true;
	board[0][8].type = 'c';
	board[9][0].player = false; //�ڷ���
	board[9][0].type = 'c';
	board[9][8].player = false;
	board[9][8].type = 'c';

	board[0][1].player = true; //�췽��
	board[0][1].type = 'm';
	board[0][7].player = true;
	board[0][7].type = 'm';
	board[9][1].player = false; //�ڷ���
	board[9][1].type = 'm';
	board[9][7].player = false;
	board[9][7].type = 'm';

	board[0][2].player = true; //�췽��
	board[0][2].type = 'x';
	board[0][6].player = true;
	board[0][6].type = 'x';
	board[9][2].player = false; //�ڷ���
	board[9][2].type = 'x';
	board[9][6].player = false;
	board[9][6].type = 'x';

	board[0][3].player = true; //�췽ʿ
	board[0][3].type = 's';
	board[0][5].player = true;
	board[0][5].type = 's';
	board[9][3].player = false; //�ڷ�ʿ
	board[9][3].type = 's';
	board[9][5].player = false;
	board[9][5].type = 's';

	board[0][4].player = true; //�췽��
	board[0][4].type = 'j';
	board[9][4].player = false; //�ڷ���
	board[9][4].type = 'j';

	//��ʼ��list
	list[0][0].type = 'j'; //����λ��
	list[0][0].x = 4;
	list[0][0].y = 9;
	list[1][0].type = 'j';
	list[1][0].x = 4;
	list[1][0].y = 0;
	for (int i = 1; i <= 5; i++) //����λ��
	{
		list[0][i].type = 'b';
		list[0][i].x = (i - 1) * 2;
		list[0][i].y = 6;
		list[1][i].type = 'b';
		list[1][i].x = (i - 1) * 2;
		list[1][i].y = 3;
	}
	list[0][6].type = 'p'; //�ڵ�λ��
	list[0][6].x = 1;
	list[0][6].y = 7;
	list[0][7].type = 'p';
	list[0][7].x = 7;
	list[0][7].y = 7;
	list[1][6].type = 'p';
	list[1][6].x = 1;
	list[1][6].y = 2;
	list[1][7].type = 'p';
	list[1][7].x = 7;
	list[1][7].y = 2;
	list[0][8].type = 'c'; //����λ��
	list[0][8].x = 0;
	list[0][8].y = 9;
	list[0][9].type = 'c';
	list[0][9].x = 8;
	list[0][9].y = 9;
	list[1][8].type = 'c';
	list[1][8].x = 0;
	list[1][8].y = 0;
	list[1][9].type = 'c';
	list[1][9].x = 8;
	list[1][9].y = 0;
	list[0][10].type = 'm'; //���λ��
	list[0][10].x = 1;
	list[0][10].y = 9;
	list[0][11].type = 'm';
	list[0][11].x = 7;
	list[0][11].y = 9;
	list[1][10].type = 'm';
	list[1][10].x = 1;
	list[1][10].y = 0;
	list[1][11].type = 'm';
	list[1][11].x = 7;
	list[1][11].y = 0;
}

int load(void)
{
	FILE* fp = fopen(SAVE_FILE, "r");
	if (fp == NULL) //�Ҳ����ĵ�ʱ
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n");
		printf("                                                    û�н����еĶԾ�\n\n\n\n\n");
		int temp;
		printf("                                                   ");
		system("pause");
		return -1;
	}
	int player_temp; //��int�ȽϺö���
	char type_temp;
	fscanf_s(fp, "%d %d %d", &player, &threat_flag, &step);
	for (int i = 0; i <= 9; i++)
	{
		for (int j = 0; j <= 8; j++)
		{
			fscanf_s(fp,"%d %c", &player_temp, &type_temp);
			board[i][j].player = player_temp;
			board[i][j].type = type_temp;
		}
	}
	fclose(fp);
	fp = fopen("save_list.txt", "r"); //����list
	if (fp == NULL)
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("                                                    �浵�ļ���\n\n\n\n\n");
		int temp;
		printf("                                               ������0�Է����ϼ�Ŀ¼��");
		scanf_s("%d", &temp);
		return -1;
	}
	for (int i = 0; i <= 11; i++)
	{
		list[0][i].type = fgetc(fp);
		fscanf_s(fp, "%d%d", &list[0][i].x, &list[0][i].y);
	}
	for (int i = 0; i <= 11; i++)
	{
		list[1][i].type = fgetc(fp);
		fscanf_s(fp, "%d%d", &list[1][i].x, &list[1][i].y);
	}
	fclose(fp);
	return 1;
}
