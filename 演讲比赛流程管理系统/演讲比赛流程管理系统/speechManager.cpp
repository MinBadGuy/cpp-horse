#include "speechManager.h"
#include <algorithm>
#include <deque>
#include <functional>
#include <numeric>
#include <fstream>

// 构造函数
SpeechManager::SpeechManager() {
	// 初始化容器和属性
	this->initSpeech();

	// 创建12名选手
	this->createSpeaker();

	// 加载往届记录
	this->loadRecord();
}

// 展示菜单
void SpeechManager::showMenu() {
	cout << "*************************************" << endl;
	cout << "********** 欢迎参加演讲比赛 **********" << endl;
	cout << "*********** 1.开始演讲比赛 ***********" << endl;
	cout << "*********** 2.查看往届记录 ***********" << endl;
	cout << "*********** 3.清空比赛记录 ***********" << endl;
	cout << "*********** 0.退出比赛程序 ***********" << endl;
	cout << "*************************************" << endl;
	cout << endl;
}

// 退出系统
void SpeechManager::exitSystem() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void SpeechManager::initSpeech() {
	// 容器都置空
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->mSpeaker.clear();

	// 初始化比赛轮数
	this->mIndex = 1;

	// 将记录容器也清空
	this->mRecord.clear();

}

// 创建12名选手
void SpeechManager::createSpeaker() {
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "选手";
		name += nameSeed[i];

		// 创建具体选手
		Speaker sp;
		sp.mName = name;

		for (int j = 0; j < 2; j++)
		{
			sp.mScore[j] = 0;
		}

		// 创建选手编号，并且放入到v1容器中
		this->v1.push_back(i + 10001);

		// 选手编号以及对应选手，放入到map容器中
		this->mSpeaker.insert(pair<int, Speaker>(i + 10001, sp));	// make_pair(i+10001, sp)

	}
}

// 开始比赛，比赛整个流程控制函数
void SpeechManager::startSpeech() {
	// 第一轮比赛开始
	// 1、抽签
	this->speechDraw();
	// 2、比赛
	this->speechContest();
	// 3、显示晋级结果
	this->showScore();

	// 第二轮比赛开始
	this->mIndex++;
	// 1、抽签
	this->speechDraw();
	// 2、比赛
	this->speechContest();
	// 3、显示最终结果
	this->showScore();
	
	// 4、保存分数到文件
	this->saveRecord();

	// 重置比赛，获取记录
	// 初始化容器和属性
	this->initSpeech();

	// 创建12名选手
	this->createSpeaker();

	// 加载往届记录
	this->loadRecord();


	cout << "本届比赛完毕！" << endl;
	system("pause");
	system("cls");

}

// 抽签
void SpeechManager::speechDraw() {
	cout << "第 <" << this->mIndex << "> 轮比赛选手正在抽签" << endl;
	cout << "----------------------" << endl;
	cout << "抽签后演讲顺序如下：" << endl;

	if (this->mIndex == 1)
	{
		// 第一轮比赛
		random_shuffle(v1.begin(), v1.end());

		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;

	}
	else
	{
		// 第二轮比赛
		random_shuffle(v2.begin(), v2.end());

		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}

	cout << "---------------------------" << endl;
	system("pause");
	cout << endl;

}

// 比赛
void SpeechManager::speechContest() {
	cout << "---------- 第 <" << this->mIndex << "> 轮比赛正式开始 ----------" << endl;

	// 准备容器存放小组成绩
	multimap<double, int, greater<double>> groupScore;	// 分数为key，选手编号为value
	
	int num = 0;	// 记录人员个数，6人一组

	vector<int> vSrc;	// 比赛选手容器
	if (this->mIndex == 1)
	{
		vSrc = v1;
	}
	else
	{
		vSrc = v2;
	}

	// 遍历所有选手进行比赛
	for (vector<int>::iterator it = vSrc.begin(); it != vSrc.end(); it++)
	{
		num++;

		// 评委打分
		deque<double> d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;	// 600~100
			// cout << score << " ";
			d.push_back(score);
		}
		// cout << endl;

		sort(d.begin(), d.end(), greater<double>());	// 排序
		d.pop_front();	// 去除最高分
		d.pop_back();	// 去除最低分

		double sum = accumulate(d.begin(), d.end(), 0.f);	// 总分
		double avg = sum / d.size();	// 平均分

		// 打印平均分
		// cout << "编号：" << *it << " 姓名：" << this->mSpeaker[*it].mName << " 获取平均分：" << avg << endl;

		// 将平均分放到map容器里
		this->mSpeaker[*it].mScore[this->mIndex - 1] = avg;

		// 将打分数据放入到临时小组成绩容器中
		groupScore.insert(make_pair(avg, *it));		// key: 得分，value：选手编号

		// 每6人取前三名
		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组比赛名次：" << endl;
			for (multimap<double, int>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "编号：" << it->second 
					<< " 姓名：" << this->mSpeaker[it->second].mName 
					<< " 成绩：" << this->mSpeaker[it->second].mScore[this->mIndex - 1] << endl;
			}

			// 取出前三名
			int count = 0;
			for (multimap<double, int>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++)
			{
				if (this->mIndex == 1)
				{
					v2.push_back(it->second);
				}
				else
				{
					vVictory.push_back(it->second);
				}
			}

			// 小组容器清空
			groupScore.clear();	
			cout << endl;
		}
	}

	cout << "---------- 第 <" << this->mIndex << "> 轮比赛结束 ----------" << endl;
	system("pause");
}

// 显示得分
void SpeechManager::showScore() {
	cout << "---------- 第 <" << this->mIndex << "> 轮晋级选手信息如下：----------" << endl;
	
	vector<int> v;
	if (this->mIndex == 1)
	{
		v = v2;
	}
	else
	{
		v = vVictory;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "选手编号：" << *it 
			<< " 姓名：" << this->mSpeaker[*it].mName 
			<< " 得分" << this->mSpeaker[*it].mScore[this->mIndex - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
	this->showMenu();
}

// 保存记录
void SpeechManager::saveRecord() {
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);	// 用追加的方式写文件

	// 将每个选手数据写入到文件中
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," << this->mSpeaker[*it].mScore[1] << ",";
	}
	ofs << endl;

	// 关闭
	ofs.close();
	cout << "记录已经保存" << endl;

	// 更改文件不为空的状态
	this->fileIsEmpty = false;
}

// 读取记录
void SpeechManager::loadRecord() {
	ifstream ifs("speech.csv", ios::in);	// 读文件

	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		// cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}

	// 文件清空情况
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		// cout << "文件为空！" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	// 文件不为空
	this->fileIsEmpty = false;

	ifs.putback(ch);	// 将上面读取的单个字符放回来

	int index = 0;
	string data;
	while (ifs >> data)
	{
		// 10012,84.7625,10002,83.8,10004,80.4125,
		// cout << data << endl;

		vector<string> v;	// 存放6个string的容器

		int pos = -1;	// 查到 "," 位置的变量
		int start = 0;
		while (true)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				// 没有找到
				break;
			}
			string temp = data.substr(start, pos - start);
			v.push_back(temp);
			// cout << temp << endl;

			start = pos + 1;
		}
		
		this->mRecord.insert(make_pair(index, v));
		index++;
	}
	ifs.close();

	/*for (map<int, vector<string>>::iterator it = this->mRecord.begin(); it != this->mRecord.end(); it++)
	{
		cout << "第" << it->first << "届冠军编号：" << it->second[0] << " 分数：" << it->second[1] << endl;
	}*/
}

// 显示往届记录
void SpeechManager::showRecord() {
	if (this->fileIsEmpty)
	{
		cout << "文件不存在，或记录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < this->mRecord.size(); i++)
		{
			cout << "第" << i + 1 << "届"
				<< "冠军编号：" << this->mRecord[i][0] << " 分数：" << this->mRecord[i][1] << " "
				<< "亚军编号：" << this->mRecord[i][2] << " 分数：" << this->mRecord[i][3] << " "
				<< "季军编号：" << this->mRecord[i][4] << " 分数：" << this->mRecord[i][5] << endl;
		}
	}

	system("pause");
	system("cls");
}

// 清空记录
void SpeechManager::clearRecord() {
	cout << "确认清空？" << endl;
	cout << "1、是" << endl;
	cout << "2、否" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		// 确认清空
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		// 初始化容器和属性
		this->initSpeech();

		// 创建12名选手
		this->createSpeaker();

		// 加载往届记录
		this->loadRecord();

		cout << "清空成功！" << endl;
	}

	system("pause");
	system("cls");

}

// 析构函数
SpeechManager::~SpeechManager() {

}