#include<iostream>
using namespace std;

int main()
{
	// 所有水仙花数

	// 1、先打印所有三位数
	int num = 100;
	do
	{
		// 2、从所有三位数中找到水仙花数
		int a = 0;
		int b = 0;
		int c = 0;

		a = num % 10;		// 个位
		b = num / 10 % 10;	// 十位
		c = num / 100;		// 百位

		if (a*a*a + b*b*b + c*c*c == num)
		{
			cout << num << endl;
		}

		num++;
	} while (num < 1000);

	system("pause");

	return 0;
}