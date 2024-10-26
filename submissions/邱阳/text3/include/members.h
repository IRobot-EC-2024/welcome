#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//��Ա��
class Member
{
private:
	long long int ID = 0;	//ѧ��
	wstring name;			//����
	int YEAR = 0;			//������
	int MONTH = 0;			//����·�

public:
	//ʹ��Vector���������Ա��Ϣ
	vector<Member> exit_members;

	//Ĭ�Ϲ���
	Member();
	//���캯��
	Member(long long int id, wstring name, int year, int month);

	//��ӹ���
	void add_member();

	//ɾ������
	void delete_member();
	//ɾ������
	void remove_id(vector<Member>& exit_members, const long long int& identifier);
	void remove_name(vector<Member>& exit_members, const wstring& identifier);

	//������
	void sort_print();
	void print_partners_Info(vector<Member>& exit_members);

	//�޸Ĺ���
	void modifyMemInfo();
	//�޸Ĳ���
	bool is_id_exist(vector<Member>& exit_members, const long long int& id, int& Index);
	bool is_name_exist(vector<Member>& exit_members, const wstring& name, int& Index);

	//ѧ���Ƿ��ظ�
	bool id_is_unique(vector<Member>& exit_members, const long long int& id);
	bool name_is_unique(vector<Member>& exit_members, const wstring& name);

	//���Ҷ�Աλ��
	int exit_id(vector<Member>& exit_members, const long long int& input);//ѧ��
	int exit_name(vector<Member>& exit_members, const wstring& input);//����

	//ѧ�Ŷ���ӿ�
	long long int get_id()const;
	void set_id(long long int input_id);

	//��������ӿ�
	wstring get_name()const;
	void set_name(wstring InputName);

	//�����ݶ���ӿ�
	int get_year() const;
	void set_year(int InputYear);

	//����·ݶ���ӿ�
	int get_month() const;
	void set_month(int inputMonth);
};