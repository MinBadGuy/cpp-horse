#include<iostream>
using namespace std;

int main()
{
	// ����ˮ�ɻ���

	// 1���ȴ�ӡ������λ��
	int num = 100;
	do
	{
		// 2����������λ�����ҵ�ˮ�ɻ���
		int a = 0;
		int b = 0;
		int c = 0;

		a = num % 10;		// ��λ
		b = num / 10 % 10;	// ʮλ
		c = num / 100;		// ��λ

		if (a*a*a + b*b*b + c*c*c == num)
		{
			cout << num << endl;
		}

		num++;
	} while (num < 1000);

	system("pause");

	return 0;
}