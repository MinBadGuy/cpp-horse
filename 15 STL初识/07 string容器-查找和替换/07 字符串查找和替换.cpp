#include <iostream>
using namespace std;

// 字符串查找和替换

// 1、查找
void test01() {
	string str1 = "abcdefgde";

	// find
	int pos = str1.find("de");

	if (pos == -1)
	{
		cout << "未找到字符串" << endl;
	}
	else
	{
		cout << "找到字符串，pos = " << pos << endl;
	}

	// rfind 和find区别
	// rfind从右往左查找	find从左往右查找
	pos = str1.rfind("de");
	cout << "pos = " << pos << endl;
}

// 2、替换
void test02() {
	string str2 = "abcdefg";
	// 从1号位置起 3个字符字符替换为 "1111"
	str2.replace(1, 3, "1111");
	cout << "str2 = " << str2 << endl;
}

int main() {
	// test01();

	test02();

	system("pause");

	return 0;
}