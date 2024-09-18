#include "workermanager.h"

////////////////////////////////////////////////////////////////////////////////////////////////
void WorkerManager::Show_Menu()
{
	cout << "            " << endl;
	cout << "人员管理系统" << endl;
	cout << "======================" << endl;
	cout << "1.添加考勤" << endl;
	cout << "2.查找考勤" << endl;
	cout << "3.删除考勤" << endl;
	cout << "4.列出所有考勤" << endl;
	cout << "5.查询考勤时间信息" << endl;
	cout << "0.退出" << endl;
	cout << ">>>";
}
//////////////////////////////////////////////////////////////////////////////////////////////////
void WorkerManager::Add_Worker()
{
	vector<Worker>Worker;
	string data1;
	string data2;
	string data3;

	cout << "请输入学号：";
	cin >> data1;
	cout <<"请输入姓名：";
	cin >> data2;
	cout << "请输入上班或下班：";
	cin >> data3;
	if(data3=="上班" || data3=="下班")
	{
		//如果未上班打卡就进行下班打卡会打卡失败
		if (data3 == "下班")
		{

			ifstream ifs("Work.txt");
			if (!ifs.is_open())
			{
				cout << "文件打开失败 " << endl;
				return;
			}

			string line;
			bool found = false;

			// 读取文件内容
			while (getline(ifs, line))
			{
				// 查找输入的对象
				if (line.find(data1) != string::npos)
				{
					if (line.find("上班") != string::npos)
						found = true;
					else
						found = false;
				}
			}

			if (!found)
			{
				cout << "未进行上班打卡，请先进行上班打卡 " << endl;
				system("pause");
				ifs.close();
				return;
			}
			else
				ifs.close();
		}
	}
	else
	{
		cout << "打卡输入错误，请重新输入" << endl;
		return;
	}

	//时间生成函数
	auto now = time(nullptr);
	struct tm* LocalTime = localtime(&now);
	int year = LocalTime->tm_year + 1900;
	int month = LocalTime->tm_mon + 1;
	int day = LocalTime->tm_mday;
	int hour = LocalTime->tm_hour;
	int minute = LocalTime->tm_min;
	int second = LocalTime->tm_sec;

	//写操作
	ofstream ofs;
	ofs.open("Work.txt", ios::app);

	//写失败
	if (!ofs.is_open())
	{
		cout << "文件打开失败" << endl;
		system("pause");
		return;
	}

	cout << year << "-" << month << "-" << day << " " << hour << ":" << minute << ":" << second << endl;
	ofs << year << "-" << month << "-" << day << " " << hour << ":" << minute << ":" << second << " " << data1 << " " << data2 <<" "<<data3<<endl;
	cout << "打卡成功" << endl;
	ofs.close();
	system("pause");
}
//////////////////////////////////////////////////////////////////////////////////////////////////
int WorkerManager::Delete_Worker()
{
		string  toRemove;
		// 读取文件内容到内存中
		cout << "请输入需要移除的学号或姓名：";
		cin >> toRemove;
		ifstream ifs("Work.txt");
		if (!ifs.is_open()) 
		{ 
			cout << "文件打开失败" << endl;
			return 0;
		} 


		vector<string> lines;
		string line; 
		bool flag = false;
		while (getline(ifs, line)) 
		{ 
			if (line.find(toRemove) == string::npos) 
			{ // 如果行中不包含要删除的字符串
				lines.push_back(line);
			}
			else
			{ //如果包含，则把标志位记为真
				flag = true;
			}
		}
		ifs.close();

		// 将处理后的内容写回文件
		ofstream ofs;
		ofs.open("Work.txt",ios::trunc);
		if (!ofs.is_open()) 
		{
			cout << "无法打开输出文件" << endl;
			return 0;
		}

		for (vector<string>::iterator it=lines.begin();it!=lines.end();it++)
		{
			ofs << *it << endl;
		}
		ofs.close();
		if (flag)
		{
			 cout << "移除成功" << endl;
			 system("pause");
			 return 1;
		}
		else
		{
			cout << "未找到查询对象" << endl;
			system("pause");
			return 0;
		}


}
//////////////////////////////////////////////////////////////////////////////////////////////////
void WorkerManager::List_All_Workers()
{
	ifstream ifs;
	ifs.open("Work.txt",ios::in);

	//读失败
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		system("pause");
		return;
	}

	//遍历文件
	char c;
	while ((c = ifs.get()) != EOF)
	{
		cout << c;
	}
	ifs.close();
	system("pause");
}
//////////////////////////////////////////////////////////////////////////////////////////////////
void WorkerManager::Search_Time()
{
	string searchString;
	cout << "请输入要查找的姓名或学号: ";
	cin >> searchString;

	ifstream ifs("Work.txt");
	if (!ifs.is_open())
	{
		cout << "文件打开失败 " << endl;
		return ;
	}

	string line;
	long lineNumber = 0;
	bool found = false;
	int year, month, day, hour, minute, second, number = 0 , All_Hour = 0, All_Minute = 0, All_Second = 0;


	// 读取文件内容
	while (getline(ifs, line))
	{
		lineNumber++;
		// 查找输入的对象
		if (line.find(searchString) != string::npos)
		{
			tm tm = {};
			istringstream ss(line); 
			ss >> get_time(&tm, "%Y-%m-%d %H:%M:%S"); 
			found = true;
			if (line.find("上班") != string::npos)
			{
				year = tm.tm_year + 1900;
				month = tm.tm_mon + 1;
				day = tm.tm_mday;
				hour = tm.tm_hour;
				minute = tm.tm_min;
				second = tm.tm_sec;
				cout << tm.tm_year + 1900 << "-" << tm.tm_mon + 1 << "-" << tm.tm_mday << " " << tm.tm_hour << ":" << tm.tm_min << ":" << tm.tm_sec <<" "<<"上班" <<endl;
			}
			else if (line.find("下班") != string::npos)
			{
				number++;//有效打卡次数
				if (tm.tm_year + 1900 == year && tm.tm_mon + 1 == month && tm.tm_mday == day)//比较是否是当天打卡
				{
					All_Hour += tm.tm_hour - hour;
					All_Minute += tm.tm_min - minute;
					All_Second += tm.tm_sec - second;
					cout << tm.tm_year + 1900 << "-" << tm.tm_mon + 1 << "-" << tm.tm_mday << " " << tm.tm_hour << ":" << tm.tm_min << ":" << tm.tm_sec << " " << "下班" << endl;
				}
			}
		}
	}

	if (!found)
	{
		cout << "未找到对象: " << searchString << endl;
		system("pause");
	}

	ifs.close();
	cout << "工作总时间为：" << All_Hour << ":" << All_Minute << ":" << All_Second << endl;
	cout << "打卡总次数为：" << number << endl;
	system("pause");
	return ;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
long WorkerManager::Search_Work()
{

	string searchString;
	cout << "请输入要查找的姓名或学号: ";
	cin >> searchString;

	ifstream ifs("Work.txt");
	if (!ifs.is_open()) 
	{
		cout << "文件打开失败 " << endl;
		return 0;
	}

	string line;
	long lineNumber = 0;
	bool found = false;

	// 读取文件内容
	while (getline(ifs, line)) 
	{
		lineNumber++;
		// 查找输入的对象
		if (line.find(searchString) != string::npos) 
		{
			cout << "找到对象在第 " << lineNumber << " 行: " << line << endl;
			found = true;
		}
	}

	if (!found) 
	{
		cout << "未找到对象: " << searchString << endl;
		system("pause");
	}

	ifs.close();
	system("pause");
	return lineNumber;

}
//////////////////////////////////////////////////////////////////////////////////////////////////




