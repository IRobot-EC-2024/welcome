#include <iostream>
#include "team.h"
using namespace std;
#include <limits>
void showMainMenu()
{
    cout << "================= 战队人员管理系统 =================" << endl;
    cout << "1. 增加队员" << endl;
    cout << "2. 删除队员" << endl;
    cout << "3. 修改队员信息" << endl;
    cout << "4. 显示所有队员信息" << endl;
    cout << "5. 增加考勤记录" << endl;
    cout << "6. 显示队员考勤记录" << endl;
    cout << "7. 退出" << endl;
    cout << "=====================================================" << endl;
}

void showSortMenu()
{
    cout << "============== 队员信息排序方式 ==============" << endl;
    cout << "1. 按学号排序" << endl;
    cout << "2. 按入队年月排序" << endl;
    cout << "3. 返回主菜单" << endl;
    cout << "=============================================" << endl;
}

int main()
{
    Team team;
    int choice;
    string id, name, joinDate, punchTime;
    double workTime;

    do
    {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "无效输入，请输入数字！" << endl;
            continue;
        }
        showMainMenu();
        cout << "请选择操作: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "请输入学号: ";
            cin >> id;
            cout << "请输入姓名: ";
            cin >> name;
            cout << "请输入入队年月(格式: YYYY-MM): ";
            cin >> joinDate;
            try
            {
                Member newMember(id, name, joinDate);
                team.addMember(newMember);
                cout << "队员添加成功！" << endl;
            }
            catch (const exception &e)
            {
                cerr << "错误: " << e.what() << endl;
            }
            break;

        case 2:
            cout << "请输入要删除的队员学号: ";
            cin >> id;
            if (team.removeMember(id))
            {
                cout << "队员删除成功！" << endl;
            }
            else
            {
                cout << "未找到该学号的队员。" << endl;
            }
            break;

        case 3:
            cout << "请输入要修改的队员学号: ";
            cin >> id;
            cout << "请输入新姓名: ";
            cin >> name;
            cout << "请输入新入队年月(格式: YYYY-MM): ";
            cin >> joinDate;
            try
            {
                team.updateMember(id, name, joinDate);
                cout << "队员信息更新成功！" << endl;
            }
            catch (const exception &e)
            {
                cerr << "错误: " << e.what() << endl;
            }
            break;

        case 4:
        {
            int sortChoice;
            do
            {
                showSortMenu();
                cout << "请选择操作: ";
                cin >> sortChoice;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "无效输入，请输入数字！" << endl;
                    continue;
                }

                switch (sortChoice)
                {
                case 1:
                    team.sortMembersById();
                    cout << "队员按学号排序成功！" << endl;
                    team.displayMembers();
                    break;
                    system("pause");
                case 2:
                    team.sortMembersByJoinDate();
                    cout << "队员按入队年月排序成功！" << endl;
                    team.displayMembers();
                    break;
                    system("pause");
                case 3:
                    cout << "返回主菜单..." << endl;
                    break;

                default:
                    cout << "无效选择，请重新输入！" << endl;
                    system("pause");
                }
            } while (sortChoice != 3);
            break;
        }

        case 5:
            cout << "请输入学号: ";
            cin >> id;
            cout << "请输入打卡时间(格式: YYYY-MM-DD-HH-MIN): ";
            cin >> punchTime;
            cout << "请输入工作时长(小时): ";
            cin >> workTime;
            try
            {
                team.addAttendance(id, punchTime, workTime);
                cout << "考勤记录添加成功！" << endl;
            }
            catch (const exception &e)
            {
                cerr << "错误: " << e.what() << endl;
                system("pause");
            }
            break;

        case 6:
            cout << "请输入要查询的队员学号: ";
            cin >> id;
            team.displayAttendance(id);
            break;

        case 7:
            cout << "退出系统" << endl;
            break;

        default:
            cout << "无效选择，请重新输入！" << endl;
        }
        system("pause");
    } while (choice != 7);

    return 0;
}