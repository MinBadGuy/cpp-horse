#include<iostream>
using namespace std;

int main()
{
	// 转义字符

	// 换行符 \n
	cout << "hello world\n";

	/* 反斜杠 \\ */
	cout << "\\" << endl;

	// 水平制表符 \t		作用是可以整齐输出数据
	cout << "aaaa\thelloworld" << endl;
	cout << "aaa\thelloworld" << endl;
	cout << "aaaaaa\thelloworld" << endl;

	system("pause");

	return 0;
}