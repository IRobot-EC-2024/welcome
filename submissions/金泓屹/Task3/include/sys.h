#ifndef SYS_H
#define SYS_H
#include<iostream>
using namespace std; 
class sys {
public:
	sys();//���캯��
	void show_menu();
	void exit();
	virtual ~sys();//��������
};
#endif // SYS_H