#include <iostream>
using namespace std;

// �̳з�ʽ

// �����̳�
class Base {
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son1 :public Base {
public:
	void func() {
		m_A = 10;	// �����еĹ���Ȩ�޳�Ա ����������Ȼ�ǹ���Ȩ��
		m_B = 10;	// �����еı���Ȩ�޳�Ա ����������Ȼ�Ǳ���Ȩ��
		// m_C = 10;	// �����е�˽��Ȩ�޳�Ա �������з��ʲ���
	}
};

void test01() {
	Son1 s1;
	s1.m_A = 100;
	// s1.m_B = 100; ��Son1�� m_B�Ǳ���Ȩ�� ������ʲ���
}

// �����̳�
class Son2 :protected Base {
public:
	void func() {
		m_A = 100;	// �����й��г�Ա���������б�Ϊ����Ȩ��
		m_B = 100;	// �����б�����Ա���������б�Ϊ����Ȩ��
		// m_C = 100;	// ������˽�г�Ա ������ʲ���
	}
};

void test02() {
	Son2 s2;
	// s2.m_A = 1000;	// ��Son2�� m_A��Ϊ����Ȩ�ޣ����������ʲ���
	// s2.m_B = 1000;	// ��Son2�� m_B�Ǳ���Ȩ�ޣ����ⲻ���Է���
}

// ˽�м̳�
class Son3 :private Base {
public:
	void func() {
		m_A = 100;	// �����й�����Ա �������б�Ϊ ˽�г�Ա
		m_B = 100;	// �����б�����Ա �������б�Ϊ ˽�г�Ա	
		// m_C = 100;	// ������˽�г�Ա��������ʲ���
	}
};

class GrandSon3 : public Son3 {
public:
	void func() {
		// m_A = 1000;	// ����Son3�� m_A��Ϊ˽�У���ʹ�Ƕ��ӣ�Ҳ�Ƿ��ʲ���
		// m_B = 1000; // ����Son3�� m_B��Ϊ˽�У���ʹ�Ƕ��ӣ�Ҳ�Ƿ��ʲ���
	}
};

void test03() {
	Son3 s3;
	// s3.m_A = 1000;	// ��Son3�� ��Ϊ ˽�г�Ա ������ʲ���
	// s1.m_B = 1000;	// ��Son3�� ��Ϊ ˽�г�Ա ������ʲ���
}

int main() {


	system("pause");

	return 0;
}