#include <iostream>
using namespace std;
#include <string>
// string??????ɾ??

void test01() {
	string str = "hello";

	// ????
	str.insert(1, "111");
	cout << "str = " << str << endl;

	// ɾ??
	str.erase(1, 3);
	// hello
	cout << "str = " << str << endl;
}

int main() {
	test01();

	system("pause");

	return 0;
}