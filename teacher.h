#pragma once
#include<iostream>
using namespace std;
#include"Person.h"

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