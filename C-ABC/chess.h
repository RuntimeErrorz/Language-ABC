#pragma once
#ifndef __CHESS_H___
#define __CHESS_H___
#include "islegal.h"
#include "initialize.h"
#include "show.h"
#include "myInput.h"
#include "interface.h"
#include "winJudge.h"
#include "specialDeal.h"
#include "record.h"
#include "threat.h"
#include <stdbool.h>

#define MAX_ROW 10
#define MAX_COL 9
#define SAVE_FILE "save.txt"

typedef struct qiZi_T
{
	bool player; //0���� 1����
	char type; //b���� p���� c���� m���� x���� s��ʿ j��˧ k����
}qiZi_T, * qiZi_PT;

typedef struct locate_T
{
	int x;
	int y;
	char type;
}locate_T;

typedef struct node_T //
{
	int player;
	int now_x;
	int now_y;
	int move_x;
	int move_y;
	char taking; //�Ե���
	char piece; //������
	node_T* next;
	node_T* prev;
}node_T, * node_PT;

typedef struct
{
	int step;
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
}record_T,*recod_PT;
#endif