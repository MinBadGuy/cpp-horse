#include<iostream>
using namespace std;

int main()
{
	// ³Ë·¨¿Ú¾÷±í
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << j << "x" << i << "=" << i * j << '\t';
		}
		cout << endl;
	}
}