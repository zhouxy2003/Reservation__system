#pragma once
#include<iostream>
using namespace std;
#include"Person.h"
#include"orderData.h"
#include<fstream>
#include"globalFile.h"
#include<string>

class teacher:public Person {
public:
	//Ĭ�Ϲ���
	teacher();

	//�вι���
	teacher(int id, string name, int password);

	//�˵�����
	void teacherMenu();

	//�鿴����ԤԼ
	void viewAllOrder();

	//���ԤԼ
	void auditOrder();


	int t_id;
};