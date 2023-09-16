#include"manger.h"




//Ĭ�Ϲ���
manger::manger() {

}

//�вι���
manger::manger(string name, int pwd) {
	this->P_name = name;
	this->P_password = pwd;
}

//�ж�id�Ƿ��ظ�
bool manger::checkFind(int id, int type) {
	if (type == 1) {
		vector<teacher> teachers;
		ifstream ifs;
		ifs.open(TEACHER_FILE, ios::in);
		teacher t;
		while (ifs >> t.t_id && ifs >> t.P_name && ifs >> t.P_password) {
			teachers.push_back(t);
		}
		ifs.close();
		for (vector<teacher>::iterator it = teachers.begin(); it != teachers.end(); it++) {
			if (id == it->t_id) {
				return true;
			}
		}
	}
	if (type == 2) {
		vector<student>s;
		ifstream ifs;
		ifs.open(STUDENT_FILE, ios::in);
		student stu;
		while (ifs >> stu.s_id && ifs >> stu.P_name && ifs >> stu.P_password) {
			s.push_back(stu);
		}
		ifs.close();
		for (vector<student>::iterator it = s.begin(); it != s.end(); it++) {
			if (id == it->s_id) {
				return true;
			}
		}
	}
	return false;
}


//��ʾ����Ա�����Ĳ˵�����
void manger::showMangerMenu() {
	cout << "��ӭ����Ա��" << this->P_name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

// ����˺�
void manger::addUser() {
	cout << "\t\t --------------------\n";
	cout << "\t\t|   1.��ʦ�˻�ע��   |\n";
	cout << "\t\t|   2.ѧ���˻�ע��   |\n";
	cout << "\t\t --------------------\n";
	cout << "== ���������ѡ�� ==" << endl;
	int select;
	cin >> select;

	if (select == 1) {
		string fileName = TEACHER_FILE;
		ofstream ofs;
		ofs.open(fileName, ios::out | ios::app);
		string name;
		int id;
		int pwd;


		cout << "== ������ID ==" << endl;
		cin >> id;
		//�ж��Ƿ�id�ظ�
		if (this->checkFind(id, 1)) {
			cout << "== ID�ظ����� ==" << endl;
			system("pause");
			system("cls");
			return;
		}
		ofs << id << "\t";
		cout << "�������˻���:" << endl;
		cin >> name;
		ofs << name << "\t";
		cout << "����������:" << endl;
		cin >> pwd;
		ofs << pwd;
		ofs << endl;

		cout << "�����ɹ�" << endl;
		ofs.close();
		system("pause");
		system("cls");


	}
	else if (select == 2) {
		string fileName = STUDENT_FILE;
		ofstream ofs;
		ofs.open(fileName, ios::out | ios::app);
		string name;
		int id;
		int pwd;

		cout << "== ������ID ==" << endl;
		cin >> id;
		//�ж�id�Ƿ��ظ�
		if (this->checkFind(id, 2)) {
			cout << "== ID�ظ����� ==" << endl;
			system("pause");
			system("cls");
			return;
		}
		ofs <<id << "\t";
		cout << "�������˻���:" << endl;
		cin >> name;
		ofs<<name << "\t";
		cout << "����������:" << endl;
		cin >> pwd;
		ofs <<pwd;
		ofs << endl;

		cout << "�����ɹ�" << endl;
		ofs.close();
		system("pause");
		system("cls");
	}
	else {
		cout << "=== ��������ȷ��ѡ�� ===" << endl;
		system("pause");
		system("cls");
		
	}

}

// �鿴�˺�
void manger::viewUser() {
	cout << "\t\t ------------------------\n";
	cout << "\t\t|   1.�鿴��ʦ�˻�ע��   |\n";
	cout << "\t\t|   2.�鿴ѧ���˻�ע��   |\n";
	cout << "\t\t ------------------------\n";
	cout << "== ���������ѡ�� ==" << endl;

	int select;
	cin >> select;

	if (select == 1) {
		ifstream ifs;
		ifs.open(TEACHER_FILE, ios::in);
		teacher t;
		while (ifs >> t.t_id && ifs >> t.P_name && ifs >> t.P_password) {
			cout << "ID��" << t.t_id << "\t\t������" << t.P_name << "\t\t���룺" << t.P_password << endl;
		}

		ifs.close();
		system("pause");
		system("cls");
		return;
	}
	else if (select == 2) {
		ifstream ifs;
		ifs.open(STUDENT_FILE, ios::in);
		student s;
		while (ifs >> s.s_id && ifs >> s.P_name && ifs >> s.P_password) {
			cout << "ID��" << s.s_id << "\t\t������" << s.P_name << "\t\t���룺" << s.P_password << endl;
		}
		ifs.close();
		system("pause");
		system("cls");
		return;
	}
	else {
		cout << "== �������� ==" << endl;
		system("pause");
		system("cls");
		return;
	}

}

// �鿴������Ϣ
void manger::viewRoom() {
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	computerRoom cr;
	while (ifs >> cr.R_id && ifs >> cr.R_num) {
		cout << "������ţ�" << cr.R_id << "\t�������������" << cr.R_num << endl;
	}
	ifs.close();
	system("pause");
	system("cls");
	return;
}

// ���ԤԼ��¼
void manger::clearData() {
	ofstream ofs;
	int num;
	cout << "\t\t-----------------" << endl;
	cout << "\t\t| 1 - ȷ�����  |" << endl;
	cout << "\t\t| 0 - ȡ�����  |" << endl;
	cout << "\t\t-----------------" << endl;
	cout << "> > ���������ѡ��:" << endl;
	cout << ">>";
	cin >> num;
	if (num == 1) {
		ofs.open(ORDER_FILE, ios::trunc);
		ofs.close();
		cout << "== ��ճɹ� ==" << endl;
	}
	else {
		cout << "== ȡ���ɹ� ==" << endl;
	}
	system("pause");
	system("cls");
	return;
}