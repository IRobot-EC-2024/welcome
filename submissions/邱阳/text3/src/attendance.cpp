#include "attendance.h"

//添加打卡记录到map容器
void Attendance::add_time(string check_in_out_time, double work_time)
{
	check_records[check_in_out_time] = work_time;			//map的key+Value
	check_num++;											//记录打卡次数
	work_total_time += work_time;							//记录工作时长
}

//获取打卡时间
void Attendance::check_time_get()
{
	system("cls");
	if (check_in_out == 0)//判断打卡为上班或者下班
	{
		time_t time_in = time(NULL);			//获取当前时间
		tm* time_tm = localtime(&time_in);		//时间戳转换为tm结构体
		//格式化时间字符串
		stringstream Strstream;
		Strstream << put_time(time_tm, "%Y年%m月%d日%H:%M:%S");
		check_in_time = Strstream.str();
		cout << "上班时间为：" << check_in_time << endl;
		check_in_out = 1;
		work_time_ = time_in;
		system("pause");
		system("cls");
	}
	else
	{
		time_t time_out = time(NULL);			//获取当前时间
		tm* time_tm = localtime(&time_out);		//时间戳转换为tm结构体
		//格式化时间字符串
		stringstream Strstream;
		Strstream << put_time(time_tm, "%Y年%m月%d日%H:%M:%S");
		check_out_time = Strstream.str();
		cout << "下班时间为：" << check_out_time << endl;
		check_in_out = 0;
		work_time_ = time_out - work_time_;
		work_time = (double)work_time_ / 3600;
		string check_in_out_time = check_in_time + check_out_time;
		add_time(check_in_out_time, work_time);
		system("pause");
		system("cls");
	}
}

//打卡记录输出显示
void Attendance::print_check_record() const
{
	for (const auto& print_record : check_records)
	{
		cout << "打卡日期及时间：" << print_record.first
			<< " 工作时长:" << print_record.second << "小时" << endl;
	}
	cout << "按任意键返回主菜单。";
	system("pause");
	system("cls");

}

//输出显示所有考勤信息
void Attendance::print_all_record() const
{
	if (check_num != 0)
	{	
		cout << "以下为该对象的考勤信息:" << endl;
		cout << "打卡次数:" <<  check_num << " 总工作时长:" << work_total_time << "小时" << endl;
		cout << "打卡记录:" << endl;
		print_check_record();
	} 
	else
	{
		cout << "打卡次数为0，无打卡记录。" << endl;
		system("pause");
		system("cls");
	}
}

//清空所有考勤记录
void Attendance::clear_all_records()
{	
	if (check_num != 0)
	{	
		cout << "确定 *删除* 所有考勤记录么？(yes:1 / no:0)" << endl;
		int choice;
		cin >> choice;

		if (choice == 1)
		{
			cout << "请再次确认。(yes:1 / no:0)" << endl;
			if (choice == 1)
			{
				cout << "已清除。" << endl;

				check_records.clear();
				check_num = 0;
				work_total_time = 0;

				system("pause");
				system("cls");
			}
			else
			{
				cout << "已取消。" << endl;
				system("pause");
				system("cls");
			}
		}
		else
		{
			cout << "已取消。" << endl;
			system("pause");
			system("cls");
		}
	}
	else
	{
		cout << "打卡次数为0，无打卡记录。" << endl;
		system("pause");
		system("cls");
	}
}

//修改特定日期的考勤信息
void Attendance::change_update()
{
	system("cls");
	int back2 = 1;
	while (back2)
	{
		if (check_num != 0)
		{
			cout << "以下为该对象的考勤信息:" << endl;
			cout << "打卡次数:" << check_num << " 总工作时长:" << work_total_time << "小时" << endl;
			cout << "打卡记录:" << endl;
			int i = 0;
			for (const auto& print_record : check_records)
			{
				i++;
				cout << i << ".打卡日期及时间：" << print_record.first << "\n工作时长: " << print_record.second << "小时" << endl;
			}

			string input_time;
			cout << "输入您想要修改的打卡记录的打卡日期:" << endl;
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
						cout << "请输入新的上班时间: ";
						cin >> new_check_in_time;
						if (add_time_format(new_check_in_time))
						{
							tm time_struct_in = {};
							istringstream (check_in_time) >> get_time(&time_struct_in, "%Y年%m月%d日%H:%M:%S");
							new_in_time = mktime(&time_struct_in);
							break;
						}
						else
						{
							cout << "输入格式有误，请按照格式输入。（YYYY年MM月DD日HH:MM:SS）" << endl;
						}
					}
					while(1)
					{
						system("cls");
						cout << "请输入新的下班时间: ";
						cin >> new_check_out_time;
						if (add_time_format(new_check_out_time))
						{
							tm time_struct_out = {};
							istringstream(new_check_out_time) >> get_time(&time_struct_out, "%Y年%m月%d日%H:%M:%S");
							new_out_time = mktime(&time_struct_out);
							if(new_out_time > new_in_time)
							{
								break;
							}
							else
							{
								cout << "下班时间不合理，请重新输入。" << endl;
								system("pause");
							}
						}
						else
						{
							cout << "输入格式有误，请按照格式输入。（YYYY年MM月DD日HH:MM:SS）" << endl;
						}
					}
					string check_in_out_time = new_check_in_time + new_check_out_time;
					work_time_ = new_out_time - new_in_time;
					work_time = (double)work_time_ / 3600;
					add_time(check_in_out_time, work_time);
					cout << "修改成功" << endl;
					back2 = 0;
				}
				else
				{
					cout << "未找到指定日期的考勤记录。请重新输入。\n(建议直接复制)" << endl;
					system("pause");
					system("cls");
				}
			}
			else
			{
				cout << "输入的时间格式不正确，请按照“YYYY年MM月DD日HH:MM:SSYYYY年MM月DD日HH:MM:SS”的格式输入。\n(建议直接复制)" << endl;
				system("pause");
				system("cls");
			}
		}
		else
		{
			cout << "打卡次数为0，无打卡记录。" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

//输入时间格式判断
bool Attendance::time_format(const string& input_time)
{
	istringstream ss(input_time);
	tm tm = {};

	try
	{
		ss >> get_time(&tm, "%Y年%m月%d日%H:%M:%S%Y年%m月%d日%H:%M:%S");
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
		ss >> get_time(&tm, "%Y年%m月%d日%H:%M:%S");
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
