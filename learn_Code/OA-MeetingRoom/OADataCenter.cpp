#include "OADataCenter.h"
#include "OAUtils.h"

OADataCenter OADataCenter::_instance = OADataCenter();

OADataCenter::OADataCenter()
{
	admins.push_back(OAAdmin("admin", "password"));

	users.push_back(OAUser("justin", "123123", "行政部"));
	users.push_back(OAUser("jack", "123456", "人力资源部"));

	rooms.push_back(OAMeetingRoom(1, 10));
	rooms.push_back(OAMeetingRoom(2, 6));
	rooms.push_back(OAMeetingRoom(3, 4));

	OAUser* user = new OAUser("liny", "123456", "项目研发部");
	OAMeetingRoom r(4, 12);
	r._user = user; 
	rooms.push_back(r);
}

OADataCenter & OADataCenter::getInstance()
{
	return _instance;
}

OAAdmin & OADataCenter::loginAdmin(string username, string password)
{
	for (OAAdmin& admin : admins)
	{
		if (admin._username == username && admin._password == password)
		{
			return admin;
		}
	}
	return OAAdmin::ERROR_ADMIN;
}

OAUser & OADataCenter::loginUser(string username, string password)
{
	for (OAUser& user : users)
	{
		if (user._username == username && user._password == password)
		{
			return user;
		}
	}
	return OAUser::ERROR_USER;
}

bool OADataCenter::addUser(string username, string passwd, string department)
{
	// 检查用户是否存在
	for (OAUser& user : users)
	{
		if (user._username == username)
		{
			return false;
		}
	}
	// 添加用户
	users.push_back(OAUser(username, passwd, department));
	return true;
}

bool OADataCenter::delUser(string username)
{
	auto it = users.begin();
	for (; it != users.end(); it++)
	{
		if (it->username() == username)
		{
			break;
		}
	}
	// 判断是否找到了这个用户
	if (it == users.end())
	{
		return false;
	}
	users.erase(it);
	return true;
}

bool OADataCenter::addMeetingRoom(int mid, int capacity)
{
	// 检查会议室是否存在
	for (OAMeetingRoom& room : rooms)
	{
		if (room._mid == mid)
		{
			return false;
		}
	}
	// 添加成功
	rooms.push_back(OAMeetingRoom(mid, capacity));
	return true;
}

bool OADataCenter::delMeetingRoom(int mid)
{
	vector<OAMeetingRoom>:: iterator it = rooms.begin(); 
	for (; it != rooms.end(); it++)
	{
		if (it->_mid == mid)
			break;
	}
	// 判断是否存在
	if (it == rooms.end())
	{
		return false;
	}
	// 存在
	rooms.erase(it);

	return true;
}

void OADataCenter::clearMeetingRoomStatus()
{
	for (OAMeetingRoom& room : rooms)
	{
		room._user = &OAUser::ERROR_USER;
	}

}

int OADataCenter::bookMeetingRoom(OAUser & user, int mid)
{
	// 通过mid找到指定的会议室
	auto it = rooms.begin();
	for (; it != rooms.end(); it++)
	{
		if (it->_mid == mid)
			break;
	}

	//判断会议室是否存在
	if (it == rooms.end())
		return MEETING_ROOM_NOT_FOUND;
	//判断会议室是否已经被预定了
	if (it->_user != &OAUser::ERROR_USER)
		return MEETING_ROOM_BOOKED;
	// 预定会议室
	it->_user = &user;
	return BOOK_SUCCESS;

}

int OADataCenter::cancelBookMeetingRoom(OAUser & user, int mid)
{
	// 通过mid找到指定的会议室
	auto it = rooms.begin();
	for (; it != rooms.end(); it++)
	{
		if (it->_mid == mid)
			break;
	}

	// 判断会议室是否存在
	if (it == rooms.end())
		return CANCEL_MEETING_NOT_FOUND;	

	// 判断这个会议室是否是指定用户预定的
	if (it->_user != &user)
		return CANCEL_MEETING_FAIL;

	// 取消预定
	it->_user = &OAUser::ERROR_USER;
	return CANCEL_MEETING_SUCCESS;
}

vector<OAUser> OADataCenter::getUsers()
{
	vector<OAUser> users_bak(users);
	return users_bak;
}

vector<OAMeetingRoom> OADataCenter::getRooms()
{
	/*vector<OAMeetingRoom> rooms_bak(rooms);
	return rooms_bak;*/

	return vector<OAMeetingRoom>(rooms);
}
