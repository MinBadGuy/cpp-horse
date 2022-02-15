#include<iostream>
#include<string>
using namespace std;

struct Student
{
	string name;	// 学生姓名
	int age;		// 学生年龄
	int score;		// 学生分数
};

// 定义老师结构体
struct Teacher
{
	int id;			// 教师编号
	string name;	// 教师姓名
	int age;		// 教师年龄
	Student stu;	// 辅导学生
};

int main()
{
	// 结构体嵌套结构体
	// 创建老师
	Teacher t;
	t.id = 10000;
	t.name = "老王";
	t.age = 50;
	t.stu.name = "小王";
	t.stu.age = 20;
	t.stu.score = 60;

	cout << "老师姓名：" << t.name << " 老师编号：" << t.id << " 老师年龄：" << t.age << endl
		<< "辅导的学生姓名：" << t.stu.name << " 学生年龄：" << t.stu.age << " 学生考试分数：" << t.stu.score << endl;

	system("pause");

	return 0;
}