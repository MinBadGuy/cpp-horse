#include<iostream>
#include<string>
using namespace std;

// 1�����Ӣ�۽ṹ��
// Ӣ�۽ṹ��
struct Hero
{
	// ����
	string name;
	// ����
	int age;
	// �Ա�
	string gender;
};

void bubbleSort(Hero* hArray, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			// ���j�±�Ԫ�ص��������j+1�±�Ԫ�ص����䣬��������Ԫ��
			if (hArray[j].age > hArray[j+1].age)
			{
				Hero temp = hArray[j];
				hArray[j] = hArray[j + 1];
				hArray[j + 1] = temp;
			}
		}
	}
}

// ��ӡӢ����Ϣ
void printHero(const Hero* hArray, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "������" << hArray[i].name << " ���䣺" << hArray[i].age << " �Ա�" << hArray[i].gender << endl;
	}
}

int main()
{
	// 2������������5��Ӣ��
	Hero hArray[5] =
	{
		{"����", 23, "��"},
		{"����", 22, "��"},
		{"�ŷ�", 20, "��"},
		{"����", 21, "��"},
		{"����", 19, "Ů"}
	};

	int len = sizeof(hArray) / sizeof(hArray[0]);

	cout << "����ǰ��ӡ��" << endl;
	printHero(hArray, len);

	// 3��������������򣬰������������������
	bubbleSort(hArray, len);

	// 4���������Ľ����ӡ���
	cout << "������ӡ��" << endl;
	printHero(hArray, len);

	system("pause");

	return 0;
}