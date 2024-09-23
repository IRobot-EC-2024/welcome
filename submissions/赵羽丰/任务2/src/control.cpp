#include "workermanager.h"
#include "teammanager.h"

using namespace std;


int main()
{



	WorkerManager wm;
	TeamManager tm;
	int choice,choice1 ,choice2;

	do
	{
		cout << "            " << endl;
		cout << "人员管理系统" << endl;
		cout << "======================" << endl;
		cout << "1.队伍管理" << endl;
		cout << "2.考勤管理" << endl;
		cout << "0.退出" << endl;
		cout << ">>>";

		cin >> choice;

		switch (choice)
		{
		case 0:
			cout << "退出中" << endl;
			break;
		case 1:
			do {
				tm.Show_Menu();
				cout << ">>>" << endl;
				cin >> choice1;

				switch (choice1)
				{
				case 0:
					cout << "退出中" << endl;
					break;
				case 1:
					tm.Add_Teamer();
					break;
				case 2:
					tm.Search_Teamer();
					break;
				case 3:
					tm.Delete_Teamer();
					break;
				case 4:
					tm.List_All_Teamers();
					break;
				case 5:
					tm.Change_Teamer();
					break;
				default:
					cout << "输入错误，请重新输入" << endl;
					system("pause");
					break;
				}
			} while (choice1);

			break;
		case 2:
			do {
				wm.Show_Menu();
				cout << ">>>" << endl;
				cin >> choice2;
				switch (choice2)
				{
				case 0:
					cout << "退出中" << endl;
					break;
				case 1:
					wm.Add_Worker();
					break;
				case 2:
					wm.Search_Work();
					break;
				case 3:
					wm.Delete_Worker();
					break;
				case 4:
					wm.List_All_Workers();
					break;
				case 5:
					wm.Search_Time();
					break;
				default:
					cout << "输入错误，请重新输入" << endl;
					system("pause");
					break;
				}
			} while (choice2);
			break;
		default:
			cout << "输入错误，请重新输入" << endl;
			system("pause");
			break;
		}
	} while (choice);
	cout << "退出成功" << endl;
	system("pause");
	return 0;
}







