#include<iostream>
#include<time.h>
using namespace std;

int main()
{
	// ������������ ���õ�ǰϵͳʱ���������������ֹÿ���������һ��
	srand((unsigned int) time(NULL));

	// 1��ϵͳ���������
	int num = rand() % 100 + 1;	// rand() % 100 + 1	���� 0+1 ~ 99+1�����
	// cout << num << endl;

	/*num = rand() % 100 + 1;
	cout << num << endl;

	num = rand() % 100 + 1;
	cout << num << endl;*/

	// 2����ҽ��в²�
	int val = 0;

	// 3���ж���ҵĲ²�
	while (1)
	{
		cin >> val;

		if (val > num)
		{
			cout << "�²����" << endl;
		}
		else if (val < num)
		{
			cout << "�²��С" << endl;
		}
		else
		{
			cout << "��ϲ���¶���" << endl;
			// �¶� �˳���Ϸ
			break;	// break���������øùؼ������Ƴ���ǰѭ��
		}
	}
	

	// �¶�	�˳���Ϸ
	// �´�	��ʾ�µĽ�� ������С ���·��ص�2��

	system("pause");

	return 0;
}