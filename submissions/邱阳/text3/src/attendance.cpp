#include "attendance.h"

//��Ӵ򿨼�¼��map����
void Attendance::add_time(string check_in_out_time, double work_time)
{
	check_records[check_in_out_time] = work_time;			//map��key+Value
	check_num++;											//��¼�򿨴���
	work_total_time += work_time;							//��¼����ʱ��
}

//��ȡ��ʱ��
void Attendance::check_time_get()
{
	system("cls");
	if (check_in_out == 0)//�жϴ�Ϊ�ϰ�����°�
	{
		time_t time_in = time(NULL);			//��ȡ��ǰʱ��
		tm* time_tm = localtime(&time_in);		//ʱ���ת��Ϊtm�ṹ��
		//��ʽ��ʱ���ַ���
		stringstream Strstream;
		Strstream << put_time(time_tm, "%Y��%m��%d��%H:%M:%S");
		check_in_time = Strstream.str();
		cout << "�ϰ�ʱ��Ϊ��" << check_in_time << endl;
		check_in_out = 1;
		work_time_ = time_in;
		system("pause");
		system("cls");
	}
	else
	{
		time_t time_out = time(NULL);			//��ȡ��ǰʱ��
		tm* time_tm = localtime(&time_out);		//ʱ���ת��Ϊtm�ṹ��
		//��ʽ��ʱ���ַ���
		stringstream Strstream;
		Strstream << put_time(time_tm, "%Y��%m��%d��%H:%M:%S");
		check_out_time = Strstream.str();
		cout << "�°�ʱ��Ϊ��" << check_out_time << endl;
		check_in_out = 0;
		work_time_ = time_out - work_time_;
		work_time = (double)work_time_ / 3600;
		string check_in_out_time = check_in_time + check_out_time;
		add_time(check_in_out_time, work_time);
		system("pause");
		system("cls");
	}
}

//�򿨼�¼�����ʾ
void Attendance::print_check_record() const
{
	for (const auto& print_record : check_records)
	{
		cout << "�����ڼ�ʱ�䣺" << print_record.first
			<< " ����ʱ��:" << print_record.second << "Сʱ" << endl;
	}
	cout << "��������������˵���";
	system("pause");
	system("cls");

}

//�����ʾ���п�����Ϣ
void Attendance::print_all_record() const
{
	if (check_num != 0)
	{	
		cout << "����Ϊ�ö���Ŀ�����Ϣ:" << endl;
		cout << "�򿨴���:" <<  check_num << " �ܹ���ʱ��:" << work_total_time << "Сʱ" << endl;
		cout << "�򿨼�¼:" << endl;
		print_check_record();
	} 
	else
	{
		cout << "�򿨴���Ϊ0���޴򿨼�¼��" << endl;
		system("pause");
		system("cls");
	}
}

//������п��ڼ�¼
void Attendance::clear_all_records()
{	
	if (check_num != 0)
	{	
		cout << "ȷ�� *ɾ��* ���п��ڼ�¼ô��(yes:1 / no:0)" << endl;
		int choice;
		cin >> choice;

		if (choice == 1)
		{
			cout << "���ٴ�ȷ�ϡ�(yes:1 / no:0)" << endl;
			if (choice == 1)
			{
				cout << "�������" << endl;

				check_records.clear();
				check_num = 0;
				work_total_time = 0;

				system("pause");
				system("cls");
			}
			else
			{
				cout << "��ȡ����" << endl;
				system("pause");
				system("cls");
			}
		}
		else
		{
			cout << "��ȡ����" << endl;
			system("pause");
			system("cls");
		}
	}
	else
	{
		cout << "�򿨴���Ϊ0���޴򿨼�¼��" << endl;
		system("pause");
		system("cls");
	}
}

//�޸��ض����ڵĿ�����Ϣ
void Attendance::change_update()
{
	system("cls");
	int back2 = 1;
	while (back2)
	{
		if (check_num != 0)
		{
			cout << "����Ϊ�ö���Ŀ�����Ϣ:" << endl;
			cout << "�򿨴���:" << check_num << " �ܹ���ʱ��:" << work_total_time << "Сʱ" << endl;
			cout << "�򿨼�¼:" << endl;
			int i = 0;
			for (const auto& print_record : check_records)
			{
				i++;
				cout << i << ".�����ڼ�ʱ�䣺" << print_record.first << "\n����ʱ��: " << print_record.second << "Сʱ" << endl;
			}

			string input_time;
			cout << "��������Ҫ�޸ĵĴ򿨼�¼�Ĵ�����:" << endl;
			cin >> input_time;

			if (time_format(input_time))
			{	
				auto it = check_records.find(input_time);
				if (it != check_records.end())
				{
					work_total_time -= check_records[input_time];
					check_num--;
					check_records.erase(input_time);
					string new_check_in_time;
					string new_check_out_time;
					time_t new_in_time;
					time_t new_out_time;
					while (1)
					{
						system("cls");
						cout << "�������µ��ϰ�ʱ��: ";
						cin >> new_check_in_time;
						if (add_time_format(new_check_in_time))
						{
							tm time_struct_in = {};
							istringstream (check_in_time) >> get_time(&time_struct_in, "%Y��%m��%d��%H:%M:%S");
							new_in_time = mktime(&time_struct_in);
							break;
						}
						else
						{
							cout << "�����ʽ�����밴�ո�ʽ���롣��YYYY��MM��DD��HH:MM:SS��" << endl;
						}
					}
					while(1)
					{
						system("cls");
						cout << "�������µ��°�ʱ��: ";
						cin >> new_check_out_time;
						if (add_time_format(new_check_out_time))
						{
							tm time_struct_out = {};
							istringstream(new_check_out_time) >> get_time(&time_struct_out, "%Y��%m��%d��%H:%M:%S");
							new_out_time = mktime(&time_struct_out);
							if(new_out_time > new_in_time)
							{
								break;
							}
							else
							{
								cout << "�°�ʱ�䲻�������������롣" << endl;
								system("pause");
							}
						}
						else
						{
							cout << "�����ʽ�����밴�ո�ʽ���롣��YYYY��MM��DD��HH:MM:SS��" << endl;
						}
					}
					string check_in_out_time = new_check_in_time + new_check_out_time;
					work_time_ = new_out_time - new_in_time;
					work_time = (double)work_time_ / 3600;
					add_time(check_in_out_time, work_time);
					cout << "�޸ĳɹ�" << endl;
					back2 = 0;
				}
				else
				{
					cout << "δ�ҵ�ָ�����ڵĿ��ڼ�¼�����������롣\n(����ֱ�Ӹ���)" << endl;
					system("pause");
					system("cls");
				}
			}
			else
			{
				cout << "�����ʱ���ʽ����ȷ���밴�ա�YYYY��MM��DD��HH:MM:SSYYYY��MM��DD��HH:MM:SS���ĸ�ʽ���롣\n(����ֱ�Ӹ���)" << endl;
				system("pause");
				system("cls");
			}
		}
		else
		{
			cout << "�򿨴���Ϊ0���޴򿨼�¼��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

//����ʱ���ʽ�ж�
bool Attendance::time_format(const string& input_time)
{
	istringstream ss(input_time);
	tm tm = {};

	try
	{
		ss >> get_time(&tm, "%Y��%m��%d��%H:%M:%S%Y��%m��%d��%H:%M:%S");
		if (ss.fail())
		{
			return false;
		}
	}
	catch (exception& attendance)
	{
		return false;
	}
	return true;
}
bool Attendance::add_time_format(const string& input_time)
{
	istringstream ss(input_time);
	tm tm = {};

	try
	{
		ss >> get_time(&tm, "%Y��%m��%d��%H:%M:%S");
		if (ss.fail())
		{
			return false;
		}
	}
	catch (exception& attendance)
	{
		return false;
	}
	return true;
}
