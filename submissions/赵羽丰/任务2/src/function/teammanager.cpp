#include "teammanager.h"
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void TeamManager::Show_Menu()
{
	cout << "            " << endl;
	cout << "��Ա����ϵͳ" << endl;
	cout << "======================" << endl;
	cout << "1.��ӳ�Ա" << endl;
	cout << "2.���ҳ�Ա" << endl;
	cout << "3.ɾ����Ա" << endl;
	cout << "4.�г����г�Ա" << endl;
	cout << "5.�޸���Ա��Ϣ" << endl;
	cout << "0.�˳�" << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void TeamManager::Add_Teamer()
{
	
		vector<Teamer>Teamer;
		string data1;
		string data2;
		int data3;
		int data4;
		int data5;


		cout << "������ѧ��: ";
		cin >> data1;

		ifstream ifs("Team.txt");

		string line;
		long lineNumber = 0;
		bool found = false;

		// ��ȡ�ļ�����
		while (getline(ifs, line))
		{
			lineNumber++;
			// ��������Ķ���
			if (line.find(data1) != string::npos)
			{
				cout << "�ҵ������ڵ� " << lineNumber << " ��: " << line << endl;
				cout << "�����ظ����" << endl;
				found = true;
			}
		}
		//���δ�ظ����������Ա
		if (!found)
		{
			cout << "������������";
			cin >> data2;
			cout << "����������꣺";
			cin >> data3;
			cout << "����������£�";
			cin >> data4;
			if (data4 > 12 || data4 < 1)
			{
				cout << "�·ݴ�����������ȷ�·�" << endl;
				return;
			}
			cout << "����������գ�";
			cin >> data5;
			if (data5 > 31 || data5 < 1)
			{
				cout << "���ڴ�����������ȷ����" << endl;
				return;
			}


			//д����
			ofstream ofs;
			ofs.open("Team.txt", ios::app);

			//дʧ��
			if (!ofs.is_open())
			{
				cout << "�ļ���ʧ��" << endl;
				system("pause");
				return;
			}


			ofs << data1 << " " << data2 << " " << data3 << "-" << data4 << "-" << data5 << endl;
			cout << "��¼�ɹ�" << endl;
			ofs.close();
			system("pause");
			ifs.close();
			return;
		}

		ifs.close();
		system("pause");
		return;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int TeamManager::Delete_Teamer()
{
	string  toRemove;
	// ��ȡ�ļ����ݵ��ڴ���
	cout << "��������Ҫ�Ƴ���ѧ�Ż�������";
	cin >> toRemove;
	ifstream ifs("Team.txt");
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return 0;
	}


	vector<string> lines;
	string line;
	bool flag = false;
	while (getline(ifs, line))
	{
		if (line.find(toRemove) == string::npos)
		{ // ������в�����Ҫɾ�����ַ���
			lines.push_back(line);
		}
		else
		{ //�����������ѱ�־λ��Ϊ��
			flag = true;
		}
	}
	ifs.close();

	// ������������д���ļ�
	ofstream ofs;
	ofs.open("Team.txt", ios::trunc);
	if (!ofs.is_open())
	{
		cout << "�޷�������ļ�" << endl;
		return 0;
	}

	for (vector<string>::iterator it = lines.begin(); it != lines.end(); it++)
	{
		ofs << *it << endl;
	}
	ofs.close();
	if (flag)
	{
		cout << "�Ƴ��ɹ�" << endl;
		system("pause");
		return 1;
	}
	else
	{
		cout << "δ�ҵ���ѯ����" << endl;
		system("pause");
		return 0;
	}


}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void TeamManager::List_All_Teamers()
{
	ifstream ifs;
	ifs.open("Team.txt", ios::in);

	//��ʧ��
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		system("pause");
		return;
	}

	//�����ļ�
	char c;
	while ((c = ifs.get()) != EOF)
	{
		cout << c;
	}
	ifs.close();
	system("pause");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void TeamManager::Change_Teamer()
{
	int a = Delete_Teamer();
	cout << "������Ҫ�ı��ֵ��";
	if (a)
	{
		Add_Teamer();
		cout << "�ı�ɹ�" << endl;
		system("pause");
		return;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

long TeamManager::Search_Teamer()
{

	string searchString;
	cout << "������Ҫ���ҵ�������ѧ��: ";
	cin >> searchString;

	ifstream ifs("Team.txt");
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�� " << endl;
		return 0;
	}

	string line;
	long lineNumber = 0;
	bool found = false;

	// ��ȡ�ļ�����
	while (getline(ifs, line))
	{
		lineNumber++;
		// ��������Ķ���
		if (line.find(searchString) != string::npos)
		{
			cout << "�ҵ������ڵ� " << lineNumber << " ��: " << line << endl;
			found = true;
		}
	}

	if (!found)
	{
		cout << "δ�ҵ�����: " << searchString << endl;
		system("pause");
	}

	ifs.close();
	system("pause");
	return lineNumber;

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//void TeamManager::Updata_Teamer()
//{
//
//
//
//}
