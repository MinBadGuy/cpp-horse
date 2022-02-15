#include<iostream>
#include<string>
using namespace std;

// 定义学生结构体
struct Student
{
	// 姓名
	string name;
	// 年龄
	int age;
	// 分数
	int score;
};

// 打印学生信息函数
// 1、值传递
void printStudent1(Student s)
{
	s.age = 100;
	cout << "子函数1中 姓名：" << s.name << " 年龄：" << s.age << " 分数：" << s.score << endl;
}

// 2、地址传递
void printStudent2(Student* p)
{
	p->age = 100;
	cout << "子函数2中 姓名：" << p->name << " 年龄：" << p->age << " 分数：" << p->score << endl;
}

int main()
{
	// 结构体做函数参数
	// 将学生传入到一个参数值，打印学生身上的所有信息
	Student s;
	s.name = "张三";
	s.age = 20;
	s.score = 85;

	printStudent1(s);
	printStudent2(&s);
	cout << "main函数中 姓名：" << s.name << " 年龄：" << s.age << " 分数：" << s.score << endl;
	

	system("pause");

	return 0;
}