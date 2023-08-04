#include <iostream>
#include <string>
#include "OASystemUI.h"
#include "OAUtils.h"
#include "OADataCenter.h"
using namespace std;


void showAdminAddUserPage(OAAdmin& admin)
{
	system("cls");
	string username, password, department;
	cout << "请输入需要添加的用户名：";
	cin >> username;
	cout << "请输入添加用户名的密码：";
	cin >> password;
	cout << "请输入该用户的所属部门：";
	cin >> department;

	if (admin.addUser(username, password, department)) {
		cout << "添加成功！" << endl;
	}
	else {
		cout << "添加失败，该用户已存在！" << endl;
	}

	system("pause"); 
}

void showAdminDeleteUserPage(OAAdmin& admin)
{
	system("cls");
	string username;
	cout << "请输入需要删除的用户：";
	cin >> username;

	if (admin.delUser(username))
	{
		cout << "删除成功！" << endl;
	}
	else {
		cout << "删除失败，该用户未找到！" << endl;
	}

}

void showAdminListUsers(OAAdmin& admin)
{
	admin.showA11Users();
}

void showAdminAddMeetingRoomPage(OAAdmin& admin)
{
	system("cls");
	int mid, capacity;
	cout << "请输入需要添加的会议室编号：";
	mid = OAUtils::inputNumber(); 
	cout << "请输入需要添加会议室的容量：";
	capacity = OAUtils::inputNumber(); 

	if (admin.addRoom(mid, capacity))
	{
		cout << "添加成功！" << endl;
	}
	else {
		cout << "添加失败，会议室已存在！" << endl; 
	}
}

// 删除会议室
void showAdminDeleteMeetingRoomPage(OAAdmin& admin)
{
	system("cls");
	int mid;
	cout << "请输入需要删除的会议室编号：";
	mid = OAUtils::inputNumber();

	if (admin.delRoom(mid))
	{
		cout << "删除成功！" << endl;
	}
	else {
		cout << "删除失败，该会议室不存在！" << endl;
	}

}

// 显示管理员的主界面
void showAdminMainPage(OAAdmin& admin)
{
	while (1) {
		system("cls");
		cout << "欢迎管理员用户：" << admin.username() << endl;
		cout << "+-------------------------+" << endl;
		cout << "|     1. 添加普通用户     |" << endl;
		cout << "|     2. 删除普通用户     |" << endl;
		cout << "|     3. 查看普通用户     |" << endl;
		cout << "|     4. 添加会议室       |" << endl;
		cout << "|     5. 删除会议室       |" << endl;
		cout << "|     6. 查询会议室       |" << endl;
		cout << "|     7. 重置会议室       |" << endl;
		cout << "|     8. 退出当前账号     |" << endl;
		cout << "+-------------------------+" << endl;
		cout << "请输入您的选择：";

		int c = OAUtils::inputNumber();

		switch (c)
		{
		case 1:
			showAdminAddUserPage(admin);
			break;
		case 2:
			showAdminDeleteUserPage(admin);
			break;
		case 3:
			showAdminListUsers(admin);
			break;
		case 4:
			showAdminAddMeetingRoomPage(admin);
			break;
		case 5:
			showAdminDeleteMeetingRoomPage(admin);
			break;
		case 6:
			system("cls"); 
			admin.showA11Rooms();
			break;
		case 7:
			admin.clrRoomStatus();
			break;
		case 8:
			goto end;
		}

		system("pause");
	}
end:
	cout << "欢迎下次使用！" << endl;
}

// 用户预定会议室
void showUserBookMeekingRoomPage(OAUser& user)
{
	system("cls");
	cout << "请输入您要预定的会议室：";
	int mid = OAUtils::inputNumber();

	// 预定会议室
	int res = user.bookMeetingRoom(mid);
	if (res == BOOK_SUCCESS)
	{
		cout << "预定成功！" << endl;
	}
	else if (res == MEETING_ROOM_BOOKED)
	{
		cout << "预定失败，该会议室已经被预定！" << endl;
	}
	else if (res == MEETING_ROOM_NOT_FOUND)
	{
		cout << "预定失败，该会议室不存在！" << endl;
	} 
}

// 取消预定会议室
void showUserCancelBookMeetingRoom(OAUser& user)
{
	system("cls");
	cout << "请输入您要取消的会议室：";
	int mid = OAUtils::inputNumber();

	int res = user.cancelBookMeetingRoom(mid);
	if (res == CANCEL_MEETING_SUCCESS)
		cout << "取消预订成功！" << endl;
	else if (res == CANCEL_MEETING_FAIL)
		cout << "取消失败，该会议室您没有预定。" << endl;
	else if (res == CANCEL_MEETING_NOT_FOUND)
		cout << "取消失败，该会议室不存在。" << endl;
}

void showUserMainPage(OAUser& user)
{
	while (1) {
		system("cls");
		cout << "欢迎" << user.department() << "的用户：" << user.username() << endl;
		cout << "+-------------------------+" << endl;
		cout << "|     1. 预定会议室       |" << endl;
		cout << "|     2. 取消会议室       |" << endl;
		cout << "|     3. 查询会议室       |" << endl;
		cout << "|     4. 退出当前账号     |" << endl;
		cout << "+-------------------------+" << endl;
		cout << "请输入您的选择：";

		int c = OAUtils::inputNumber();
		switch (c)
		{
		case 1:
			showUserBookMeekingRoomPage(user);
			break; 
		case 2:
			showUserCancelBookMeetingRoom(user);
			break;
		case 3:
			system("cls");
			user.showA11B00kedMeetingRooms();
			break;
		case 4:
			goto end;
		}
		system("pause");
	}
end:
	cout << "欢迎下次使用！" << endl;
}

// 显示登录界面， flag表示身份 ==> 1. 管理员  0. 普通
void showLogin(int flag)
{
	system("cls");

	if (flag == FLAG_ADMIN)
	{
		cout << "\t管理员登录" << endl;
	}
	else 
	{
		cout << "\t普通用户登录" << endl;
	}
	cout << "+-------------------------+" << endl;
	string username, password;
	cout << "请输入用户名：";
	cin >> username;

	cout << "请输入密码：";
	cin >> password;

	OADataCenter& dataCenter = OADataCenter::getInstance();

	if (flag == FLAG_ADMIN)
	{
		OAAdmin& admin = dataCenter.loginAdmin(username, password);
		if (&admin == &(OAAdmin::ERROR_ADMIN))
		{
			cout << "登录失败，回到上一层。" << endl;
		}
		else
		{
			//cout << "登录成功！欢迎管理员用户：" << admin.username() << endl;
			showAdminMainPage(admin);
		}
	}
	else 
	{
		OAUser& user = dataCenter.loginUser(username, password); 
		if (&user == &(OAUser::ERROR_USER))
		{
			cout << "登录失败，回到上一层。" << endl;
		}
		else
		{
			showUserMainPage(user);
		}
	}
}

void OASystemUI::displayMainPage()
{
	while (1) 
	{
		cout << " 欢迎使用OA会议室预定系统!" << endl;
		cout << "+-------------------------+" << endl;
		cout << "|     1. 管理员登录       |" << endl;
		cout << "|     2. 普通用户登录     |" << endl;
		cout << "|     3. 退出系统         |" << endl;
		cout << "+-------------------------+" << endl;
		cout << "请输入您的选择：";

		// 让用户进行控制台的输入选择
		int choice = OAUtils::inputNumber();

		switch (choice)
		{
		case 1:
			showLogin(FLAG_ADMIN);
			break;
		case 2:
			showLogin(FLAG_USER);
			break;
		case 3:
			goto end;
			// break;
		}
		system("pause");
		system("cls");
	}
end:
	cout << "欢迎下次使用!" << endl;
}
