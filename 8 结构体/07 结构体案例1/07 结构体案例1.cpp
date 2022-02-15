#include<iostream>
#include<string>
#include<ctime>
using namespace std;

// 学生结构体定义
struct Student
{
	string sName;	// 姓名
	int score;		// 分数
};

// 老师结构体定义
struct Teacher
{
	string tName;		// 姓名
	Student sArray[5];	// 学生数组
};

// 给老师和学生赋值的函数
void allocateSpace(Teacher* tArray, int length)
{
	string nameSeed = "ABCDE";
	// 给老师赋值
	for (int i = 0; i < length; i++)
	{
		tArray[i].tName = "Teacher_";
		tArray[i].tName += nameSeed[i];
		for (int j = 0; j < 5; j++)
		{
			tArray[i].sArray[j].sName = "Student_";
			tArray[i].sArray[j].sName += nameSeed[j];
			
			int random = rand() % 61 + 40;	// 40~100
			tArray[i].sArray[j].score = random;
		}
	}
}

// 打印所有信息
void printInfo(Teacher tArray[], int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << "老师姓名：" << tArray[i].tName << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "\t姓名：" << tArray[i].sArray[j].sName << " 分数：" << tArray[i].sArray[j].score << endl;
		}
	}
}

int main()
{
	// 随机数种子
	// 根据系统时间设置随机数种子，可避免每次运行时产生的随机数都一样
	srand((unsigned int)time(NULL));

	// 1、创建3名老师的数组
	Teacher tArray[3];

	// 2、通过函数给3名老师的信息赋值，并给老师带的学生信息赋值
	int len = sizeof(tArray) / sizeof(tArray[0]);
	allocateSpace(tArray, len);

	// 3、打印所有老师及所带学生的信息
	printInfo(tArray, len);

	system("pause");

	return 0;
}