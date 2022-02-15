#include <iostream>
using namespace std;
#include <deque>

// deque ��С����

void printDeque(const deque<int>& d) {
	for (deque<int>::const_iterator it = d.cbegin(); it != d.cend(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01() {
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);

	if (d1.empty())
	{
		cout << "d1Ϊ��" << endl;
	}
	else
	{
		cout << "d1��Ϊ��" << endl;
		cout << "d1�Ĵ�СΪ��" << d1.size() << endl;
		// dequeû���������� capacity
	}

	// ����ָ����С
	d1.resize(15);
	d1.resize(15, 1);
	printDeque(d1);

	d1.resize(5);
	printDeque(d1);
}

int main() {
	test01();

	system("pause");

	return 0;
}