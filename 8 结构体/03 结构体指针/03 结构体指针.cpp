#include<iostream>
#include<string>
using namespace std;

// �ṹ��ָ��

// ����ѧ���ṹ��
struct Student
{
	string name;	// ����
	int age;		// ����
	int score;		// ����
};

int main()
{
	// ����ѧ���Ľṹ�����
	Student s = { "����", 18, 100 };
	
	// ͨ��ָ��ָ��ṹ�����
	Student* p = &s;

	// ͨ��ָ����ʽṹ������е�����
	// ͨ���ṹ��ָ����ʽṹ���е����ԣ���Ҫʹ�� ->
	cout << "������" << p->name << " ���䣺" << p->age << " ������" << p->score << endl;

	system("pause");

	return 0;
}