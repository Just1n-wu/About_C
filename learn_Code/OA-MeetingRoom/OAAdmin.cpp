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
	cout << "�û���" << "\t|" << "      ����" << "\t |" << endl;
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
	// 1����ȡ�����еĻ�����
	vector<OAMeetingRoom> rooms = OADataCenter::getInstance().getRooms();
	// 2. ����ÿһ��������
	for (OAMeetingRoom& m : rooms)
	{
		cout << "�����ұ��: " << m.mid() << "������: " << m.capacity();
		if (m.user() == &(OAUser::ERROR_USER))
		{
			cout << "����Ԥ����" << endl;
		}
		else 
		{
			cout << "������������Ѿ���" << m.user()->department() << "��" << m.user()->username() << "ռ����" << endl;
		}

	}

}

OAAdmin OAAdmin::ERROR_ADMIN = OAAdmin();
