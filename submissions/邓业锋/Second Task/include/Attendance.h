#ifndef    _ATTENDANCE_H_			// 宏守卫防止头文件重复定义
#define    _ATTENDANCE_H_
	
#include <iostream>		// 标准输入输出流
#include <map>			// 引入STL的map容器
#include <string>		// 字符串类型
#include <algorithm>	// 算法

#include <ctime>		// 处理有关时间的操作
#include <iomanip>		// 自定义时间的输出格式
#include <sstream>		// 时间格式化为字符串

using namespace std;		// 使用标准命名空间

// 考勤信息类
class Attendance
{	
private:
	// 使用map作为打卡记录的容器，存储打卡时间以及对应的工作时长
	map<string, double> checkInRecords;		

	int checkInCount;		// 打卡次数
	double totalWorkTime;		// 总工作时间(单位:小时)

public:
	
	// 利用默认构造函数初始化私有属性
	Attendance() : checkInCount(0), totalWorkTime(0) {}

	// 打卡时间设为本地时间，工作时间手动输入
	void SetRecordValue();

	// 添加打卡记录（打卡时间以及对应工作时长）
	void addRecordInMap(string checkInTime, double workDuration);

	// 打卡记录输出显示
	void displayAllCheckInRecords() const;

	// 输出显示所有考勤信息
	void PrintAllAttendanceInfo() const;

	// 清空所有考勤信息
	void ClearAllRecords();

	// 更新所有考勤信息
	void updateAttendanceInfo();

};

#endif


