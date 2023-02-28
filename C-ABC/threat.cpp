#include "chess.h"
#include <stdbool.h>

extern bool player;
extern locate_T list[2][12]; //����λ���б�   0:�ڣ�1:��    list[][0]�̶��ǽ�

bool threat(void)
{
	player = !player; //�ȷ�ת�Ա�ʹ��isLegal����
	for (int i = 1; i <= 11; i++)
	{
		if (list[player][i].type != 'k' && isLegal(list[player][i].x, list[player][i].y, list[!player][0].x, list[!player][0].y) == 0)
		{
			player = !player; //��ת��ȥ
			return true;
		}
	}
	player = !player; //��ת��ȥ
	return false;
}