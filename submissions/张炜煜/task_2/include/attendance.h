#ifndef    _ATTENDANCE_H_			
#define    _ATTENDANCE_H_
	
#include "member.h"	

#include <iostream>		
#include <map>			
#include <string>		
#include <algorithm>	
#include <ctime>		
#include <iomanip>		
#include <sstream>		

using namespace std;		

// 考勤信息类
class attendance
{	
public:
	wstring _ID;
	string _time;		//打卡时间
	int _frequency;		//打卡次数
	float _worktime;		//单次工作时间
	float _sum_worktime;	//总工作时间
	
	vector<attendance> attendance_vector;

	attendance();
	attendance(wstring _ID, string _time, int _frequency, float _worktime , float _sum_worktime);

	void Clock_In();
	void Show_Attendance();
};

#endif



