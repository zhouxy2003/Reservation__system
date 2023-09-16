#include"student.h"

//Ĭ�Ϲ���
student::student(){

}

//�вι���
student::student(int id,string name, int password) {
	this->s_id = id;
	this->P_name = name;
	this->P_password = password;
}

//�ж��ļ��Ƿ�Ϊ��
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




//�˵�����
void student::studentMenu() {
	cout << "��ӭѧ������" << this->P_name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.����ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.�鿴�ҵ�ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          3.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          4.ȡ��ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}


//����ԤԼ�Ӳ˵�����
void showApplyOrderScreen() {
	cout << "\t---------------------------------" << endl;
	cout << "\t| ��������ʱ��Ϊ��һ�����壡" << "\t|" << endl;
	cout << "\t| ����������ԤԼ��ʱ�䣺" << "\t|" << endl;
	cout << "\t| 1����һ" << "\t\t\t|" << endl;
	cout << "\t| 2���ܶ�" << "\t\t\t|" << endl;
	cout << "\t| 3������" << "\t\t\t|" << endl;
	cout << "\t| 4������" << "\t\t\t|" << endl;
	cout << "\t| 5������" << "\t\t\t|" << endl;
	cout << "\t---------------------------------" << endl << endl;
}


//����ԤԼ
void student::applyOrder() {
	showApplyOrderScreen();

	int date = 0;
	int interval = 0;
	cout << "== ��ѡ��ԤԼ���� ==" << endl;
	while (true) {
		cin >> date;
		if (date <= 5 && date >= 1) {
			break;
		}
		cout << "���������� ��" << endl;
	}
	cout << endl;

	cout << "== ��ѡ��ԤԼʱ�� ==" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;

	while (true) {
		cin >> interval;
		if (interval <= 2 && interval >= 1) {
			break;
		}
		cout << "���������� ��" << endl;
	}
	cout << endl;


	//��ȡ������Ϣ
	vector<computerRoom>v;
	computerRoom cm;
	ifstream ifs;
	ifs.open(COMPUTER_FILE);
	if (isEmpty()) {
		cout << "== �����ļ�����,�ļ�Ϊ�� ==" << endl;
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
		cout << "\t| "<< it->R_id<<"�Ż���"<< "\t��������:" << it->R_num << "\t|" << endl;
	}
	cout << "\t---------------------------------" << endl;
	cout << endl;
	cout << "> > ���������ѡ��:" << endl;
	int room;
	while (true) {
		cin >> room;
		if (room <= 3 && room >= 1) {
			break;
		}
		cout << "���������� ��" << endl;
	}

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::app);
	string time = interval == 1 ? "����" : "����";
	ofs << "ԤԼ����:��" << date << "\tʱ��:" << time 
		<< "\tID:" << this->s_id << "\t  ����:" 
		<< this->P_name << "\t  ������:" << room << "�Ż���"<<"\t  ״̬:�����";
	ofs << endl;
	ofs.close();
	cout << "=== ����ԤԼ�ɹ�������� ===" << endl;


	system("pause");
	system("cls");
	return;
}


//�鿴�ҵ�ԤԼ
void student::viewMyOrder() {
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	if (isEmpty()) {
		cout << "== �����ļ�����,�ļ�Ϊ�� ==" << endl;
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

//�鿴����ԤԼ
void student::viewAllOrder(){
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	if (isEmpty()) {
		cout << "== �����ļ�����,�ļ�Ϊ�� ==" << endl;
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

//ȡ��ԤԼ
void student::delteOrder(){
	cout << "=== ԤԼ��Ϣ���� ===" << endl;
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	if (isEmpty()) {
		cout << "== �����ļ�����,�ļ�Ϊ�� ==" << endl;
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
	cout << "=== ��ѡ��Ҫȡ����ԤԼ��Ϣ��� ===" << endl;
	int select = 0;
	cout << ">>";
	cin >> select;
	int ind = 0;
	for (int i = 0; i < od.v.size(); i++) {
		if (od.v[i].stuName.find(this->P_name)!=string::npos) {
			ind++;
		}
		if (ind==select) {
			od.v[i].status = "״̬:��ȡ��ԤԼ";
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