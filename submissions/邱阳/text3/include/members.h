#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//队员类
class Member
{
private:
	long long int ID = 0;	//学号
	wstring name;			//姓名
	int YEAR = 0;			//入队年份
	int MONTH = 0;			//入队月份

public:
	//使用Vector容器储存队员信息
	vector<Member> exit_members;

	//默认构造
	Member();
	//构造函数
	Member(long long int id, wstring name, int year, int month);

	//添加功能
	void add_member();

	//删除功能
	void delete_member();
	//删除查找
	void remove_id(vector<Member>& exit_members, const long long int& identifier);
	void remove_name(vector<Member>& exit_members, const wstring& identifier);

	//排序功能
	void sort_print();
	void print_partners_Info(vector<Member>& exit_members);

	//修改功能
	void modifyMemInfo();
	//修改查找
	bool is_id_exist(vector<Member>& exit_members, const long long int& id, int& Index);
	bool is_name_exist(vector<Member>& exit_members, const wstring& name, int& Index);

	//学号是否重复
	bool id_is_unique(vector<Member>& exit_members, const long long int& id);
	bool name_is_unique(vector<Member>& exit_members, const wstring& name);

	//查找队员位置
	int exit_id(vector<Member>& exit_members, const long long int& input);//学号
	int exit_name(vector<Member>& exit_members, const wstring& input);//姓名

	//学号对外接口
	long long int get_id()const;
	void set_id(long long int input_id);

	//姓名对外接口
	wstring get_name()const;
	void set_name(wstring InputName);

	//入队年份对外接口
	int get_year() const;
	void set_year(int InputYear);

	//入队月份对外接口
	int get_month() const;
	void set_month(int inputMonth);
};