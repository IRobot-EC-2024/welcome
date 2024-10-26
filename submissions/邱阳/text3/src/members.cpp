#include "members.h"
using namespace std;

//����ʽ
bool up_id(Member& a, Member& b);
bool down_id(Member& a, Member& b);
bool up_join_time(Member& a, Member& b);
bool down_join_time(Member& a, Member& b);

//Ĭ�Ϲ���
Member::Member(){}
//���캯��
Member::Member(long long int id, wstring name, int year, int month):
	ID(id),
	name(name),
	YEAR(year), MONTH(month){}

//���
void Member::add_member()
{	
	long long int input_id = 0;
	wstring input_name;
	int year, month;

	//ѧ��
	while (1)
	{
		system("cls");
		cout << "�������¶�Ա��ѧ��:" << endl;
		cin >> input_id;

		if (input_id >= 10000000000 && input_id <= 99999999999) 
		{
			if (id_is_unique(exit_members, input_id))
			{
				ID = input_id;
				break;
			}
			else
			{
				cout << "ѧ���ظ������������롣" << endl;
				system("pause");
			}
		}
		else
		{
			cout << "ѧ�Ÿ�ʽ����ȷ�����������롣" << endl;
			system("pause");
		}
	}

	//����
	while (1)
	{
		system("cls");
		cout << "�������¶�Ա����:" << endl;
		wcin >> input_name;

		if (input_name.empty())
		{
			cout << "��������Ϊ�գ����������롣" << endl;
		}
		else 
		{ 
			if (name_is_unique(exit_members, input_name))
			{
				name = input_name;
				break;
			}
			else
			{
				cout << "�����ظ������������롣" << endl;
				system("pause");
			}
		}
	}
	//��������֤
	while (1)
	{	
		system("cls");
		cout << "������������:" << endl;
		cin >> year;

		if (year >= 2016 && year <= 2024)
		{
			YEAR = year; 
			break;
		} 
		else
		{
			cout << "�����������������������ݡ�" << endl;
			system("pause");
		}
	} 
	//����·���֤
	while (1)
	{
		system("cls");
		cout << "����������·�:" << endl;
		cin >> month;

		if (month >= 1 && month <= 12)
		{
			MONTH = month;
			break;
		} 
		else
		{
			cout << "�����·�������������ȷ���·ݡ�" << endl;
			system("pause");
		}
	}

	Member new_member(ID, name, YEAR, MONTH);
	exit_members.push_back(new_member);
	system("cls");
	cout << "�¶�Ա��Ϣ��ӳɹ���" << endl;
	system("pause");
	system("cls");
}

//ѧ��Ψһ���ж�
bool Member::id_is_unique(vector<Member>& exit_members,const long long int& id)
{
	bool unique = true;
	for (int i = 0; i < exit_members.size(); i ++)
	{
		if(exit_members[i].get_id() == id)
		{
			unique = false;
			break;
		}
	}
	return unique;
}
//����Ψһ���ж�
bool Member::name_is_unique(vector<Member>& exit_members, const wstring& name)
{
	bool unique = true;
	for (int i = 0; i < exit_members.size(); i++)
	{
		if (exit_members[i].get_name() == name)
		{
			unique = false;
			break;
		}
	}
	return unique;
}

//ɾ��
void Member::delete_member()
{	

	if (exit_members.size() == 0)
	{
		cout << "Ŀǰ�޶�Ա��Ϣ������ӡ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		system("cls");
		int back1 = 1;
		//����ƥ���ж�
		while (back1)
		{
			cout << "����Ϊ�ֶ�Ա������Ϣ:" << endl;
			for (int i = 0; i < exit_members.size(); i++)
			{
				wcout << "ѧ��: " << exit_members[i].ID
					<< "\t ����: " << exit_members[i].name
					<< "\t �������: " << exit_members[i].YEAR << "��" << exit_members[i].MONTH << "��" << endl;
			}
			cout << "��ѡ����Ҹö�Ա��ʽ��\n0.���ء�\n1.��ѧ�Ų��ҡ�\n2.���������ҡ�" << endl;
			int choice_modity = -1;
			cin >> choice_modity;
			int index;
			long long int id = 0;
			wstring name;

			switch (choice_modity)
			{
				case 0:
				{
					back1 = 0;
					system("cls");
					break;
				}
				case 1:
				{
					//��ѧ�Ų���
					system("cls");
					cout << "��������Ҫɾ����Ϣ�Ķ�Ա��ѧ�ţ�" << endl;
					cin >> id;
					index = exit_id(exit_members, id);
					if (index != -1)
					{
						remove_id(exit_members, id);
						print_partners_Info(exit_members);
						cout << "ɾ���ɹ���" << endl;
						break;
					}
					else
					{
						cout << "����ʧ�ܣ����޴��ˡ�" << endl;
						system("pause");
					}
					system("cls");
				}
				break;
				case 2:
				{
					//����������
					system("cls");
					cout << "��������Ҫɾ����Ϣ�Ķ�Ա��������" << endl;
					wcin >> name;
					index = exit_name(exit_members, name);
					if (index != -1)
					{
						remove_name(exit_members, name);
						print_partners_Info(exit_members);
						cout << "ɾ���ɹ���" << endl;
						break;
					}
					else
					{
						cout << "����ʧ�ܣ����޴��ˡ�" << endl;
						system("pause");
					}
					system("cls");
				}
				break;
				default:
				{
					cout << "�����������������롣" << endl;
					system("pause");
					system("cls");
				}
			}
		}
	}
}

//VectorԪ��ɾ��
void Member::remove_id(vector<Member>& exit_members, const long long int& identifier)//ѧ��
{
	long long int id =identifier;
	for (auto it = exit_members.begin(); it != exit_members.end();)
	{
		if (it->get_id() == long long int(id))
		{
			it = exit_members.erase(it);
		}
		else
		{
			++it;
		}
	}
}
void Member::remove_name(vector<Member>&exit_members, const wstring& identifier)//����
{
	wstring name = identifier;
	for (auto it = exit_members.begin(); it != exit_members.end(); )
	{
		if (it -> get_name() == identifier)
		{
			it = exit_members.erase(it);
		}
		else 
		{ 
			++it; 
		}
	}
	cout << "ɾ���ɹ�!������ʣ�����ж�Ա����Ϣ��" << endl;
	system("pause");
	system("cls");
}

//������ʾ
void Member::sort_print()
{	
	if (exit_members.size() == 0)
	{
		cout << "Ŀǰ�޶�Ա��Ϣ������ӡ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		while (1)
		{
			system("cls");
			cout << "��ѡ������һ������ʽ�г���Ϣ��" << endl;
			cout << "0.���ء�" << endl;
			cout << "1.��ѧ���������С�" << endl;
			cout << "2.��ѧ�Ž������С�" << endl;
			cout << "3.����������������С�" << endl;
			cout << "4.��������½������С�" << endl;
			cout << "����������ѡ��:" << endl;
			
			int sort_choice;
			cin >> sort_choice;

			switch (sort_choice)
			{
			case 0:
				system("cls");
				return;
			case 1:
				sort(exit_members.begin(), exit_members.end(), up_id);
				print_partners_Info(exit_members);
				break;
			case 2:
				sort(exit_members.begin(), exit_members.end(), up_join_time);
				print_partners_Info(exit_members);
				break;
			case 3:
				sort(exit_members.begin(), exit_members.end(), down_id);
				print_partners_Info(exit_members);
				break;
			case 4:
				sort(exit_members.begin(), exit_members.end(), down_join_time);
				print_partners_Info(exit_members);
				break;
			default:
				cout << "��Чѡ����������롣" << endl;
				system("pause");
				system("cls");
				break;
			}
		} 
	}
}

//�����Ϣ
void Member::print_partners_Info(vector<Member>& exit_members)
{

	if(exit_members.size() == 0)
	{
		cout << "Ŀǰ�޶�Ա��Ϣ������ӡ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		system("cls");

		cout << "���¼�Ϊ�ֶ�Ա������Ϣ:" << endl;
		for (int i = 0; i < exit_members.size(); i++)
		{
			wcout << "ѧ��:" << exit_members[i].get_id()
				<< " ����:" << exit_members[i].get_name()
				<< " �������:" << exit_members[i].get_year() << "��" << exit_members[i].get_month() << "��" << endl;
		}

		cout << "��������ص��˵���";
		system("pause");
		system("cls");
	}
}

//����
//ѧ������
bool up_id(Member& a, Member& b)
{
	return a.get_id() < b.get_id();
}
//ѧ�Ž���
bool down_id(Member& a, Member& b)
{
	return a.get_id() > b.get_id();
}
//�����������
bool up_join_time(Member& a, Member& b)
{
	if (a.get_year() != b.get_year())
	{
		return a.get_year() < b.get_year();
	}
	else
	{
		return a.get_month() < b.get_month();
	}
}
//������ڽ���
bool down_join_time(Member& a, Member& b)
{
	if (a.get_year() != b.get_year())
	{
		return a.get_year() > b.get_year();
	}
	else
	{
		return a.get_month() > b.get_month();
	}
}

//�޸�
void Member::modifyMemInfo()
{

	if (exit_members.size() == 0)
	{
		cout << "Ŀǰ�޶�Ա��Ϣ������ӡ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		long long int input_id;
		wstring input_name;
		int Index = 0;
		int back1 = 1;
		int choice_find;
		while(back1)
		{
			system("cls");
			//��ʾ��Ա�б�
			cout << "����Ϊ�ֶ�Ա������Ϣ:" << endl;
			for (int i = 0; i < exit_members.size(); i++)
			{
				wcout << "ѧ��: " << exit_members[i].ID
					<< "\t ����: " << exit_members[i].name
					<< "\t �������: " << exit_members[i].YEAR << "��" << exit_members[i].MONTH << "��" << endl;
			}
			cout << "����������Ҫ��ѯ��Ա�ķ�ʽ��\n0.���ء�\n1.��ѧ�Ų��ҡ�\n2.���������ҡ�" << endl;
			cin >> choice_find;
			switch(choice_find)
			{
			case 0:
				system("cls");
				back1 = 0;
				break;
			case 1:
				while(1)
				{
					cout << "��������Ҫ�޸���Ϣ�Ķ�Ա��ѧ�š�" << endl;
					cin >> input_id;
					//��֤ѧ���Ƿ����
					if (ID >= 10000000000 && ID <= 99999999999)
					{
						if (is_id_exist(exit_members, input_id, Index))
						{
							back1 = 0;
							break;
						}
						else
						{
							cout << "�������ѧ�Ų����ڣ����������롣" << endl;
							system("pause");
							system("cls");
						}
					}
					else
					{
						cout << "ѧ�Ÿ�ʽ����ȷ�����������롣" << endl;
						system("pause");
					}
				}
				break;
			case 2:
				while(1)
				{
					cout << "��������Ҫ�޸���Ϣ�Ķ�Ա��������" << endl;
					wcin >> input_name;
					//��֤�����Ƿ����
					if (is_name_exist(exit_members, input_name, Index))
					{
						back1 = 0;
						break;
					}
					else
					{
						cout << "�������ѧ�Ų����ڣ����������롣" << endl;
						system("pause");
						system("cls");
					}
				}
				break;
			default:
				cout << "�����������������롣" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		//�޸����岿��
		long long int input_new_id;
		wstring	input_new_name;
		int new_year, new_month;
		int back2 = 1;
		while(back2)
		{
			system("cls");
			//ѡ���޸ĵ�����
			int choice_sort;
			cout << "����������ѡ��" << endl;
			cout << "0.���ء�\n1.����ѧ�š�\n2.����������\n3.���������ݡ�\n4.��������·ݡ�" << endl;
			cin >> choice_sort;

			switch (choice_sort)
			{
			case 0:
				back2 = 0;
				system("cls");
				break;
			case 1:
				while(1)
				{
					system("cls");
					cout << "�������µĶ�Աѧ��: ";
					cin >> input_new_id;
					if (input_new_id >= 10000000000 && input_new_id <= 99999999999)
					{
						if (id_is_unique(exit_members, input_new_id))
						{
							exit_members[Index].ID = input_new_id;
							cout << "�޸ĳɹ���" << endl;
							system("pause");
							break;
						}
						else
						{
							cout << "ѧ���ظ������������롣" << endl;
							system("pause");
						}
					}
					else
					{
						cout << "ѧ�Ÿ�ʽ����ȷ�����������롣" << endl;
						system("pause");
					}
				}
			case 2:
				while (1)
				{
					system("cls");

					cout << "�����µĶ�Ա����: ";
					wcin >> input_new_name;
					if (!input_new_name.empty())
					{
						if (name_is_unique(exit_members, input_new_name))
						{
							exit_members[Index].name = input_new_name;
							cout << "�޸ĳɹ���" << endl;
							system("pause");
							break;
						}
						else
						{
							cout << "�����ظ������������롣" << endl;
							system("pause");
						}
					}
					else
					{
						cout << "��������Ϊ�գ����������롣" << endl;
					}
				}
			case 3:
				while (1)
				{
					system("cls");
					cout << "�������µ�������: ";
					cin >> new_year;
					if (new_year >= 2016 && new_year <= 2025)
					{
						exit_members[Index].YEAR = new_year;
						cout << "�޸ĳɹ���" << endl;
						system("pause");
						break;
					}
					else
					{
						cout << "���������ֵ�������������롣" << endl;
						system("pause");
					}
				}
			case 4:
				while (1)
				{
					system("cls");
					cout << "�������µ�����·�: ";
					cin >> new_month;
					if (new_month >= 1 && new_month <= 12)
					{
						exit_members[Index].MONTH = new_month;
						cout << "�޸ĳɹ���" << endl;
						system("pause");
						break;
					}
					else
					{
						cout << "�����·���ֵ�������������롣" << endl;
						system("pause");
					}
				}
			default:
				cout << "��������" << endl;
				break;
			}
		system("cls");
		print_partners_Info(exit_members);
		system("cls");
		}
	}
}

//����ָ��ѧ�ŵĶ�Ա��Ϣ
bool Member::is_id_exist( vector<Member>& exit_members, const long long int& id, int& Index)
{
	for (int i = 0; i < exit_members.size(); ++i)
	{
		if(exit_members[i].get_id() == id)
		{
			Index = i;
			return true;
		}
	}
	return false;
}
//����ָ�������Ķ�Ա��Ϣ
bool Member::is_name_exist(vector<Member>& exit_members, const wstring& name, int& Index)
{
	for (int i = 0; i < exit_members.size(); ++i)
	{
		if (exit_members[i].get_name() == name)
		{
			Index = i;
			return true;
		}
	}
	return false;
}


//�ж϶�Ա�Ƿ���ڣ���������Ӧ��Ա�����е�λ��
int Member::exit_id(vector<Member>& exit_members, const long long int& input)//ѧ��
{
	int index = -1;

	for (int i = 0; i < exit_members.size(); i++)
	{
		if (exit_members[i].get_id() == input)
		{
			index = i;
			break;
		}
	}
	return index;
}
int Member::exit_name(vector<Member>& exit_members, const wstring& input)//����

{
	int index = -1;

	for (int i = 0; i < exit_members.size(); i++)
	{
		if (exit_members[i].get_name() == input)
		{
			index = i;
			break;
		}
	}
	return index;
}

// ѧ�Ŷ���ӿ�
long long int Member::get_id()const
{
	return ID;
}
void Member::set_id(long long int input_id)
{
	ID = input_id;
}

//��������ӿ�
wstring Member::get_name() const
{
	return name;
}
void Member::set_name(wstring InputName)
{
	name = InputName;
}

//�����ݶ���ӿ�
int Member::get_year() const 
{
	return YEAR; 
}
void Member::set_year(int InputYear) 
{ 
	YEAR = InputYear; 
}

//����·ݶ���ӿ�
int Member::get_month() const 
{ 
	return MONTH; 
}
void Member::set_month(int InputMonth) 
{
	MONTH = InputMonth; 
}
