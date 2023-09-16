	#include"allControl.h"
	#include"globalFile.h"
	#include"Person.h"
	#include"student.h"
	#include"teacher.h"
	#include"manger.h"

	void allControl::headMenu() {
		cout << "======================  欢迎来到传智播客机房预约系统  =====================" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t       -------------------------------\n";
		cout << "\t\t      |                               |\n";
		cout << "\t\t      |          1.学生代表           |\n";
		cout << "\t\t      |                               |\n";
		cout << "\t\t      |          2.老    师           |\n";
		cout << "\t\t      |                               |\n";
		cout << "\t\t      |          3.管 理 员           |\n";
		cout << "\t\t      |                               |\n";
		cout << "\t\t      |          0.退    出           |\n";
		cout << "\t\t      |                               |\n";
		cout << "\t\t       -------------------------------\n";
		cout << "输入您的选择: ";
	}

	//管理员
	void  mangerMenu(manger* &mang) {
		mang->showMangerMenu();
		while (true)
		{
			int select = 0;
			cout << ">> ";
			cin >> select;
			//1.添加账号
			if (select == 1) {
				mang->addUser();
				mang->showMangerMenu();
			}
			//2.查看账号
			else if (select == 2) {
				mang->viewUser();
				mang->showMangerMenu();
			}
			// 3.查看机房 
			else if (select == 3) {
				mang->viewRoom();
				mang->showMangerMenu();
			}
			//4.清空预约
			else if (select == 4) {
				mang->clearData();
				mang->showMangerMenu();
			}
			//0.注销登录  
			else
			{
				delete mang;
				cout << "注销成功" << endl;
				system("pause");
				system("cls");
				return;
			}
		}
	}


	//学生登录
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




	//登录
	void allControl::loginSystem(string filename, int type) {
	


		ifstream ifs;

		ifs.open(filename, ios::in);
		if (!ifs.is_open()) {
			cout << "=== 文件不存在 ===" << endl;
			ifs.close();
			system("pause");
			system("cls");
			return;
		}
		else if (ifs.peek() == EOF) {
			cout << "=== 文件为空 ===" << endl;
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
			//学生验证登录
			cout << "== 请输入ID ==" << endl;
			cin >> id;
			////处理输入错误类型导致程序卡死
			if (cin.fail()) {
				cout << "输入的ID无效" << endl;
				cin.clear(); // 清除错误标志
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略无效的输入
				system("pause");
				system("cls");
				return; // 或者执行其他错误处理逻辑
			}
			cout << "请输入账户名:" << endl;
			cin >> name;
			cout << "请输入密码:" << endl;
			cin >> pwd;

			string fname;
			int fid;
			int fpwd;
			ifs.seekg(0, ios::beg); // 将文件指针重新定位到文件开头
			bool found = false; // 标记是否找到匹配的账户

			while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
				if (id == fid && name == fname && pwd == fpwd) {
					cout << endl;
					cout << "--- 学生验证登录成功 ---" << endl << endl;
					system("pause");
					system("cls");
					p = new student(id, name, pwd);
					studentLogin(p);
					found = true; // 找到匹配的账户
					break;
				}
			}

			if (!found) {
				cout << "=== 验证失败 ===" << endl;
				system("pause");
				system("cls");
			}

		}
		else if (type == 2) {
			teacher* p = NULL;
			//老师登录
			cout << "== 请输入ID ==" << endl;
			cin >> id;
			//处理输入错误类型导致程序卡死
			if (cin.fail()) {
				cout << "=== 输入ID无效 ===" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("pause");
				system("cls");
				return;
			}
			cout << "请输入账户名:" << endl;
			cin >> name;
			cout << "请输入密码:" << endl;
			cin >> pwd;

			string fname;
			int fid;
			int fpwd;
			ifs.seekg(0, ios::beg); // 将文件指针重新定位到文件开头
			bool found = false; // 标记是否找到匹配的账户

			while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
				if (id == fid && name == fname && pwd == fpwd) {
					cout << endl;
					cout << "--- 老师验证登录成功 ---" << endl << endl;
					system("pause");
					system("cls");
					p = new teacher(id, name, pwd);
					
					found = true; // 找到匹配的账户
					break;
				}
			}

			if (!found) {
				cout << "=== 验证失败 ===" << endl;
				system("pause");
				system("cls");
			}

		}

		else if(type==3){

			manger* p = NULL;
			//管理员登录
			cout << "请输入账户名:" << endl;
			cin >> name;
			cout << "请输入密码:" << endl;
			cin >> pwd;
			//处理输入错误类型导致程序卡死
			if (cin.fail()) {
				cout << "=== 输入无效 ===" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("pause");
				system("cls");
				return;
			}

			string fname;
			int fpwd;
			ifs.seekg(0, ios::beg); // 将文件指针重新定位到文件开头
			bool found = false; // 标记是否找到匹配的账户

			while (ifs >> fname && ifs >> fpwd) {
				if (name == fname && pwd == fpwd) {
					cout << endl;
					cout << "--- 管理员验证登录成功 ---" << endl << endl;
					system("pause");
					system("cls");
					p = new manger(name, pwd);
					mangerMenu(p);
					found = true; // 找到匹配的账户
					break;
				}
			}

			if (!found) {
				cout << "=== 验证失败 ===" << endl;
				system("pause");
				system("cls");
			}


		}
	}