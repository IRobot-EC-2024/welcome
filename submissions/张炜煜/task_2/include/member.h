#ifndef    _MEMBER_H_			
#define    _MEMBER_H_

#include <iostream>		
#include <vector>		
#include <string>		
#include <algorithm>	
#include <fstream>
#include <locale>
#include <codecvt>
using namespace std;		// 使用标准命名空间
// 队员类
class member
{
//private:

				
public:
	wstring _ID;		
	wstring _name;			
	vector<member> member_vector;
	int _year = 0;		
	int _month = 0;		
	int _day = 0;
	
	/*功能函数*/
	// 默认构造
	member();
	// 构造函数
	member(wstring id, wstring name, int year, int month , int day);
	// 添加
	void AddMember();
	// 删除
	void DeleteMember();
	// 修改
	void ChangeMember();

};
	
void PrintMembers(void);

#endif

