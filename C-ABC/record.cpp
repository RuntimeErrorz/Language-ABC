#define _CRT_SECURE_NO_WARNINGS
#include "chess.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

extern bool player;
extern qiZi_T board[MAX_ROW][MAX_COL];
extern node_PT record_start; //���������ͷ
extern node_PT record_now; //��������β�����


//��������������
//����������ڻ���

void createLinkList(void)
{
	record_start = (node_PT)malloc(sizeof(node_T));
	if (record_start == NULL)
	{
		printf("���׼�¼����ʧ��\n");
		system("pause");
		return;
	}
	//ͷ��㲻������
	record_start->next = NULL; //��ʶ����β��
	record_start->prev = NULL; //��ʶ����ͷ��
	//(*pStart)->piece = 'a'; //��ʶ����ͷ���
	record_now = record_start;
}


void recordMove(int now_x, int now_y, int move_x, int move_y) //��β������һ���½������¼�ƶ�
{
	record_now->next = (node_PT)malloc(sizeof(node_T));
	if (record_now->next == NULL)
	{
		printf("���׼�¼��㴴��ʧ��\n");
		system("pause");
		return;
	}
	record_now->next->next = NULL; //��ʶ�µ�β��
	record_now->next->prev = record_now;
	record_now = record_now->next; //���µ�ǰ���ָ��
	record_now->player = player;
	record_now->now_x = now_x;
	record_now->now_y = now_y;
	record_now->move_x = move_x;
	record_now->move_y = move_y;
	record_now->piece = board[now_y][now_x].type;
	record_now->taking = board[move_y][move_x].type;
	return;
}


//��������е�û��Ҫ
void deleteRecord(void) //��β��ɾ��һ����㣬���ڻ�����ͷ��ڴ�
{
	if (record_now == NULL)
		return;
	if (record_now->prev == NULL)
	{
		free(record_now);
		record_now = NULL;
		return;
	}
	record_now = record_now->prev;
	free(record_now->next);
	record_now->next = NULL;
}

void loadLinkList(void)
{
	FILE* fp;
	fp = fopen("record_internal_1.txt", "r");
	if (fp == NULL)
	{
		system("cls");
		printf("                                                   δ�ҵ����׼�¼\n");
		printf("\n                                                    ���׼���ʧ��\n");
		printf("\n\n\n                                                      �����������������");
		system("pause");
		return;
	}
	int input_temp;
	while (fscanf_s(fp, "%d", &input_temp)!=EOF)
	{
		record_now->next = (node_PT)malloc(sizeof(node_T));
		if (record_now->next == NULL)
		{
			printf("                                                     ���׼�¼��㴴��ʧ��\n");
			printf("                                                          �����������������");
			system("pause");
			return;
		}

		record_now->next->next = NULL; //��ʶ�µ�β��
		record_now->next->prev = record_now;
		record_now = record_now->next; //���µ�ǰ���ָ��
		record_now->player = input_temp;
		fscanf_s(fp, "%d%d%d%d", &(record_now->now_x), &(record_now->now_y), &(record_now->move_x), &(record_now->move_y));
		/*fscanf_s(fp, "%c %c\n", &(record_now->piece), &(record_now->taking));*/
		record_now->piece = fgetc(fp);
		record_now->taking = fgetc(fp);
	}
	fclose(fp);
	return;
}