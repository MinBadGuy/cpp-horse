#include <iostream>
#include "speechManager.h"
#include <ctime>
using namespace std;

int main() {

	// 随机数种子
	srand((unsigned int)time(NULL));

	// 创建管理类对象
	SpeechManager sm;

	//// 测试12名选手创建
	//for (map<int, Speaker>::iterator it = sm.mSpeaker.begin(); it != sm.mSpeaker.end(); it++) {
	//	cout << "选手编号：" << it->first << " 姓名：" << it->second.mName << " 分数：" << it->second.mScore[0] << endl;
	//}


	int choice;	// 用于存储用户的输入

	while (true)
	{
		sm.showMenu();

		cout << "请输入您的选择：" << endl;
		cin >> choice;
		
		switch (choice)
		{
		case 1:	// 开始比赛
			sm.startSpeech();
			break;
		case 2:	// 查看往届比赛记录
			sm.showRecord();
			break;
		case 3:	// 清空比赛记录
			sm.clearRecord();
			break;
		case 0:	// 退出系统
			sm.exitSystem();
			break;
		default:
			system("cls");	// 清屏
			break;
		}

	}

	
	

	system("pause");
	return 0;
}