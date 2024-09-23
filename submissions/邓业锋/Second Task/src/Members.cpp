#include "Members.h"

using namespace std;

// 添加:功能函数声明
bool isUniqueID(vector<Member>& membersVector, const wstring& id);
// 删除:功能函数声明
bool isMember(vector<Member>& membersVector, const wstring& input);
bool isRepeat(vector<Member>& membersVector, const wstring& name);
bool tryStringToInt(const wstring& identifier, long long& id);
void removeMem(vector<Member>& membersVector, const wstring& identifier);
// 排序显示:功能函数声明
void printMemInfo(vector<Member>& membersVector);
bool AscCompareByStudentID(Member& a, Member& b);
bool AscCompareByJoinYearMonth(Member& a, Member& b);
bool DeascCompareByStudentID( Member& a, Member& b);
bool DeascCompareByJoinYearMonth(Member& a, Member& b);
// 修改:功能函数声明
bool isExistent(vector<Member>& membersVector, const wstring& id, int& Index);
bool noModifyID();

/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

// 显式声明默认构造
Member::Member(){}
// 构造（可用this指针）
Member::Member(wstring id, wstring name, int year, int month) :
	studentID(id),
	name(name),
	enrollmentYear(year), enrollmentMonth(month){}

/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

// 添加功能的主体
void Member::addMember()
{	
	wstring input_ID;
	wstring StrYear, StrMonth;

	// 学号验证（格式加重复性验证）
	do{
		cout << "\n新队员学号（11位数字）: ";
		getline(wcin, input_ID);
		input_ID.erase(remove_if(input_ID.begin(), input_ID.end(), ::iswspace), input_ID.end());		// 去除字符串中的所有空格

		if (input_ID.length() == 11 && all_of(input_ID.begin(), input_ID.end(), ::isdigit))
		{
			if (isUniqueID(membersVector, input_ID))
			{studentID = input_ID; break;}
			else
			{
				cout << "学号重复，请重新输入。" << endl;
				system("pause");
			}
		}
		else
		{
			cout << "学号格式不正确，请输入11位数字。" << endl;
			system("pause");
		}

	}while (true);

	// 姓名验证（不为空）
	do 
	{
		cout << "\n新队员姓名: ";
		getline(wcin, name);
		name.erase(remove_if(name.begin(), name.end(), ::isspace), name.end());

		if (name.empty())
		{
			cout << "姓名不能为空，请重新输入。" << endl;;
			continue;
		}
		else { break; }

	} while (true);

	// 入队年份验证
	do {
		cout << "\n请输入入队年份: ";
		getline(wcin, StrYear);
		StrYear.erase(remove_if(StrYear.begin(), StrYear.end(), ::iswspace), StrYear.end());		// 去除字符串中的所有空格			

		if (StrYear.length() == 4 && all_of(StrYear.begin(), StrYear.end(), ::isdigit))
		{	
			if (stoi(StrYear) >= 2000 && stoi(StrYear) < 9999)
			{
				enrollmentYear = stoi(StrYear); 
				break;
			} 
			else
			{
				cout << "输入年份数值错误，请输入2000以后的4位数字。" << endl;
			}
		}
		else
		{
			cout << "输入年份格式错误，请输入2000以后的4位数字。" << endl;
		}

	} while (true);

	// 入队月份验证
	do {
		cout << "\n请输入入队月份: ";
		getline(wcin, StrMonth);
		StrMonth.erase(remove_if(StrMonth.begin(), StrMonth.end(), ::iswspace), StrMonth.end());		// 去除字符串中的所有空格

		if ((StrMonth.length() == 1 || StrMonth.length() == 2) && all_of(StrMonth.begin(), StrMonth.end(), ::isdigit))
		{	
			if (stoi(StrMonth) >= 1 && stoi(StrMonth) <= 12)
			{
				enrollmentMonth = stoi(StrMonth);
				break;
			} 
			else
			{
				cout << "输入月份数值不正确，请输入1-12间的数字。" << endl;
			}
		}
		else
		{
			cout << "输入月份格式不正确，请输入1-12间的数字。" << endl;
		}

	} while (true);

	Member newMember(studentID, name, enrollmentYear, enrollmentMonth);
	membersVector.push_back(newMember);

	cout << "\n新队员信息添加成功！" << endl;
	system("pause");
	system("cls");
}

// 添加:学号唯一性判断
bool isUniqueID(vector<Member>& membersVector,const wstring& id)
{
	bool Unique = true;
	for (int i = 0; i < membersVector.size(); i ++)
	{
		if(membersVector[i].GetStudentID() == id)
		{
			Unique = false;
			break;
		}
	}
	return Unique;
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

// 删除功能的主体
void Member::deleteMember()
{	

	if (membersVector.size() == 0)
	{
		cout << "目前无队员信息，请添加。" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		system("cls");		// 清屏，便于查看

		// 输入匹配判断
		do 
		{
			cout << "以下为现队员所有信息:" << endl;
			for (int i = 0; i < membersVector.size(); i++)
			{
				wcout << "学号: " << membersVector[i].studentID
					<< "\t 姓名: " << membersVector[i].name
					<< "\t 入队年月: " << membersVector[i].enrollmentYear << "-" << membersVector[i].enrollmentMonth << endl;
			}
			cout << "\n请输入欲删除队员的姓名或学号: ";

			wstring identifier;
			getline(wcin, identifier);
			identifier.erase(remove_if(identifier.begin(), identifier.end(), ::iswspace), identifier.end());		// 去除字符串中的所有空格

			if(isMember(membersVector, identifier))
			{
				if (!isRepeat(membersVector, identifier))
				{
					removeMem(membersVector, identifier);		// 删除队员	

					printMemInfo(membersVector);
					return;
				}
				else
				{
					cout << "含有重名，请用学号检索。" << endl;
					system("pause");
					system("cls");
				}
			}
			else
			{	
				cout << "抱歉，您输入的队员信息不存在，请按提示重新输入。" << endl;
				system("pause");
				system("cls");
			}

		} while (true);
	}
}

// 删除:输入ID或name是否匹配
bool isMember(vector<Member>& membersVector, const wstring& input)
{
	for(int i = 0; i < membersVector.size(); i++)
	{
		if(membersVector[i].GetName() == input || membersVector[i].GetStudentID() == input)
		{return true;}
	}
	return false;
}

// 删除:判断是否存在重名
bool isRepeat(vector<Member>& membersVector, const wstring& inputname)
{
	return count_if
	(
		membersVector.begin(), membersVector.end(),
		// 谓词函数
		[&inputname](Member& testmember)
		{
			return testmember.GetName() == inputname;
		}
	) > 1;
}

// 删除:将字符串转换为整数，实现字符串的等式判断
bool tryStringToInt(const wstring& identifier, long long& id)
{
	try{ id = stoll(identifier);return true;}
	catch (const invalid_argument&) {return false; }
	catch (const out_of_range&) { return false; }
}

// 删除:内置Vector元素删除
void  removeMem(vector<Member>& membersVector, const wstring& identifier)
{
	long long id;
	if(tryStringToInt(identifier, id))
	{
		// 如果转换成功，认为是学号
		for(auto it = membersVector.begin(); it != membersVector.end();)
		{
			if(it->GetStudentID() == to_wstring(id))
			{it = membersVector.erase(it);}
			else{++ it;}
		}

	}
	else 
	{
		// 如果转换失败，认为是姓名
		for (auto it = membersVector.begin(); it != membersVector.end(); )
		{
			if (it->GetName() == identifier)
			{
				it = membersVector.erase(it);
			}
			else { ++it; }
		}

	}

	cout << "\n删除成功!下面将列出剩余所有队员的信息。" << endl;
	system("pause");
	system("cls");

}

/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

// 排序显示
void Member::sortedPrintInfo()
{	

	if (membersVector.size() == 0)
	{
		cout << "目前无队员信息，请添加。" << endl;
		system("pause");
		system("cls");        // 第一次
	}
	else
	{
		system("cls");        // 清屏，便于查看

		do
		{
			cout << "请选择其中一种排序方式列出信息。" << endl;
			cout << "1.学号升序排列显示" << endl;
			cout << "2.入队年月升序排列" << endl;
			cout << "==================" << endl;
			cout << "3.学号降序排列显示" << endl;
			cout << "4.入队年月降序排列" << endl;
			cout << "请输入您的选择:";
			
			wstring SortChioce;
			getline(wcin ,SortChioce);
			SortChioce.erase(remove_if(SortChioce.begin(), SortChioce.end(), ::isspace), SortChioce.end());

			if (SortChioce.length()==1 && all_of(SortChioce.begin(), SortChioce.end(), ::isdigit))
			{
				// 排序选择
				switch (stoi(SortChioce))
				{
				case 1:
					sort(membersVector.begin(), membersVector.end(), AscCompareByStudentID);
					printMemInfo(membersVector);
					return;
				case 2:
					sort(membersVector.begin(), membersVector.end(), AscCompareByJoinYearMonth);
					printMemInfo(membersVector);
					return;
				case 3:
					sort(membersVector.begin(), membersVector.end(), DeascCompareByStudentID);
					printMemInfo(membersVector);
					return;
				case 4:
					sort(membersVector.begin(), membersVector.end(), DeascCompareByJoinYearMonth);
					printMemInfo(membersVector);
					return;
				default:
					cout << "无效选项，请重新输入。" << endl;
					system("pause");
					system("cls");
					return;
				}
			} 
			else
			{
				cout << "输入格式不正确，请按提示输入。" << endl;
				system("pause");
				system("cls");
			}

		} while (true);
	}
}

// 输出信息
void printMemInfo(vector<Member>& membersVector)
{

	if(membersVector.size() == 0)
	{
		cout << "目前无队员信息，请添加。" << endl;
		system("pause");
		system("cls");		// 第一次
	}
	else
	{
		system("cls");		// 清屏，便于查看

		cout << "以下即为现队员所有信息:" << endl;
		for (int i = 0; i < membersVector.size(); i++)
		{
			wcout << "学号: " << membersVector[i].GetStudentID()
				<< "\t 姓名: " << membersVector[i].GetName()
				<< "\t 入队年月: " << membersVector[i].GetYear() << "-" << membersVector[i].GetMonth() << endl;
		}

		cout << "\n按任意键回到菜单。";
		system("pause");
		system("cls");		// 第二次，使用两次是为了减小耦合
	}
}

// 升序的参数函数
bool AscCompareByStudentID(Member& a, Member& b)
{return a.GetStudentID() < b.GetStudentID();}
bool AscCompareByJoinYearMonth(Member& a, Member& b)
{
	if (a.GetYear() != b.GetYear())
	{return a.GetYear() < b.GetYear();}

	return a.GetMonth() < b.GetMonth();
}

// 降序的参数函数
bool DeascCompareByStudentID( Member& a,  Member& b)
{return a.GetStudentID() > b.GetStudentID();}
bool DeascCompareByJoinYearMonth( Member& a, Member& b)
{
	if (a.GetYear() != b.GetYear())
	{return a.GetYear() > b.GetYear();}

	return a.GetMonth() > b.GetMonth();
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

// 修改功能的主体(依据学号检索)
void Member::modifyMemInfo()
{

	if (membersVector.size() == 0)
	{
		cout << "目前无队员信息，请添加。" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		system("cls");		// 清屏，便于查看

		// 数据匹配
		do {
			cout << "以下为现队员所有信息:" << endl;
			for (int i = 0; i < membersVector.size(); i++)
			{
				wcout << "学号: " << membersVector[i].studentID
					<< "\t 姓名: " << membersVector[i].name
					<< "\t 入队年月: " << membersVector[i].enrollmentYear << "-" << membersVector[i].enrollmentMonth << endl;
			}

			cout << "\n请输入需要修改信息的队员学号: ";
			
			wstring inputID;
			getline(wcin, inputID);
			inputID.erase(remove_if(inputID.begin(), inputID.end(), ::isspace), inputID.end());

			//格式匹配
			if (inputID.length() == 11 && all_of(inputID.begin(), inputID.end(), ::isdigit))
			{
				// 存在性验证
				int Index = 0;		// 位置索引
				if (isExistent(membersVector, inputID, Index))
				{
					// 修改主体部分
					wstring inputnewID, newName;
					wstring StrYear, StrMonth;

					if (noModifyID())
					{
						cout << "学号保持不变。\n" << endl;

						// 姓名验证（不为空）
						do
						{
							cout << "\n改后队员姓名: ";
							getline(wcin, newName);
							newName.erase(remove_if(newName.begin(), newName.end(), ::isspace), newName.end());

							if (newName.empty())
							{
								cout << "姓名不能为空，请重新输入。" << endl;;
								continue;
							}
							else
							{
								membersVector[Index].name = newName;
								break;
							}

						} while (true);

						// 入队年份验证
						do {
							cout << "\n改后入队年份: ";
							getline(wcin, StrYear);
							StrYear.erase(remove_if(StrYear.begin(), StrYear.end(), ::iswspace), StrYear.end());		// 去除字符串中的所有空格			

							if (StrYear.length() == 4 && all_of(StrYear.begin(), StrYear.end(), ::isdigit))
							{
								if (stoi(StrYear) >= 2000 && stoi(StrYear) < 9999)
								{
									membersVector[Index].enrollmentYear = stoi(StrYear);
									break;
								}
								else
								{
									cout << "输入年份数值错误，请输入2000以后的4位数字。" << endl;
									system("pause");
								}
							}
							else
							{
								cout << "输入年份格式错误，请输入2000以后的4位数字。" << endl;
								system("pause");
							}
						} while (true);

						// 入队月份验证
						do {
							cout << "\n改后入队月份: ";
							getline(wcin, StrMonth);
							StrMonth.erase(remove_if(StrMonth.begin(), StrMonth.end(), ::iswspace), StrMonth.end());		// 去除字符串中的所有空格

							if ((StrMonth.length() == 1 || StrMonth.length() == 2) && all_of(StrMonth.begin(), StrMonth.end(), ::isdigit))
							{
								if (stoi(StrMonth) >= 1 && stoi(StrMonth) <= 12)
								{
									membersVector[Index].enrollmentMonth = stoi(StrMonth);
									break;
								}
								else
								{
									cout << "输入月份数值不正确，请输入1-12间的数字。" << endl;
									system("pause");
								}
							}
							else
							{
								cout << "输入月份格式不正确，请输入1-12间的数字。" << endl;
								system("pause");
							}
						} while (true);

						cout << "\n修改成功，下面将列出修改后所有队员的信息。" << endl;
						system("pause");
						system("cls");

						printMemInfo(membersVector);
						break;
					}
					else
					{
						// 学号验证（格式加重复性验证）
						do {
							cout << "\n新队员学号（11位数字）: ";
							getline(wcin, inputnewID);
							inputnewID.erase(remove_if(inputnewID.begin(), inputnewID.end(), ::iswspace), inputnewID.end());		// 去除字符串中的所有空格

							if (inputnewID.length() == 11 && all_of(inputnewID.begin(), inputnewID.end(), ::isdigit))
							{
								if (isUniqueID(membersVector, inputnewID))
								{
									membersVector[Index].studentID = inputnewID; break;
								}
								else
								{
									cout << "学号重复，请重新输入。" << endl;
									system("pause");
								}
							}
							else
							{
								cout << "学号格式不正确，请输入11位数字。" << endl;
								system("pause");
							}

						} while (true);

						// 姓名验证（不为空）
						do
						{
							cout << "\n改后队员姓名: ";
							getline(wcin, newName);
							newName.erase(remove_if(newName.begin(), newName.end(), ::isspace), newName.end());

							if (newName.empty())
							{
								cout << "姓名不能为空，请重新输入。" << endl;;
								continue;
							}
							else
							{
								membersVector[Index].name = newName;
								break;
							}

						} while (true);

						// 入队年份验证
						do {
							cout << "\n改后入队年份: ";
							getline(wcin, StrYear);
							StrYear.erase(remove_if(StrYear.begin(), StrYear.end(), ::iswspace), StrYear.end());		// 去除字符串中的所有空格			

							if (StrYear.length() == 4 && all_of(StrYear.begin(), StrYear.end(), ::isdigit))
							{
								if (stoi(StrYear) >= 2000 && stoi(StrYear) < 9999)
								{
									membersVector[Index].enrollmentYear = stoi(StrYear);
									break;
								}
								else
								{
									cout << "输入年份数值错误，请输入2000以后的4位数字。" << endl;
									system("pause");
								}
							}
							else
							{
								cout << "输入年份格式错误，请输入2000以后的4位数字。" << endl;
								system("pause");
							}
						} while (true);

						// 入队月份验证
						do {
							cout << "\n改后入队月份: ";
							getline(wcin, StrMonth);
							StrMonth.erase(remove_if(StrMonth.begin(), StrMonth.end(), ::iswspace), StrMonth.end());		// 去除字符串中的所有空格

							if ((StrMonth.length() == 1 || StrMonth.length() == 2) && all_of(StrMonth.begin(), StrMonth.end(), ::isdigit))
							{
								if (stoi(StrMonth) >= 1 && stoi(StrMonth) <= 12)
								{
									membersVector[Index].enrollmentMonth = stoi(StrMonth);
									break;
								}
								else
								{
									cout << "输入月份数值不正确，请输入1-12间的数字。" << endl;
									system("pause");
								}
							}
							else
							{
								cout << "输入月份格式不正确，请输入1-12间的数字。" << endl;
								system("pause");
							}
						} while (true);

						cout << "\n修改成功，下面将列出修改后所有队员的信息。" << endl;
						system("pause");
						system("cls");

						printMemInfo(membersVector);
						break;
					}
				}
				else
				{
					cout << "抱歉，您输入的学号不存在，请重新输入。" << endl;
					system("pause");
				}
			}
			else
			{
				cout << "学号格式不正确，请输入11位数字。" << endl;
				system("pause");
				system("cls");
			}

		} while (true);
	}
}

// 修改:查找指定学号的队员信息
bool isExistent( vector<Member>& membersVector, const wstring& id, int& Index)
{
	for (int i = 0; i < membersVector.size(); ++i)
	{
		if(membersVector[i].GetStudentID() == id)
		{
			Index = i;
			return true;
		}
	}
	return false;
}

// 修改:是否修改学号判断
bool noModifyID()
{	
	do 
	{
		wstring choice;
		cout << "\n是否修改学号？[Y/N](默认[N]): ";
		getline(wcin, choice);
		choice.erase(remove_if(choice.begin(), choice.end(), ::isspace), choice.end());
	
		// 将输入转换为小写以忽略大小写差异
		transform(choice.begin(), choice.end(), choice.begin(), [](unsigned short c){return towlower(c);});

		if (!choice.empty())
		{
			if (choice.compare(L"y") && choice.compare(L"n"))
			{
				cout << "请在[Y/N]中选择。";
				system("pause");
			}
			else{return choice.compare(L"y");}
		}
		else{return true;}

	} while (true);
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

/*私有属性对外接口*/

//  学号对外接口
wstring Member::GetStudentID(){return studentID;}
void Member::SetStudentID(wstring InputID){studentID = InputID;}

// 姓名对外接口
wstring Member::GetName() { return name; }
void Member::SetName(wstring InputName){name = InputName;}

// 入队年份对外接口
int Member::GetYear() const { return enrollmentYear; }
void Member::SetYear(int InputYear) { enrollmentYear = InputYear; }

// 入队月份对外接口
int Member::GetMonth() const { return enrollmentMonth; }
void Member::SetMonth(int InputMonth) { enrollmentMonth = InputMonth; }
