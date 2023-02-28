#include "chess.h"
#include <stdio.h>

extern qiZi_T board[MAX_ROW][MAX_COL];
extern locate_T list[2][12];
extern bool player;

/*******************
* ����ֵ˵��       *
* 0.�Ϸ�           *
* 1.����Խ��       *
* 2.û���ƶ�       *
* 3.ѡ������������ *
* 4.�Ǽ�������     *
* 5.Ŀ����м����� *
* 6.�ƶ��Ƿ�       *
********************/

int isLegal(const int now_x, const int now_y, const int move_x, const int move_y)
{
	if (now_x < 0 || now_x>8 || now_y < 0 || now_y>9
		|| move_x < 0 || move_x>8 || move_y < 0 || move_y>9)
		return 1;
	if (move_x == now_x && move_y == now_y)
		return 2;
	if (board[now_y][now_x].type == 'k')
		return 3;
	if (board[now_y][now_x].player != player)
		return 4;
	if (board[move_y][move_x].player == player && board[move_y][move_x].type != 'k')
		return 5;


	if (board[now_y][now_x].type == 'b') //��
	{
		if (player) //�췽
		{
			if (now_y <= 4) //����ǰ
			{
				if (move_x != now_x || move_y != now_y + 1)
					return 6;
			}
			else //���Ӻ�
			{
				bool flag = true;
				if (move_x == now_x && move_y == now_y + 1)
					flag = false;
				else if (move_x == now_x + 1 && move_y == now_y)
					flag = false;
				else if (move_x == now_x - 1 && move_y == now_y)
					flag = false;
				if (flag) //�������ϣ�����������ߣ���Ϊ�Ƿ�
					return 6;
			}
		}
		else //�ڷ�
		{
			if (now_y >= 5) //����ǰ
			{
				if (move_x != now_x || move_y != now_y - 1)
					return 6;
			}
			else //���Ӻ�
			{
				bool flag = true;
				if (move_x == now_x && move_y == now_y - 1)
					flag = false;
				else if (move_x == now_x + 1 && move_y == now_y)
					flag = false;
				else if (move_x == now_x - 1 && move_y == now_y)
					flag = false;
				if (flag) //�������£�����������ߣ���Ϊ�Ƿ�
					return 6;
			}
		}
		return 0;
	}


	else if (board[now_y][now_x].type == 'p') //��
	{
		int interval = 0; //�������������
		//�ж��������������
		if (now_x == move_x && now_y < move_y) //���϶�
		{
			for (int i = now_y + 1; i != move_y; i++)
				if (board[i][now_x].type != 'k')
					interval++;
		}
		else if (now_x == move_x && now_y > move_y) //���¶�
		{
			for (int i = now_y - 1; i != move_y; i--)
				if (board[i][now_x].type != 'k')
					interval++;
		}
		else if (now_y == move_y && now_x < move_x) //���Ҷ�
		{
			for (int i = now_x + 1; i != move_x; i++)
				if (board[now_y][i].type != 'k')
					interval++;
		}
		else if (now_y == move_y && now_x > move_x) //����
		{
			for (int i = now_x - 1; i != move_x; i--)
				if (board[now_y][i].type != 'k')
					interval++;
		}
		else //������ֱ���ߵģ�����Ȼ�ǷǷ��ƶ�
			return 6;

		if (interval == 0) //����������ӣ���Ϊ�Ϸ���
			return 0;
		else if (interval > 1) //���������һ�����ϵ��ӣ���Ϊ�Ƿ��ƶ�
			return 6;
		else if (board[move_y][move_x].type != 'k') //�Ϸ�����
			return 0;
		else //���ӿɳ��򲻿������ƶ��Ƿ�
			return 6;
	}


	else if (board[now_y][now_x].type == 'c') //��
	{
		if (now_x == move_x && now_y < move_y) //������
		{
			for (int i = now_y + 1; i != move_y; i++)
				if (board[i][now_x].type != 'k') //�м������赲ʱ�ƶ��Ƿ�����ͬ
					return 6;
		}
		else if (now_x == move_x && now_y > move_y) //������
		{
			for (int i = now_y - 1; i != move_y; i--)
				if (board[i][now_x].type != 'k')
					return 6;
		}
		else if (now_y == move_y && now_x < move_x) //������
		{
			for (int i = now_x + 1; i != move_x; i++)
				if (board[now_y][i].type != 'k')
					return 6;
		}
		else if (now_y == move_y && now_x > move_x) //������
		{
			for (int i = now_x - 1; i != move_x; i--)
				if (board[now_y][i].type != 'k')
					return 6;
		}
		else //����ֱ��������Ȼ�ƶ��Ƿ�
			return 6;
		return 0; //ֱ����ǰ��δ�����������赲���ƶ��Ϸ�
	}


	else if (board[now_y][now_x].type == 'm') //��
	{ //д���Ƚ�������ܿɶ��Խϲ�
	    int dif_x = now_x > move_x ? now_x - move_x : move_x - now_x;
		int dif_y = now_y > move_y ? now_y - move_y : move_y - now_y;
		if (dif_x == 2 && dif_y == 1) //�������������һ���ĸ��㣩
		{
			if (board[now_y][(now_x + move_x) / 2].type != 'k') //��������
				return 6;
		}
		else if (dif_x == 1 && dif_y == 2) //����������һ�������ĸ��㣩
		{
			if (board[(now_y + move_y) / 2][now_x].type != 'k') //�������
				return 6;
		}
		else //���ߡ��ա�����Ϊ�Ƿ��ƶ�
			return 6;
		return 0; //���ˡ��ա��֣���û�������ȣ��Ϸ��ƶ�
	}

	else if (board[now_y][now_x].type == 'x') //��
	{
	    if (player == true && move_y > 4) //�췽���ܹ���
		    return 6;
	    else if (player == false && move_y < 5) //�ڷ����ܹ���
		    return 6;
		else
		{
			int dif_x = now_x > move_x ? now_x - move_x : move_x - now_x;
			int dif_y = now_y > move_y ? now_y - move_y : move_y - now_y;
			if (dif_x != 2 || dif_y != 2) //�����������ƶ��Ƿ�
				return 6;
			else if (board[(now_y + move_y) / 2][(now_x + move_x) / 2].type != 'k') //������
				return 6;
			return 0;
		}
    }

	else if (board[now_y][now_x].type == 's') //ʿ
	{
		if (player)//�췽
		{
			if (move_x < 3 || move_x > 5 || move_y > 2) return 6;//����
			else if (now_x == move_x || now_y == move_y) return 6;//��б��
			else if (now_x - move_x > 1 || now_x - move_x < -1 || now_y - move_y>1 || now_y - move_y < -1) return 6;//�ƶ�����һ��
			else return 0;
		}
		else //�ڷ�
		{
			if (move_x < 3 || move_x > 5 || move_y < 7) return 6;//����
			else if (now_x == move_x || now_y == move_y) return 6;//��б��
			else if (now_x - move_x > 1 || now_x - move_x < -1 || now_y - move_y>1 || now_y - move_y < -1) return 6;//�ƶ�����һ��
			else return 0;
		}
     }
     
    
	else if (board[now_y][now_x].type == 'j')//��
	{
		if (player) //�췽
		{
			if (move_x < 3 || move_x > 5 || move_y > 2) return 6;//����
			else if (now_x != move_x && now_y != move_y) return 6;//б��
			else if (now_x - move_x > 1 || now_x - move_x < -1 || now_y - move_y>1 || now_y - move_y < -1) return 6;//�ƶ�����һ��
			if (move_x != list[0][0].x) return 0;//�Խ�
			int between = 0; //����֮����������
			for (int i = list[1][0].y + 1; i < list[0][0].y; i++)
				if (board[i][now_x].type != 'k')
					between++;
			if (between == 0) return 6;
			else return 0;
		}
		else //�ڷ�
		{
			if (move_x < 3 || move_x > 5 || move_y < 7) return 6;//����
			else if (now_x != move_x && now_y != move_y) return 6;//б��
			else if (now_x - move_x > 1 || now_x - move_x < -1 || now_y - move_y>1 || now_y - move_y < -1) return 6;//�ƶ�����һ��
			if (move_x != list[1][0].x) return 0;//�Խ�
			int between = 0; //����֮����������
			for (int i = list[1][0].y + 1; i < list[0][0].y; i++)
				if (board[i][now_x].type != 'k')
					between++;
			if (between == 0) return 6;
			else return 0;
		}
	}
}

bool meet(int now_x, int now_y, int move_x, int move_y) //true��ʾ�ᵼ�¶Խ�
{
	if (board[now_y][now_x].type == 'j')
		return false;
	if (list[0][0].x != list[1][0].x) //������һ����϶���������
		return false;
	if (now_x != list[0][0].x) //Ҫ�����ӱ����Ͳ�����һ������Ҳ���ᵼ������
		return false;
	//������һ����û���أ����ʱ�����ӿ϶���һ��
	if (move_x == list[0][0].x || move_x == list[1][0].x) //���Խ�����
		return false;
	int between = 0; //����֮����������
	for (int i = list[1][0].y + 1; i < list[0][0].y; i++)
		if (board[i][now_x].type != 'k')
			between++;
	if (between == 1 && move_x != now_x) //ֻ�е�����֮��ֻ����һ���ӣ��Ҹ�����Ҫ�Ƶ������ʱ�Żᵼ�¶Խ�
		return true;
	else
		return false;
}