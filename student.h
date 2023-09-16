#pragma once
#include<iostream>
using namespace std;
#include"Person.h"
#include"computerRoom.h"
#include<vector>
#include"globalFile.h"
#include<fstream>
#include<string>
#include"orderData.h"


class student :public Person {
public:
	//默认构造
	student();

	//有参构造
	student(int id,string name, int password);

	//菜单界面
	void studentMenu();


	//申请预约
	void applyOrder();


	//查看我的预约
	void viewMyOrder();

	//查看所有预约
	void viewAllOrder();

	//取消预约
	void delteOrder();


	int s_id;

};