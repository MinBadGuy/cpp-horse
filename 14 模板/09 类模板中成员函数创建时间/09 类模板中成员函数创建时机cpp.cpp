#include <iostream>
using namespace std;

// ��ģ���г�Ա��������ʱ��
// ��ģ���Ա�����ڵ���ʱ��ȥ����

class Person1 {
public:
	void showPerson1() {
		cout << "Person1 show" << endl;
	}
};

class Person2 {
public:
	void showPerson2() {
		cout << "Person2 show" << endl;
	}
};

template<class T>
class MyClass {
public:
	T obj;

	// ��ģ���еĳ�Ա����
	void fun1() {
		obj.showPerson1();
	}

	void fun2() {
		obj.showPerson2();
	}
};

void test01() {
	MyClass<Person2> m;
	// m.fun1();
	m.fun2();
}

int main() {
	test01();

	system("pause");

	return 0;
}