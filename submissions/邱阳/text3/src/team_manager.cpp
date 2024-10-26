#include "team_manager.h"

//构造实现
Team_Manager::Team_Manager()
{
	cout << "****************** 欢迎使用人员管理系统! *****************" << endl;
}

//析构实现
Team_Manager::~Team_Manager()
{
	cout << "********************  欢迎您下次使用！********************" << endl;
}



//主菜单
void Team_Manager::ShowMenu()
{
	cout << "----------------------------------------------------------" << endl;
	cout << "--------------------   人员管理系统   --------------------" << endl;
	cout << "--------------------    1.添加人员    --------------------" << endl;
	cout << "--------------------    2.删除人员    --------------------" << endl;
	cout << "--------------------  3.列出所有人员  --------------------" << endl;
	cout << "--------------------  4.修改人员信息  --------------------" << endl;
	cout << "--------------------  5.查询考勤信息  --------------------" << endl;
	cout << "--------------------  6.修改考勤信息  --------------------" << endl;
	cout << "--------------------    7.退出系统    --------------------" << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "********************  请输入您的选择: ********************" << endl;

}

   
//考勤菜单
void Team_Manager::attendance_info(Attendance& A)
{
	cout << "成功进入该对象的考勤信息操作页。" << endl;
	system("pause");
	system("cls");

	while (1)
	{
		cout << "请选择操作:" << endl;
		cout << "======================" << endl;
		cout << "0.退出修改。" << endl;
		cout << "1.上下班打卡。" << endl;
		cout << "2.删除考勤信息。" << endl;
		cout << "3.更新考勤信息。" << endl;
		cout << "请输入您的选择:";

		int choice;
		cin >> choice;
		switch (choice)
		{
			//退出程序
		case 0:
			system("pause");
			system("cls");
			return;
			//添加考勤信息
		case 1:
			A.check_time_get();
			break;
			//删除考勤信息
		case 2:
			A.clear_all_records();
			break;
			//更新考勤信息
		case 3:
			A.change_update();
			system("pause");
			system("cls");
			break;
		default:
			cout << "输入有误，请重新输入。";
			system("pause");
			system("cls");
			break;
		}
	}
}

//考勤信息显示
void Team_Manager::show_info(Member& M)
{
	if (M.exit_members.size() == 0)
	{
		cout << "目前无队员信息，请添加。" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		system("cls");

		//输入验证
		while (1)
		{
			cout << "以下为全部可考勤队员:" << endl;
			for (int i = 0; i < M.exit_members.size(); i++)
			{
				wcout << "学号:" << M.exit_members[i].get_id()
					<< "\t姓名:" << M.exit_members[i].get_name() << endl;

				//if (MAmap.find(M.exit_members[i].get_id()) == MAmap.end())
				//{
				//	MAmap[M.exit_members[i].get_id()] = Attendance();
				//}
			}

			long long int MAinput;
			cout << "请选择欲查询对象(学号): ";
			cin >> MAinput;

			if (MAis_id_exist(M.exit_members, MAinput))
			{
				MAmap[MAinput].print_all_record();
				return;
			}
			else
			{
				cout << "输入有误，请重新输入。" << endl;
				system("pause");
				system("cls");
			}
		}
	}
}

//判断学号是否存在
bool Team_Manager::MAis_id_exist(vector<Member>& exit_members, const long long int& MAinput)
{
	for (int i = 0; i < exit_members.size(); i++)
	{
		if (exit_members[i].get_id() == MAinput)
		{
			return true;
		}
	}
	return false;
}

//修改考勤信息
void Team_Manager::modify_MAInfo(Member& M)
{
	if (M.exit_members.size() == 0)
	{
		cout << "目前无队员信息，请添加。" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		system("cls");

		//输入验证
		while (1)
		{
			cout << "以下为全部可考勤队员:" << endl;
			for (int i = 0; i < M.exit_members.size(); i++)
			{	
				wcout << "学号:" << M.exit_members[i].get_id()
					<< "\t姓名:" << M.exit_members[i].get_name() << endl;
				//if (MAmap.find(M.exit_members[i].get_id()) == MAmap.end())
				//{
				//	MAmap[M.exit_members[i].get_id()] = Attendance();
				//}
			}

			long long int MAinput;
			cout << "请选择考勤对象(学号): ";
			cin >> MAinput;

			if (MAis_id_exist(M.exit_members, MAinput))
			{	
				attendance_info(MAmap[MAinput]);
				return;
			}
			else
			{
				cout << "输入有误，请重新输入。" << endl;
				system("pause");
				system("cls");
			}
		}
	}
}


