#define _CRT_SECURE_NO_WARNINGS
#include "chess.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

//����ֵ˵����0.�����������̣�1.���ļ�������
int show_UI()
{
	char temp_s[11];
	temp_s[10] = '\n';
	int deal = 0;
	char ch;
	int shift = 0;
	while (deal == 0)
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n");
		printf("                                                        �й�����\n\n\n\n");
		printf("                                                     1.�� �� �� Ϸ\n");
		printf("                                                     2.�� �� �� ��\n");
		printf("                                                     3.�� �� �� ��\n");
		printf("                                                     4.�� ʷ �� ��\n");
		printf("                                                     5.�� �� �� Ϸ\n");
		printf("                                                            ");
		fgets(temp_s, 10, stdin); //��ȫ������
		shift = 0;
		sscanf_s(temp_s + (shift++), "%c", &ch);
		if (ch < '1' || ch>'5')
			continue;
		else
			deal = ch - '0';
		sscanf_s(temp_s + (shift++), "%c", &ch); //���벻��ȷʱ������ʾ����֤�������
		if (ch != '\n' && ch != '\0')
		{
			deal = 0;
			continue;
		} //��ȫ���뵽��Ϊֹ
		if (deal == 1)
			return 0;
		else if (deal == 2)
			return 1;
		else if (deal == 3)
		{
			while (deal != 0)
			{
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n\n");
				printf("                                                          ����\n\n\n");
				printf("                                                     0.�����ϼ�Ŀ¼\n");
				printf("                                                     1.��Ϸ����\n");
				printf("                                                     2.��Ϸ����\n");
				printf("                                                     3.��Ȩ˵��\n");
				printf("                                                     4.����������\n");
				printf("                                                            ");
				fgets(temp_s, 10, stdin); //��ȫ������
				shift = 0;
				sscanf_s(temp_s + (shift++), "%c", &ch);
				if (ch < '0' || ch>'4')
					continue;
				else
					deal = ch - '0';
				sscanf_s(temp_s + (shift++), "%c", &ch); //���벻��ȷʱ������ʾ����֤�������
				if (ch != '\n' && ch != '\0')
				{
					deal = 0;
					continue;
				}
				switch (deal)
				{
					case 0:
						break;
					case 1:
						system("cls");
						printf("\n                                                         ��Ϸ����\n");
						printf("\n\n");
						printf(" ʤ��:\n");
						printf("\n  ����������һ����һ����֮����ͼ�Ե�һ����˧�����������÷���˧������ȴ���ܶ��");
						printf("\n  ���С����ֵ�һ�����壬�����涨������������ߣ�");
						printf("\n  ���䡪�������������⣬�����ֿ�����������������䣻\n\n");
						printf("\n ����:\n");
						printf("\n     ˧��������˧�����������е����ԣ���˫�����������Ŀ�ꡣ��ֻ���ھŹ�֮�ڻ�����Ͽ��£�������ң�ÿ���߶�ֻ�ܰ�\n  ���߻�����߶�һ��˧�뽫������ͬһֱ����ֱ�Ӷ��档\n");
						printf("\n     �ˣ�ʿ�����ˣ�ʿ���ǽ���˧���������ڣ���Ҳֻ���ھŹ����߶�����������·��ֻ�оŹ��ڵ�����б�ߡ�\n");
						printf("\n     �ࣨ�󣩣��ࣨ�󣩵���Ҫ�����Ƿ��أ������Լ���˧�������������߷���ÿ��ѭ�Խ����������׳ơ��������ࣨ��\n  �Ļ��Χ���ںӽ����ڵı�����أ����ܹ��ӣ���������ߵ�����������һ�����ӣ��Ͳ����ߣ��׳ơ������ۡ���\n");
						printf("\n     ������������������������ۺ��ߡ����߾������ߣ�ֻҪ���������������������ơ���ˣ�һ�����Կ���ʮ�߸��㣬����\n  ��һ��ʮ�Ӻ���֮�ơ�\n");
						printf("\n     �ڣ����ڲ����ӵ�ʱ���ƶ��복��ȫ��ͬ��������ʱ�������ͶԷ��������м������1�����ӣ����۶Է��򼺷����ӣ���\n  ����������Ψһ����Խ�ӵ����֡�\n");
						printf("\n     �����߶��ķ�����һֱһб�����Ⱥ��Ż�ֱ����һ��Ȼ����б����һ���Խ��ߣ��׳ơ������ա�����һ�ο��ߵ�ѡ���\n  ���Դﵽ���ܵİ˸��㣬���С��������硱֮˵�������Ҫȥ�ķ����б�����ӵ�ס������޷��߹�ȥ���׳ơ������ȡ���\n");
						printf("\n     �����䣩�������䣩��δ����ǰ��ֻ����ǰһ�����ߣ������Ժ󣬳����ܺ����⣬���������ƶ�����Ҳֻ��һ��һ������ʹ\n  �����������䣩������Ҳ�����ǿ�����С����ӵ����Ӷ��������֮˵��");
						printf("\n\n                                                  ������0�ص��ϼ�Ŀ¼��");
						scanf_s("%d", &deal);
						deal = 1;
						break;
					case 2:
						system("cls");
						printf("\n                                                         ��Ϸ����\n");
						printf("\n\n\n\n\n");
						printf("          ���������Ե����������ʾ���������ӡ�\n");
						printf("\n          ����\"t\"��Ͷ��\n");
						printf("\n          ����\"h\"��һ����\n");
						printf("\n          ����\"s\"���浵\n");
						printf("\n          ����\"c\"���鿴��������\n");
						printf("\n          ����\"q\"���˳�\n");
						printf("\n\n\n\n\n\n\n\n                                                  ������0�ص��ϼ�Ŀ¼��");
						scanf_s("%d", &deal);
						deal = 1;
						break;
					case 3:
						system("cls");
						printf("\n                                                         ��Ȩ˵��\n");
						printf("\n\n\n");
						printf("                                        ����Ʒ��ѭ֪ʶ�������Э��(CC)4.0Э�顣\n");
						printf("  ���������ɵ�ʹ�ñ�����\n\n");
						printf("    Ω����������������\n\n");
						printf("  ����ͬ��ʽ���� �� ���������ɸ��ơ�ɢ����չʾ���ݳ�����Ʒ; �����ı䡢ת�����ı���Ʒ�����������뱾��Ʒ��ͬ����������£�������ɢ���ɱ���Ʒ������������Ʒ��\n");
						printf("\n  ������ �� �����û������Ը��ơ����С�չ�������ݡ���ӳ���㲥��ͨ����Ϣ���紫������Ʒ�������밴�����߻��������ָ���ķ�ʽ����Ʒ����������\n");
						printf("\n  ������ҵ��ʹ�� �� ���������ɸ��ơ�ɢ����չʾ���ݳ�����Ʒ;������Ϊ��ҵĿ�Ķ�ʹ�ñ���Ʒ��\n");
						printf("\n  ��û�и������� �� ������ʹ�÷���������߼�����ʩ�Ӷ����������������Э����������顣\n");
						printf("\n\n  ������\n");
						printf("    ��������Ϊ�����������ƷҪ�ض��������Э�飬��������ʹ�ñ������õ����������������\n");
						printf("    ���ṩ���������Э����ܲ����������ͼʹ�õ��������������ɡ����磬����Ȩ����������Ȩ����˽Ȩ���˸�Ȩ��������\n  �����ʹ����Ʒ��\n");
						printf("                                                  ������0�ص��ϼ�Ŀ¼��");
						scanf_s("%d", &deal);
						deal = 1;
						break;
					case 4:
						system("cls");
						printf("\n                                            ������������������ƴ������ĸ����\n");
						printf("\n\n\n\n\n\n");
						printf("                                                       ���F��\n\n");
						printf("                                                       ����\n\n");
						printf("                                                       ½����\n\n");
						printf("                                                       ̷��Ԫ\n\n");
						printf("                                                       ������\n\n");
						printf("\n\n\n                                                 ������0�ص��ϼ�Ŀ¼��");
						scanf_s("%d", &deal);
						deal = 1;
						break;
				}
			}
		}
		else if (deal == 4)
		{
			while (deal != 0)
			{
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n\n                                                        ��ʷ�ع�\n\n\n");
				printf("                                                    0.�����ϼ�Ŀ¼\n");
				printf("                                                    1.�Ͼ�����\n");
				printf("                                                    2.��Ծ����а�\n");
				printf("                                                           ");
				fgets(temp_s, 10, stdin); //��ȫ������
				shift = 0;
				sscanf_s(temp_s + (shift++), "%c", &ch);
				if (ch < '0' || ch>'2')
					continue;
				else
					deal = ch - '0';
				sscanf_s(temp_s + (shift++), "%c", &ch); //���벻��ȷʱ������ʾ����֤�������
				if (ch != '\n' && ch != '\0')
				{
					deal = 0;
					continue;
				}
				if (deal == 1)
				{
					system("cls");
					FILE* fp;
					fp = fopen("record_1.txt", "r");
					if (fp == NULL)
					{
						printf("\n\n\n\n\n\n\n\n\n\n\n                                                     δ�ҵ�����ļ�\n");
						deal = 1;
					}
					else
					{
						char record_line[101];
						record_line[100] = '\0';
						int i = 1;
						bool printf_flag = true;
						while (fgets(record_line, 100, fp) != NULL)
						{
							if(printf_flag)
								printf("\n\n                                                      �Ͼ�����\n\n\n");
							printf("                                            ��%d��  %s\n", i++, record_line);
							printf_flag = false;
						}
						if (printf_flag)
							printf("\n\n\n\n\n\n\n\n\n\n\n                                                      �������޼�¼��\n");
						fclose(fp);
					}
					printf("\n\n\n\n\n                                                   ");
					system("pause");
					deal = 1;
				}

				else if (deal == 2) //���а�
				{
					FILE* fp;
					fp = fopen("ranking_list.txt", "r");
					if (fp == NULL)
					{
						system("cls");
						printf("\n\n\n\n\n\n\n\n\n\n\n                                                     ���а��¼��ʧ\n");
						printf("\n\n\n\n\n                                                   ");
						system("pause");
						deal = 1;
						continue;
					}
					int step_temp;
					system("cls");
					printf("\n\n                                                    ��������а�\n\n\n\n\n\n");
					int i;
					for (i = 0; fscanf(fp, "%d", &step_temp) != EOF; i++)
					{
						struct tm info;
						fscanf(fp, "%d %d %d %d %d %d", &info.tm_year, &info.tm_mon, &info.tm_mday, &info.tm_hour, &info.tm_min, &info.tm_sec);
						printf("        %2d.  ��%4d  ��  ", i+1, step_temp);
						printf("%d �� %2d �� %2d ��  %2d : %.2d : %.2d\n", info.tm_year, info.tm_mon, info.tm_mday, info.tm_hour, info.tm_min, info.tm_sec);
					}
					while (i < 10)
					{
						printf("        %2d.\n", (i++)+1);
					}
					printf("\n\n\n\n\n                                                 ������0�ص��ϼ�Ŀ¼��");
					scanf_s("%d", &deal);
					deal = 1;
					fclose(fp);
				}
			}
		}
		else if (deal == 5) //�˳�
			exit(EXIT_SUCCESS);
	}
}