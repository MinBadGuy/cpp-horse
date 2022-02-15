#include "speechManager.h"
#include <algorithm>
#include <deque>
#include <functional>
#include <numeric>
#include <fstream>

// ���캯��
SpeechManager::SpeechManager() {
	// ��ʼ������������
	this->initSpeech();

	// ����12��ѡ��
	this->createSpeaker();

	// ���������¼
	this->loadRecord();
}

// չʾ�˵�
void SpeechManager::showMenu() {
	cout << "*************************************" << endl;
	cout << "********** ��ӭ�μ��ݽ����� **********" << endl;
	cout << "*********** 1.��ʼ�ݽ����� ***********" << endl;
	cout << "*********** 2.�鿴�����¼ ***********" << endl;
	cout << "*********** 3.��ձ�����¼ ***********" << endl;
	cout << "*********** 0.�˳��������� ***********" << endl;
	cout << "*************************************" << endl;
	cout << endl;
}

// �˳�ϵͳ
void SpeechManager::exitSystem() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

void SpeechManager::initSpeech() {
	// �������ÿ�
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->mSpeaker.clear();

	// ��ʼ����������
	this->mIndex = 1;

	// ����¼����Ҳ���
	this->mRecord.clear();

}

// ����12��ѡ��
void SpeechManager::createSpeaker() {
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];

		// ��������ѡ��
		Speaker sp;
		sp.mName = name;

		for (int j = 0; j < 2; j++)
		{
			sp.mScore[j] = 0;
		}

		// ����ѡ�ֱ�ţ����ҷ��뵽v1������
		this->v1.push_back(i + 10001);

		// ѡ�ֱ���Լ���Ӧѡ�֣����뵽map������
		this->mSpeaker.insert(pair<int, Speaker>(i + 10001, sp));	// make_pair(i+10001, sp)

	}
}

// ��ʼ�����������������̿��ƺ���
void SpeechManager::startSpeech() {
	// ��һ�ֱ�����ʼ
	// 1����ǩ
	this->speechDraw();
	// 2������
	this->speechContest();
	// 3����ʾ�������
	this->showScore();

	// �ڶ��ֱ�����ʼ
	this->mIndex++;
	// 1����ǩ
	this->speechDraw();
	// 2������
	this->speechContest();
	// 3����ʾ���ս��
	this->showScore();
	
	// 4������������ļ�
	this->saveRecord();

	// ���ñ�������ȡ��¼
	// ��ʼ������������
	this->initSpeech();

	// ����12��ѡ��
	this->createSpeaker();

	// ���������¼
	this->loadRecord();


	cout << "���������ϣ�" << endl;
	system("pause");
	system("cls");

}

// ��ǩ
void SpeechManager::speechDraw() {
	cout << "�� <" << this->mIndex << "> �ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "----------------------" << endl;
	cout << "��ǩ���ݽ�˳�����£�" << endl;

	if (this->mIndex == 1)
	{
		// ��һ�ֱ���
		random_shuffle(v1.begin(), v1.end());

		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;

	}
	else
	{
		// �ڶ��ֱ���
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

// ����
void SpeechManager::speechContest() {
	cout << "---------- �� <" << this->mIndex << "> �ֱ�����ʽ��ʼ ----------" << endl;

	// ׼���������С��ɼ�
	multimap<double, int, greater<double>> groupScore;	// ����Ϊkey��ѡ�ֱ��Ϊvalue
	
	int num = 0;	// ��¼��Ա������6��һ��

	vector<int> vSrc;	// ����ѡ������
	if (this->mIndex == 1)
	{
		vSrc = v1;
	}
	else
	{
		vSrc = v2;
	}

	// ��������ѡ�ֽ��б���
	for (vector<int>::iterator it = vSrc.begin(); it != vSrc.end(); it++)
	{
		num++;

		// ��ί���
		deque<double> d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;	// 600~100
			// cout << score << " ";
			d.push_back(score);
		}
		// cout << endl;

		sort(d.begin(), d.end(), greater<double>());	// ����
		d.pop_front();	// ȥ����߷�
		d.pop_back();	// ȥ����ͷ�

		double sum = accumulate(d.begin(), d.end(), 0.f);	// �ܷ�
		double avg = sum / d.size();	// ƽ����

		// ��ӡƽ����
		// cout << "��ţ�" << *it << " ������" << this->mSpeaker[*it].mName << " ��ȡƽ���֣�" << avg << endl;

		// ��ƽ���ַŵ�map������
		this->mSpeaker[*it].mScore[this->mIndex - 1] = avg;

		// ��������ݷ��뵽��ʱС��ɼ�������
		groupScore.insert(make_pair(avg, *it));		// key: �÷֣�value��ѡ�ֱ��

		// ÿ6��ȡǰ����
		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "С��������Σ�" << endl;
			for (multimap<double, int>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "��ţ�" << it->second 
					<< " ������" << this->mSpeaker[it->second].mName 
					<< " �ɼ���" << this->mSpeaker[it->second].mScore[this->mIndex - 1] << endl;
			}

			// ȡ��ǰ����
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

			// С���������
			groupScore.clear();	
			cout << endl;
		}
	}

	cout << "---------- �� <" << this->mIndex << "> �ֱ������� ----------" << endl;
	system("pause");
}

// ��ʾ�÷�
void SpeechManager::showScore() {
	cout << "---------- �� <" << this->mIndex << "> �ֽ���ѡ����Ϣ���£�----------" << endl;
	
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
		cout << "ѡ�ֱ�ţ�" << *it 
			<< " ������" << this->mSpeaker[*it].mName 
			<< " �÷�" << this->mSpeaker[*it].mScore[this->mIndex - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
	this->showMenu();
}

// �����¼
void SpeechManager::saveRecord() {
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);	// ��׷�ӵķ�ʽд�ļ�

	// ��ÿ��ѡ������д�뵽�ļ���
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," << this->mSpeaker[*it].mScore[1] << ",";
	}
	ofs << endl;

	// �ر�
	ofs.close();
	cout << "��¼�Ѿ�����" << endl;

	// �����ļ���Ϊ�յ�״̬
	this->fileIsEmpty = false;
}

// ��ȡ��¼
void SpeechManager::loadRecord() {
	ifstream ifs("speech.csv", ios::in);	// ���ļ�

	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		// cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}

	// �ļ�������
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		// cout << "�ļ�Ϊ�գ�" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	// �ļ���Ϊ��
	this->fileIsEmpty = false;

	ifs.putback(ch);	// �������ȡ�ĵ����ַ��Ż���

	int index = 0;
	string data;
	while (ifs >> data)
	{
		// 10012,84.7625,10002,83.8,10004,80.4125,
		// cout << data << endl;

		vector<string> v;	// ���6��string������

		int pos = -1;	// �鵽 "," λ�õı���
		int start = 0;
		while (true)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				// û���ҵ�
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
		cout << "��" << it->first << "��ھ���ţ�" << it->second[0] << " ������" << it->second[1] << endl;
	}*/
}

// ��ʾ�����¼
void SpeechManager::showRecord() {
	if (this->fileIsEmpty)
	{
		cout << "�ļ������ڣ����¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < this->mRecord.size(); i++)
		{
			cout << "��" << i + 1 << "��"
				<< "�ھ���ţ�" << this->mRecord[i][0] << " ������" << this->mRecord[i][1] << " "
				<< "�Ǿ���ţ�" << this->mRecord[i][2] << " ������" << this->mRecord[i][3] << " "
				<< "������ţ�" << this->mRecord[i][4] << " ������" << this->mRecord[i][5] << endl;
		}
	}

	system("pause");
	system("cls");
}

// ��ռ�¼
void SpeechManager::clearRecord() {
	cout << "ȷ����գ�" << endl;
	cout << "1����" << endl;
	cout << "2����" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		// ȷ�����
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		// ��ʼ������������
		this->initSpeech();

		// ����12��ѡ��
		this->createSpeaker();

		// ���������¼
		this->loadRecord();

		cout << "��ճɹ���" << endl;
	}

	system("pause");
	system("cls");

}

// ��������
SpeechManager::~SpeechManager() {

}