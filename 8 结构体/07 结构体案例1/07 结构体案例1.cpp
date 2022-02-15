#include<iostream>
#include<string>
#include<ctime>
using namespace std;

// ѧ���ṹ�嶨��
struct Student
{
	string sName;	// ����
	int score;		// ����
};

// ��ʦ�ṹ�嶨��
struct Teacher
{
	string tName;		// ����
	Student sArray[5];	// ѧ������
};

// ����ʦ��ѧ����ֵ�ĺ���
void allocateSpace(Teacher* tArray, int length)
{
	string nameSeed = "ABCDE";
	// ����ʦ��ֵ
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

// ��ӡ������Ϣ
void printInfo(Teacher tArray[], int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << "��ʦ������" << tArray[i].tName << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "\t������" << tArray[i].sArray[j].sName << " ������" << tArray[i].sArray[j].score << endl;
		}
	}
}

int main()
{
	// ���������
	// ����ϵͳʱ��������������ӣ��ɱ���ÿ������ʱ�������������һ��
	srand((unsigned int)time(NULL));

	// 1������3����ʦ������
	Teacher tArray[3];

	// 2��ͨ��������3����ʦ����Ϣ��ֵ��������ʦ����ѧ����Ϣ��ֵ
	int len = sizeof(tArray) / sizeof(tArray[0]);
	allocateSpace(tArray, len);

	// 3����ӡ������ʦ������ѧ������Ϣ
	printInfo(tArray, len);

	system("pause");

	return 0;
}