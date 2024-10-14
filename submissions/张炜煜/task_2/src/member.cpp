#include "member.h"

using namespace std;

// 显式声明默认构造
member::member(){}
// 构造（可用this指针）
member::member(wstring id, wstring name, int year, int month ,int day) :
	_ID(id),
	_name(name),
	_year(year), _month(month), _day(day){}
int number=1;
void member::AddMember()
{	
	wstring ID;
	wstring name;
	wstring year, month,day;

	do{
		cout << "\n请输入学号: ";
		getline(wcin, ID);
		ID.erase(remove_if(ID.begin(), ID.end(), ::iswspace), ID.end());		
		if (ID.length() == 11 && all_of(ID.begin(), ID.end(), ::isdigit))
		{
			_ID=ID;///////////////
			break;		
		}
		else
		{
			cout << "学号格式不正确,请输入11位数字。" << endl;
			system("pause");
		}

	}while (1);
	// 姓名验证
	do 
	{
		cout << "\n新队员姓名: ";
		getline(wcin, name);
		name.erase(remove_if(name.begin(), name.end(), ::isspace), name.end());

		if (name.empty())
		{
			cout << "姓名不能为空,请重新输入。" << endl;;
			continue;
		}
		else
		{ 
			_name=name;////////////
			break; 
		}

	} while (true);

	// 入队年份验证
	do {
		cout << "\n请输入入队年份: ";
		getline(wcin, year);
		year.erase(remove_if(year.begin(), year.end(), ::iswspace), year.end());					

		if (year.length() == 4 && all_of(year.begin(), year.end(), ::isdigit))
		{	
			_year=stoi(year);///////////////
			break;
		}
		else
		{
			cout << "输入年份格式错误,请重新输入" << endl;
		}

	} while (true);

	// 入队月份验证
	do {
		cout << "\n请输入入队月份: ";
		getline(wcin, month);
		month.erase(remove_if(month.begin(), month.end(), ::iswspace), month.end());	

		if ((month.length() == 1 || month.length() == 2) && all_of(month.begin(), month.end(), ::isdigit))
		{	
			if (stoi(month) >= 1 && stoi(month) <= 12)
			{
				_month=stoi(month);//////////////
				break;
			} 
			else
			{
				cout << "输入月份数值错误,请输入1-12间数字" << endl;
			}
		}
		else
		{
			cout << "输入月份格式错误,请重新输入" << endl;
		}

	} while (true);

	// 入队日期验证
	do {
		cout << "\n请输入入队日期: ";
		getline(wcin, day);
		day.erase(remove_if(day.begin(), day.end(), ::iswspace), day.end());	

		if ((day.length() == 1 || day.length() == 2) && all_of(day.begin(), day.end(), ::isdigit))
		{	
			if (stoi(day) >= 1 && stoi(day) <= 31)
			{
				_day=stoi(day);
				break;
			} 
			else
			{
				cout << "输入日期数值错误,请输入1-31间数字" << endl;
			}
		}
		else
		{
			cout << "输入日期格式错误,请重新输入" << endl;
		}

	} while (true);
	member newMember(_ID, _name, _year, _month, _year);
	member_vector.push_back(newMember);
	cout << member_vector.size() << endl;
	cout << "\n信息添加成功!" << endl;
	do
	{
		cout << "\n保存信息中" << endl;
		FILE* fp = fopen("members.txt","a");
		if(!fp)
		{
			cout << "\n文件打开失败" << endl;
			
		}else{
			wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
   			string text = converter.to_bytes(name);

			fprintf(fp,"序号:%d 学号:%llu 姓名:%s 入队时间:%d 年 %d 月 %d 日\n",number,stoll(ID),text,stoi(year),stoi(month),stoi(day));
			number+=1;
			fclose(fp);
			cout << "\n保存成功" << endl;
			break;			
		}
	} while (true);
	
}


// 输出信息
void PrintMembers(void)
{	
		ifstream ifs;
		ifs.open("members.txt", ios::in);
		if (!ifs.is_open())
		{
			cout << "文件打开失败" << endl;
			system("pause");
			return;
		}
		cout << "以下即为现队员所有信息:" << endl;
		//打印
		string buf;
    	while (getline(ifs,buf))
   		{
        	cout << buf << endl;
    	}
		ifs.close();			
//		system("pause");
//		system("cls");		
}

bool isMember(vector<member>& member_vector, const wstring& input)
{
	for(int i = 0; i < member_vector.size(); i++)
	{
		if( member_vector[i]._ID == input)
		{
			return true;
		}
	}
	return false;
}


// 删除:内置Vector元素删除
void  removeMem(vector<member>& member_vector, const wstring& removeID)
{
	long long id;
	// 删除member_vector
	for(auto it = member_vector.begin(); it != member_vector.end();)
	{
		if(it->_ID == to_wstring(id))
		{it = member_vector.erase(it);}
		else{++ it;}
	}
	//删除文件
	ifstream ifs("members.txt");
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	vector<string> lines;
	string line;	
	wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
   	string deleteID = converter.to_bytes(removeID);
	bool flag = false;
	while (getline(ifs, line))
	{
		if (line.find(deleteID) == string::npos)
		{ // 如果行中不包含要删除的字符串
			lines.push_back(line);
		}
		else
		{ //如果包含，则把标志位记为真
			flag = true;
		}
	}
	ifs.close();

	// 将处理后的内容写回文件
	ofstream ofs;
	ofs.open("members.txt", ios::trunc);
	if (!ofs.is_open())
	{
		cout << "无法打开输出文件" << endl;
		return;
	}

	for (vector<string>::iterator it = lines.begin(); it != lines.end(); it++)
	{
		ofs << *it << endl;
	}
	ofs.close();
	if (flag)
	{
		cout << "操作成功" << endl;
		system("pause");
		return;
	}

}

// 删除
void member::DeleteMember()
{	

	if (member_vector.size() == 0)
	{
		cout << "目前无队员信息，请添加。" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		system("cls");		// 清屏，便于查看

		// 输入匹配判断
		do 
		{	
			cout << "\n请核对欲删除队员的学号";
			PrintMembers();
			cout << "\n请输入欲删除队员的学号(输入0以返回菜单):";
			
			wstring removeID;
			getline(wcin, removeID);
			removeID.erase(remove_if(removeID.begin(), removeID.end(), ::iswspace), removeID.end());		// 去除字符串中的所有空格
			if(stoll(removeID)==0){
				return;
			}
			if(isMember(member_vector, removeID))
			{
				removeMem(member_vector, removeID);		// 删除队员	
				cout << "删除成功,请核验" << endl;
				PrintMembers();
				system("pause");
				system("cls");
				
				return;
				
			}
			else
			{	
				cout << "抱歉，您输入的队员信息不存在，请按提示重新输入。" << endl;
				system("pause");
				system("cls");
			}

		} while (true);
	}
}

// 修改
void member::ChangeMember()
{

	if (member_vector.size() == 0)
	{
		cout << "目前无队员信息，请添加。" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		system("cls");		// 清屏，便于查看
		// 输入匹配判断
		do 
		{	
			PrintMembers();
			cout << "\n请输入欲修改信息队员的学号(输入0以返回菜单):";
			
			wstring removeID;
			getline(wcin, removeID);
			removeID.erase(remove_if(removeID.begin(), removeID.end(), ::iswspace), removeID.end());		// 去除字符串中的所有空格
			if(stoll(removeID)==0){
				return;
			}
			if(isMember(member_vector, removeID))
			{
				removeMem(member_vector, removeID);		// 删除队员					
				number-=1;
				AddMember();
				system("cls");
				cout << "修改完成,请核验" << endl;
				PrintMembers();
				system("pause");
				system("cls");				
				return;
				
			}
			else
			{	
				cout << "抱歉，您输入的队员信息不存在，请按提示重新输入。" << endl;
				system("pause");
				system("cls");
			}
		} while (true);		
	}
}