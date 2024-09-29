#include "Attendance.h"

bool ConfirmAct_NoClear();
bool isValidTimeFormat(const string& inputTime);

/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

// �򿨼�¼�����ʾ
void Attendance::displayAllCheckInRecords() const
{
	for (const auto& recordPrint : checkInRecords)
	{
		cout << recordPrint.first
			<< "\t����ʱ��: " << recordPrint.second << "h\n" << endl;
	}
	cout << "��������������˵���";
	system("pause");
	system("cls");

}

// �����ʾ���п�����Ϣ
void Attendance::PrintAllAttendanceInfo() const
{
	if (checkInCount != 0)
	{	
		cout << "����Ϊ�ö���Ŀ�����Ϣ:" << endl;
		cout << "\n�򿨴���:" <<  checkInCount << "\t�ܹ���ʱ��:" << totalWorkTime << "h" << endl;

		cout << "\n�򿨼�¼:" << endl;

		displayAllCheckInRecords();
	} 
	else
	{
		cout << "�򿨴���Ϊ0���޴򿨼�¼��" << endl;
		system("pause");
		system("cls");
	}
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

// ��Ӵ򿨼�¼��map��������ʱ���Լ���Ӧ����ʱ����
void Attendance::addRecordInMap(string checkInTime, double workDuration)
{
	checkInRecords[checkInTime] = workDuration;			// map��key+Value

	checkInCount++;			// �򿨴�����һ
	totalWorkTime += workDuration;		// �ܹ���ʱ���ۼ�
}

// ��ʱ����Ϊ����ʱ�䣬����ʱ���ֶ�����
void Attendance::SetRecordValue()
{
	time_t now = time(nullptr);			// ��ȡ��ǰʱ���
	tm* timePtr = localtime(&now);		// ʱ���ת��Ϊtm�ṹ��

	// ��ʽ��ʱ���ַ���
	stringstream Strstream;
	Strstream << put_time(timePtr, "����:%Y-%m-%d ʱ��:%H:%M:%S");
	string checkInTime = Strstream.str();

	cout << "�˴δ�ʱ��:\n" << checkInTime << endl;

	while (true)
	{
		// �û����빤��ʱ��
		string workDuration;

		cout << "\n��������չ���ʱ��(h): ";
		getline(cin, workDuration);
		workDuration.erase(remove_if(workDuration.begin(), workDuration.end(), ::isspace), workDuration.end()); // ����ַ����ո�

		// ��ʽ��֤
		if ((workDuration.length() == 1 || workDuration.length() == 3) && 
			(all_of(workDuration.begin(), workDuration.end(), ::isdigit) || workDuration.find(L'.' == string::npos)))
		{	
				// ����ʱ��͹���ʱ���洢�ڼ�¼��
				addRecordInMap(checkInTime, stod(workDuration));

				cout << "\n��ӳɹ���(����������ز˵�)" << endl;
				system("pause");
				system("cls");
				break;
		}
		else
		{
			cout << "�����ʽ����(С��10������1λС��),���������롣" << endl;
			system("pause");
		}
	}
	
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

// ������п��ڼ�¼
void Attendance::ClearAllRecords()
{	
	if (checkInCount != 0)
	{	
		if (ConfirmAct_NoClear())
		{
			cout << "����������ز˵���";
			system("pause");
			system("cls");
		} 
		else
		{
			checkInRecords.clear();
			checkInCount = 0;
			totalWorkTime = 0;

			cout << "���п��ڼ�¼����ա�" << endl;
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

// �����ȷ��
bool ConfirmAct_NoClear()
{
	do
	{
		wstring choice;
		cout << "\nȷ����տ�����Ϣ��[Y/N](Ĭ��[N]): ";
		getline(wcin, choice);
		choice.erase(remove_if(choice.begin(), choice.end(), ::isspace), choice.end());

		// ������ת��ΪСд�Ժ��Դ�Сд����
		transform(choice.begin(), choice.end(), choice.begin(), [](unsigned short c) {return towlower(c); });

		if (!choice.empty())
		{
			if (choice.compare(L"y") && choice.compare(L"n"))
			{
				cout << "����[Y/N]��ѡ��";
				system("pause");
			}
			else { return choice.compare(L"y"); }
		}
		else { return true; }

	} while (true);
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

// ����ʱ���ʽ�ж�
bool isValidTimeFormat(const string& inputTime)
{
	istringstream ss(inputTime);
	tm tm = {};

	try
	{
		ss >> get_time(&tm, "����:%Y-%m-%d") >> ws >> get_time(&tm, "ʱ��:%H:%M:%S");
		if (ss.fail()) { return false; }
	}
	catch (exception& e)
	{return false;}

	return true;
}

// �����ض����ڵĿ�����Ϣ�����Ĵ�����
void Attendance::updateAttendanceInfo()
{
	while (true)
	{
		if (checkInCount != 0)
		{
			cout << "����Ϊ�ö���Ŀ�����Ϣ:" << endl;
			cout << "\n�򿨴���:" << checkInCount << "\t�ܹ���ʱ��:" << totalWorkTime << "h" << endl;

			cout << "\n�򿨼�¼:" << endl;

			for (const auto& recordPrint : checkInRecords)
			{
				cout << recordPrint.first
					<< "\t\t����ʱ��: " << recordPrint.second << "h\n" << endl;
			}

			string inputTime;
			cout << "�����������´򿨼�¼��ʱ��(ע���ʽ):" << endl;
			getline(cin, inputTime);

			if (isValidTimeFormat(inputTime))
			{	
				auto it = checkInRecords.find(inputTime);
				if (it != checkInRecords.end())
				{
					while (true)
					{
						// �û����¹���ʱ��
						wstring newWorkDuration;

						cout << "\n������ĺ���ʱ��(h): ";
						getline(wcin, newWorkDuration);
						newWorkDuration.erase(remove_if(newWorkDuration.begin(), newWorkDuration.end(), ::isspace), newWorkDuration.end()); // ����ַ����ո�

						// ��ʽ��֤
						if ((newWorkDuration.length() == 1 || newWorkDuration.length() == 3) &&
							(all_of(newWorkDuration.begin(), newWorkDuration.end(), ::isdigit) || newWorkDuration.find('.' == string::npos)))
						{
							totalWorkTime -= it->second;
							totalWorkTime += stod(newWorkDuration);
							it->second = stod(newWorkDuration);

							cout << "\n���³ɹ������潫�г��ĺ�����Ϣ��" << endl;
							system("pause");
							system("cls");

							PrintAllAttendanceInfo();
							return;
						}
						else
						{
							cout << "���빤��ʱ����ʽ����(С��10������1λС��),���������롣" << endl;
							system("pause");
						}
					}
				}
				else
				{
					cout << "δ�ҵ�ָ�����ڵĿ��ڼ�¼�����������롣\n(����ֱ�Ӹ���)";
					system("pause");
					system("cls");
				}

			}
			else
			{
				cout << "�����ʱ���ʽ����ȷ���밴�ա�����:YYYY-MM-DD ʱ��:HH:MM:SS���ĸ�ʽ���롣\n(����ֱ�Ӹ���)";
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