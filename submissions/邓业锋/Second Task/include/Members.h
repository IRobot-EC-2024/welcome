#pragma once			// 防止头文件重复定义

#include <iostream>		// 标准输入输出流
#include <vector>		// 引入STL的vector容器
#include <string>		// 字符串类型
#include <algorithm>	// 算法

using namespace std;		// 使用标准命名空间

// 队员类
class Member
{
private:

	wstring studentID;		// 学号
	wstring name;			// 姓名

	int enrollmentYear = 0;			// 入队年份
	int enrollmentMonth = 0;		// 入队月份

public:
	// 创建一个 vector 容器存储 Member 对象
	vector<Member> membersVector;

	// 默认构造
	Member();
	// 构造函数
	Member(wstring id, wstring name, int year, int month);

	/*功能函数*/
	// 添加
	void addMember();

	// 删除
	void deleteMember();

	// 排序显示
	void sortedPrintInfo();

	// 修改
	void modifyMemInfo();


	/*对外接口*/

	// 学号对外接口
	wstring GetStudentID();
	void SetStudentID(wstring InputID);

	// 姓名对外接口
	wstring GetName();
	void SetName(wstring InputName);

	// 入队年份对外接口
	int GetYear() const;
	void SetYear(int InputYear);

	// 入队月份对外接口
	int GetMonth() const;
	void SetMonth(int inputMonth);

};