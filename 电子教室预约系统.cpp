#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include"allControl.h"
#include"globalFile.h"


int main() {
	allControl ac;
	int select;

	while (true) {
		ac.headMenu();
		cin >> select;

		switch (select)
		{
			case 0:
				cout << "=== ��ӭ�´�ʹ�� ===" << endl;
				system("pause");
				exit(0);
				break;
			case 1:
				ac.loginSystem(STUDENT_FILE, 1);
				break;
			case 2:
				ac.loginSystem(TEACHER_FILE, 2);
				break;
			case 3:
				ac.loginSystem(ADMIN_FILE, 3);
				break;
			default:
				cout << "=== �������� ���������� ===" << endl;
				system("pause");
				system("cls");
				break;
		}


	}


	system("pause");
	return 0;
}