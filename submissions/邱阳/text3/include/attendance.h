#pragma once
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
using namespace std;

//考勤信息类
class Attendance
{	
private:
	int check_num;				//打卡次数
	double work_total_time;		//总工作时间
	int check_in_out = 0;		//记录打卡状态
	double work_time{};							//记录工作时长
	long long int work_time_ = 0;				//记录工作时长
	string check_in_time, check_out_time;		//记录考勤时间
	string check_in_out_time;					//记录考勤时间

public:
	//使用map储存打卡时间和工作时长
	map<string, double> check_records;		

	//获取打卡时间
	void check_time_get();

	//添加打卡记录到map容器
	void add_time(string check_in_time, double work_time);

	//打卡记录输出显示
	void print_check_record() const;

	//输出显示所有考勤信息
	void print_all_record() const;

	//清空所有考勤信息
	void clear_all_records();

	//修改特定日期的考勤信息
	void change_update();

	//输入时间格式判断
	bool time_format(const string& input_time);
	bool add_time_format(const string& input_time);
};



