#pragma once
#include<iostream>
using namespace std;
#include"Person.h"

class teacher:public Person {
public:
	//默认构造
	teacher();

	//有参构造
	teacher(int id, string name, int password);

	//菜单界面
	void teacherMenu();

	//查看所有预约
	void viewAllOrder();

	//审核预约
	void auditOrder();


	int t_id;
};