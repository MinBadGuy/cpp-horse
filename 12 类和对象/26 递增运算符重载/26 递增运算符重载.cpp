#include <iostream>
using namespace std;

// ���ص��������

// �Զ�������
class MyInteger {
	friend ostream& operator<<(ostream& os, MyInteger myint);
public:
	MyInteger() {
		m_Num = 0;
	}

	// ����ǰ��++�����
	MyInteger& operator++() {
		// �Ƚ���++����
		m_Num++;

		// �ٽ�����������
		return *this;
	}

	// ���غ���++�����
	// MyInteger operator++(int)	int����ռλ������������������ǰ�úͺ��õ���
	MyInteger operator++(int) {
		// �� ��¼��ʱ���
		MyInteger temp = *this;
		// �� ����
		m_Num++;
		// ��󽫼�¼������
		return temp;
	}

private:
	int m_Num;
};

// ����<<�����
//ostream& operator<<(ostream& os, MyInteger& myint) {
//	os << myint.m_Num;
//	return os;
//}

ostream& operator<<(ostream& os, MyInteger myint) {
	os << myint.m_Num;
	return os;
}

void test01() {
	MyInteger myint;

	cout << ++(++myint) << endl;
	cout << myint << endl;
}

void test02() {
	MyInteger myint;

	cout << myint++ << endl;
	cout << myint << endl;
}

int main() {
	// test01();
	test02();

	system("pause");

	return 0;
}