#include<iostream>
#include<time.h>
using namespace std;

int main()
{
	// 添加随机数种子 利用当前系统时间生成随机数，防止每次随机数都一样
	srand((unsigned int) time(NULL));

	// 1、系统生成随机数
	int num = rand() % 100 + 1;	// rand() % 100 + 1	生成 0+1 ~ 99+1随机数
	// cout << num << endl;

	/*num = rand() % 100 + 1;
	cout << num << endl;

	num = rand() % 100 + 1;
	cout << num << endl;*/

	// 2、玩家进行猜测
	int val = 0;

	// 3、判断玩家的猜测
	while (1)
	{
		cin >> val;

		if (val > num)
		{
			cout << "猜测过大" << endl;
		}
		else if (val < num)
		{
			cout << "猜测过小" << endl;
		}
		else
		{
			cout << "恭喜您猜对了" << endl;
			// 猜对 退出游戏
			break;	// break，可以利用该关键字来推出当前循环
		}
	}
	

	// 猜对	退出游戏
	// 猜错	提示猜的结果 过大或过小 重新返回地2步

	system("pause");

	return 0;
}