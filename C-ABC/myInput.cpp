#include "chess.h"
#include <stdio.h>
//����һ�����԰�ȫ�����뺯����������ζ������������������
//���˺þ�����������ˣ�����qaq

/**********************
* ����ֵ˵����        *
* 0.��������          *
* 1.Ͷ��              *
* 2.����              *
* 3.�浵              *
* 4.����              *
* 5.�˳�              *
***********************/
int myInput(int* p_now_x, int* p_now_y, int* p_move_x, int* p_move_y)
{
	int temp; //����int
	char input_temp[21], ch; //��������ʹ���ĵ����ַ�����
	input_temp[20] = '\n'; //��β��֤���治������ѭ��
	bool flag = false; //��ʶ���޴���
	int num = 0; //ֻ��Ϊ�˰����˴���ѹ��һ�Σ�0Ϊnow��1Ϊmove
	while (1)
	{
		if (flag)
		{
			temp = 0;
			printf("                       �������������⣬���������꣬��һ������Ӧ��0��8��Χ�ڣ��ڶ���Ӧ��0��9��Χ��\n");
			if (num == 0) //͵��ing
				printf("                                             ��������Ҫ�ƶ��ĵ�����꣺");
			else
				printf("                                             ������Ŀ�������꣺");
		}
		else
		{
			if (num == 0)
				printf("                                             ��������Ҫ�ƶ��ĵ�����꣺");
			else
				printf("                                             ������Ŀ�������꣺");
		}
		fgets(input_temp, 20, stdin); //�����������ַ���
		int shift = 0;
		sscanf_s(input_temp + (shift++), "%c", &ch);

		if (ch == 't') //Ͷ������
		{
			sscanf_s(input_temp + (shift++), "%c", &ch);
			if (ch == '\n')
				return 1;
			else
			{
				flag = true;
				continue;
			}
		}
		else if (ch == 'h') //��������
		{
			sscanf_s(input_temp + (shift++), "%c", &ch);
			if (ch == '\n')
				return 2;
			else
			{
				flag = true;
				continue;
			}
		}
		else if (ch == 's') //�浵����
		{
			sscanf_s(input_temp + (shift++), "%c", &ch);
			if (ch == '\n')
				return 3;
			else
			{
				flag = false;
				continue;
			}
		}
		else if (ch == 'c') //��������
		{
			sscanf_s(input_temp + (shift++), "%c", &ch);
			if (ch == '\n')
				return 4;
			else
			{
				flag = false;
				continue;
			}
		}
		else if (ch == 'q') //�˳�����
		{
			sscanf_s(input_temp + (shift++), "%c", &ch);
			if (ch == '\n')
				return 5;
			else
			{
				flag = false;
				continue;
			}
		}

		if (ch < '0' || ch>'9')
		{
			flag = true;
			continue;
		}
		temp = 0;
		flag = false;
		while (ch != ' ' && ch != '\n' && ch != ',')
		{
			if (ch >= '0' && ch <= '9')
				temp = temp * 10 + ch - '0';
			else
			{
				flag = true;
				break;
			}
			sscanf_s(input_temp + (shift++), "%c", &ch);
		}
		if (ch == '\n')
			flag = true;
		if (flag)
			continue;
		if (num == 0) //�ٴ�͵��������
			*p_now_x = temp;
		else
			*p_move_x = temp;
		temp = 0;
		while ((ch == ' ' || ch == ',') && ch != '\n')
			sscanf_s(input_temp + (shift++), "%c", &ch);
		while (ch != ' ' && ch != '\n')
		{
			if (ch >= '0' && ch <= '9')
				temp = temp * 10 + ch - '0';
			else
			{
				flag = true;
				break;
			}
			sscanf_s(input_temp + (shift++), "%c", &ch);
		}
		if (flag)
			continue;
		if (num == 0) //��͵���Ĺؼ�
		{
			*p_now_y = temp;
			temp = 0;
			num++;
		}
		else
		{
			*p_move_y = temp;
			break;
		}
	}
	return 0; //��������
}