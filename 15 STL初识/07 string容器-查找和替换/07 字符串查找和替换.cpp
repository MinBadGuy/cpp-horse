#include <iostream>
using namespace std;

// �ַ������Һ��滻

// 1������
void test01() {
	string str1 = "abcdefgde";

	// find
	int pos = str1.find("de");

	if (pos == -1)
	{
		cout << "δ�ҵ��ַ���" << endl;
	}
	else
	{
		cout << "�ҵ��ַ�����pos = " << pos << endl;
	}

	// rfind ��find����
	// rfind�����������	find�������Ҳ���
	pos = str1.rfind("de");
	cout << "pos = " << pos << endl;
}

// 2���滻
void test02() {
	string str2 = "abcdefg";
	// ��1��λ���� 3���ַ��ַ��滻Ϊ "1111"
	str2.replace(1, 3, "1111");
	cout << "str2 = " << str2 << endl;
}

int main() {
	// test01();

	test02();

	system("pause");

	return 0;
}