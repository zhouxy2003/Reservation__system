#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include"globalFile.h"
#include<fstream>

class OrderData {
public:
	OrderData();

	OrderData(const string& date, const string& interval, const string& stuId, const string& stuName, const string& roomId, const string& status);

	void inData();

	string date;      // ����
	string interval;  // ʱ���
	string stuId;     // ѧ�����
	string stuName;   // ѧ������
	string roomId;    // �������
	string status;    // ԤԼ״̬

	vector<OrderData>v;

};