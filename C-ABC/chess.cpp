#include "chess.h"
//��������

bool player; //��¼��ǰ���� trueΪ�죬falseΪ��
qiZi_T board[MAX_ROW][MAX_COL]; //����
locate_T list[2][12]; //����λ���б�   0:�ڣ�1:��    list[][0]�̶��ǽ� �����11���Ӷ��ǹ�����
node_PT record_start; //���������ͷ
node_PT record_now; //����β�����
bool threat_flag; //�ж����ޱ�����
int step; //��¼�����ж�����