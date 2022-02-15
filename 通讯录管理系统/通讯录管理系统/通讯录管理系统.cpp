#include<iostream>
#include<string>
using namespace std;

#define MAX 1000

// ��ϵ�˽ṹ��
struct Person
{
	string	m_name;		// ����
	int		m_sex;		// �Ա�		1-��		2-Ů
	int		m_age;		// ����
	string	m_phone;	// �绰
	string	m_addr;		// סַ
};

// ͨѶ¼�ṹ��
struct AddressBooks
{
	Person	pArray[MAX];		// ��ϵ������
	int		m_size;				// ��ϵ������
};

// ��ʾ�˵�
void showMenu()
{
	cout << "*************************" << endl;
	cout << "***** 1. �����ϵ�� *****" << endl;
	cout << "***** 2. ��ʾ��ϵ�� *****" << endl;
	cout << "***** 3. ɾ����ϵ�� *****" << endl;
	cout << "***** 4. ������ϵ�� *****" << endl;
	cout << "***** 5. �޸���ϵ�� *****" << endl;
	cout << "***** 6. �����ϵ�� *****" << endl;
	cout << "***** 0. �˳�ͨѶ¼ *****" << endl;
	cout << "*************************" << endl;
}

// 1�������ϵ��
void addPerson(AddressBooks* abs)
{
	if (abs->m_size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else
	{
		// ��Ӿ�����ϵ��

		// ����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->pArray[abs->m_size].m_name = name;

		// �Ա�
		cout << "�������Ա�" << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			// ����������1��2�������˳�ѭ��
			// �������������������
			if (sex == 1 || sex == 2)
			{
				abs->pArray[abs->m_size].m_sex = sex;
				break;
			}
			else
			{
				cout << "�����������������룺" << endl;
			}

		}

		// ����
		int age;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->pArray[abs->m_size].m_age = age;

		// �绰
		string phone;
		cout << "��������ϵ�绰��" << endl;
		cin >> phone;
		abs->pArray[abs->m_size].m_phone = phone;
		
		// סַ
		string address;
		cout << "�������ͥסַ��" << endl;
		cin >> address;
		abs->pArray[abs->m_size].m_addr = address;

		// ����ͨѶ¼����
		abs->m_size++;

		cout << "��ӳɹ���" << endl;

		system("pause");	// �밴���������
		system("cls");		// ��������
	}	
}

// 2����ʾ��ϵ��
void showPerson(AddressBooks* abs)
{
	// �ж�ͨѶ¼�������Ƿ�Ϊ0�����Ϊ0����ʾ��¼Ϊ��
	if (abs->m_size == 0)
	{
		cout << "��ǰͨѶ¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "������" << abs->pArray[i].m_name
				<< "\t�Ա�" << (abs->pArray[i].m_sex == 1 ? "��" : "Ů")
				<< "\t���䣺" << abs->pArray[i].m_age
				<< "\t�绰��" << abs->pArray[i].m_phone
				<< "\tסַ��" << abs->pArray[i].m_addr << endl;
		}
	}
	system("pause");
	system("cls");
}

// �����ϵ���Ƿ����
// ������ڣ�������ϵ����ͨѶ¼�����еľ���λ�ã������ڷ���-1
// ����1 - ͨѶ¼	����2 - �Ա�����
int isExist(AddressBooks* abs, string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->pArray[i].m_name == name)
		{
			return i;	// �ҵ��������±�
		}
	}
	return -1;	// �������������û�ҵ�������-1
}


// 3��ɾ��ָ����ϵ��
void deletePerson(AddressBooks* abs)
{
	cout << "��������Ҫɾ������ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	
	// ret == -1	δ�鵽
	// ret != -1	�鵽��
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		// ���ҵ��ˣ�Ҫ����ɾ������
		for (int i = ret; i < abs->m_size - 1; i++)
		{
			// ����ǰ��
			abs->pArray[i] = abs->pArray[i + 1];
		}
		abs->m_size--;
		cout << "ɾ���ɹ���" << endl;
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}
	system("pause");
	system("cls");
}

//4������ָ����ϵ����Ϣ
void findPerson(AddressBooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "������"<<abs->pArray[ret].m_name
			<< "\t�Ա�" << (abs->pArray[ret].m_sex == 1 ? "��" : "Ů")
			<< "\t���䣺" << abs->pArray[ret].m_age
			<< "\t�绰��" << abs->pArray[ret].m_phone
			<< "\tסַ��" << abs->pArray[ret].m_addr << endl;
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}

	system("pause");
	system("cls");
}

// 5���޸���ϵ��
void modifyPerson(AddressBooks* abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	
	int ret = isExist(abs, name);
	if (ret != -1)	// �ҵ�ָ����ϵ��
	{
		// ����
		cout << "������������" << endl;
		string name;
		cin >> name;
		abs->pArray[ret].m_name = name;

		// �Ա�
		cout << "�������Ա�" << endl;
		cout << "1 -- ��" << endl;
		cout << "2 -- Ů" << endl;
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
				cout << "�����������������룡" << endl;
			}
		}

		// ����
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->pArray[ret].m_age = age;

		// �绰
		cout << "������绰��" << endl;
		string phone;
		cin >> phone;
		abs->pArray[ret].m_phone = phone;

		// סַ
		cout << "������סַ��" << endl;
		string address;
		cin >> address;
		abs->pArray[ret].m_addr = address;

		cout << "�޸ĳɹ���" << endl;
	}
	else // δ�ҵ�
	{
		cout << "���޴��ˣ�" << endl;
	}
	system("pause");
	system("cls");
}

// 6�������ϵ��
void cleanPerson(AddressBooks* abs)
{
	abs->m_size = 0;	// ����ǰ��¼��ϵ��������0�����߼���ղ���
	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");
}

int main()
{
	// ����ͨѶ¼�ṹ�����
	AddressBooks abs;
	abs.m_size = 0;
	
	int select = 0;		// �����û�ѡ������ı���
	
	while (true)
	{
		// �˵�����
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1:		// �����ϵ��
			addPerson(&abs);	// ���õ�ַ���ݣ������޸�ʵ��
			break;
		case 2:		// ��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3:		// ɾ����ϵ��
		{
			deletePerson(&abs);
			break;
		}
		case 4:		// ������ϵ��
			findPerson(&abs);
			break;
		case 5:		// �޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6:		// �����ϵ��
			cleanPerson(&abs);
			break;
		case 0:		// �˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
		default:
			break;
		}
	}
	


	
}