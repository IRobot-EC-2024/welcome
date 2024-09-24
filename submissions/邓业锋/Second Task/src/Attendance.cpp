#include "Attendance.h"

bool ConfirmAct_NoClear();
bool isValidTimeFormat(const string& inputTime);

/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

// 打卡记录输出显示
void Attendance::displayAllCheckInRecords() const
{
	for (const auto& recordPrint : checkInRecords)
	{
		cout << recordPrint.first
			<< "\t工作时长: " << recordPrint.second << "h\n" << endl;
	}
	cout << "按任意键返回主菜单。";
	system("pause");
	system("cls");

}

// 输出显示所有考勤信息
void Attendance::PrintAllAttendanceInfo() const
{
	if (checkInCount != 0)
	{	
		cout << "以下为该对象的考勤信息:" << endl;
		cout << "\n打卡次数:" <<  checkInCount << "\t总工作时长:" << totalWorkTime << "h" << endl;

		cout << "\n打卡记录:" << endl;

		displayAllCheckInRecords();
	} 
	else
	{
		cout << "打卡次数为0，无打卡记录。" << endl;
		system("pause");
		system("cls");
	}
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

// 添加打卡记录到map容器（打卡时间以及对应工作时长）
void Attendance::addRecordInMap(string checkInTime, double workDuration)
{
	checkInRecords[checkInTime] = workDuration;			// map的key+Value

	checkInCount++;			// 打卡次数加一
	totalWorkTime += workDuration;		// 总工作时长累加
}

// 打卡时间设为本地时间，工作时间手动输入
void Attendance::SetRecordValue()
{
	time_t now = time(nullptr);			// 获取当前时间戳
	tm* timePtr = localtime(&now);		// 时间戳转换为tm结构体

	// 格式化时间字符串
	stringstream Strstream;
	Strstream << put_time(timePtr, "日期:%Y-%m-%d 时间:%H:%M:%S");
	string checkInTime = Strstream.str();

	cout << "此次打卡时间:\n" << checkInTime << endl;

	while (true)
	{
		// 用户输入工作时长
		string workDuration;

		cout << "\n请输入今日工作时长(h): ";
		getline(cin, workDuration);
		workDuration.erase(remove_if(workDuration.begin(), workDuration.end(), ::isspace), workDuration.end()); // 清除字符串空格

		// 格式验证
		if ((workDuration.length() == 1 || workDuration.length() == 3) && 
			(all_of(workDuration.begin(), workDuration.end(), ::isdigit) || workDuration.find(L'.' == string::npos)))
		{	
				// 将打卡时间和工作时长存储在记录中
				addRecordInMap(checkInTime, stod(workDuration));

				cout << "\n添加成功。(按任意键返回菜单)" << endl;
				system("pause");
				system("cls");
				break;
		}
		else
		{
			cout << "输入格式错误(小于10，至多1位小数),请重新输入。" << endl;
			system("pause");
		}
	}
	
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

// 清空所有考勤记录
void Attendance::ClearAllRecords()
{	
	if (checkInCount != 0)
	{	
		if (ConfirmAct_NoClear())
		{
			cout << "按任意键返回菜单。";
			system("pause");
			system("cls");
		} 
		else
		{
			checkInRecords.clear();
			checkInCount = 0;
			totalWorkTime = 0;

			cout << "所有考勤记录已清空。" << endl;
			system("pause");
			system("cls");
		}
	}
	else
	{
		cout << "打卡次数为0，无打卡记录。" << endl;
		system("pause");
		system("cls");
	}
}

// 清空再确认
bool ConfirmAct_NoClear()
{
	do
	{
		wstring choice;
		cout << "\n确认清空考勤信息？[Y/N](默认[N]): ";
		getline(wcin, choice);
		choice.erase(remove_if(choice.begin(), choice.end(), ::isspace), choice.end());

		// 将输入转换为小写以忽略大小写差异
		transform(choice.begin(), choice.end(), choice.begin(), [](unsigned short c) {return towlower(c); });

		if (!choice.empty())
		{
			if (choice.compare(L"y") && choice.compare(L"n"))
			{
				cout << "请在[Y/N]中选择。";
				system("pause");
			}
			else { return choice.compare(L"y"); }
		}
		else { return true; }

	} while (true);
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

// 输入时间格式判断
bool isValidTimeFormat(const string& inputTime)
{
	istringstream ss(inputTime);
	tm tm = {};

	try
	{
		ss >> get_time(&tm, "日期:%Y-%m-%d") >> ws >> get_time(&tm, "时间:%H:%M:%S");
		if (ss.fail()) { return false; }
	}
	catch (exception& e)
	{return false;}

	return true;
}

// 更新特定日期的考勤信息（不改次数）
void Attendance::updateAttendanceInfo()
{
	while (true)
	{
		if (checkInCount != 0)
		{
			cout << "以下为该对象的考勤信息:" << endl;
			cout << "\n打卡次数:" << checkInCount << "\t总工作时长:" << totalWorkTime << "h" << endl;

			cout << "\n打卡记录:" << endl;

			for (const auto& recordPrint : checkInRecords)
			{
				cout << recordPrint.first
					<< "\t\t工作时长: " << recordPrint.second << "h\n" << endl;
			}

			string inputTime;
			cout << "输入您欲更新打卡记录的时间(注意格式):" << endl;
			getline(cin, inputTime);

			if (isValidTimeFormat(inputTime))
			{	
				auto it = checkInRecords.find(inputTime);
				if (it != checkInRecords.end())
				{
					while (true)
					{
						// 用户更新工作时长
						wstring newWorkDuration;

						cout << "\n请输入改后工作时长(h): ";
						getline(wcin, newWorkDuration);
						newWorkDuration.erase(remove_if(newWorkDuration.begin(), newWorkDuration.end(), ::isspace), newWorkDuration.end()); // 清除字符串空格

						// 格式验证
						if ((newWorkDuration.length() == 1 || newWorkDuration.length() == 3) &&
							(all_of(newWorkDuration.begin(), newWorkDuration.end(), ::isdigit) || newWorkDuration.find('.' == string::npos)))
						{
							totalWorkTime -= it->second;
							totalWorkTime += stod(newWorkDuration);
							it->second = stod(newWorkDuration);

							cout << "\n更新成功。下面将列出改后考勤信息。" << endl;
							system("pause");
							system("cls");

							PrintAllAttendanceInfo();
							return;
						}
						else
						{
							cout << "输入工作时长格式错误(小于10，至多1位小数),请重新输入。" << endl;
							system("pause");
						}
					}
				}
				else
				{
					cout << "未找到指定日期的考勤记录。请重新输入。\n(建议直接复制)";
					system("pause");
					system("cls");
				}

			}
			else
			{
				cout << "输入的时间格式不正确，请按照“日期:YYYY-MM-DD 时间:HH:MM:SS”的格式输入。\n(建议直接复制)";
				system("pause");
				system("cls");
			}
		}
		else
		{
			cout << "打卡次数为0，无打卡记录。" << endl;
			system("pause");
			system("cls");
			break;
		}

	}

}