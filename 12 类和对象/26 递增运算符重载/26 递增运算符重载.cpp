#include <iostream>
using namespace std;

// 重载递增运算符

// 自定义整型
class MyInteger {
	friend ostream& operator<<(ostream& os, MyInteger myint);
public:
	MyInteger() {
		m_Num = 0;
	}

	// 重载前置++运算符
	MyInteger& operator++() {
		// 先进行++运算
		m_Num++;

		// 再将自身做返回
		return *this;
	}

	// 重载后置++运算符
	// MyInteger operator++(int)	int代表占位参数，可以用于区分前置和后置递增
	MyInteger operator++(int) {
		// 先 记录当时结果
		MyInteger temp = *this;
		// 后 递增
		m_Num++;
		// 最后将记录做返回
		return temp;
	}

private:
	int m_Num;
};

// 重载<<运算符
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