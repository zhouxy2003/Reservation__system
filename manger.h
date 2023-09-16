#pragma once
#include<iostream>
using namespace std;
#include"Person.h"
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"computerRoom.h"
#include<vector>
#include<fstream>
#include<string>

class manger:public Person {
public:

	//默认构造
	manger();

	//有参构造
	manger(string name, int pwd);

	//判断id是否重复
	bool checkFind(int id,int type);

	//显示管理员操作的菜单界面
	void showMangerMenu();

	// 添加账号
	void addUser();

	// 查看账号
	void viewUser();

	// 查看机房信息
	void viewRoom();

	// 清空预约记录
	void clearData();


};