#include<stdlib.h>
#include"sys.h"
sys::sys() {};
void sys::show_menu() {
	cout << endl;
	cout << "战队成员管理系统" << endl;
	cout << "1.添加人员" << endl;
	cout << "2.删除人员" << endl;
	cout << "3.查询人员" << endl;
	cout << "4.列出所有人员" << endl;
	cout << "5.修改人员信息" << endl;
	cout << "6.人员排序" << endl;
	cout << "7.增加考勤信息" << endl;
	cout << "8.查询考勤信息" << endl;
	cout << "9.删除考勤信息" << endl;
	cout << "10.修改考勤信息" << endl;
	cout << "11.对考勤信息排序" << endl;
	cout << "12.退出" << endl;
	cout << endl;
}
void sys::exit() {
	cout << endl;
	cout << "下次一定" << endl;
	cout << endl;
	system("pause");
	exit();
}
sys::~sys(){};