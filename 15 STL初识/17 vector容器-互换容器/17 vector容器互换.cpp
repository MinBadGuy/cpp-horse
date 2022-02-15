#include <iostream>
using namespace std;
#include <vector>

// vector��������

void printVector(vector<int>& v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

// 1������ʹ��
void test01() {
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	cout << "����ǰ��" << endl;
	printVector(v1);

	vector<int> v2;
	for (int i = 10; i > 0; i--)
	{
		v2.push_back(i);
	}
	printVector(v2);

	cout << "������" << endl;
	v1.swap(v2);
	printVector(v1);
	printVector(v2);
}

// 2��ʵ����;
// ����swap���������ڴ�ռ�
void test02() {
	vector<int> v2;
	for (int i = 0; i < 100000; i++)
	{
		v2.push_back(i);
	}

	cout << "v2������Ϊ��" << v2.capacity() << endl;
	cout << "v2�Ĵ�СΪ��" << v2.size() << endl;

	// ����ָ����С
	v2.resize(3);
	cout << "v2������Ϊ��" << v2.capacity() << endl;
	cout << "v2�Ĵ�СΪ��" << v2.size() << endl;

	// ����swap�����ڴ�
	vector<int>(v2).swap(v2);	// vector<int>(v2) ��һ���������󣬵��ÿ������캯��
	cout << "v2������Ϊ��" << v2.capacity() << endl;
	cout << "v2�Ĵ�СΪ��" << v2.size() << endl;
}

int main() {
	// test01();
	test02();

	system("pause");

	return 0;
}
