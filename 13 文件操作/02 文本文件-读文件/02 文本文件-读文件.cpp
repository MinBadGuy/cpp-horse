#include <iostream>
#include <fstream>
using namespace std;
#include <string>

// �ı��ļ� ���ļ�

void test01() {
	// 1������ͷ�ļ�

	// 2������������
	ifstream ifs;

	// 3�����ļ� �����ж��Ƿ�򿪳ɹ�
	ifs.open("test.txt", ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	// 4��������
	
	// ��һ��
	/*char buff[1024] = { 0 };
	while (ifs >> buff)
	{
		cout << buff << endl;
	}*/

	// �ڶ���
	/*char buff[1024] = { 0 };
	while (ifs.getline(buff, sizeof(buff)))
	{
		cout << buff << endl;
	}*/

	// ������
	string buff;
	while (getline(ifs, buff))
	{
		cout << buff << endl;
	}

	// ������
	/*char c;
	while ((c = ifs.get()) != EOF)
	{
		cout << c;
	}*/

	// 5���ر��ļ�
	ifs.close();

}

int main() {
	test01();

	system("pause");

	return 0;
}