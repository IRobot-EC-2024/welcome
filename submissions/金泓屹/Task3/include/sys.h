#ifndef SYS_H
#define SYS_H
#include<iostream>
using namespace std; 
class sys {
public:
	sys();//构造函数
	void show_menu();
	void exit();
	virtual ~sys();//析构函数
};
#endif // SYS_H