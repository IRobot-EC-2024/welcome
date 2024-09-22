#include "Team_Manager.h"

void modifyAttendanceInfo(Attendance& testAttendance);
bool MAisExistent(vector<Member>& membersVector, const wstring& name);

/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

// 构造实现
Team_Manager::Team_Manager()
{
	cout << "进入系统，欢迎您的使用！" << endl;
}

// 析构实现
Team_Manager::~Team_Manager()
{
	cout << "退出程序。欢迎您的再次使用！" << endl;
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

// 主菜单
void Team_Manager::ShowMenu()
{
	while (true)
	{
		cout << "人员管理系统" << endl;
		cout << "=====================" << endl;
		cout << "1.添加人员" << endl;
		cout << "2.删除人员" << endl;
		cout << "3.列出所有人员" << endl;
		cout << "4.修改人员信息" << endl;
		cout << "5.查询考勤信息" << endl;
		cout << "6.修改考勤信息" << endl;
		cout << "7.退出" << endl;
		cout << "请输入您的选择:";

		wstring choice;
		getline(wcin, choice);
		choice.erase(remove_if(choice.begin(), choice.end(), ::isspace), choice.end());			// 清除字符串空格

		// 格式验证
		if (choice.length() == 1 && all_of(choice.begin(), choice.end(), ::isdigit))
		{
			switch (stoi(choice))
			{
				// 添加战队人员
			case 1:
				testMember.addMember();
				break;
				//	删除战队人员
			case 2:
				testMember.deleteMember();
				break;
				//	列出所有战队人员的信息
			case 3:
				testMember.sortedPrintInfo();
				break;
				//	修改战队人员信息
			case 4:
				testMember.modifyMemInfo();
				break;
				//	查询考勤信息
			case 5:
				ShowMAInfo(testMember);
				break;
				// 修改考勤信息(增删改)
			case 6:
				ModifyMAInfo(testMember);
				break;
				//	退出程序
			case 7:return;
				//	用户输入非选项数字处理
			default:
				cout << "\n无效选项，请重新输入。";
				system("pause");
				system("cls");
				break;
			}
		}
		else
		{
			cout << "\n输入无效，请按提示输入数字。";
			system("pause");
			system("cls");
		}
	}
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

// 考勤信息输出显示
void Team_Manager::ShowMAInfo(Member& testMember)
{
	if (testMember.membersVector.size() == 0)
	{
		cout << "目前无队员信息，请添加。" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		system("cls");		// 清屏，便于查看

		// 输入验证
		while (true)
		{
			cout << "以下为全部可考勤队员:" << endl;
			for (int i = 0; i < testMember.membersVector.size(); i++)
			{
				wcout << "学号:" << testMember.membersVector[i].GetStudentID()
					<< "\t姓名:" << testMember.membersVector[i].GetName() << endl;

				if (MAmap.find(testMember.membersVector[i].GetStudentID()) == MAmap.end())
				{
					MAmap[testMember.membersVector[i].GetStudentID()] = Attendance();
				}
			}

			wstring MAinput;
			cout << "\n请选择欲查询对象(学号): ";
			getline(wcin, MAinput);
			MAinput.erase(remove_if(MAinput.begin(), MAinput.end(), ::isspace), MAinput.end());

			if (MAisExistent(testMember.membersVector, MAinput))
			{
				MAmap[MAinput].PrintAllAttendanceInfo();
				return;
			}
			else
			{
				cout << "输入无效，请按提示重新输入。" << endl;
				system("pause");
				system("cls");
			}
		}
	}
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

// 修改考勤信息菜单
void modifyAttendanceInfo(Attendance& AttendanceObj)
{
	cout << "成功进入该对象的考勤信息操作页。" << endl;
	system("pause");
	system("cls");

	while (true)
	{
		cout << "请选择操作:" << endl;
		cout << "======================" << endl;
		cout << "1.添加考勤信息" << endl;
		cout << "2.删除考勤信息" << endl;
		cout << "3.更新考勤信息" << endl;
		cout << "4.退出修改" << endl;
		cout << "请输入您的选择:";

		wstring choice;
		getline(wcin, choice);
		choice.erase(remove_if(choice.begin(), choice.end(), ::isspace), choice.end());			// 清除字符串空格

		// 格式验证
		if (choice.length() == 1 && all_of(choice.begin(), choice.end(), ::isdigit))
		{
			switch (stoi(choice))
			{
				// 添加考勤信息
			case 1:
				AttendanceObj.SetRecordValue();
				break;
				//删除考勤信息
			case 2:
				AttendanceObj.ClearAllRecords();
				break;
				// 更新考勤信息
			case 3:
				AttendanceObj.updateAttendanceInfo();
				break;
				// 退出程序
			case 4:
				system("pause");
				system("cls");
				return;
				// 用户输入非选项数字处理
			default:
				cout << "\n无效选项，请重新输入。";
				system("pause");
				system("cls");
				break;
			}
		}
		else
		{
			cout << "\n输入无效，请按提示输入数字。";
			system("pause");
			system("cls");
		}
	}
}

// 修改考勤信息:学号存在性判断
bool MAisExistent(vector<Member>& membersVector, const wstring& MAinput)
{
	for (int i = 0; i < membersVector.size(); i++)
	{
		if (membersVector[i].GetStudentID() == MAinput)
		{
			return true;
		}
	}
	return false;
}

// 修改考勤信息:选择操作对象
void Team_Manager::ModifyMAInfo(Member& testMember)
{
	if (testMember.membersVector.size() == 0)
	{
		cout << "目前无队员信息，请添加。" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		system("cls");		// 清屏，便于查看

		// 输入验证
		while (true)
		{
			cout << "以下为全部可考勤队员:" << endl;
			for (int i = 0; i < testMember.membersVector.size(); i++)
			{	
				wcout << "学号:" << testMember.membersVector[i].GetStudentID()
					<< "\t姓名:" << testMember.membersVector[i].GetName() << endl;
				if (MAmap.find(testMember.membersVector[i].GetStudentID()) == MAmap.end())
				{
					MAmap[testMember.membersVector[i].GetStudentID()] = Attendance();
				}
			}

			wstring MAinput;
			cout << "\n请选择考勤对象(学号): ";
			getline(wcin, MAinput);
			MAinput.erase(remove_if(MAinput.begin(), MAinput.end(), ::isspace), MAinput.end());

			if (MAisExistent(testMember.membersVector, MAinput))
			{	
				modifyAttendanceInfo(MAmap[MAinput]);
				return;
			}
			else
			{
				cout << "输入无效，请按提示重新输入。" << endl;
				system("pause");
				system("cls");
			}
		}
	}
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------*/
