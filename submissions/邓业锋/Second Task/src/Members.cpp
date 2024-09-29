#include "Members.h"

using namespace std;

// ���:���ܺ�������
bool isUniqueID(vector<Member>& membersVector, const wstring& id);
// ɾ��:���ܺ�������
bool isMember(vector<Member>& membersVector, const wstring& input);
bool isRepeat(vector<Member>& membersVector, const wstring& name);
bool tryStringToInt(const wstring& identifier, long long& id);
void removeMem(vector<Member>& membersVector, const wstring& identifier);
// ������ʾ:���ܺ�������
void printMemInfo(vector<Member>& membersVector);
bool AscCompareByStudentID(Member& a, Member& b);
bool AscCompareByJoinYearMonth(Member& a, Member& b);
bool DeascCompareByStudentID( Member& a, Member& b);
bool DeascCompareByJoinYearMonth(Member& a, Member& b);
// �޸�:���ܺ�������
bool isExistent(vector<Member>& membersVector, const wstring& id, int& Index);
bool noModifyID();

/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

// ��ʽ����Ĭ�Ϲ���
Member::Member(){}
// ���죨����thisָ�룩
Member::Member(wstring id, wstring name, int year, int month) :
	studentID(id),
	name(name),
	enrollmentYear(year), enrollmentMonth(month){}

/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

// ��ӹ��ܵ�����
void Member::addMember()
{	
	wstring input_ID;
	wstring StrYear, StrMonth;

	// ѧ����֤����ʽ���ظ�����֤��
	do{
		cout << "\n�¶�Աѧ�ţ�11λ���֣�: ";
		getline(wcin, input_ID);
		input_ID.erase(remove_if(input_ID.begin(), input_ID.end(), ::iswspace), input_ID.end());		// ȥ���ַ����е����пո�

		if (input_ID.length() == 11 && all_of(input_ID.begin(), input_ID.end(), ::isdigit))
		{
			if (isUniqueID(membersVector, input_ID))
			{studentID = input_ID; break;}
			else
			{
				cout << "ѧ���ظ������������롣" << endl;
				system("pause");
			}
		}
		else
		{
			cout << "ѧ�Ÿ�ʽ����ȷ��������11λ���֡�" << endl;
			system("pause");
		}

	}while (true);

	// ������֤����Ϊ�գ�
	do 
	{
		cout << "\n�¶�Ա����: ";
		getline(wcin, name);
		name.erase(remove_if(name.begin(), name.end(), ::isspace), name.end());

		if (name.empty())
		{
			cout << "��������Ϊ�գ����������롣" << endl;;
			continue;
		}
		else { break; }

	} while (true);

	// ��������֤
	do {
		cout << "\n������������: ";
		getline(wcin, StrYear);
		StrYear.erase(remove_if(StrYear.begin(), StrYear.end(), ::iswspace), StrYear.end());		// ȥ���ַ����е����пո�			

		if (StrYear.length() == 4 && all_of(StrYear.begin(), StrYear.end(), ::isdigit))
		{	
			if (stoi(StrYear) >= 2000 && stoi(StrYear) < 9999)
			{
				enrollmentYear = stoi(StrYear); 
				break;
			} 
			else
			{
				cout << "���������ֵ����������2000�Ժ��4λ���֡�" << endl;
			}
		}
		else
		{
			cout << "������ݸ�ʽ����������2000�Ժ��4λ���֡�" << endl;
		}

	} while (true);

	// ����·���֤
	do {
		cout << "\n����������·�: ";
		getline(wcin, StrMonth);
		StrMonth.erase(remove_if(StrMonth.begin(), StrMonth.end(), ::iswspace), StrMonth.end());		// ȥ���ַ����е����пո�

		if ((StrMonth.length() == 1 || StrMonth.length() == 2) && all_of(StrMonth.begin(), StrMonth.end(), ::isdigit))
		{	
			if (stoi(StrMonth) >= 1 && stoi(StrMonth) <= 12)
			{
				enrollmentMonth = stoi(StrMonth);
				break;
			} 
			else
			{
				cout << "�����·���ֵ����ȷ��������1-12������֡�" << endl;
			}
		}
		else
		{
			cout << "�����·ݸ�ʽ����ȷ��������1-12������֡�" << endl;
		}

	} while (true);

	Member newMember(studentID, name, enrollmentYear, enrollmentMonth);
	membersVector.push_back(newMember);

	cout << "\n�¶�Ա��Ϣ��ӳɹ���" << endl;
	system("pause");
	system("cls");
}

// ���:ѧ��Ψһ���ж�
bool isUniqueID(vector<Member>& membersVector,const wstring& id)
{
	bool Unique = true;
	for (int i = 0; i < membersVector.size(); i ++)
	{
		if(membersVector[i].GetStudentID() == id)
		{
			Unique = false;
			break;
		}
	}
	return Unique;
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

// ɾ�����ܵ�����
void Member::deleteMember()
{	

	if (membersVector.size() == 0)
	{
		cout << "Ŀǰ�޶�Ա��Ϣ������ӡ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		system("cls");		// ���������ڲ鿴

		// ����ƥ���ж�
		do 
		{
			cout << "����Ϊ�ֶ�Ա������Ϣ:" << endl;
			for (int i = 0; i < membersVector.size(); i++)
			{
				wcout << "ѧ��: " << membersVector[i].studentID
					<< "\t ����: " << membersVector[i].name
					<< "\t �������: " << membersVector[i].enrollmentYear << "-" << membersVector[i].enrollmentMonth << endl;
			}
			cout << "\n��������ɾ����Ա��������ѧ��: ";

			wstring identifier;
			getline(wcin, identifier);
			identifier.erase(remove_if(identifier.begin(), identifier.end(), ::iswspace), identifier.end());		// ȥ���ַ����е����пո�

			if(isMember(membersVector, identifier))
			{
				if (!isRepeat(membersVector, identifier))
				{
					removeMem(membersVector, identifier);		// ɾ����Ա	

					printMemInfo(membersVector);
					return;
				}
				else
				{
					cout << "��������������ѧ�ż�����" << endl;
					system("pause");
					system("cls");
				}
			}
			else
			{	
				cout << "��Ǹ��������Ķ�Ա��Ϣ�����ڣ��밴��ʾ�������롣" << endl;
				system("pause");
				system("cls");
			}

		} while (true);
	}
}

// ɾ��:����ID��name�Ƿ�ƥ��
bool isMember(vector<Member>& membersVector, const wstring& input)
{
	for(int i = 0; i < membersVector.size(); i++)
	{
		if(membersVector[i].GetName() == input || membersVector[i].GetStudentID() == input)
		{return true;}
	}
	return false;
}

// ɾ��:�ж��Ƿ��������
bool isRepeat(vector<Member>& membersVector, const wstring& inputname)
{
	return count_if
	(
		membersVector.begin(), membersVector.end(),
		// ν�ʺ���
		[&inputname](Member& testmember)
		{
			return testmember.GetName() == inputname;
		}
	) > 1;
}

// ɾ��:���ַ���ת��Ϊ������ʵ���ַ����ĵ�ʽ�ж�
bool tryStringToInt(const wstring& identifier, long long& id)
{
	try{ id = stoll(identifier);return true;}
	catch (const invalid_argument&) {return false; }
	catch (const out_of_range&) { return false; }
}

// ɾ��:����VectorԪ��ɾ��
void  removeMem(vector<Member>& membersVector, const wstring& identifier)
{
	long long id;
	if(tryStringToInt(identifier, id))
	{
		// ���ת���ɹ�����Ϊ��ѧ��
		for(auto it = membersVector.begin(); it != membersVector.end();)
		{
			if(it->GetStudentID() == to_wstring(id))
			{it = membersVector.erase(it);}
			else{++ it;}
		}

	}
	else 
	{
		// ���ת��ʧ�ܣ���Ϊ������
		for (auto it = membersVector.begin(); it != membersVector.end(); )
		{
			if (it->GetName() == identifier)
			{
				it = membersVector.erase(it);
			}
			else { ++it; }
		}

	}

	cout << "\nɾ���ɹ�!���潫�г�ʣ�����ж�Ա����Ϣ��" << endl;
	system("pause");
	system("cls");

}

/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

// ������ʾ
void Member::sortedPrintInfo()
{	

	if (membersVector.size() == 0)
	{
		cout << "Ŀǰ�޶�Ա��Ϣ������ӡ�" << endl;
		system("pause");
		system("cls");        // ��һ��
	}
	else
	{
		system("cls");        // ���������ڲ鿴

		do
		{
			cout << "��ѡ������һ������ʽ�г���Ϣ��" << endl;
			cout << "1.ѧ������������ʾ" << endl;
			cout << "2.���������������" << endl;
			cout << "==================" << endl;
			cout << "3.ѧ�Ž���������ʾ" << endl;
			cout << "4.������½�������" << endl;
			cout << "����������ѡ��:";
			
			wstring SortChioce;
			getline(wcin ,SortChioce);
			SortChioce.erase(remove_if(SortChioce.begin(), SortChioce.end(), ::isspace), SortChioce.end());

			if (SortChioce.length()==1 && all_of(SortChioce.begin(), SortChioce.end(), ::isdigit))
			{
				// ����ѡ��
				switch (stoi(SortChioce))
				{
				case 1:
					sort(membersVector.begin(), membersVector.end(), AscCompareByStudentID);
					printMemInfo(membersVector);
					return;
				case 2:
					sort(membersVector.begin(), membersVector.end(), AscCompareByJoinYearMonth);
					printMemInfo(membersVector);
					return;
				case 3:
					sort(membersVector.begin(), membersVector.end(), DeascCompareByStudentID);
					printMemInfo(membersVector);
					return;
				case 4:
					sort(membersVector.begin(), membersVector.end(), DeascCompareByJoinYearMonth);
					printMemInfo(membersVector);
					return;
				default:
					cout << "��Чѡ����������롣" << endl;
					system("pause");
					system("cls");
					return;
				}
			} 
			else
			{
				cout << "�����ʽ����ȷ���밴��ʾ���롣" << endl;
				system("pause");
				system("cls");
			}

		} while (true);
	}
}

// �����Ϣ
void printMemInfo(vector<Member>& membersVector)
{

	if(membersVector.size() == 0)
	{
		cout << "Ŀǰ�޶�Ա��Ϣ������ӡ�" << endl;
		system("pause");
		system("cls");		// ��һ��
	}
	else
	{
		system("cls");		// ���������ڲ鿴

		cout << "���¼�Ϊ�ֶ�Ա������Ϣ:" << endl;
		for (int i = 0; i < membersVector.size(); i++)
		{
			wcout << "ѧ��: " << membersVector[i].GetStudentID()
				<< "\t ����: " << membersVector[i].GetName()
				<< "\t �������: " << membersVector[i].GetYear() << "-" << membersVector[i].GetMonth() << endl;
		}

		cout << "\n��������ص��˵���";
		system("pause");
		system("cls");		// �ڶ��Σ�ʹ��������Ϊ�˼�С���
	}
}

// ����Ĳ�������
bool AscCompareByStudentID(Member& a, Member& b)
{return a.GetStudentID() < b.GetStudentID();}
bool AscCompareByJoinYearMonth(Member& a, Member& b)
{
	if (a.GetYear() != b.GetYear())
	{return a.GetYear() < b.GetYear();}

	return a.GetMonth() < b.GetMonth();
}

// ����Ĳ�������
bool DeascCompareByStudentID( Member& a,  Member& b)
{return a.GetStudentID() > b.GetStudentID();}
bool DeascCompareByJoinYearMonth( Member& a, Member& b)
{
	if (a.GetYear() != b.GetYear())
	{return a.GetYear() > b.GetYear();}

	return a.GetMonth() > b.GetMonth();
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

// �޸Ĺ��ܵ�����(����ѧ�ż���)
void Member::modifyMemInfo()
{

	if (membersVector.size() == 0)
	{
		cout << "Ŀǰ�޶�Ա��Ϣ������ӡ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		system("cls");		// ���������ڲ鿴

		// ����ƥ��
		do {
			cout << "����Ϊ�ֶ�Ա������Ϣ:" << endl;
			for (int i = 0; i < membersVector.size(); i++)
			{
				wcout << "ѧ��: " << membersVector[i].studentID
					<< "\t ����: " << membersVector[i].name
					<< "\t �������: " << membersVector[i].enrollmentYear << "-" << membersVector[i].enrollmentMonth << endl;
			}

			cout << "\n��������Ҫ�޸���Ϣ�Ķ�Աѧ��: ";
			
			wstring inputID;
			getline(wcin, inputID);
			inputID.erase(remove_if(inputID.begin(), inputID.end(), ::isspace), inputID.end());

			//��ʽƥ��
			if (inputID.length() == 11 && all_of(inputID.begin(), inputID.end(), ::isdigit))
			{
				// ��������֤
				int Index = 0;		// λ������
				if (isExistent(membersVector, inputID, Index))
				{
					// �޸����岿��
					wstring inputnewID, newName;
					wstring StrYear, StrMonth;

					if (noModifyID())
					{
						cout << "ѧ�ű��ֲ��䡣\n" << endl;

						// ������֤����Ϊ�գ�
						do
						{
							cout << "\n�ĺ��Ա����: ";
							getline(wcin, newName);
							newName.erase(remove_if(newName.begin(), newName.end(), ::isspace), newName.end());

							if (newName.empty())
							{
								cout << "��������Ϊ�գ����������롣" << endl;;
								continue;
							}
							else
							{
								membersVector[Index].name = newName;
								break;
							}

						} while (true);

						// ��������֤
						do {
							cout << "\n�ĺ�������: ";
							getline(wcin, StrYear);
							StrYear.erase(remove_if(StrYear.begin(), StrYear.end(), ::iswspace), StrYear.end());		// ȥ���ַ����е����пո�			

							if (StrYear.length() == 4 && all_of(StrYear.begin(), StrYear.end(), ::isdigit))
							{
								if (stoi(StrYear) >= 2000 && stoi(StrYear) < 9999)
								{
									membersVector[Index].enrollmentYear = stoi(StrYear);
									break;
								}
								else
								{
									cout << "���������ֵ����������2000�Ժ��4λ���֡�" << endl;
									system("pause");
								}
							}
							else
							{
								cout << "������ݸ�ʽ����������2000�Ժ��4λ���֡�" << endl;
								system("pause");
							}
						} while (true);

						// ����·���֤
						do {
							cout << "\n�ĺ�����·�: ";
							getline(wcin, StrMonth);
							StrMonth.erase(remove_if(StrMonth.begin(), StrMonth.end(), ::iswspace), StrMonth.end());		// ȥ���ַ����е����пո�

							if ((StrMonth.length() == 1 || StrMonth.length() == 2) && all_of(StrMonth.begin(), StrMonth.end(), ::isdigit))
							{
								if (stoi(StrMonth) >= 1 && stoi(StrMonth) <= 12)
								{
									membersVector[Index].enrollmentMonth = stoi(StrMonth);
									break;
								}
								else
								{
									cout << "�����·���ֵ����ȷ��������1-12������֡�" << endl;
									system("pause");
								}
							}
							else
							{
								cout << "�����·ݸ�ʽ����ȷ��������1-12������֡�" << endl;
								system("pause");
							}
						} while (true);

						cout << "\n�޸ĳɹ������潫�г��޸ĺ����ж�Ա����Ϣ��" << endl;
						system("pause");
						system("cls");

						printMemInfo(membersVector);
						break;
					}
					else
					{
						// ѧ����֤����ʽ���ظ�����֤��
						do {
							cout << "\n�¶�Աѧ�ţ�11λ���֣�: ";
							getline(wcin, inputnewID);
							inputnewID.erase(remove_if(inputnewID.begin(), inputnewID.end(), ::iswspace), inputnewID.end());		// ȥ���ַ����е����пո�

							if (inputnewID.length() == 11 && all_of(inputnewID.begin(), inputnewID.end(), ::isdigit))
							{
								if (isUniqueID(membersVector, inputnewID))
								{
									membersVector[Index].studentID = inputnewID; break;
								}
								else
								{
									cout << "ѧ���ظ������������롣" << endl;
									system("pause");
								}
							}
							else
							{
								cout << "ѧ�Ÿ�ʽ����ȷ��������11λ���֡�" << endl;
								system("pause");
							}

						} while (true);

						// ������֤����Ϊ�գ�
						do
						{
							cout << "\n�ĺ��Ա����: ";
							getline(wcin, newName);
							newName.erase(remove_if(newName.begin(), newName.end(), ::isspace), newName.end());

							if (newName.empty())
							{
								cout << "��������Ϊ�գ����������롣" << endl;;
								continue;
							}
							else
							{
								membersVector[Index].name = newName;
								break;
							}

						} while (true);

						// ��������֤
						do {
							cout << "\n�ĺ�������: ";
							getline(wcin, StrYear);
							StrYear.erase(remove_if(StrYear.begin(), StrYear.end(), ::iswspace), StrYear.end());		// ȥ���ַ����е����пո�			

							if (StrYear.length() == 4 && all_of(StrYear.begin(), StrYear.end(), ::isdigit))
							{
								if (stoi(StrYear) >= 2000 && stoi(StrYear) < 9999)
								{
									membersVector[Index].enrollmentYear = stoi(StrYear);
									break;
								}
								else
								{
									cout << "���������ֵ����������2000�Ժ��4λ���֡�" << endl;
									system("pause");
								}
							}
							else
							{
								cout << "������ݸ�ʽ����������2000�Ժ��4λ���֡�" << endl;
								system("pause");
							}
						} while (true);

						// ����·���֤
						do {
							cout << "\n�ĺ�����·�: ";
							getline(wcin, StrMonth);
							StrMonth.erase(remove_if(StrMonth.begin(), StrMonth.end(), ::iswspace), StrMonth.end());		// ȥ���ַ����е����пո�

							if ((StrMonth.length() == 1 || StrMonth.length() == 2) && all_of(StrMonth.begin(), StrMonth.end(), ::isdigit))
							{
								if (stoi(StrMonth) >= 1 && stoi(StrMonth) <= 12)
								{
									membersVector[Index].enrollmentMonth = stoi(StrMonth);
									break;
								}
								else
								{
									cout << "�����·���ֵ����ȷ��������1-12������֡�" << endl;
									system("pause");
								}
							}
							else
							{
								cout << "�����·ݸ�ʽ����ȷ��������1-12������֡�" << endl;
								system("pause");
							}
						} while (true);

						cout << "\n�޸ĳɹ������潫�г��޸ĺ����ж�Ա����Ϣ��" << endl;
						system("pause");
						system("cls");

						printMemInfo(membersVector);
						break;
					}
				}
				else
				{
					cout << "��Ǹ���������ѧ�Ų����ڣ����������롣" << endl;
					system("pause");
				}
			}
			else
			{
				cout << "ѧ�Ÿ�ʽ����ȷ��������11λ���֡�" << endl;
				system("pause");
				system("cls");
			}

		} while (true);
	}
}

// �޸�:����ָ��ѧ�ŵĶ�Ա��Ϣ
bool isExistent( vector<Member>& membersVector, const wstring& id, int& Index)
{
	for (int i = 0; i < membersVector.size(); ++i)
	{
		if(membersVector[i].GetStudentID() == id)
		{
			Index = i;
			return true;
		}
	}
	return false;
}

// �޸�:�Ƿ��޸�ѧ���ж�
bool noModifyID()
{	
	do 
	{
		wstring choice;
		cout << "\n�Ƿ��޸�ѧ�ţ�[Y/N](Ĭ��[N]): ";
		getline(wcin, choice);
		choice.erase(remove_if(choice.begin(), choice.end(), ::isspace), choice.end());
	
		// ������ת��ΪСд�Ժ��Դ�Сд����
		transform(choice.begin(), choice.end(), choice.begin(), [](unsigned short c){return towlower(c);});

		if (!choice.empty())
		{
			if (choice.compare(L"y") && choice.compare(L"n"))
			{
				cout << "����[Y/N]��ѡ��";
				system("pause");
			}
			else{return choice.compare(L"y");}
		}
		else{return true;}

	} while (true);
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

/*˽�����Զ���ӿ�*/

//  ѧ�Ŷ���ӿ�
wstring Member::GetStudentID(){return studentID;}
void Member::SetStudentID(wstring InputID){studentID = InputID;}

// ��������ӿ�
wstring Member::GetName() { return name; }
void Member::SetName(wstring InputName){name = InputName;}

// �����ݶ���ӿ�
int Member::GetYear() const { return enrollmentYear; }
void Member::SetYear(int InputYear) { enrollmentYear = InputYear; }

// ����·ݶ���ӿ�
int Member::GetMonth() const { return enrollmentMonth; }
void Member::SetMonth(int InputMonth) { enrollmentMonth = InputMonth; }
