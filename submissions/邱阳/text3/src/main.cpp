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
		//��ʽ��֤
		if (choice >= 1 && choice <= 7)
		{
			switch (choice)
			{
			case 1://���ս����Ա
				M.add_member();
				break;

			case 2://ɾ��ս����Ա
				M.delete_member();
				break;

			case 3://�г�����ս����Ա����Ϣ
				M.sort_print();
				break;

			case 4://�޸�ս����Ա��Ϣ
				M.modifyMemInfo();
				break;

			case 5://��ѯ������Ϣ
				T.show_info(M);
				break;

			case 6://�޸Ŀ�����Ϣ(��ɾ��)
				T.modify_MAInfo(M);
				break;

			case 7://�˳�����
				//exit(0);
				return 0;

			default://�û������ѡ�����ִ���
				cout << "��Чѡ����������롣";
				system("pause");
				system("cls");
				break;
			}
		}
		else
		{
			cout << "������Ч���밴��ʾ�������֡�";
			system("pause");
			system("cls");
		}
	}
}