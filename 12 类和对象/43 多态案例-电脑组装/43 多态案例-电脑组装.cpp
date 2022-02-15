#include <iostream>
using namespace std;

// ��̬����-��װ����

// ����ͬ�����

// ����CPU��
class CPU {
public:
	// ����ļ��㺯��
	virtual void calculate() = 0;
};

// �����Կ���
class VideoCard {
public:
	// �������ʾ����
	virtual void display() = 0;
};

// �����ڴ�����
class Memory {
public:
	// ����Ĵ洢����
	virtual void storage() = 0;
};

// ������
class Computer {
public:
	Computer(CPU* cpu, VideoCard* vc, Memory* mem) {
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}

	// �ṩ�����ĺ���
	void work() {
		// ������������������ýӿ�
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}

	~Computer() {
		if (m_cpu != NULL)
		{
			delete m_cpu;
		}
		if (m_vc != NULL)
		{
			delete m_vc;
		}
		if (m_mem != NULL)
		{
			delete m_mem;
		}
	}

private:
	CPU* m_cpu;	// CPU�����ָ��
	VideoCard* m_vc;	// �Կ������ָ��
	Memory* m_mem;	// �ڴ��������ָ��
};

// ���峧��

// Intel����
class IntelCPU :public CPU {
	virtual void calculate() {
		cout << "Intel��CPU��ʼ�����ˣ�" << endl;
	}
};

class IntelVideoCard :public VideoCard {
	virtual void display() {
		cout << "Intel���Կ���ʼ��ʾ�ˣ�" << endl;
	}
};

class IntelMemory :public Memory {
	virtual void storage() {
		cout << "Intel���ڴ�����ʼ�洢�ˣ�" << endl;
	}
};

// Lenovo����
class LenovoCPU :public CPU {
	virtual void calculate() {
		cout << "Lenovo��CPU��ʼ�����ˣ�" << endl;
	}
};

class LenovoVideoCard :public VideoCard {
	virtual void display() {
		cout << "Lenovo���Կ���ʼ��ʾ�ˣ�" << endl;
	}
};

class LenovoMemory :public Memory {
	virtual void storage() {
		cout << "Lenovo���ڴ�����ʼ�洢�ˣ�" << endl;
	}
};

void test01() {
	cout << "��һ�����Կ�ʼ����" << endl;
	// ��һ̨�������
	CPU* intelCpu = new IntelCPU;
	VideoCard* intelCard = new IntelVideoCard;
	Memory* intelMem = new IntelMemory;

	// ������һ̨����
	Computer* computer1 = new Computer(intelCpu, intelCard, intelMem);
	computer1->work();
	delete computer1;

	cout << "-----------------------" << endl;
	cout << "�ڶ������Կ�ʼ����" << endl;
	// �����ڶ�̨����
	Computer* computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
	computer2->work();
	delete computer2;

	cout << "-----------------------" << endl;
	cout << "���������Կ�ʼ����" << endl;
	// ��������̨����
	Computer* computer3 = new Computer(new LenovoCPU, new IntelVideoCard, new LenovoMemory);
	computer3->work();
	delete computer3;
}

int main() {
	test01();

	system("pause");

	return 0;
}