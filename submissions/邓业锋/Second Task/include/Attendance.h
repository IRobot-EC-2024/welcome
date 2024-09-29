#ifndef    _ATTENDANCE_H_			// ��������ֹͷ�ļ��ظ�����
#define    _ATTENDANCE_H_
	
#include <iostream>		// ��׼���������
#include <map>			// ����STL��map����
#include <string>		// �ַ�������
#include <algorithm>	// �㷨

#include <ctime>		// �����й�ʱ��Ĳ���
#include <iomanip>		// �Զ���ʱ��������ʽ
#include <sstream>		// ʱ���ʽ��Ϊ�ַ���

using namespace std;		// ʹ�ñ�׼�����ռ�

// ������Ϣ��
class Attendance
{	
private:
	// ʹ��map��Ϊ�򿨼�¼���������洢��ʱ���Լ���Ӧ�Ĺ���ʱ��
	map<string, double> checkInRecords;		

	int checkInCount;		// �򿨴���
	double totalWorkTime;		// �ܹ���ʱ��(��λ:Сʱ)

public:
	
	// ����Ĭ�Ϲ��캯����ʼ��˽������
	Attendance() : checkInCount(0), totalWorkTime(0) {}

	// ��ʱ����Ϊ����ʱ�䣬����ʱ���ֶ�����
	void SetRecordValue();

	// ��Ӵ򿨼�¼����ʱ���Լ���Ӧ����ʱ����
	void addRecordInMap(string checkInTime, double workDuration);

	// �򿨼�¼�����ʾ
	void displayAllCheckInRecords() const;

	// �����ʾ���п�����Ϣ
	void PrintAllAttendanceInfo() const;

	// ������п�����Ϣ
	void ClearAllRecords();

	// �������п�����Ϣ
	void updateAttendanceInfo();

};

#endif


