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

	string date;      // 日期
	string interval;  // 时间段
	string stuId;     // 学生编号
	string stuName;   // 学生姓名
	string roomId;    // 机房编号
	string status;    // 预约状态

	vector<OrderData>v;

};