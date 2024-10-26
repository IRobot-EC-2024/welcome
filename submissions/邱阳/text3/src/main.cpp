#include "team_manager.h"
#include "members.h"
#include "attendance.h"

int main(void)
{
	Attendance A;
	Member M;
	Team_Manager T;
	while(1)
	{
		T.ShowMenu();
		int choice = 0;
		cin >> choice;
		//格式验证
		if (choice >= 1 && choice <= 7)
		{
			switch (choice)
			{
			case 1://添加战队人员
				M.add_member();
				break;

			case 2://删除战队人员
				M.delete_member();
				break;

			case 3://列出所有战队人员的信息
				M.sort_print();
				break;

			case 4://修改战队人员信息
				M.modifyMemInfo();
				break;

			case 5://查询考勤信息
				T.show_info(M);
				break;

			case 6://修改考勤信息(增删改)
				T.modify_MAInfo(M);
				break;

			case 7://退出程序
				//exit(0);
				return 0;

			default://用户输入非选项数字处理
				cout << "无效选项，请重新输入。";
				system("pause");
				system("cls");
				break;
			}
		}
		else
		{
			cout << "输入无效，请按提示输入数字。";
			system("pause");
			system("cls");
		}
	}
}