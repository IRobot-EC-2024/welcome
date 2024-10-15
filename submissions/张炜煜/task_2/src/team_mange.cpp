#include "team_mange.h"
//总系统：主界面，列出成员，列出考勤信息

using namespace std;
Menu_Options choices;
member members;
attendance attendances;
int Menu_Select(void)		//选择函数，选项为返回值，选错返回值为-1，
{	
	cout << "      人员管理系统"       << endl;
	cout << "=======================" << endl;
	cout << "1.添加人员" << endl;
	cout << "2.删除人员" << endl;
	cout << "3.列出所有人员" << endl;
	cout << "4.修改人员信息" << endl;
	cout << "5.查询考勤信息" << endl;
	cout << "6.修改考勤信息" << endl;
	cout << "0.退出" << endl;
	cout << "请输入您的选择:";

	wstring choice;
	getline(wcin, choice);
	choice.erase(remove_if(choice.begin(), choice.end(), ::isspace), choice.end());

	if (choice.length() == 1 && all_of(choice.begin(), choice.end(), ::isdigit))	//判断
	{
		if(stoi(choice)>=0 && stoi(choice) <= 6)
		{
			system("cls");
			return stoi(choice);
		}else{
			cout << "\n无此选项,请重新输入。";	//输入数字超限
			system("pause");
			
			return -1;				
		}		
	}else{
		cout << "\n无效输入,请按提示输入数字";	//输入非数字
		system("pause");
		system("cls");
		return -1;
	}
}


void Menu_Option(int choice)	//执行函数，执行各个命令
{	
	
	switch (choice)
	{	
		case quit:
			break;
		case entry_member:						
			members.AddMember();
			system("pause");
			system("cls");
			break;
		case remove_member:
			members.DeleteMember();
			break;
		case print_members:
			system("cls");
			PrintMembers();
			system("pause");
			system("cls");
			break;
		case revise_members:
			members.ChangeMember();
			break;
		case read_attendence:
			attendances.Show_Attendance();
			break;
		case revise_attendence:
			attendances.Clock_In();
			break;				
		default:
			break;
	}

}


