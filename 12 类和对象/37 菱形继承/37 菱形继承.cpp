#include <iostream>
using namespace std;

// ���μ̳�

// ������
class Animal {
public:
	int m_Age;
};

// ������̳� ������μ̳е�����
// �̳�֮ǰ ���Ϲؼ��� virtual ��Ϊ��̳�
// Animal���Ϊ �����
// ����
class Sheep :virtual public Animal {

};

// ����
class Camel :virtual public Animal {

};

// ������
class SheepCamel : public Sheep, public Camel {

};

void test01() {
	SheepCamel sc;

	sc.Sheep::m_Age = 18;
	sc.Camel::m_Age = 28;
	// �����μ̳�ʱ����������ӵ����ͬ���ݣ���Ҫ������������
	cout << "sc.Sheep::m_Age = " << sc.Sheep::m_Age << endl;
	cout << "sc.Camel::m_Age = " << sc.Camel::m_Age << endl;
	cout << "sc.m_Age = " << sc.m_Age << endl;
	
	// �����������֪����ֻҪ��һ�ݾͿ��ԣ����μ̳е������������ݣ���Դ�˷�
}

int main() {
	test01();

	system("pause");

	return 0;
}