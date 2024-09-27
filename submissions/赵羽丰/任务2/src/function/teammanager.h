#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip> //get_time()
//成员管理系统
using namespace std;

class Teamer
{
public:
	string ID; 
	string Name;
	int Year; 
	int Month;
	int Day;

};



class TeamManager
{
public:
	void Show_Menu();
	void Add_Teamer();
	int  Delete_Teamer();
	void List_All_Teamers();
	void Change_Teamer();
	long Search_Teamer();
	//void Updata_Teamer();

};
