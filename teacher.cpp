#include"teacher.h"



teacher::teacher() {

}

//有参构造
teacher::teacher(int id, string name, int password) {
	this->P_name = name;
	this->t_id = id;
	this->P_password = password;

}

//菜单界面
void teacher::teacherMenu() {
	cout << "欢迎教师：" << this->P_name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.查看所有预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.审核预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

//查看所有预约
void teacher::viewAllOrder() {
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	string line;
	while (getline(ifs, line)) {
		cout << line << endl;
	}

	system("pause");
	system("cls");
	return;
}

//审核预约
void teacher::auditOrder() {
	OrderData od;
	//先将数据存入容器
	od.inData();
	int index = 1;
	cout << "\t------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < od.v.size(); i++) {
		if (od.v[i].status.find("审核中") != string::npos) {
			cout <<"\t"<< index<<" - " << od.v[i].date <<"   "<< od.v[i].interval
				<< "   " << od.v[i].stuId << "   " << od.v[i].stuName 
				<< "   " << od.v[i].roomId << "   " << od.v[i].status << endl;
			index++;
		}
	}
	if (index == 1) {
		cout << "\t\t\t\t=== 暂无需要处理预约 ===" << endl;
		cout << "\t------------------------------------------------------------------------------" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "\t------------------------------------------------------------------------------" << endl;
	cout << endl;
	int choseNum;
	cout << "=== 请输入审核的编号 ===" << endl;
	cout << "> >";
	cin >> choseNum;

	cout << endl;
	cout << "\t--------------" << endl;
	cout << "\t| 1 - 通过   |" << endl;
	cout << "\t| 0 - 不通过 |" << endl;
	cout << "\t--------------" << endl;
	cout << endl;

	int is;
	cout << "> >请输入：" << endl;
	cout << ">>";
	cin >> is;
	int ind = 0;
	if (is == 1) {
		ofstream ofs;
		ofs.open(ORDER_FILE, ios::out | ios::trunc);
		for (int i = 0; i < od.v.size(); i++) {
			if (od.v[i].status.find("审核中") != string::npos) {
				ind++;
			}
			if(ind==index-1){
				od.v[i].status = "状态:通过";
				break;
			}
		}
		for (int i = 0; i < od.v.size(); i++) {
			ofs << od.v[i].date << "\t" << od.v[i].interval
				<< "\t" << od.v[i].stuId << "\t  "
				<< od.v[i].stuName << "\t  " << od.v[i].roomId << "\t" << od.v[i].status;
			ofs << endl;
		}
		ofs.close();
	}
	else if (is == 0) {
		ofstream ofs;
		ofs.open(ORDER_FILE, ios::out | ios::trunc);
		for (int i = 0; i < od.v.size(); i++) {
			if (od.v[i].status.find("审核中") != string::npos) {
				ind++;
			}
			if (ind == index - 1) {
				od.v[i].status = "状态:不通过";
				break;
			}
		}
		for (int i = 0; i < od.v.size(); i++) {
			ofs << od.v[i].date << "\t" << od.v[i].interval
				<< "\t" << od.v[i].stuId << "\t  "
				<< od.v[i].stuName << "\t  " << od.v[i].roomId << "\t" << od.v[i].status;
			ofs << endl;
		}
		ofs.close();
	}


	cout << "=== 审核完毕 ===" << endl;
	system("pause");
	system("cls");
	return;
}