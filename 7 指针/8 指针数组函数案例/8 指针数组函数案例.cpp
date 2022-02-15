#include<iostream>
using namespace std;

// 冒泡排序
// arr：数组首地址	length：数组长度
void bubbleSort(int* arr, int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length -1 -i; j++)
		{
			// 如果 j > j+1 的值，交换数字
			if (*(arr + j) > *(arr + j + 1))
			{
				int temp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = temp;
			}
		}
	}
}

// 打印数组
void printArr(int* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << *(arr + i) << endl;
	}
}


int main()
{
	// 1、先创建数组
	int arr[10] = { 4,3,6,9,1,2,10,8,7,5 };
	
	// 数组长度
	int len = sizeof(arr) / sizeof(arr[0]);

	// 2、创建函数，实现冒泡排序
	bubbleSort(arr, len);

	// 3、打印排序后的数组
	printArr(arr, len);

	system("pause");

	return 0;
}