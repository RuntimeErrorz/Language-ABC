#define _CRT_SECURE_NO_WARNINGS
#include "chess.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

extern bool player;
extern bool threat_flag;
extern qiZi_T board[MAX_ROW][MAX_COL];
extern locate_T list[2][12];
extern node_PT record_start; //����ͷ
extern node_PT record_now; //��β�巨��¼�µ��ƶ����ñ�����������β��
extern int step;

void specialDeal(int type) //����ture��ʾ���������������false��ʾû��
{
	if (type == 1)
	{
		if (player) //�췽Ͷ��
		{
			for (int i = 0; i <= 2; i++)
				for (int j = 3; j <= 5; j++)
					if (board[i][j].type == 'j')
						board[i][j].type = 'k';
		}
		else //�̷�Ͷ��
		{
			for (int i = 7; i <= 9; i++)
				for (int j = 3; j <= 5; j++)
					if (board[i][j].type == 'j')
						board[i][j].type = 'k';
		}
		return;
	}
	else if (type == 2) //����
	{
		if (record_now->prev == NULL || record_now->prev->prev == NULL) //��·���㣬��ʵ�ǰ�ȫ��
		{
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n                                                  ����û�߹�����\n");
			printf("\n\n\n                                               ");
			system("pause");
			return;
		}
		board[(record_now->move_y)][(record_now->move_x)].player = player;
		board[(record_now->move_y)][(record_now->move_x)].type = record_now->taking;
		board[(record_now->now_y)][(record_now->now_x)].player = !player;
		board[(record_now->now_y)][(record_now->now_x)].type = record_now->piece;
		if (record_now->taking != 'k' && record_now->taking != 'x' && record_now->taking != 's') //����list
		{
			for (int i = 0; i <= 11; i++)
			{
				if (list[player][i].x == record_now->move_x && list[player][i].y == record_now->move_y&&list[player][i].type=='k')
				{
					list[player][i].type = record_now->taking;
					break;
				}
			}
		}
		for (int i = 0; i <= 11; i++)
		{
			if (list[!player][i].x == record_now->move_x && list[!player][i].y == record_now->move_y && list[!player][i].type == record_now->piece)
			{
				list[!player][i].x = record_now->now_x;
				list[!player][i].y = record_now->now_y;
				break;
			}
		}
		deleteRecord(); //����һ��
		board[record_now->move_y][record_now->move_x].player = !player; //
		board[record_now->move_y][record_now->move_x].type = record_now->taking;
		board[record_now->now_y][record_now->now_x].player = player; //
		board[record_now->now_y][record_now->now_x].type = record_now->piece;
		if (record_now->taking != 'k' && record_now->taking != 'x' && record_now->taking != 's') //����list
		{
			for (int i = 0; i <= 11; i++)
			{
				if (list[!player][i].x == record_now->move_x && list[!player][i].y == record_now->move_y && list[!player][i].type == 'k')
				{
					list[!player][i].type = record_now->taking;
					break;
				}
			}
		}
		for (int i = 0; i <= 11; i++)
		{
			if (list[player][i].x == record_now->move_x && list[player][i].y == record_now->move_y && list[player][i].type == record_now->piece)
			{
				list[player][i].x = record_now->now_x;
				list[player][i].y = record_now->now_y;
				break;
			}
		}
		deleteRecord(); //�ٻ���һ��
		step -= 2; //ȥ������
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n                                                �ɹ����壬�´�����˼����\n");
		printf("\n\n\n                                                    ");
		system("pause");
		return;
	}
	else if (type == 3) //�򵥴ֱ��ĸ�дʽ�浵
	{
		FILE* fp;
		fp = fopen(SAVE_FILE, "w"); //�ı��ļ�
		if (fp == NULL)
		{
			system("cls");
			printf("\n\n\n\n\n                                                       ��ϵͳ���⣬�޷��浵\n");
			printf("\n\n\n\n                                                         ");
			system("pause");
			return;
		}
		fprintf_s(fp, "%d %d %d\n", player,threat_flag,step); //�����������
		for (int i = 0; i <= 9; i++)
		{
			for (int j = 0; j <= 8; j++)
				fprintf_s(fp, "%d %c", board[i][j].player, board[i][j].type);
			fprintf_s(fp, "\n");
		}
		fclose(fp);
		//
		fp = fopen("record_1.txt", "w");
		if (fp == NULL)
		{
			system("cls");
			printf("\n\n\n\n\n                                                       ��ϵͳ���⣬�޷��浵\n");
			printf("\n\n\n\n                                                         ");
			system("pause");
			return;
		}
		node_PT temp = record_start->next;
		while (temp != NULL)
		{
			if (temp->player)
				fprintf(fp, "�� ");
			else
				fprintf(fp, "�� ");
			switch (temp->piece)
			{
				case 'b':fprintf(fp, "��"); break;
				case 'p':fprintf(fp, "��"); break;
				case 'c':fprintf(fp, "��"); break;
				case 'm':fprintf(fp, "��"); break;
				case 'x':fprintf(fp, "��"); break;
				case 's':fprintf(fp, "ʿ"); break;
				case 'j':fprintf(fp, "��"); break;
			}
			fprintf(fp, "(%d,%d) -> (%d,%d)", temp->now_x, temp->now_y, temp->move_x, temp->move_y);
			if (temp->taking != 'k')
			{
				fprintf(fp, " ��");
				switch (temp->taking)
				{
					case 'b':fprintf(fp, "��"); break;
					case 'p':fprintf(fp, "��"); break;
					case 'c':fprintf(fp, "��"); break;
					case 'm':fprintf(fp, "��"); break;
					case 'x':fprintf(fp, "��"); break;
					case 's':fprintf(fp, "ʿ"); break;
					case 'j':fprintf(fp, "��"); break;
				}
			}
			fprintf(fp, "\n");
			temp = temp->next;
		}
		fclose(fp);
		//
		fp = fopen("save_list.txt", "w"); //list�Ĵ浵
		if (fp == NULL)
		{
			system("cls");
			printf("\n\n\n\n\n                                                       ��ϵͳ���⣬�޷��浵\n");
			printf("\n\n\n\n                                                         ");
			system("pause");
			return;
		}
		for (int i = 0; i <= 11; i++)
			fprintf(fp,"%c%d %d", list[0][i].type, list[0][i].x, list[0][i].y);
		for (int i = 0; i <= 11; i++)
			fprintf(fp,"%c%d %d", list[1][i].type, list[1][i].x, list[1][i].y);
		fclose(fp);
		//
		fp = fopen("record_internal_1.txt", "w"); //���ڶ�ȡ���ڲ���¼
		if (fp == NULL)
		{
			system("cls");
			printf("\n\n\n\n\n                                                       ��ϵͳ���⣬�޷��浵\n");
			printf("\n\n\n\n                                                         ");
			system("pause");
			return;
		}
		temp = record_start->next;
		while (temp != NULL)
		{
			fprintf(fp, "%d", temp->player);
			fprintf(fp, " %d %d %d %d", temp->now_x, temp->now_y, temp->move_x, temp->move_y);
			fprintf(fp, "%c%c", temp->piece, temp->taking);
			fprintf(fp, "\n");
			temp = temp->next;
		}
		fclose(fp);
		//
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n");
		printf("                                                          �ѱ���\n");
		printf("\n\n\n");
		printf("                                                    ");
		system("pause");
		return;
	}
	else if (type == 4) //����в鿴����
	{
		system("cls");
		node_PT temp = record_start->next;
		bool printf_flag = false;
		int i = 1;
		while (temp != NULL)
		{
			if (printf_flag == false) //��һ�����⴦��
				printf("\n\n\n");
			printf_flag = true;
			printf("                                           �� %d ��   ",i++);
			if (temp->player)
				printf("�� ");
			else
				printf("�� ");
			switch (temp->piece)
			{
				case 'b':printf("��"); break;
				case 'p':printf("��"); break;
				case 'c':printf("��"); break;
				case 'm':printf("��"); break;
				case 'x':printf("��"); break;
				case 's':printf("ʿ"); break;
				case 'j':printf("��"); break;
			}
			printf("(%d,%d) -> (%d,%d)", temp->now_x, temp->now_y, temp->move_x, temp->move_y);
			if (temp->taking != 'k')
			{
				printf(" ��");
				switch (temp->piece)
				{
					case 'b':printf("��"); break;
					case 'p':printf("��"); break;
					case 'c':printf("��"); break;
					case 'm':printf("��"); break;
					case 'x':printf("��"); break;
					case 's':printf("ʿ"); break;
					case 'j':printf("��"); break;
				}
			}
			printf("\n");
			temp = temp->next;
		}
		printf("\n\n\n");
		if (printf_flag == false)
			printf("\n\n\n\n\n\n\n\n\n                                                  ��ǰ��ֻ�δ�߹���\n\n\n\n");
		printf("                                                 ");
		system("pause");
		return;
	}
	else if (type == 5) //��ȫ�˳�
	{
		while (record_now != NULL) //�ͷ��ڴ�
			deleteRecord();
		printf("\n                                                  �Ѿ�����ڴ��ͷ�\n");
		printf("\n                                                ");
		system("pause");
		exit(EXIT_SUCCESS);
	}
}