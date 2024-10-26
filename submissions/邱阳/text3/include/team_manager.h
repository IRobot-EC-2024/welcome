#pragma once
#include "members.h"
#include "attendance.h"

//定义团队管理类
class Team_Manager
{
public:
	//使用map关联学号和考勤对象
	map <long long int, Attendance> MAmap;

	//构造函数
	Team_Manager();

	Member M;
	Attendance A;

	//菜单
	void ShowMenu();

	//考勤菜单
	void attendance_info(Attendance& TAttendance);

	//修改考勤信息:学号存在性判断
	bool MAis_id_exist(vector<Member>& exit_members, const long long int& id);

	//考勤信息修改
	void modify_MAInfo(Member& M);

	//考勤信息输出
	void show_info(Member& M);

	//析构函数(虚函数，防止资源泄露)
	virtual ~Team_Manager();
};
