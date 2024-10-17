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
        makeMenu();//菜单栏
        int ueser = 0, delete_1 = 0, update_1 = 0, get_1 = 0;
        cin >> ueser;
        switch (ueser)
        {
        case 1:
            cout << "添加人员\n\n" << endl;
            head->get_information(head);
            break;
        case 2:
            cout << "删除人员\n\n" << "请输入\n" << "1.学号\n" << "2.姓名\n" << endl;
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
            cout << "列出所有人员\n\n" << "1.列出所有无排序\n" << "2.按学号排序\n" << "3.按入队时间排序\n" << "4.按打卡次数排序\n" << "5.按总工时排序\n" << endl;
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
            cout << "修改人员信息\n\n" << "请输入修改内容：\n" << "1.学号\n" << "2.姓名\n" << "3.入队时间\n" << endl;
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
            cout << "查询考勤信息\n" << "请输入：\n" << "1.姓名\n" << "2.学号\n" << endl;
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
            cout << "修改考勤信息\n" << "请输入修改内容\n" << "1.打卡记录\n" << "2.打卡次数\n" << "3.总工时\n" << endl;
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