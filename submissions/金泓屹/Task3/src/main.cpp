#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include"sys.h"
#include"team.h"
#include "AttendanceRecord.h"
using namespace std;
int main() {
	std::vector<AttendanceRecord> attendanceRecords;
	sys syst;
	Team team;
	int choice = 0;
	int subchoice = 0;
	int subsubchoice = 0;
	string name;
	int id;
	int year;
	int month;
	size_t num;
	int h;
	int m;
	int index;
	while (true) {
		syst.show_menu();
		//选择
		while (!(std::cin >> choice)) { // 循环直到输入成功
			std::cin.clear(); // 清除失败状态
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 忽略错误输入直到下一个换行符
			std::cout << "输入无效，请输入数字: ";
		}
		

		switch (choice) {
			//添加人员
		case 1: {

			cout << endl;
			cout << "请输入队员姓名：" << endl;
			cin >> name;
			cout << "请输入队员学号" << endl;
			while (!(std::cin >> id)) { // 循环直到输入成功
				std::cin.clear(); // 清除失败状态
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 忽略错误输入直到下一个换行符
				std::cout << "输入无效，请输入数字: ";
			}
			std::cout << "输入的学号是: " << id << std::endl;
			cout << "请输入队员入队年份" << endl;
			while (!(std::cin >> year)) { // 循环直到输入成功
				std::cin.clear(); // 清除失败状态
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 忽略错误输入直到下一个换行符
				std::cout << "输入无效，请输入数字: ";
			}
			std::cout << "输入的入队年份是: " << year << std::endl;
			cout << "请输入入队月份：" << endl;
			while (!(std::cin >> month)) { // 循环直到输入成功
				std::cin.clear(); // 清除失败状态
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 忽略错误输入直到下一个换行符
				std::cout << "输入无效，请输入数字: ";
			}
			std::cout << "输入的入队月份是: " << month << std::endl;
			team.addMember(name, id, year,month);
			cout << endl;
			cout << "添加成功！添加后的名单为：" << endl;
			cout << endl;
			team.printMembers();
			cout << endl;
			break;
		}
			  //删除人员
		case 2:{
			cout << endl;
			team.printMembers();
			cout << endl;
			cout << "请输入需要删除的是第几个队员：" << endl;
			while (!(std::cin >> num)) { // 循环直到输入成功
				std::cin.clear(); // 清除失败状态
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 忽略错误输入直到下一个换行符
				std::cout << "输入无效，请输入数字: ";
			}
			num = num - 1;
			team.removeMember(num);
			cout << endl;
			cout << "删除成功！删除后的名单为：" << endl;
			cout << endl;
			team.printMembers();
			cout << endl;
			break;
		}
			  //查询人员
		case 3: {
			cout << endl;
			cout << "请输入队员姓名：" << endl;
			cin >> name;
			
			team.printspecificMember(team.findMember(name));
			cout << endl;
			break;
		}
			  //列出所有人员
		case 4: {
			cout << endl;
			team.printMembers();
			cout << endl;
			break;
		}
			  //修改人员信息
		case 5: {
			cout << endl;
			team.printMembers();
			cout << endl;
			cout << "请输入需要更改的是第几个队员：" << endl;
			cout << endl;
			while (!(std::cin >> num)) { // 循环直到输入成功
				std::cin.clear(); // 清除失败状态
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 忽略错误输入直到下一个换行符
				std::cout << "输入无效，请输入数字: ";
			}
			num = num - 1;
			cout << endl;
			cout << "请输入队员的新名字：" << endl;
			cout << endl;
			while (!(std::cin >> name)) { // 循环直到输入成功
				std::cin.clear(); // 清除失败状态
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 忽略错误输入直到下一个换行符
				std::cout << "输入无效，请输入数字: ";
			}
			cout << endl;
			cout << "请输入队员的新学号：" << endl;
			cout << endl;
			while (!(std::cin >> id)) { // 循环直到输入成功
				std::cin.clear(); // 清除失败状态
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 忽略错误输入直到下一个换行符
				std::cout << "输入无效，请输入数字: ";
			}
			cout << endl;
			cout << "请输入队员的新入队年份：" << endl;
			cout << endl;
			while (!(std::cin >> year)) { // 循环直到输入成功
				std::cin.clear(); // 清除失败状态
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 忽略错误输入直到下一个换行符
				std::cout << "输入无效，请输入数字: ";
			}
			cout << "请输入队员的新入队月份" << endl;
			cout << endl;
			while (!(std::cin >> month)) { // 循环直到输入成功
				std::cin.clear(); // 清除失败状态
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 忽略错误输入直到下一个换行符
				std::cout << "输入无效，请输入数字: ";
			}
			team.updateMember(num, name, id, year,month);
			cout << "修改成功！修改后的名单为：" << endl;
			cout << endl;
			team.printMembers();
			cout << endl;
			break;
		}
			  //人员排序
		case 6: {
			cout << "请选择排序类型：" << endl;
			cout << "1.按学号排序" << endl;
			cout << "2.按入队时间排序" << endl;
			while (!(std::cin >> subchoice)) { // 循环直到输入成功
				std::cin.clear(); // 清除失败状态
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 忽略错误输入直到下一个换行符
				std::cout << "输入无效，请输入数字: ";
			}
			cout << "请选择排序方向：" << endl;
			cout << "1.由高到低" << endl;
			cout << "2.由低到高" << endl;
			while (!(std::cin >> subsubchoice)) { // 循环直到输入成功
				std::cin.clear(); // 清除失败状态
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 忽略错误输入直到下一个换行符
				std::cout << "输入无效，请输入数字: ";
			}
			switch (subchoice) {
			case 1: {
				switch (subsubchoice) {
				case 1:team.sortByStudentIDjian();
				case 2:team.sortByStudentIDzeng();
				}
			case 2: {
				switch (subsubchoice) {
				case 1:team.sortByStudentEntryjian();
				case 2:team.sortByStudentEntryzeng();
				}
			}
			}
			}
		}

			  //增加考勤信息
		case 7: {
			cout << "请输入队员姓名，工作时间：HH（用回车分隔）MM" << endl;
			cin >> name;
			while (!(std::cin >> h)) { // 循环直到输入成功
				std::cin.clear(); // 清除失败状态
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 忽略错误输入直到下一个换行符
				std::cout << "输入无效，请输入数字: ";
			}
			while (!(std::cin >> m)) { // 循环直到输入成功
				std::cin.clear(); // 清除失败状态
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 忽略错误输入直到下一个换行符
				std::cout << "输入无效，请输入数字: ";
			}
			if (h > 24 || h < 0 || m>60 || m < 0) {
				cout << "时间有误，请重试" << endl;
				break;
			}
			addRecord(attendanceRecords, name, h, m);
			break;
		}
			  //查询考勤信息
		case 8: {
			cout << "1.查看所有考勤记录" << endl;
			cout << "2.查询某人考勤记录" << endl;
			while (!(std::cin >> subchoice)) { // 循环直到输入成功
				std::cin.clear(); // 清除失败状态
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 忽略错误输入直到下一个换行符
				std::cout << "输入无效，请输入数字: ";
			}
			switch (subchoice) {
			case 1://查看全部的
				cout << endl;
				for (const auto& record : attendanceRecords) {
					printRecord(record);
				}
				cout << endl; break;
			case 2: //查看某个人的
				cout << "" << endl;
				cin >> name;
				cout << endl;
				printRecords(attendanceRecords, name);
				cout << endl;
				break;
			}
			break;
		}
			  //删除考勤信息
		case 9: {
			cout << "" << endl;
			while (!(std::cin >> subsubchoice)) { // 循环直到输入成功
				std::cin.clear(); // 清除失败状态
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 忽略错误输入直到下一个换行符
				std::cout << "输入无效，请输入数字: ";
			}
			switch (subsubchoice) {
			case 1://删除所有
				clearAllRecords(attendanceRecords);
			case 2://删除某人
				cout << "请输入需要删除的考勤记录所属队员姓名：(输出为空则无此人记录）" << endl;
				cin >> name;
				cout << endl;
				printRecords(attendanceRecords, name);
				cout << endl;
				cout << "1.删除此人某一条记录" << endl;
				cout << "2.删除此人所有记录" << endl;
				while (!(std::cin >> subchoice)) { // 循环直到输入成功
					std::cin.clear(); // 清除失败状态
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 忽略错误输入直到下一个换行符
					std::cout << "输入无效，请输入数字: ";
				}
				switch (subchoice) {
				case 1://删除某一条
					cout << "请输入需要删除第几条记录：" << endl;
					while (!(std::cin >> index)) { // 循环直到输入成功
						std::cin.clear(); // 清除失败状态
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 忽略错误输入直到下一个换行符
						std::cout << "输入无效，请输入数字: ";
					}
					index = index - 1;
					removeSpecificRecord(attendanceRecords, name, index);
					cout << endl;
					cout << "删除成功！删除后此人的考勤记录为：" << endl;
					printRecords(attendanceRecords, name);
					cout << endl;
					break;
				case 2://删除所有
					removeRecord(attendanceRecords, name);
				}
			}
			break;
		}
			  //修改考勤信息
		case 10: {
			cout << "请输入需要修改的考勤记录所属队员姓名：" << endl;
			cin >> name;
			printRecords(attendanceRecords, name);
			cout << "请输入需要修改第几条记录：" << endl;
			while (!(std::cin >> index)) { // 循环直到输入成功
				std::cin.clear(); // 清除失败状态
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 忽略错误输入直到下一个换行符
				std::cout << "输入无效，请输入数字: ";
			}
			index = index - 1;
			cout << "请输入修改的工作时间：HH（用回车分隔）MM" << endl;
			while (!(std::cin >> h)) { // 循环直到输入成功
				std::cin.clear(); // 清除失败状态
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 忽略错误输入直到下一个换行符
				std::cout << "输入无效，请输入数字: ";
			}
			while (!(std::cin >> m)) { // 循环直到输入成功
				std::cin.clear(); // 清除失败状态
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 忽略错误输入直到下一个换行符
				std::cout << "输入无效，请输入数字: ";
			}
			modifyRecord(attendanceRecords, name, index, h, m);
			break;
		}
			  //对考勤信息排序
		case 11: {
			cout << "请选择排序类型：" << endl;
			cout << "1.按考勤次数排序" << endl;
			cout << "2.按工作总时长排序" << endl;
			while (!(std::cin >> subchoice)) { // 循环直到输入成功
				std::cin.clear(); // 清除失败状态
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 忽略错误输入直到下一个换行符
				std::cout << "输入无效，请输入数字: ";
			}
			cout << "请选择排序方向：" << endl;
			cout << "1.由高到低" << endl;
			cout << "2.由低到高" << endl;
			while (!(std::cin >> subsubchoice)) { // 循环直到输入成功
				std::cin.clear(); // 清除失败状态
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 忽略错误输入直到下一个换行符
				std::cout << "输入无效，请输入数字: ";
			}
			switch (subchoice) {
			case 1: {
				switch (subsubchoice) {
				case 1:sortRecordsByCountjian(attendanceRecords);
				case 2:sortRecordsByCountzeng(attendanceRecords);
				}
			}
			case 2: {
				switch (subsubchoice) {
				case 1:sortRecordsByTotalMinutesjian(attendanceRecords);
				case 2:sortRecordsByTotalMinuteszeng(attendanceRecords);
				}
				break;
			}

			}
		}
				  //退出
		case 12: {
				syst.exit();
				break;
			}
			}
			}
		}

		