#include<iostream>
using namespace std;

int main()
{
	// ���û����﷨
	// �������� &���� = ԭ��

	int a = 10;
	// ��������
	int& b = a;

	cout << "a = " << a << endl;
	cout << "b = " << a << endl;

	b = 100;
	cout << "a = " << a << endl;
	cout << "b = " << a << endl;

	system("pause");

	return 0;
}