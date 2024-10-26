#include "members.h"
using namespace std;

//排序方式
bool up_id(Member& a, Member& b);
bool down_id(Member& a, Member& b);
bool up_join_time(Member& a, Member& b);
bool down_join_time(Member& a, Member& b);

//默认构造
Member::Member(){}
//构造函数
Member::Member(long long int id, wstring name, int year, int month):
	ID(id),
	name(name),
	YEAR(year), MONTH(month){}

//添加
void Member::add_member()
{	
	long long int input_id = 0;
	wstring input_name;
	int year, month;

	//学号
	while (1)
	{
		system("cls");
		cout << "请输入新队员的学号:" << endl;
		cin >> input_id;

		if (input_id >= 10000000000 && input_id <= 99999999999) 
		{
			if (id_is_unique(exit_members, input_id))
			{
				ID = input_id;
				break;
			}
			else
			{
				cout << "学号重复，请重新输入。" << endl;
				system("pause");
			}
		}
		else
		{
			cout << "学号格式不正确，请重新输入。" << endl;
			system("pause");
		}
	}

	//姓名
	while (1)
	{
		system("cls");
		cout << "请输入新队员姓名:" << endl;
		wcin >> input_name;

		if (input_name.empty())
		{
			cout << "姓名不能为空，请重新输入。" << endl;
		}
		else 
		{ 
			if (name_is_unique(exit_members, input_name))
			{
				name = input_name;
				break;
			}
			else
			{
				cout << "姓名重复，请重新输入。" << endl;
				system("pause");
			}
		}
	}
	//入队年份验证
	while (1)
	{	
		system("cls");
		cout << "请输入入队年份:" << endl;
		cin >> year;

		if (year >= 2016 && year <= 2024)
		{
			YEAR = year; 
			break;
		} 
		else
		{
			cout << "输入年份有误，请输入合理的年份。" << endl;
			system("pause");
		}
	} 
	//入队月份验证
	while (1)
	{
		system("cls");
		cout << "请输入入队月份:" << endl;
		cin >> month;

		if (month >= 1 && month <= 12)
		{
			MONTH = month;
			break;
		} 
		else
		{
			cout << "输入月份有误，请输入正确的月份。" << endl;
			system("pause");
		}
	}

	Member new_member(ID, name, YEAR, MONTH);
	exit_members.push_back(new_member);
	system("cls");
	cout << "新队员信息添加成功！" << endl;
	system("pause");
	system("cls");
}

//学号唯一性判断
bool Member::id_is_unique(vector<Member>& exit_members,const long long int& id)
{
	bool unique = true;
	for (int i = 0; i < exit_members.size(); i ++)
	{
		if(exit_members[i].get_id() == id)
		{
			unique = false;
			break;
		}
	}
	return unique;
}
//姓名唯一性判断
bool Member::name_is_unique(vector<Member>& exit_members, const wstring& name)
{
	bool unique = true;
	for (int i = 0; i < exit_members.size(); i++)
	{
		if (exit_members[i].get_name() == name)
		{
			unique = false;
			break;
		}
	}
	return unique;
}

//删除
void Member::delete_member()
{	

	if (exit_members.size() == 0)
	{
		cout << "目前无队员信息，请添加。" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		system("cls");
		int back1 = 1;
		//输入匹配判断
		while (back1)
		{
			cout << "以下为现队员所有信息:" << endl;
			for (int i = 0; i < exit_members.size(); i++)
			{
				wcout << "学号: " << exit_members[i].ID
					<< "\t 姓名: " << exit_members[i].name
					<< "\t 入队年月: " << exit_members[i].YEAR << "年" << exit_members[i].MONTH << "月" << endl;
			}
			cout << "请选择查找该队员方式：\n0.返回。\n1.按学号查找。\n2.按姓名查找。" << endl;
			int choice_modity = -1;
			cin >> choice_modity;
			int index;
			long long int id = 0;
			wstring name;

			switch (choice_modity)
			{
				case 0:
				{
					back1 = 0;
					system("cls");
					break;
				}
				case 1:
				{
					//按学号查找
					system("cls");
					cout << "请输入想要删除信息的队员的学号：" << endl;
					cin >> id;
					index = exit_id(exit_members, id);
					if (index != -1)
					{
						remove_id(exit_members, id);
						print_partners_Info(exit_members);
						cout << "删除成功。" << endl;
						break;
					}
					else
					{
						cout << "查找失败，查无此人。" << endl;
						system("pause");
					}
					system("cls");
				}
				break;
				case 2:
				{
					//按姓名查找
					system("cls");
					cout << "请输入想要删除信息的队员的姓名：" << endl;
					wcin >> name;
					index = exit_name(exit_members, name);
					if (index != -1)
					{
						remove_name(exit_members, name);
						print_partners_Info(exit_members);
						cout << "删除成功。" << endl;
						break;
					}
					else
					{
						cout << "查找失败，查无此人。" << endl;
						system("pause");
					}
					system("cls");
				}
				break;
				default:
				{
					cout << "输入有误，请重新输入。" << endl;
					system("pause");
					system("cls");
				}
			}
		}
	}
}

//Vector元素删除
void Member::remove_id(vector<Member>& exit_members, const long long int& identifier)//学号
{
	long long int id =identifier;
	for (auto it = exit_members.begin(); it != exit_members.end();)
	{
		if (it->get_id() == long long int(id))
		{
			it = exit_members.erase(it);
		}
		else
		{
			++it;
		}
	}
}
void Member::remove_name(vector<Member>&exit_members, const wstring& identifier)//姓名
{
	wstring name = identifier;
	for (auto it = exit_members.begin(); it != exit_members.end(); )
	{
		if (it -> get_name() == identifier)
		{
			it = exit_members.erase(it);
		}
		else 
		{ 
			++it; 
		}
	}
	cout << "删除成功!下面是剩余所有队员的信息。" << endl;
	system("pause");
	system("cls");
}

//排序显示
void Member::sort_print()
{	
	if (exit_members.size() == 0)
	{
		cout << "目前无队员信息，请添加。" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		while (1)
		{
			system("cls");
			cout << "请选择其中一种排序方式列出信息。" << endl;
			cout << "0.返回。" << endl;
			cout << "1.按学号升序排列。" << endl;
			cout << "2.按学号降序排列。" << endl;
			cout << "3.按入队年月升序排列。" << endl;
			cout << "4.按入队年月降序排列。" << endl;
			cout << "请输入您的选择:" << endl;
			
			int sort_choice;
			cin >> sort_choice;

			switch (sort_choice)
			{
			case 0:
				system("cls");
				return;
			case 1:
				sort(exit_members.begin(), exit_members.end(), up_id);
				print_partners_Info(exit_members);
				break;
			case 2:
				sort(exit_members.begin(), exit_members.end(), up_join_time);
				print_partners_Info(exit_members);
				break;
			case 3:
				sort(exit_members.begin(), exit_members.end(), down_id);
				print_partners_Info(exit_members);
				break;
			case 4:
				sort(exit_members.begin(), exit_members.end(), down_join_time);
				print_partners_Info(exit_members);
				break;
			default:
				cout << "无效选项，请重新输入。" << endl;
				system("pause");
				system("cls");
				break;
			}
		} 
	}
}

//输出信息
void Member::print_partners_Info(vector<Member>& exit_members)
{

	if(exit_members.size() == 0)
	{
		cout << "目前无队员信息，请添加。" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		system("cls");

		cout << "以下即为现队员所有信息:" << endl;
		for (int i = 0; i < exit_members.size(); i++)
		{
			wcout << "学号:" << exit_members[i].get_id()
				<< " 姓名:" << exit_members[i].get_name()
				<< " 入队年月:" << exit_members[i].get_year() << "年" << exit_members[i].get_month() << "月" << endl;
		}

		cout << "按任意键回到菜单。";
		system("pause");
		system("cls");
	}
}

//排序
//学号升序
bool up_id(Member& a, Member& b)
{
	return a.get_id() < b.get_id();
}
//学号降序
bool down_id(Member& a, Member& b)
{
	return a.get_id() > b.get_id();
}
//入队日期升序
bool up_join_time(Member& a, Member& b)
{
	if (a.get_year() != b.get_year())
	{
		return a.get_year() < b.get_year();
	}
	else
	{
		return a.get_month() < b.get_month();
	}
}
//入队日期降序
bool down_join_time(Member& a, Member& b)
{
	if (a.get_year() != b.get_year())
	{
		return a.get_year() > b.get_year();
	}
	else
	{
		return a.get_month() > b.get_month();
	}
}

//修改
void Member::modifyMemInfo()
{

	if (exit_members.size() == 0)
	{
		cout << "目前无队员信息，请添加。" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		long long int input_id;
		wstring input_name;
		int Index = 0;
		int back1 = 1;
		int choice_find;
		while(back1)
		{
			system("cls");
			//显示队员列表
			cout << "以下为现队员所有信息:" << endl;
			for (int i = 0; i < exit_members.size(); i++)
			{
				wcout << "学号: " << exit_members[i].ID
					<< "\t 姓名: " << exit_members[i].name
					<< "\t 入队年月: " << exit_members[i].YEAR << "年" << exit_members[i].MONTH << "月" << endl;
			}
			cout << "请输入您想要查询队员的方式：\n0.返回。\n1.按学号查找。\n2.按姓名查找。" << endl;
			cin >> choice_find;
			switch(choice_find)
			{
			case 0:
				system("cls");
				back1 = 0;
				break;
			case 1:
				while(1)
				{
					cout << "请输入想要修改信息的队员的学号。" << endl;
					cin >> input_id;
					//验证学号是否存在
					if (ID >= 10000000000 && ID <= 99999999999)
					{
						if (is_id_exist(exit_members, input_id, Index))
						{
							back1 = 0;
							break;
						}
						else
						{
							cout << "您输入的学号不存在，请重新输入。" << endl;
							system("pause");
							system("cls");
						}
					}
					else
					{
						cout << "学号格式不正确，请重新输入。" << endl;
						system("pause");
					}
				}
				break;
			case 2:
				while(1)
				{
					cout << "请输入想要修改信息的队员的姓名。" << endl;
					wcin >> input_name;
					//验证姓名是否存在
					if (is_name_exist(exit_members, input_name, Index))
					{
						back1 = 0;
						break;
					}
					else
					{
						cout << "您输入的学号不存在，请重新输入。" << endl;
						system("pause");
						system("cls");
					}
				}
				break;
			default:
				cout << "输入有误，请重新输入。" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		//修改主体部分
		long long int input_new_id;
		wstring	input_new_name;
		int new_year, new_month;
		int back2 = 1;
		while(back2)
		{
			system("cls");
			//选择修改的内容
			int choice_sort;
			cout << "请输入您的选择" << endl;
			cout << "0.返回。\n1.更改学号。\n2.更改姓名。\n3.更改入队年份。\n4.更改入队月份。" << endl;
			cin >> choice_sort;

			switch (choice_sort)
			{
			case 0:
				back2 = 0;
				system("cls");
				break;
			case 1:
				while(1)
				{
					system("cls");
					cout << "请输入新的队员学号: ";
					cin >> input_new_id;
					if (input_new_id >= 10000000000 && input_new_id <= 99999999999)
					{
						if (id_is_unique(exit_members, input_new_id))
						{
							exit_members[Index].ID = input_new_id;
							cout << "修改成功。" << endl;
							system("pause");
							break;
						}
						else
						{
							cout << "学号重复，请重新输入。" << endl;
							system("pause");
						}
					}
					else
					{
						cout << "学号格式不正确，请重新输入。" << endl;
						system("pause");
					}
				}
			case 2:
				while (1)
				{
					system("cls");

					cout << "请输新的队员姓名: ";
					wcin >> input_new_name;
					if (!input_new_name.empty())
					{
						if (name_is_unique(exit_members, input_new_name))
						{
							exit_members[Index].name = input_new_name;
							cout << "修改成功。" << endl;
							system("pause");
							break;
						}
						else
						{
							cout << "姓名重复，请重新输入。" << endl;
							system("pause");
						}
					}
					else
					{
						cout << "姓名不能为空，请重新输入。" << endl;
					}
				}
			case 3:
				while (1)
				{
					system("cls");
					cout << "请输入新的入队年份: ";
					cin >> new_year;
					if (new_year >= 2016 && new_year <= 2025)
					{
						exit_members[Index].YEAR = new_year;
						cout << "修改成功。" << endl;
						system("pause");
						break;
					}
					else
					{
						cout << "输入年份数值有误，请重新输入。" << endl;
						system("pause");
					}
				}
			case 4:
				while (1)
				{
					system("cls");
					cout << "请输入新的入队月份: ";
					cin >> new_month;
					if (new_month >= 1 && new_month <= 12)
					{
						exit_members[Index].MONTH = new_month;
						cout << "修改成功。" << endl;
						system("pause");
						break;
					}
					else
					{
						cout << "输入月份数值有误，请重新输入。" << endl;
						system("pause");
					}
				}
			default:
				cout << "输入有误。" << endl;
				break;
			}
		system("cls");
		print_partners_Info(exit_members);
		system("cls");
		}
	}
}

//查找指定学号的队员信息
bool Member::is_id_exist( vector<Member>& exit_members, const long long int& id, int& Index)
{
	for (int i = 0; i < exit_members.size(); ++i)
	{
		if(exit_members[i].get_id() == id)
		{
			Index = i;
			return true;
		}
	}
	return false;
}
//查找指定姓名的队员信息
bool Member::is_name_exist(vector<Member>& exit_members, const wstring& name, int& Index)
{
	for (int i = 0; i < exit_members.size(); ++i)
	{
		if (exit_members[i].get_name() == name)
		{
			Index = i;
			return true;
		}
	}
	return false;
}


//判断队员是否存在，并返回相应队员数组中的位置
int Member::exit_id(vector<Member>& exit_members, const long long int& input)//学号
{
	int index = -1;

	for (int i = 0; i < exit_members.size(); i++)
	{
		if (exit_members[i].get_id() == input)
		{
			index = i;
			break;
		}
	}
	return index;
}
int Member::exit_name(vector<Member>& exit_members, const wstring& input)//姓名

{
	int index = -1;

	for (int i = 0; i < exit_members.size(); i++)
	{
		if (exit_members[i].get_name() == input)
		{
			index = i;
			break;
		}
	}
	return index;
}

// 学号对外接口
long long int Member::get_id()const
{
	return ID;
}
void Member::set_id(long long int input_id)
{
	ID = input_id;
}

//姓名对外接口
wstring Member::get_name() const
{
	return name;
}
void Member::set_name(wstring InputName)
{
	name = InputName;
}

//入队年份对外接口
int Member::get_year() const 
{
	return YEAR; 
}
void Member::set_year(int InputYear) 
{ 
	YEAR = InputYear; 
}

//入队月份对外接口
int Member::get_month() const 
{ 
	return MONTH; 
}
void Member::set_month(int InputMonth) 
{
	MONTH = InputMonth; 
}
