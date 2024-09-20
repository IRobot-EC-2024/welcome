#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip> //get_time()
//考勤管理系统



using namespace std;




class Worker
{
public:
	string ID;
	string Name;
};




class WorkerManager
{
public:

	void Add_Worker();
	void Show_Menu();
	int  Delete_Worker();
	void List_All_Workers();
	void Search_Time();
	long Search_Work();

};




