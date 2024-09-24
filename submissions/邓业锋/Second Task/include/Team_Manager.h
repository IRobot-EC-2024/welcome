#include "Members.h"
#include "Attendance.h"

// 定义团队管理类
class Team_Manager
{

public:
	// map（key为学号, value为考勤对象）
	map <wstring, Attendance> MAmap;

	// 构造函数
	Team_Manager();

	// 析构函数(虚函数，防止资源泄露)
	virtual ~Team_Manager();

	Member testMember;
	Attendance testAttendance;

	void ShowMenu();

	// 考勤信息修改(连接两类)
	void ModifyMAInfo(Member& testMember);

	// 考勤信息输出(map)
	void ShowMAInfo(Member& testMember);

};
