#include<iostream>
#include<string>
using namespace std;

// ����ѧ���ṹ��
struct Student
{
	// ����
	string name;
	// ����
	int age;
	// ����
	int score;
};

// ��ӡѧ����Ϣ����
// 1��ֵ����
void printStudent1(Student s)
{
	s.age = 100;
	cout << "�Ӻ���1�� ������" << s.name << " ���䣺" << s.age << " ������" << s.score << endl;
}

// 2����ַ����
void printStudent2(Student* p)
{
	p->age = 100;
	cout << "�Ӻ���2�� ������" << p->name << " ���䣺" << p->age << " ������" << p->score << endl;
}

int main()
{
	// �ṹ������������
	// ��ѧ�����뵽һ������ֵ����ӡѧ�����ϵ�������Ϣ
	Student s;
	s.name = "����";
	s.age = 20;
	s.score = 85;

	printStudent1(s);
	printStudent2(&s);
	cout << "main������ ������" << s.name << " ���䣺" << s.age << " ������" << s.score << endl;
	

	system("pause");

	return 0;
}