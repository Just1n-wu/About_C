#pragma once
#include <iostream>
#include "OADataCenter.h"
using namespace std;

class OAAdmin
{
	friend class OADataCenter;  // ��Ԫ��
private:
	string _username;
	string _password;
public:
	OAAdmin();
	OAAdmin(string username, string password);
	static OAAdmin ERROR_ADMIN;

	string username();

	bool addUser(string username, string passwd, string department);
	bool delUser(string username);
	void showA11Users();

	bool addRoom(int mid, int capacity);
	bool delRoom(int mid);
	void clrRoomStatus();
	void showA11Rooms();
}; 

