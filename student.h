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
	//Ĭ�Ϲ���
	student();

	//�вι���
	student(int id,string name, int password);

	//�˵�����
	void studentMenu();


	//����ԤԼ
	void applyOrder();


	//�鿴�ҵ�ԤԼ
	void viewMyOrder();

	//�鿴����ԤԼ
	void viewAllOrder();

	//ȡ��ԤԼ
	void delteOrder();


	int s_id;

};