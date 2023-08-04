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
	cout << "��������Ҫ��ӵ��û�����";
	cin >> username;
	cout << "����������û��������룺";
	cin >> password;
	cout << "��������û����������ţ�";
	cin >> department;

	if (admin.addUser(username, password, department)) {
		cout << "��ӳɹ���" << endl;
	}
	else {
		cout << "���ʧ�ܣ����û��Ѵ��ڣ�" << endl;
	}

	system("pause"); 
}

void showAdminDeleteUserPage(OAAdmin& admin)
{
	system("cls");
	string username;
	cout << "��������Ҫɾ�����û���";
	cin >> username;

	if (admin.delUser(username))
	{
		cout << "ɾ���ɹ���" << endl;
	}
	else {
		cout << "ɾ��ʧ�ܣ����û�δ�ҵ���" << endl;
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
	cout << "��������Ҫ��ӵĻ����ұ�ţ�";
	mid = OAUtils::inputNumber(); 
	cout << "��������Ҫ��ӻ����ҵ�������";
	capacity = OAUtils::inputNumber(); 

	if (admin.addRoom(mid, capacity))
	{
		cout << "��ӳɹ���" << endl;
	}
	else {
		cout << "���ʧ�ܣ��������Ѵ��ڣ�" << endl; 
	}
}

// ɾ��������
void showAdminDeleteMeetingRoomPage(OAAdmin& admin)
{
	system("cls");
	int mid;
	cout << "��������Ҫɾ���Ļ����ұ�ţ�";
	mid = OAUtils::inputNumber();

	if (admin.delRoom(mid))
	{
		cout << "ɾ���ɹ���" << endl;
	}
	else {
		cout << "ɾ��ʧ�ܣ��û����Ҳ����ڣ�" << endl;
	}

}

// ��ʾ����Ա��������
void showAdminMainPage(OAAdmin& admin)
{
	while (1) {
		system("cls");
		cout << "��ӭ����Ա�û���" << admin.username() << endl;
		cout << "+-------------------------+" << endl;
		cout << "|     1. �����ͨ�û�     |" << endl;
		cout << "|     2. ɾ����ͨ�û�     |" << endl;
		cout << "|     3. �鿴��ͨ�û�     |" << endl;
		cout << "|     4. ��ӻ�����       |" << endl;
		cout << "|     5. ɾ��������       |" << endl;
		cout << "|     6. ��ѯ������       |" << endl;
		cout << "|     7. ���û�����       |" << endl;
		cout << "|     8. �˳���ǰ�˺�     |" << endl;
		cout << "+-------------------------+" << endl;
		cout << "����������ѡ��";

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
	cout << "��ӭ�´�ʹ�ã�" << endl;
}

// �û�Ԥ��������
void showUserBookMeekingRoomPage(OAUser& user)
{
	system("cls");
	cout << "��������ҪԤ���Ļ����ң�";
	int mid = OAUtils::inputNumber();

	// Ԥ��������
	int res = user.bookMeetingRoom(mid);
	if (res == BOOK_SUCCESS)
	{
		cout << "Ԥ���ɹ���" << endl;
	}
	else if (res == MEETING_ROOM_BOOKED)
	{
		cout << "Ԥ��ʧ�ܣ��û������Ѿ���Ԥ����" << endl;
	}
	else if (res == MEETING_ROOM_NOT_FOUND)
	{
		cout << "Ԥ��ʧ�ܣ��û����Ҳ����ڣ�" << endl;
	} 
}

// ȡ��Ԥ��������
void showUserCancelBookMeetingRoom(OAUser& user)
{
	system("cls");
	cout << "��������Ҫȡ���Ļ����ң�";
	int mid = OAUtils::inputNumber();

	int res = user.cancelBookMeetingRoom(mid);
	if (res == CANCEL_MEETING_SUCCESS)
		cout << "ȡ��Ԥ���ɹ���" << endl;
	else if (res == CANCEL_MEETING_FAIL)
		cout << "ȡ��ʧ�ܣ��û�������û��Ԥ����" << endl;
	else if (res == CANCEL_MEETING_NOT_FOUND)
		cout << "ȡ��ʧ�ܣ��û����Ҳ����ڡ�" << endl;
}

void showUserMainPage(OAUser& user)
{
	while (1) {
		system("cls");
		cout << "��ӭ" << user.department() << "���û���" << user.username() << endl;
		cout << "+-------------------------+" << endl;
		cout << "|     1. Ԥ��������       |" << endl;
		cout << "|     2. ȡ��������       |" << endl;
		cout << "|     3. ��ѯ������       |" << endl;
		cout << "|     4. �˳���ǰ�˺�     |" << endl;
		cout << "+-------------------------+" << endl;
		cout << "����������ѡ��";

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
	cout << "��ӭ�´�ʹ�ã�" << endl;
}

// ��ʾ��¼���棬 flag��ʾ��� ==> 1. ����Ա  0. ��ͨ
void showLogin(int flag)
{
	system("cls");

	if (flag == FLAG_ADMIN)
	{
		cout << "\t����Ա��¼" << endl;
	}
	else 
	{
		cout << "\t��ͨ�û���¼" << endl;
	}
	cout << "+-------------------------+" << endl;
	string username, password;
	cout << "�������û�����";
	cin >> username;

	cout << "���������룺";
	cin >> password;

	OADataCenter& dataCenter = OADataCenter::getInstance();

	if (flag == FLAG_ADMIN)
	{
		OAAdmin& admin = dataCenter.loginAdmin(username, password);
		if (&admin == &(OAAdmin::ERROR_ADMIN))
		{
			cout << "��¼ʧ�ܣ��ص���һ�㡣" << endl;
		}
		else
		{
			//cout << "��¼�ɹ�����ӭ����Ա�û���" << admin.username() << endl;
			showAdminMainPage(admin);
		}
	}
	else 
	{
		OAUser& user = dataCenter.loginUser(username, password); 
		if (&user == &(OAUser::ERROR_USER))
		{
			cout << "��¼ʧ�ܣ��ص���һ�㡣" << endl;
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
		cout << " ��ӭʹ��OA������Ԥ��ϵͳ!" << endl;
		cout << "+-------------------------+" << endl;
		cout << "|     1. ����Ա��¼       |" << endl;
		cout << "|     2. ��ͨ�û���¼     |" << endl;
		cout << "|     3. �˳�ϵͳ         |" << endl;
		cout << "+-------------------------+" << endl;
		cout << "����������ѡ��";

		// ���û����п���̨������ѡ��
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
	cout << "��ӭ�´�ʹ��!" << endl;
}
