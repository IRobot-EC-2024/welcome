#include <iostream>
#include <string>
#include <fstream>
#include <vector>  
#include <algorithm> 
#include <regex>
#include "member.h"
using namespace std;


int main()
{
    Member* head = new Member;
    head->read(head);
    string temp;
    while (1) {
        cout << "------------------------------------" << endl;
        head->put_information(head);
        cout << "------------------------------------" << endl;
        makeMenu();//�˵���
        int ueser = 0, delete_1 = 0, update_1 = 0, get_1 = 0;
        cin >> ueser;
        switch (ueser)
        {
        case 1:
            cout << "�����Ա\n\n" << endl;
            head->get_information(head);
            break;
        case 2:
            cout << "ɾ����Ա\n\n" << "������\n" << "1.ѧ��\n" << "2.����\n" << endl;
            cin >> delete_1;
            switch (delete_1)
            {
            case 1:
                head->delete_student_id(head); break;
            case 2:
                head->delete_name(head); break;
            default:
                cout << "What did you fucking import...\n" << endl;
                break;
            }
            break;
        case 3:
            cout << "�г�������Ա\n\n" << "1.�г�����������\n" << "2.��ѧ������\n" << "3.�����ʱ������\n" << "4.���򿨴�������\n" << "5.���ܹ�ʱ����\n" << endl;
            cin >> get_1;
            switch (get_1) {
            case 1: head->put_information(head); break;
            case 2:head->sort_student_id(head); break;
            case 3:head->sort_entry_date(head);; break;
            case 4:head->sort_times(head); break;
            case 5:head->sort_total_worktime(head); break;
            default: cout << "What did you fucking import...\n" << endl; break;

            }
            break;
        case 4:
            cout << "�޸���Ա��Ϣ\n\n" << "�������޸����ݣ�\n" << "1.ѧ��\n" << "2.����\n" << "3.���ʱ��\n" << endl;
            cin >> update_1;
            switch (update_1)
            {
            case 1:
                head->update_student_id(head); break;
            case 2:
                head->update_name(head); break;
            case 3:
                head->update_entry_date(head); break;
            default:
                cout << "What did you fucking import...\n" << endl;
                break;
            }
            break;
        case 5:
            cout << "��ѯ������Ϣ\n" << "�����룺\n" << "1.����\n" << "2.ѧ��\n" << endl;
            cin >> get_1;
            switch (get_1)
            {
            case 1:
                head->get_student_id(head); break;
            case 2:
                head->get_name(head); break;

            default:
                cout << "What did you fucking import...\n" << endl;
                break;
            }
            break;
        case 6:
            cout << "�޸Ŀ�����Ϣ\n" << "�������޸�����\n" << "1.�򿨼�¼\n" << "2.�򿨴���\n" << "3.�ܹ�ʱ\n" << endl;
            cin >> update_1;
            switch (update_1)
            {
            case 1:
                head->update_records(head); break;
            case 2:
                head->update_times(head); break;
            case 3:
                head->update_total_worktime(head); break;
            default:
                cout << "What did you fucking import...\n" << endl;
                break;
            }
            break;

        default:
            printf("What did you fucking import...\n"); break;
        }
        system("pause");
    }
    return 0;
}