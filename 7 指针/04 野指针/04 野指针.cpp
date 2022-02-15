#include<iostream>
using namespace std;

int main()
{
	// 野指针：指针变量指向非法的内存空间
	// 在程序中，应该避免出现野指针
	int* p = (int*)0x1100;
	cout << *p << endl;

	system("pause");

	return 0;

	// 空指针和野指针都不是自己申请的空间，因此不要访问
}