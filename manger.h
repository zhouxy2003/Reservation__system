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

	//Ĭ�Ϲ���
	manger();

	//�вι���
	manger(string name, int pwd);

	//�ж�id�Ƿ��ظ�
	bool checkFind(int id,int type);

	//��ʾ����Ա�����Ĳ˵�����
	void showMangerMenu();

	// ����˺�
	void addUser();

	// �鿴�˺�
	void viewUser();

	// �鿴������Ϣ
	void viewRoom();

	// ���ԤԼ��¼
	void clearData();


};