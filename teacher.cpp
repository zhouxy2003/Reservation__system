#include"teacher.h"



teacher::teacher() {

}

//�вι���
teacher::teacher(int id, string name, int password) {
	this->P_name = name;
	this->t_id = id;
	this->P_password = password;

}

//�˵�����
void teacher::teacherMenu() {
	cout << "��ӭ��ʦ��" << this->P_name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.���ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

//�鿴����ԤԼ
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

//���ԤԼ
void teacher::auditOrder() {
	OrderData od;
	//�Ƚ����ݴ�������
	od.inData();
	int index = 1;
	cout << "\t------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < od.v.size(); i++) {
		if (od.v[i].status.find("�����") != string::npos) {
			cout <<"\t"<< index<<" - " << od.v[i].date <<"   "<< od.v[i].interval
				<< "   " << od.v[i].stuId << "   " << od.v[i].stuName 
				<< "   " << od.v[i].roomId << "   " << od.v[i].status << endl;
			index++;
		}
	}
	if (index == 1) {
		cout << "\t\t\t\t=== ������Ҫ����ԤԼ ===" << endl;
		cout << "\t------------------------------------------------------------------------------" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "\t------------------------------------------------------------------------------" << endl;
	cout << endl;
	int choseNum;
	cout << "=== ��������˵ı�� ===" << endl;
	cout << "> >";
	cin >> choseNum;

	cout << endl;
	cout << "\t--------------" << endl;
	cout << "\t| 1 - ͨ��   |" << endl;
	cout << "\t| 0 - ��ͨ�� |" << endl;
	cout << "\t--------------" << endl;
	cout << endl;

	int is;
	cout << "> >�����룺" << endl;
	cout << ">>";
	cin >> is;
	int ind = 0;
	if (is == 1) {
		ofstream ofs;
		ofs.open(ORDER_FILE, ios::out | ios::trunc);
		for (int i = 0; i < od.v.size(); i++) {
			if (od.v[i].status.find("�����") != string::npos) {
				ind++;
			}
			if(ind==index-1){
				od.v[i].status = "״̬:ͨ��";
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
			if (od.v[i].status.find("�����") != string::npos) {
				ind++;
			}
			if (ind == index - 1) {
				od.v[i].status = "״̬:��ͨ��";
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


	cout << "=== ������ ===" << endl;
	system("pause");
	system("cls");
	return;
}