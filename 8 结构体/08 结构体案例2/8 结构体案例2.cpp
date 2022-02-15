#include<iostream>
#include<string>
using namespace std;

// 1、设计英雄结构体
// 英雄结构体
struct Hero
{
	// 姓名
	string name;
	// 年龄
	int age;
	// 性别
	string gender;
};

void bubbleSort(Hero* hArray, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			// 如果j下标元素的年龄大于j+1下标元素的年龄，交换两个元素
			if (hArray[j].age > hArray[j+1].age)
			{
				Hero temp = hArray[j];
				hArray[j] = hArray[j + 1];
				hArray[j + 1] = temp;
			}
		}
	}
}

// 打印英雄信息
void printHero(const Hero* hArray, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "姓名：" << hArray[i].name << " 年龄：" << hArray[i].age << " 性别：" << hArray[i].gender << endl;
	}
}

int main()
{
	// 2、创建数组存放5名英雄
	Hero hArray[5] =
	{
		{"刘备", 23, "男"},
		{"关羽", 22, "男"},
		{"张飞", 20, "男"},
		{"赵云", 21, "男"},
		{"貂蝉", 19, "女"}
	};

	int len = sizeof(hArray) / sizeof(hArray[0]);

	cout << "排序前打印：" << endl;
	printHero(hArray, len);

	// 3、对数组进行排序，按照年龄进行升序排序
	bubbleSort(hArray, len);

	// 4、将排序后的结果打印输出
	cout << "排序后打印：" << endl;
	printHero(hArray, len);

	system("pause");

	return 0;
}