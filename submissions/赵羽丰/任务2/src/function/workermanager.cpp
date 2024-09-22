#include "workermanager.h"

////////////////////////////////////////////////////////////////////////////////////////////////
void WorkerManager::Show_Menu()
{
	cout << "            " << endl;
	cout << "��Ա����ϵͳ" << endl;
	cout << "======================" << endl;
	cout << "1.��ӿ���" << endl;
	cout << "2.���ҿ���" << endl;
	cout << "3.ɾ������" << endl;
	cout << "4.�г����п���" << endl;
	cout << "5.��ѯ����ʱ����Ϣ" << endl;
	cout << "0.�˳�" << endl;
	cout << ">>>";
}
//////////////////////////////////////////////////////////////////////////////////////////////////
void WorkerManager::Add_Worker()
{
	vector<Worker>Worker;
	string data1;
	string data2;
	string data3;

	cout << "������ѧ�ţ�";
	cin >> data1;
	cout <<"������������";
	cin >> data2;
	cout << "�������ϰ���°ࣺ";
	cin >> data3;
	if(data3=="�ϰ�" || data3=="�°�")
	{
		//���δ�ϰ�򿨾ͽ����°�򿨻��ʧ��
		if (data3 == "�°�")
		{

			ifstream ifs("Work.txt");
			if (!ifs.is_open())
			{
				cout << "�ļ���ʧ�� " << endl;
				return;
			}

			string line;
			bool found = false;

			// ��ȡ�ļ�����
			while (getline(ifs, line))
			{
				// ��������Ķ���
				if (line.find(data1) != string::npos)
				{
					if (line.find("�ϰ�") != string::npos)
						found = true;
					else
						found = false;
				}
			}

			if (!found)
			{
				cout << "δ�����ϰ�򿨣����Ƚ����ϰ�� " << endl;
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
		cout << "�������������������" << endl;
		return;
	}

	//ʱ�����ɺ���
	auto now = time(nullptr);
	struct tm* LocalTime = localtime(&now);
	int year = LocalTime->tm_year + 1900;
	int month = LocalTime->tm_mon + 1;
	int day = LocalTime->tm_mday;
	int hour = LocalTime->tm_hour;
	int minute = LocalTime->tm_min;
	int second = LocalTime->tm_sec;

	//д����
	ofstream ofs;
	ofs.open("Work.txt", ios::app);

	//дʧ��
	if (!ofs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		system("pause");
		return;
	}

	cout << year << "-" << month << "-" << day << " " << hour << ":" << minute << ":" << second << endl;
	ofs << year << "-" << month << "-" << day << " " << hour << ":" << minute << ":" << second << " " << data1 << " " << data2 <<" "<<data3<<endl;
	cout << "�򿨳ɹ�" << endl;
	ofs.close();
	system("pause");
}
//////////////////////////////////////////////////////////////////////////////////////////////////
int WorkerManager::Delete_Worker()
{
		string  toRemove;
		// ��ȡ�ļ����ݵ��ڴ���
		cout << "��������Ҫ�Ƴ���ѧ�Ż�������";
		cin >> toRemove;
		ifstream ifs("Work.txt");
		if (!ifs.is_open()) 
		{ 
			cout << "�ļ���ʧ��" << endl;
			return 0;
		} 


		vector<string> lines;
		string line; 
		bool flag = false;
		while (getline(ifs, line)) 
		{ 
			if (line.find(toRemove) == string::npos) 
			{ // ������в�����Ҫɾ�����ַ���
				lines.push_back(line);
			}
			else
			{ //�����������ѱ�־λ��Ϊ��
				flag = true;
			}
		}
		ifs.close();

		// ������������д���ļ�
		ofstream ofs;
		ofs.open("Work.txt",ios::trunc);
		if (!ofs.is_open()) 
		{
			cout << "�޷�������ļ�" << endl;
			return 0;
		}

		for (vector<string>::iterator it=lines.begin();it!=lines.end();it++)
		{
			ofs << *it << endl;
		}
		ofs.close();
		if (flag)
		{
			 cout << "�Ƴ��ɹ�" << endl;
			 system("pause");
			 return 1;
		}
		else
		{
			cout << "δ�ҵ���ѯ����" << endl;
			system("pause");
			return 0;
		}


}
//////////////////////////////////////////////////////////////////////////////////////////////////
void WorkerManager::List_All_Workers()
{
	ifstream ifs;
	ifs.open("Work.txt",ios::in);

	//��ʧ��
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		system("pause");
		return;
	}

	//�����ļ�
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
	cout << "������Ҫ���ҵ�������ѧ��: ";
	cin >> searchString;

	ifstream ifs("Work.txt");
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�� " << endl;
		return ;
	}

	string line;
	long lineNumber = 0;
	bool found = false;
	int year, month, day, hour, minute, second, number = 0 , All_Hour = 0, All_Minute = 0, All_Second = 0;


	// ��ȡ�ļ�����
	while (getline(ifs, line))
	{
		lineNumber++;
		// ��������Ķ���
		if (line.find(searchString) != string::npos)
		{
			tm tm = {};
			istringstream ss(line); 
			ss >> get_time(&tm, "%Y-%m-%d %H:%M:%S"); 
			found = true;
			if (line.find("�ϰ�") != string::npos)
			{
				year = tm.tm_year + 1900;
				month = tm.tm_mon + 1;
				day = tm.tm_mday;
				hour = tm.tm_hour;
				minute = tm.tm_min;
				second = tm.tm_sec;
				cout << tm.tm_year + 1900 << "-" << tm.tm_mon + 1 << "-" << tm.tm_mday << " " << tm.tm_hour << ":" << tm.tm_min << ":" << tm.tm_sec <<" "<<"�ϰ�" <<endl;
			}
			else if (line.find("�°�") != string::npos)
			{
				number++;//��Ч�򿨴���
				if (tm.tm_year + 1900 == year && tm.tm_mon + 1 == month && tm.tm_mday == day)//�Ƚ��Ƿ��ǵ����
				{
					All_Hour += tm.tm_hour - hour;
					All_Minute += tm.tm_min - minute;
					All_Second += tm.tm_sec - second;
					cout << tm.tm_year + 1900 << "-" << tm.tm_mon + 1 << "-" << tm.tm_mday << " " << tm.tm_hour << ":" << tm.tm_min << ":" << tm.tm_sec << " " << "�°�" << endl;
				}
			}
		}
	}

	if (!found)
	{
		cout << "δ�ҵ�����: " << searchString << endl;
		system("pause");
	}

	ifs.close();
	cout << "������ʱ��Ϊ��" << All_Hour << ":" << All_Minute << ":" << All_Second << endl;
	cout << "���ܴ���Ϊ��" << number << endl;
	system("pause");
	return ;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
long WorkerManager::Search_Work()
{

	string searchString;
	cout << "������Ҫ���ҵ�������ѧ��: ";
	cin >> searchString;

	ifstream ifs("Work.txt");
	if (!ifs.is_open()) 
	{
		cout << "�ļ���ʧ�� " << endl;
		return 0;
	}

	string line;
	long lineNumber = 0;
	bool found = false;

	// ��ȡ�ļ�����
	while (getline(ifs, line)) 
	{
		lineNumber++;
		// ��������Ķ���
		if (line.find(searchString) != string::npos) 
		{
			cout << "�ҵ������ڵ� " << lineNumber << " ��: " << line << endl;
			found = true;
		}
	}

	if (!found) 
	{
		cout << "δ�ҵ�����: " << searchString << endl;
		system("pause");
	}

	ifs.close();
	system("pause");
	return lineNumber;

}
//////////////////////////////////////////////////////////////////////////////////////////////////




