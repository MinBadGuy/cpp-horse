#include <iostream>
using namespace std;

// 立方体类设计
// 1、创建立方体类
// 2、设计属性
// 3、设计行为	获取立方体面积和体积
// 4、分别利用全局函数和成员函数	判断两个立方体是否相等

class Cube {
public:
	// 设置长
	void setL(int l) {
		m_L = l;
	}

	// 获取长
	int getL() const {
		return m_L;
	}

	// 设置宽
	void setW(int w) {
		m_W = w;
	}

	// 获取宽
	int getW() const {
		return m_W;
	}

	// 设置高
	void setH(int h) {
		m_H = h;
	}

	// 获取高
	int getH() const {
		return m_H;
	}

	// 获取立方体面积
	int calculateS() {
		return 2 * (m_L * m_W + m_L * m_H + m_W * m_H);
	}

	// 获取立方体体积
	int calculateV() {
		return m_L * m_W * m_H;
	}

	// 利用成员函数判断两个立方体是否相等
	bool isSameByClass(const Cube& c) {
		if (m_L == c.getL() && m_W == c.getW() && m_H == c.getH())
		{
			return true;
		}
		return false;
	}

private:
	int m_L;	// 长
	int m_W;	// 宽
	int m_H;	// 高
};

// 利用全局函数判断 两个立方体是否相等
// 注意：如果isSame的形参是const引用，则Cube类中的get方法必须是const函数，
// 若形参不是const，是普通引用，则Cube类中的get方法不需要是const函数
bool isSame(const Cube& c1, const Cube& c2) {
	if (c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH())
	{
		return true;
	}
	return false;
}


int main() {
	Cube c1;
	c1.setL(10);
	c1.setW(10);
	c1.setH(10);

	cout << "c1的面积为：" << c1.calculateS() << endl;
	cout << "c1的体积为：" << c1.calculateV() << endl;

	Cube c2;
	c2.setL(10);
	c2.setW(10);
	c2.setH(100);

	// 利用全局函数判断
	bool ret = isSame(c1, c2);
	if (ret)
	{
		cout << "c1和c2是相等的" << endl;
	}
	else
	{
		cout << "c1和c2是不相等的" << endl;
	}

	// 利用成员函数判断
	ret = c1.isSameByClass(c2);
	if (ret)
	{
		cout << "成员函数判断：c1和c2是相等的" << endl;
	}
	else
	{
		cout << "成员函数判断：c1和c2是不相等的" << endl;
	}

	system("pause");

	return 0;
}