#pragma once			// ��ֹͷ�ļ��ظ�����
#include <iostream>		// �������������ͷ�ļ�
using namespace std;	// ʹ�ñ�׼�����ռ�

#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#include <fstream>
#define FILENAME "empFile.txt"

class WorkManager {
public:
	// ���캯��
	WorkManager();

	// չʾ�˵�
	void Show_Menu();

	// �˳�ϵͳ
	void ExitSystem();

	// ���ְ��
	void Add_Emp();

	// �����ļ�
	void save();

	// �ж��ļ��Ƿ�Ϊ�յı�־
	bool m_FileIsEmpty;

	// ͳ���ļ�������
	int get_EmpNum();

	// ��ʼ��Ա��
	void int_Emp();
	 
	// ��ʾְ��
	void show_Emp();

	// ɾ��ְ��
	void del_Emp();

	// ����ְ������ж�ְ���Ƿ���� ������ڷ���ְ�����������е�λ�ã������ڷ���-1 
	int isExist(int id);

	// �޸�ְ��
	void mod_Emp();

	// ����ְ��
	void find_Emp();

	// ����ְ��
	void sort_Emp();

	// ����ļ�
	void clean_File();

	// ��������
	~WorkManager();

	// ��¼ְ������
	int m_EmpNum;

	// ְ�������ָ��
	Worker** m_EmpArray;

};