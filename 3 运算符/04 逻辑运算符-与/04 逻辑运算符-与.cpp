#include<iostream>
using namespace std;

int main()
{
	// �߼������	��	&&
	int a = 10;
	int b = 10;
	cout << (a && b) << endl;

	a = 0;
	b = 10;
	cout << (a && b) << endl;

	a = 0;
	b = 0;
	cout << (a && b) << endl;

	// �߼��룺ͬ��Ϊ�棬����Ϊ��

	system("pause");

	return 0;
}