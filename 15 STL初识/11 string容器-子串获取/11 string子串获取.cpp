#include <iostream>
using namespace std;

// string �Ӵ���ȡ

void test01() {
	string str = "abcdefg";
	
	string subStr = str.substr(2, 3);
	// cde
	cout << "subStr = " << subStr << endl;
}

// ʵ�ò���
void test02() {
	string email = "zhangsan@sina.com";

	// ���ʼ���ַ�� ��ȡ�û�����Ϣ
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