#include<iostream>
#include<string>
using namespace std;

// constʹ�ó���
struct Student
{
	string name;	// ����
	int age;		// ����
	int score;		// ����
};

// �������е��βθĳ�ָ�룬���Լ����ڴ�ռ䣬���Ҳ��Ḵ���µĸ���
void printStudent(const Student* s)
{
	// s->age = 150;	// ����const֮��һ�����޸ĵĲ����ͻᱨ�����Է�ֹ�����
	cout << "������" << s->name << " ���䣺" << s->age << " �÷֣�" << s->score << endl;
}

int main()
{
	// �����ṹ�����
	Student s = { "����", 15, 70 };

	// ͨ��������ӡ�ṹ�������Ϣ
	printStudent(&s);

	cout << "main�� ������" << s.name << " ���䣺" << s.age << " �÷֣�" << s.score << endl;
}