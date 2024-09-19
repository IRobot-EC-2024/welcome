#include "teammanager.h"
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void TeamManager::Show_Menu()
{
	cout << "            " << endl;
	cout << "人员管理系统" << endl;
	cout << "======================" << endl;
	cout << "1.添加成员" << endl;
	cout << "2.查找成员" << endl;
	cout << "3.删除成员" << endl;
	cout << "4.列出所有成员" << endl;
	cout << "5.修改人员信息" << endl;
	cout << "0.退出" << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void TeamManager::Add_Teamer()
{
	
		vector<Teamer>Teamer;
		string data1;
		string data2;
		int data3;
		int data4;
		int data5;


		cout << "请输入学号: ";
		cin >> data1;

		ifstream ifs("Team.txt");

		string line;
		long lineNumber = 0;
		bool found = false;

		// 读取文件内容
		while (getline(ifs, line))
		{
			lineNumber++;
			// 查找输入的对象
			if (line.find(data1) != string::npos)
			{
				cout << "找到对象在第 " << lineNumber << " 行: " << line << endl;
				cout << "请勿重复添加" << endl;
				found = true;
			}
		}
		//如果未重复，则添加人员
		if (!found)
		{
			cout << "请输入姓名：";
			cin >> data2;
			cout << "请输入加入年：";
			cin >> data3;
			cout << "请输入加入月：";
			cin >> data4;
			if (data4 > 12 || data4 < 1)
			{
				cout << "月份错误，请输入正确月份" << endl;
				return;
			}
			cout << "请输入加入日：";
			cin >> data5;
			if (data5 > 31 || data5 < 1)
			{
				cout << "日期错误，请输入正确日期" << endl;
				return;
			}


			//写操作
			ofstream ofs;
			ofs.open("Team.txt", ios::app);

			//写失败
			if (!ofs.is_open())
			{
				cout << "文件打开失败" << endl;
				system("pause");
				return;
			}


			ofs << data1 << " " << data2 << " " << data3 << "-" << data4 << "-" << data5 << endl;
			cout << "记录成功" << endl;
			ofs.close();
			system("pause");
			ifs.close();
			return;
		}

		ifs.close();
		system("pause");
		return;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int TeamManager::Delete_Teamer()
{
	string  toRemove;
	// 读取文件内容到内存中
	cout << "请输入需要移除的学号或姓名：";
	cin >> toRemove;
	ifstream ifs("Team.txt");
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
	ofs.open("Team.txt", ios::trunc);
	if (!ofs.is_open())
	{
		cout << "无法打开输出文件" << endl;
		return 0;
	}

	for (vector<string>::iterator it = lines.begin(); it != lines.end(); it++)
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



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void TeamManager::List_All_Teamers()
{
	ifstream ifs;
	ifs.open("Team.txt", ios::in);

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void TeamManager::Change_Teamer()
{
	int a = Delete_Teamer();
	cout << "请输入要改变的值：";
	if (a)
	{
		Add_Teamer();
		cout << "改变成功" << endl;
		system("pause");
		return;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

long TeamManager::Search_Teamer()
{

	string searchString;
	cout << "请输入要查找的姓名或学号: ";
	cin >> searchString;

	ifstream ifs("Team.txt");
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//void TeamManager::Updata_Teamer()
//{
//
//
//
//}
