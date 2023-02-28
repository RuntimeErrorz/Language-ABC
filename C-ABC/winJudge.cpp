#define _CRT_SECURE_NO_WARNINGS
#include "chess.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

extern bool player; //��¼��ǰ���� trueΪ�죬falseΪ��
extern qiZi_T board[MAX_ROW][MAX_COL]; //����
extern node_PT record_now;
extern node_PT record_start;
extern int step;

bool win(void)
{
	bool r_flag = false, g_flag = false;
	bool win_flag = false;
	for (int i = 0; i <= 2; i++)
		for (int j = 3; j <= 5; j++)
			if (board[i][j].type == 'j')
				r_flag = true;
	for (int i = 9; i >= 7; i--)
		for (int j = 3; j <= 5; j++)
			if (board[i][j].type == 'j')
				g_flag = true;
	if (g_flag == false) /*�ж�ʤ�������ߺ��壩*/
	{
		color(12);
		printf("                                                     �췽ʤ����\n"); /*���ʤ�����*/
		color(7);
		win_flag = true;
	}
	else if (r_flag == false)
	{
		color(10);
		printf("                                                     �̷�ʤ����\n");
		color(7);
		win_flag = true;
	}

	if (win_flag == true)
	{
		//��������
		FILE* fp = fopen("record_1.txt", "w");
		if (fp == NULL)
		{
			printf("                                                   ��ϵͳԭ�����ױ���ʧ��\n");
			printf("                                                     ");
			system("pause");
			return 1;
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
		//�����¼
		record_T ranking_list[11];
		fp = fopen("ranking_list.txt", "r");
		if (fp == NULL)
		{
			fp = fopen("ranking_list.txt", "w");
			fclose(fp);
			fp = fopen("ranking_list.txt", "r");
		}
		int i = 0;
		while (fscanf(fp, "%d", &ranking_list[i].step) != EOF)
		{
			fscanf_s(fp, "%d %d %d", &ranking_list[i].year, &ranking_list[i].month, &ranking_list[i].day);
			fscanf_s(fp, "%d %d %d", &ranking_list[i].hour, &ranking_list[i].minute, &ranking_list[i].second);
			i++;
		}
		fclose(fp);
		ranking_list[i].step = step;

		time_t rawtime;
		struct tm *info;
		time(&rawtime);
		info = localtime(&rawtime);
		ranking_list[i].year = info->tm_year+1900;
		ranking_list[i].month = info->tm_mon+1;
		ranking_list[i].day = info->tm_mday;
		ranking_list[i].hour = info->tm_hour;
		ranking_list[i].minute = info->tm_min;
		ranking_list[i].second = info->tm_sec;

		for (int j = i; j>0; j--) //�ԣ����Ǹ����򣬵���ð������
		{
			bool flag = true;
			if (ranking_list[j-1].step < ranking_list[j].step)
			{
				record_T temp = ranking_list[j - 1];
				ranking_list[j - 1] = ranking_list[j];
				ranking_list[j] = temp;
				flag = false;
			}
			if (flag)
				break;
		}
		fp = fopen("ranking_list.txt", "w");
		for (int j = 0; j < 10 && j <= i; j++)
		{
			fprintf(fp, "%d ", ranking_list[j].step);
			fprintf(fp, "%d %d %d ", ranking_list[j].year, ranking_list[j].month, ranking_list[j].day);
			fprintf(fp, "%d %d %d\n", ranking_list[j].hour, ranking_list[j].minute, ranking_list[j].second);
		}
		fclose(fp);
		//
		remove("record_internal_1.txt"); //��������ļ��浵
		remove(SAVE_FILE); //����浵
		remove("save_list.txt"); //��������ļ�
		while (record_now != NULL) //�ͷ��ڴ�
			deleteRecord();
		return 1;
	}
	return 0;
}