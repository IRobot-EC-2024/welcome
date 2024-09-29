#pragma once			// ��ֹͷ�ļ��ظ�����

#include <iostream>		// ��׼���������
#include <vector>		// ����STL��vector����
#include <string>		// �ַ�������
#include <algorithm>	// �㷨

using namespace std;		// ʹ�ñ�׼�����ռ�

// ��Ա��
class Member
{
private:

	wstring studentID;		// ѧ��
	wstring name;			// ����

	int enrollmentYear = 0;			// ������
	int enrollmentMonth = 0;		// ����·�

public:
	// ����һ�� vector �����洢 Member ����
	vector<Member> membersVector;

	// Ĭ�Ϲ���
	Member();
	// ���캯��
	Member(wstring id, wstring name, int year, int month);

	/*���ܺ���*/
	// ���
	void addMember();

	// ɾ��
	void deleteMember();

	// ������ʾ
	void sortedPrintInfo();

	// �޸�
	void modifyMemInfo();


	/*����ӿ�*/

	// ѧ�Ŷ���ӿ�
	wstring GetStudentID();
	void SetStudentID(wstring InputID);

	// ��������ӿ�
	wstring GetName();
	void SetName(wstring InputName);

	// �����ݶ���ӿ�
	int GetYear() const;
	void SetYear(int InputYear);

	// ����·ݶ���ӿ�
	int GetMonth() const;
	void SetMonth(int inputMonth);

};