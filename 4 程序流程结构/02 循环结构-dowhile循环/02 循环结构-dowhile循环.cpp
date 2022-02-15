#include<iostream>
using namespace std;

int main()
{
	// do...while语句
	// 在屏幕中输出0~9这10个数字
	int num = 0;
	do
	{
		cout << num << endl;
		num++;
	} while (num < 10);

	// do...while 和 while循环区别在于 do...while会先执行一次循环语句 
	
	system("pause");

	return 0;
}