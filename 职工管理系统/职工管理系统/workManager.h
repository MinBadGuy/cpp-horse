#pragma once			// 防止头文件重复包含
#include <iostream>		// 包含输入输出流头文件
using namespace std;	// 使用标准命名空间

#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#include <fstream>
#define FILENAME "empFile.txt"

class WorkManager {
public:
	// 构造函数
	WorkManager();

	// 展示菜单
	void Show_Menu();

	// 退出系统
	void ExitSystem();

	// 添加职工
	void Add_Emp();

	// 保存文件
	void save();

	// 判断文件是否为空的标志
	bool m_FileIsEmpty;

	// 统计文件中人数
	int get_EmpNum();

	// 初始化员工
	void int_Emp();
	 
	// 显示职工
	void show_Emp();

	// 删除职工
	void del_Emp();

	// 按照职工编号判断职工是否存在 如果存在返回职工所在数组中的位置，不存在返回-1 
	int isExist(int id);

	// 修改职工
	void mod_Emp();

	// 查找职工
	void find_Emp();

	// 排序职工
	void sort_Emp();

	// 清空文件
	void clean_File();

	// 析构函数
	~WorkManager();

	// 记录职工人数
	int m_EmpNum;

	// 职工数组的指针
	Worker** m_EmpArray;

};