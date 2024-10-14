#include "attendance.h"

attendance::attendance(){}
attendance::attendance(wstring ID, string time, int frequency, float worktime , float sum_worktime) :
	_ID(ID),
	_time(time),
	_frequency(frequency),
	_worktime(worktime),
	_sum_worktime(sum_worktime){}


int isMember(vector<attendance>& attendance_vector, const wstring& input)
{
	for(int i = 0; i < attendance_vector.size(); i++)
	{
		if( attendance_vector[i]._ID == input)
		{
			return i;
		}
	}
	return -1;
}

void attendance::Clock_In()
{
	//学号
	wstring ID;
	do{
		cout << "\n请输入学号: ";
		getline(wcin, ID);
		ID.erase(remove_if(ID.begin(), ID.end(), ::iswspace), ID.end());		
		if (ID.length() == 11 && all_of(ID.begin(), ID.end(), ::isdigit))
		{
			_ID=ID;
			break;		
		}
		else
		{
			cout << "学号格式不正确,请输入11位数字" << endl;
			system("pause");
		}
	}while (1);

	//工作时间
	wstring worktime;
	do{
		cout << "\n请输入工作时长(单位:小时): ";
		getline(wcin, worktime);
		worktime.erase(remove_if(worktime.begin(), worktime.end(), ::iswspace), worktime.end());		
		if (all_of(worktime.begin(), worktime.end(), ::isdigit))
		{

			wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;
    		string f_worktime = converter.to_bytes(worktime);
			_worktime=stof(f_worktime);
			_sum_worktime+=_worktime;
			break;		
		}
		else
		{
			cout << "格式不正确,请输入数字" << endl;
			system("pause");
		}

	}while (1);

	//打卡时间
	time_t now = time(nullptr);			
	tm* timePtr = localtime(&now);		
	stringstream Strstream;
	Strstream << put_time(timePtr, "时间:%Y-%m-%d %H:%M:%S");
	string _time = Strstream.str();

	//添加
	attendance new_attendance(_ID,_time,_frequency,_worktime,_sum_worktime);
	attendance_vector.push_back(new_attendance);

	cout << "打卡成功！"<<endl;
	cout << "工作时长:" << _worktime << "h" << endl;
	cout << "打卡" << _time << endl;

	system("pause");
	system("cls");
	
}

void attendance::Show_Attendance()
{
	wstring id;
	if (attendance_vector.size() == 0)
	{
		cout << "目前无队员考勤信息，请添加。" << endl;
		system("pause");
		system("cls");
	}else
	{
		do{
			cout << "\n请输入想要查看考勤信息成员的学号" <<endl;
			getline(wcin, id);
			id.erase(remove_if(id.begin(), id.end(), ::iswspace), id.end());		
			if (id.length() == 11 && all_of(id.begin(), id.end(), ::isdigit))
			{		
				cout << "考勤信息如下" << endl;	
				break;		
			}
			else
			{
				cout << "学号格式不正确,请输入11位数字" << endl;
				system("pause");
			}
		}while (1);
		//查找此学号
		int num;
		for(int i = 0; i < attendance_vector.size(); i++)
		{
			if( attendance_vector[i]._ID == id)
			{
				cout << "打卡" << attendance_vector[i]._time << "  工作时长:" << attendance_vector[i]._worktime << endl;
				num=i;
			}
		}
		cout << "工作总时长:"<< attendance_vector[num]._sum_worktime << "h" << endl;
		system("pause");
		system("cls");
	}	
}