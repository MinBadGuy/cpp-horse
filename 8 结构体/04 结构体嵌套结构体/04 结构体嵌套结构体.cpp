#include<iostream>
#include<string>
using namespace std;

struct Student
{
	string name;	// ѧ������
	int age;		// ѧ������
	int score;		// ѧ������
};

// ������ʦ�ṹ��
struct Teacher
{
	int id;			// ��ʦ���
	string name;	// ��ʦ����
	int age;		// ��ʦ����
	Student stu;	// ����ѧ��
};

int main()
{
	// �ṹ��Ƕ�׽ṹ��
	// ������ʦ
	Teacher t;
	t.id = 10000;
	t.name = "����";
	t.age = 50;
	t.stu.name = "С��";
	t.stu.age = 20;
	t.stu.score = 60;

	cout << "��ʦ������" << t.name << " ��ʦ��ţ�" << t.id << " ��ʦ���䣺" << t.age << endl
		<< "������ѧ��������" << t.stu.name << " ѧ�����䣺" << t.stu.age << " ѧ�����Է�����" << t.stu.score << endl;

	system("pause");

	return 0;
}