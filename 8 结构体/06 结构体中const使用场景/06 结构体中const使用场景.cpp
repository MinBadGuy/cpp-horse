#include<iostream>
#include<string>
using namespace std;

// const使用场景
struct Student
{
	string name;	// 姓名
	int age;		// 年龄
	int score;		// 分数
};

// 将函数中的形参改成指针，可以减少内存空间，而且不会复制新的副本
void printStudent(const Student* s)
{
	// s->age = 150;	// 加入const之后，一旦有修改的操作就会报错，可以防止误操作
	cout << "姓名：" << s->name << " 年龄：" << s->age << " 得分：" << s->score << endl;
}

int main()
{
	// 创建结构体变量
	Student s = { "张三", 15, 70 };

	// 通过函数打印结构体变量信息
	printStudent(&s);

	cout << "main中 姓名：" << s.name << " 年龄：" << s.age << " 得分：" << s.score << endl;
}