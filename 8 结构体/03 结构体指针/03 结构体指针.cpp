#include<iostream>
#include<string>
using namespace std;

// 结构体指针

// 定义学生结构体
struct Student
{
	string name;	// 姓名
	int age;		// 年龄
	int score;		// 分数
};

int main()
{
	// 创建学生的结构体变量
	Student s = { "张三", 18, 100 };
	
	// 通过指针指向结构体变量
	Student* p = &s;

	// 通过指针访问结构体变量中的数据
	// 通过结构体指针访问结构体中的属性，需要使用 ->
	cout << "姓名：" << p->name << " 年龄：" << p->age << " 分数：" << p->score << endl;

	system("pause");

	return 0;
}