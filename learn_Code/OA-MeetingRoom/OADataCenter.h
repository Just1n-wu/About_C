#pragma once
#include <vector>
#include "OAAdmin.h"
#include "OAUser.h"
#include "OAMeetingRoom.h"

class OAAdmin;
class OAUser; 
class OAMeetingRoom;


class OADataCenter
{
private:
	vector<OAUser> users;
	vector<OAAdmin> admins;
	vector<OAMeetingRoom> rooms;

	OADataCenter();
	static OADataCenter _instance;

public:
	// 返回一个全局唯一对象
	static OADataCenter& getInstance();

	OAAdmin& loginAdmin(string username, string password);
	OAUser& loginUser(string username, string password);

	// 添加一个普通用户，返回表示是否添加成功，希望用户名不能重复
	bool addUser(string username, string passwd, string department);
	// 删除用户
	bool delUser(string username);

	// 添加会议室，返回时表是否添加成功
	bool addMeetingRoom(int mid, int capacity);
	// 移除会议室
	bool delMeetingRoom(int mid);
	// 清除会议室的状态
	void clearMeetingRoomStatus();


	// 预定会议室
	int bookMeetingRoom(OAUser& user, int mid);
	int cancelBookMeetingRoom(OAUser& user, int mid);


	vector<OAUser> getUsers(); 
	vector<OAMeetingRoom> getRooms();
};

