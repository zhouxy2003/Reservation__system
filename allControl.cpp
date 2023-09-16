	#include"allControl.h"
	#include"globalFile.h"
	#include"Person.h"
	#include"student.h"
	#include"teacher.h"
	#include"manger.h"

	void allControl::headMenu() {
		cout << "======================  ��ӭ�������ǲ��ͻ���ԤԼϵͳ  =====================" << endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t       -------------------------------\n";
		cout << "\t\t      |                               |\n";
		cout << "\t\t      |          1.ѧ������           |\n";
		cout << "\t\t      |                               |\n";
		cout << "\t\t      |          2.��    ʦ           |\n";
		cout << "\t\t      |                               |\n";
		cout << "\t\t      |          3.�� �� Ա           |\n";
		cout << "\t\t      |                               |\n";
		cout << "\t\t      |          0.��    ��           |\n";
		cout << "\t\t      |                               |\n";
		cout << "\t\t       -------------------------------\n";
		cout << "��������ѡ��: ";
	}

	//����Ա
	void  mangerMenu(manger* &mang) {
		mang->showMangerMenu();
		while (true)
		{
			int select = 0;
			cout << ">> ";
			cin >> select;
			//1.����˺�
			if (select == 1) {
				mang->addUser();
				mang->showMangerMenu();
			}
			//2.�鿴�˺�
			else if (select == 2) {
				mang->viewUser();
				mang->showMangerMenu();
			}
			// 3.�鿴���� 
			else if (select == 3) {
				mang->viewRoom();
				mang->showMangerMenu();
			}
			//4.���ԤԼ
			else if (select == 4) {
				mang->clearData();
				mang->showMangerMenu();
			}
			//0.ע����¼  
			else
			{
				delete mang;
				cout << "ע���ɹ�" << endl;
				system("pause");
				system("cls");
				return;
			}
		}
	}


	//ѧ����¼
	void studentLogin(student* &s) {

		while (true) {
			s->studentMenu();
			int select;
			cout << ">>";
			cin >> select;
			if (select == 1) {
				s->applyOrder();
			
			}
			else if (select == 2) {
				s->viewMyOrder();
			}
			else if (select == 3) {
				s->viewAllOrder();
			}
			else if (select == 4) {
				s->delteOrder();
			}
			else {
				system("pause");
				system("cls");
				return;
			}
		}

	}




	//��¼
	void allControl::loginSystem(string filename, int type) {
	


		ifstream ifs;

		ifs.open(filename, ios::in);
		if (!ifs.is_open()) {
			cout << "=== �ļ������� ===" << endl;
			ifs.close();
			system("pause");
			system("cls");
			return;
		}
		else if (ifs.peek() == EOF) {
			cout << "=== �ļ�Ϊ�� ===" << endl;
			ifs.close();
			system("pause");
			system("cls");
			return;
		}
		int id;
		string name;
		int pwd;


		if(type==1)
		{
			student* p = NULL;
			//ѧ����֤��¼
			cout << "== ������ID ==" << endl;
			cin >> id;
			////��������������͵��³�����
			if (cin.fail()) {
				cout << "�����ID��Ч" << endl;
				cin.clear(); // ��������־
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������Ч������
				system("pause");
				system("cls");
				return; // ����ִ�������������߼�
			}
			cout << "�������˻���:" << endl;
			cin >> name;
			cout << "����������:" << endl;
			cin >> pwd;

			string fname;
			int fid;
			int fpwd;
			ifs.seekg(0, ios::beg); // ���ļ�ָ�����¶�λ���ļ���ͷ
			bool found = false; // ����Ƿ��ҵ�ƥ����˻�

			while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
				if (id == fid && name == fname && pwd == fpwd) {
					cout << endl;
					cout << "--- ѧ����֤��¼�ɹ� ---" << endl << endl;
					system("pause");
					system("cls");
					p = new student(id, name, pwd);
					studentLogin(p);
					found = true; // �ҵ�ƥ����˻�
					break;
				}
			}

			if (!found) {
				cout << "=== ��֤ʧ�� ===" << endl;
				system("pause");
				system("cls");
			}

		}
		else if (type == 2) {
			teacher* p = NULL;
			//��ʦ��¼
			cout << "== ������ID ==" << endl;
			cin >> id;
			//��������������͵��³�����
			if (cin.fail()) {
				cout << "=== ����ID��Ч ===" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("pause");
				system("cls");
				return;
			}
			cout << "�������˻���:" << endl;
			cin >> name;
			cout << "����������:" << endl;
			cin >> pwd;

			string fname;
			int fid;
			int fpwd;
			ifs.seekg(0, ios::beg); // ���ļ�ָ�����¶�λ���ļ���ͷ
			bool found = false; // ����Ƿ��ҵ�ƥ����˻�

			while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
				if (id == fid && name == fname && pwd == fpwd) {
					cout << endl;
					cout << "--- ��ʦ��֤��¼�ɹ� ---" << endl << endl;
					system("pause");
					system("cls");
					p = new teacher(id, name, pwd);
					
					found = true; // �ҵ�ƥ����˻�
					break;
				}
			}

			if (!found) {
				cout << "=== ��֤ʧ�� ===" << endl;
				system("pause");
				system("cls");
			}

		}

		else if(type==3){

			manger* p = NULL;
			//����Ա��¼
			cout << "�������˻���:" << endl;
			cin >> name;
			cout << "����������:" << endl;
			cin >> pwd;
			//��������������͵��³�����
			if (cin.fail()) {
				cout << "=== ������Ч ===" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("pause");
				system("cls");
				return;
			}

			string fname;
			int fpwd;
			ifs.seekg(0, ios::beg); // ���ļ�ָ�����¶�λ���ļ���ͷ
			bool found = false; // ����Ƿ��ҵ�ƥ����˻�

			while (ifs >> fname && ifs >> fpwd) {
				if (name == fname && pwd == fpwd) {
					cout << endl;
					cout << "--- ����Ա��֤��¼�ɹ� ---" << endl << endl;
					system("pause");
					system("cls");
					p = new manger(name, pwd);
					mangerMenu(p);
					found = true; // �ҵ�ƥ����˻�
					break;
				}
			}

			if (!found) {
				cout << "=== ��֤ʧ�� ===" << endl;
				system("pause");
				system("cls");
			}


		}
	}