#include <iostream>
using namespace std;
#include <string>
// string²åÈëºÍÉ¾³ı

void test01() {
	string str = "hello";

	// ²åÈë
	str.insert(1, "111");
	cout << "str = " << str << endl;

	// É¾³ı
	str.erase(1, 3);
	// hello
	cout << "str = " << str << endl;
}

int main() {
	test01();

	system("pause");

	return 0;
}