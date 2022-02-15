#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "speaker.h"
using namespace std;

// ����ݽ�����������
class SpeechManager {
public:

	// ���캯��
	SpeechManager();

	// չʾ�˵�
	void showMenu();

	// �˳�ϵͳ
	void exitSystem();

	// ��������
	~SpeechManager();

	// ��ʼ������������
	void initSpeech();

	// ����12��ѡ��
	void createSpeaker();

	// ��ʼ�����������������̿��ƺ���
	void startSpeech();

	// ��ǩ
	void speechDraw();

	// ����
	void speechContest();

	// ��ʾ�÷�
	void showScore();

	// �����¼
	void saveRecord();

	// ��ȡ��¼
	void loadRecord();

	// ��ʾ�����¼
	void showRecord();

	// ��ռ�¼
	void clearRecord();

	// �ж��ļ��Ƿ�Ϊ��
	bool fileIsEmpty;

	// ��������¼������
	map<int, vector<string>> mRecord;

	// ��Ա����
	// �����һ�ֱ���ѡ�ֱ�ŵ�����
	vector<int> v1;
	
	// ��һ�ֽ���ѡ�ֱ������
	vector<int> v2;

	// ʤ��ǰ����ѡ�ֱ������
	vector<int> vVictory;

	// ��ű���Լ���Ӧ����ѡ������
	map<int, Speaker> mSpeaker;

	// ��ű�������
	int mIndex;
};