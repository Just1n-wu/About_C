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
	// ����һ��ȫ��Ψһ����
	static OADataCenter& getInstance();

	OAAdmin& loginAdmin(string username, string password);
	OAUser& loginUser(string username, string password);

	// ���һ����ͨ�û������ر�ʾ�Ƿ���ӳɹ���ϣ���û��������ظ�
	bool addUser(string username, string passwd, string department);
	// ɾ���û�
	bool delUser(string username);

	// ��ӻ����ң�����ʱ���Ƿ���ӳɹ�
	bool addMeetingRoom(int mid, int capacity);
	// �Ƴ�������
	bool delMeetingRoom(int mid);
	// ��������ҵ�״̬
	void clearMeetingRoomStatus();


	// Ԥ��������
	int bookMeetingRoom(OAUser& user, int mid);
	int cancelBookMeetingRoom(OAUser& user, int mid);


	vector<OAUser> getUsers(); 
	vector<OAMeetingRoom> getRooms();
};

