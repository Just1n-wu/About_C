#include "OAAdmin.h"
#include "OADataCenter.h"
#include <string>

OAAdmin::OAAdmin()
{
}

OAAdmin::OAAdmin(string username, string password)
{
	_username = username;
	_password = password;
}

string OAAdmin::username()
{
	return _username;
}

bool OAAdmin::addUser(string username, string passwd, string department)
{
	return OADataCenter::getInstance().addUser(username, passwd, department);
}

bool OAAdmin::delUser(string username)
{
	return OADataCenter::getInstance().delUser(username);
}

void OAAdmin::showA11Users()
{
	vector<OAUser> users = OADataCenter::getInstance().getUsers();
	system("cls");
	cout << "+------------------------+" << endl;
	cout << "用户名" << "\t|" << "      部门" << "\t |" << endl;
	cout << "+------------------------+" << endl;

	for (OAUser& u : users)
	{
		cout << '|' << u.username() << "\t|   " << u.department() << endl;
		cout << "--------------------------" << endl;
	}
}

bool OAAdmin::addRoom(int mid, int capacity)
{
	return OADataCenter::getInstance().addMeetingRoom(mid, capacity);
}

bool OAAdmin::delRoom(int mid)
{
	return OADataCenter::getInstance().delMeetingRoom(mid);
}

void OAAdmin::clrRoomStatus()
{
	OADataCenter::getInstance().clearMeetingRoomStatus();
}

void OAAdmin::showA11Rooms()
{
	// 1．获取到所有的会议室
	vector<OAMeetingRoom> rooms = OADataCenter::getInstance().getRooms();
	// 2. 遍历每一个会议室
	for (OAMeetingRoom& m : rooms)
	{
		cout << "会议室编号: " << m.mid() << "，容量: " << m.capacity();
		if (m.user() == &(OAUser::ERROR_USER))
		{
			cout << "，可预定！" << endl;
		}
		else 
		{
			cout << "，这个会议室已经被" << m.user()->department() << "的" << m.user()->username() << "占用了" << endl;
		}

	}

}

OAAdmin OAAdmin::ERROR_ADMIN = OAAdmin();
