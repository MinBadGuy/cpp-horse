#include <iostream>
using namespace std;

// ʵ��ͨ�� �������������ĺ���
// ���� �Ӵ�С
// �㷨 ѡ��
// ���� char���顢int����

// ��������ģ��
template<class T>
void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}


// ��������
template<class T>
void mySort(T arr[], int len) {
	for (int i = 0; i < len; i++)
	{
		int max = i;	// �϶����ֵ���±�
		for (int j = i+1; j < len; j++)
		{
			// �϶������ֵ �� ����������ֵ С��˵��j�±��Ԫ�ز������������ֵ
			if (arr[max] < arr[j])
			{
				// �������ֵ�±�
				max = j;
			}
		}

		if (max != i)
		{
			// ����max��iԪ��
			mySwap(arr[i], arr[max]);
		}
	}
}

// ��ӡ����ģ��
template<class T>
void printArray(T arr[], int len) {
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test01() {
	// ����char����
	char arr[] = "badcfe";
	int num = sizeof(arr) / sizeof(arr[0]);
	mySort(arr, num);
	printArray(arr, num);
}

void test02() {
	// ����int����
	int arr[] = { 7,5,1,3,9,2,4,6,8 };
	int num = sizeof(arr) / sizeof(arr[0]);
	mySort(arr, num);
	printArray(arr, num);
}

int main() {

	test01();

	test02();

	system("pause");

	return 0;
}