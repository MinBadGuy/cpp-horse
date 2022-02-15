#include <iostream>
using namespace std;

// string 子串获取

void test01() {
	string str = "abcdefg";
	
	string subStr = str.substr(2, 3);
	// cde
	cout << "subStr = " << subStr << endl;
}

// 实用操作
void test02() {
	string email = "zhangsan@sina.com";

	// 从邮件地址中 获取用户名信息
	int pos = email.find("@");	// 8
	cout << pos << endl;

	string usrName = email.substr(0, pos);
	cout << "useName = " << usrName << endl;
}

int main() {
	// test01();
	test02();

	system("pause");

	return 0;
}