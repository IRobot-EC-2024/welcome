#pragma once
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
using namespace std;

//������Ϣ��
class Attendance
{	
private:
	int check_num;				//�򿨴���
	double work_total_time;		//�ܹ���ʱ��
	int check_in_out = 0;		//��¼��״̬
	double work_time{};							//��¼����ʱ��
	long long int work_time_ = 0;				//��¼����ʱ��
	string check_in_time, check_out_time;		//��¼����ʱ��
	string check_in_out_time;					//��¼����ʱ��

public:
	//ʹ��map�����ʱ��͹���ʱ��
	map<string, double> check_records;		

	//��ȡ��ʱ��
	void check_time_get();

	//��Ӵ򿨼�¼��map����
	void add_time(string check_in_time, double work_time);

	//�򿨼�¼�����ʾ
	void print_check_record() const;

	//�����ʾ���п�����Ϣ
	void print_all_record() const;

	//������п�����Ϣ
	void clear_all_records();

	//�޸��ض����ڵĿ�����Ϣ
	void change_update();

	//����ʱ���ʽ�ж�
	bool time_format(const string& input_time);
	bool add_time_format(const string& input_time);
};



