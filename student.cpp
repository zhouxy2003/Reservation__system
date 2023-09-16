#include"student.h"

//默认构造
student::student(){

}

//有参构造
student::student(int id,string name, int password) {
	this->s_id = id;
	this->P_name = name;
	this->P_password = password;
}

//判断文件是否为空
bool isEmpty() {
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	if (ifs.peek() == EOF) {
		ifs.close();
		return true;
	}
	ifs.close();
	return false;
}




//菜单界面
void student::studentMenu() {
	cout << "欢迎学生代表：" << this->P_name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.申请预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.查看我的预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          3.查看所有预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          4.取消预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}


//申请预约子菜单界面
void showApplyOrderScreen() {
	cout << "\t---------------------------------" << endl;
	cout << "\t| 机房开放时间为周一至周五！" << "\t|" << endl;
	cout << "\t| 请输入申请预约的时间：" << "\t|" << endl;
	cout << "\t| 1、周一" << "\t\t\t|" << endl;
	cout << "\t| 2、周二" << "\t\t\t|" << endl;
	cout << "\t| 3、周三" << "\t\t\t|" << endl;
	cout << "\t| 4、周四" << "\t\t\t|" << endl;
	cout << "\t| 5、周五" << "\t\t\t|" << endl;
	cout << "\t---------------------------------" << endl << endl;
}


//申请预约
void student::applyOrder() {
	showApplyOrderScreen();

	int date = 0;
	int interval = 0;
	cout << "== 请选择预约日期 ==" << endl;
	while (true) {
		cin >> date;
		if (date <= 5 && date >= 1) {
			break;
		}
		cout << "！输入有误 ！" << endl;
	}
	cout << endl;

	cout << "== 请选择预约时段 ==" << endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;

	while (true) {
		cin >> interval;
		if (interval <= 2 && interval >= 1) {
			break;
		}
		cout << "！输入有误 ！" << endl;
	}
	cout << endl;


	//读取机房信息
	vector<computerRoom>v;
	computerRoom cm;
	ifstream ifs;
	ifs.open(COMPUTER_FILE);
	if (isEmpty()) {
		cout << "== 请检查文件内容,文件为空 ==" << endl;
		system("pause");
		system("cls");
		//return;
	}
	while (ifs >> cm.R_id && ifs >> cm.R_num) {
		v.push_back(cm);
	}
	ifs.close();
	cout << "\t---------------------------------" << endl;
	for (vector<computerRoom>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "\t| "<< it->R_id<<"号机房"<< "\t机房容量:" << it->R_num << "\t|" << endl;
	}
	cout << "\t---------------------------------" << endl;
	cout << endl;
	cout << "> > 请输入你的选择:" << endl;
	int room;
	while (true) {
		cin >> room;
		if (room <= 3 && room >= 1) {
			break;
		}
		cout << "！输入有误 ！" << endl;
	}

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::app);
	string time = interval == 1 ? "上午" : "下午";
	ofs << "预约日期:周" << date << "\t时段:" << time 
		<< "\tID:" << this->s_id << "\t  姓名:" 
		<< this->P_name << "\t  机房号:" << room << "号机房"<<"\t  状态:审核中";
	ofs << endl;
	ofs.close();
	cout << "=== 申请预约成功，审核中 ===" << endl;


	system("pause");
	system("cls");
	return;
}


//查看我的预约
void student::viewMyOrder() {
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	if (isEmpty()) {
		cout << "== 请检查文件内容,文件为空 ==" << endl;
		system("pause");
		system("cls");
	}
	string line;
	while (getline(ifs, line)) {
		if (line.find(this->P_name) != string::npos) {
			cout << line << endl;
		}
	}


	cout << endl;
	ifs.close();
	system("pause");
	system("cls");
	return;

}

//查看所有预约
void student::viewAllOrder(){
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	if (isEmpty()) {
		cout << "== 请检查文件内容,文件为空 ==" << endl;
		system("pause");
		system("cls");
	}
	string line;
	while (getline(ifs, line)) {
		cout << line << endl;
	}


	cout << endl;
	ifs.close();
	system("pause");
	system("cls");
	return;
}

//取消预约
void student::delteOrder(){
	cout << "=== 预约信息如下 ===" << endl;
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	if (isEmpty()) {
		cout << "== 请检查文件内容,文件为空 ==" << endl;
		system("pause");
		system("cls");
	}
	string line;
	int index = 1;
	while (getline(ifs, line)) {
		if (line.find(this->P_name) != string::npos) {
			cout <<index<<" - " << line << endl;
			index++;
		}
	}
	cout << endl;
	ifs.close();

	ofstream ofs;
	OrderData od;
	od.inData();

	ofs.open(ORDER_FILE, ios::out | ios::trunc);

	cout << endl;
	cout << "=== 请选择要取消的预约信息编号 ===" << endl;
	int select = 0;
	cout << ">>";
	cin >> select;
	int ind = 0;
	for (int i = 0; i < od.v.size(); i++) {
		if (od.v[i].stuName.find(this->P_name)!=string::npos) {
			ind++;
		}
		if (ind==select) {
			od.v[i].status = "状态:已取消预约";
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
	system("pause");
	system("cls");
	return;
}