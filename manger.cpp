#include"manger.h"




//默认构造
manger::manger() {

}

//有参构造
manger::manger(string name, int pwd) {
	this->P_name = name;
	this->P_password = pwd;
}

//判断id是否重复
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


//显示管理员操作的菜单界面
void manger::showMangerMenu() {
	cout << "欢迎管理员：" << this->P_name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

// 添加账号
void manger::addUser() {
	cout << "\t\t --------------------\n";
	cout << "\t\t|   1.老师账户注册   |\n";
	cout << "\t\t|   2.学生账户注册   |\n";
	cout << "\t\t --------------------\n";
	cout << "== 请输入你的选择 ==" << endl;
	int select;
	cin >> select;

	if (select == 1) {
		string fileName = TEACHER_FILE;
		ofstream ofs;
		ofs.open(fileName, ios::out | ios::app);
		string name;
		int id;
		int pwd;


		cout << "== 请输入ID ==" << endl;
		cin >> id;
		//判断是否id重复
		if (this->checkFind(id, 1)) {
			cout << "== ID重复存在 ==" << endl;
			system("pause");
			system("cls");
			return;
		}
		ofs << id << "\t";
		cout << "请输入账户名:" << endl;
		cin >> name;
		ofs << name << "\t";
		cout << "请输入密码:" << endl;
		cin >> pwd;
		ofs << pwd;
		ofs << endl;

		cout << "创建成功" << endl;
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

		cout << "== 请输入ID ==" << endl;
		cin >> id;
		//判断id是否重复
		if (this->checkFind(id, 2)) {
			cout << "== ID重复存在 ==" << endl;
			system("pause");
			system("cls");
			return;
		}
		ofs <<id << "\t";
		cout << "请输入账户名:" << endl;
		cin >> name;
		ofs<<name << "\t";
		cout << "请输入密码:" << endl;
		cin >> pwd;
		ofs <<pwd;
		ofs << endl;

		cout << "创建成功" << endl;
		ofs.close();
		system("pause");
		system("cls");
	}
	else {
		cout << "=== 请输入正确的选项 ===" << endl;
		system("pause");
		system("cls");
		
	}

}

// 查看账号
void manger::viewUser() {
	cout << "\t\t ------------------------\n";
	cout << "\t\t|   1.查看老师账户注册   |\n";
	cout << "\t\t|   2.查看学生账户注册   |\n";
	cout << "\t\t ------------------------\n";
	cout << "== 请输入你的选择 ==" << endl;

	int select;
	cin >> select;

	if (select == 1) {
		ifstream ifs;
		ifs.open(TEACHER_FILE, ios::in);
		teacher t;
		while (ifs >> t.t_id && ifs >> t.P_name && ifs >> t.P_password) {
			cout << "ID：" << t.t_id << "\t\t姓名：" << t.P_name << "\t\t密码：" << t.P_password << endl;
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
			cout << "ID：" << s.s_id << "\t\t姓名：" << s.P_name << "\t\t密码：" << s.P_password << endl;
		}
		ifs.close();
		system("pause");
		system("cls");
		return;
	}
	else {
		cout << "== 输入有误 ==" << endl;
		system("pause");
		system("cls");
		return;
	}

}

// 查看机房信息
void manger::viewRoom() {
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	computerRoom cr;
	while (ifs >> cr.R_id && ifs >> cr.R_num) {
		cout << "机房编号：" << cr.R_id << "\t机房最大容量：" << cr.R_num << endl;
	}
	ifs.close();
	system("pause");
	system("cls");
	return;
}

// 清空预约记录
void manger::clearData() {
	ofstream ofs;
	int num;
	cout << "\t\t-----------------" << endl;
	cout << "\t\t| 1 - 确认清空  |" << endl;
	cout << "\t\t| 0 - 取消清空  |" << endl;
	cout << "\t\t-----------------" << endl;
	cout << "> > 请输入你的选择:" << endl;
	cout << ">>";
	cin >> num;
	if (num == 1) {
		ofs.open(ORDER_FILE, ios::trunc);
		ofs.close();
		cout << "== 清空成功 ==" << endl;
	}
	else {
		cout << "== 取消成功 ==" << endl;
	}
	system("pause");
	system("cls");
	return;
}