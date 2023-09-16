#include"orderData.h"

OrderData::OrderData() {
		// 默认构造函数
	}

OrderData::OrderData(const string& date, const string& interval, const string& stuId, const string& stuName, const string& roomId, const string& status) {
		this->date = date;
		this->interval = interval;
		this->stuId = stuId;
		this->stuName = stuName;
		this->roomId = roomId;
		this->status = status;
	}

void OrderData::inData() {
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	OrderData od;
	while (ifs >> od.date && ifs >> od.interval && ifs >> od.stuId && ifs >> od.stuName && ifs >> od.roomId && ifs >> od.status) {
		this->v.push_back(od);
	}
	ifs.close();
}
