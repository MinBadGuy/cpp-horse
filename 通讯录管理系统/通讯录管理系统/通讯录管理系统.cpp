#include<iostream>
#include<string>
using namespace std;

#define MAX 1000

// 联系人结构体
struct Person
{
	string	m_name;		// 姓名
	int		m_sex;		// 性别		1-男		2-女
	int		m_age;		// 年龄
	string	m_phone;	// 电话
	string	m_addr;		// 住址
};

// 通讯录结构体
struct AddressBooks
{
	Person	pArray[MAX];		// 联系人数组
	int		m_size;				// 联系人数量
};

// 显示菜单
void showMenu()
{
	cout << "*************************" << endl;
	cout << "***** 1. 添加联系人 *****" << endl;
	cout << "***** 2. 显示联系人 *****" << endl;
	cout << "***** 3. 删除联系人 *****" << endl;
	cout << "***** 4. 查找联系人 *****" << endl;
	cout << "***** 5. 修改联系人 *****" << endl;
	cout << "***** 6. 清空联系人 *****" << endl;
	cout << "***** 0. 退出通讯录 *****" << endl;
	cout << "*************************" << endl;
}

// 1、添加联系人
void addPerson(AddressBooks* abs)
{
	if (abs->m_size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		// 添加具体联系人

		// 姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->pArray[abs->m_size].m_name = name;

		// 性别
		cout << "请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			// 如果输入的是1或2，可以退出循环
			// 如果输入有误，重新输入
			if (sex == 1 || sex == 2)
			{
				abs->pArray[abs->m_size].m_sex = sex;
				break;
			}
			else
			{
				cout << "输入有误，请重新输入：" << endl;
			}

		}

		// 年龄
		int age;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->pArray[abs->m_size].m_age = age;

		// 电话
		string phone;
		cout << "请输入联系电话：" << endl;
		cin >> phone;
		abs->pArray[abs->m_size].m_phone = phone;
		
		// 住址
		string address;
		cout << "请输入家庭住址：" << endl;
		cin >> address;
		abs->pArray[abs->m_size].m_addr = address;

		// 更新通讯录人数
		abs->m_size++;

		cout << "添加成功！" << endl;

		system("pause");	// 请按任意键继续
		system("cls");		// 清屏操作
	}	
}

// 2、显示联系人
void showPerson(AddressBooks* abs)
{
	// 判断通讯录中人数是否为0，如果为0，提示记录为空
	if (abs->m_size == 0)
	{
		cout << "当前通讯录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "姓名：" << abs->pArray[i].m_name
				<< "\t性别：" << (abs->pArray[i].m_sex == 1 ? "男" : "女")
				<< "\t年龄：" << abs->pArray[i].m_age
				<< "\t电话：" << abs->pArray[i].m_phone
				<< "\t住址：" << abs->pArray[i].m_addr << endl;
		}
	}
	system("pause");
	system("cls");
}

// 检测联系人是否存在
// 如果存在，返回联系人在通讯录数组中的具体位置，不存在返回-1
// 参数1 - 通讯录	参数2 - 对比姓名
int isExist(AddressBooks* abs, string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->pArray[i].m_name == name)
		{
			return i;	// 找到，返回下标
		}
	}
	return -1;	// 如果遍历结束都没找到，返回-1
}


// 3、删除指定联系人
void deletePerson(AddressBooks* abs)
{
	cout << "请输入您要删除的联系人：" << endl;
	string name;
	cin >> name;
	
	// ret == -1	未查到
	// ret != -1	查到了
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		// 查找到人，要进行删除操作
		for (int i = ret; i < abs->m_size - 1; i++)
		{
			// 数据前移
			abs->pArray[i] = abs->pArray[i + 1];
		}
		abs->m_size--;
		cout << "删除成功！" << endl;
	}
	else
	{
		cout << "查无此人！" << endl;
	}
	system("pause");
	system("cls");
}

//4、查找指定联系人信息
void findPerson(AddressBooks* abs)
{
	cout << "请输入您要查找的联系人：" << endl;
	string name;
	cin >> name;
	
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名："<<abs->pArray[ret].m_name
			<< "\t性别：" << (abs->pArray[ret].m_sex == 1 ? "男" : "女")
			<< "\t年龄：" << abs->pArray[ret].m_age
			<< "\t电话：" << abs->pArray[ret].m_phone
			<< "\t住址：" << abs->pArray[ret].m_addr << endl;
	}
	else
	{
		cout << "查无此人！" << endl;
	}

	system("pause");
	system("cls");
}

// 5、修改联系人
void modifyPerson(AddressBooks* abs)
{
	cout << "请输入您要修改的联系人：" << endl;
	string name;
	cin >> name;
	
	int ret = isExist(abs, name);
	if (ret != -1)	// 找到指定联系人
	{
		// 姓名
		cout << "请输入姓名：" << endl;
		string name;
		cin >> name;
		abs->pArray[ret].m_name = name;

		// 性别
		cout << "请输入性别：" << endl;
		cout << "1 -- 男" << endl;
		cout << "2 -- 女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex ==2)
			{
				abs->pArray[ret].m_sex = sex;
				break;
			}
			else
			{
				cout << "输入有误，请重新输入！" << endl;
			}
		}

		// 年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->pArray[ret].m_age = age;

		// 电话
		cout << "请输入电话：" << endl;
		string phone;
		cin >> phone;
		abs->pArray[ret].m_phone = phone;

		// 住址
		cout << "请输入住址：" << endl;
		string address;
		cin >> address;
		abs->pArray[ret].m_addr = address;

		cout << "修改成功！" << endl;
	}
	else // 未找到
	{
		cout << "查无此人！" << endl;
	}
	system("pause");
	system("cls");
}

// 6、清空联系人
void cleanPerson(AddressBooks* abs)
{
	abs->m_size = 0;	// 将当前记录联系人数量置0，做逻辑清空操作
	cout << "清空成功！" << endl;
	system("pause");
	system("cls");
}

int main()
{
	// 创建通讯录结构体变量
	AddressBooks abs;
	abs.m_size = 0;
	
	int select = 0;		// 创建用户选择输入的变量
	
	while (true)
	{
		// 菜单调用
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1:		// 添加联系人
			addPerson(&abs);	// 利用地址传递，可以修改实参
			break;
		case 2:		// 显示联系人
			showPerson(&abs);
			break;
		case 3:		// 删除联系人
		{
			deletePerson(&abs);
			break;
		}
		case 4:		// 查找联系人
			findPerson(&abs);
			break;
		case 5:		// 修改联系人
			modifyPerson(&abs);
			break;
		case 6:		// 清空联系人
			cleanPerson(&abs);
			break;
		case 0:		// 退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
		default:
			break;
		}
	}
	


	
}