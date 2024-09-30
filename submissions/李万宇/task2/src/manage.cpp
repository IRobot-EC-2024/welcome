#include "manage.h"
#include "person.h"
#include "attendance.h"
using namespace std;



int main() {
    PersonManager pm;
    AttendanceManager am;
    cout << "--欢迎使用战队考勤系统--" << endl
        << "命令表：" << endl
        << "0:命令表" << endl
        << "11:添加队员        " << "21:添加考勤" << endl
        << "12:查找队员信息    " << "22:查找队员考勤信息" << endl
        << "13:删除队员信息    " << "23:删除队员考勤信息" << endl
        << "14:更新队员信息    " << "24:更新队员考勤信息" << endl
        << "15:显示所有人员信息" << "25:显示所有考勤信息" << endl
        << "16:按学号排序      " << "26:按考勤次数排序" << endl
        << "17:按入队年月排序  " << "27:按总工作时长排序" << endl;
    while (true) {
        int command; 
        cout << "请输入命令：" ;
        cin >> command;
        if (cin.fail()) {
            cin.clear(); // 清除错误状态
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清空输入缓冲区//-
            //cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清空输入缓冲区//+
            cout << "请输入正确命令！必须是整数。\n";
        }
        else if(10 < command < 18 && 20<command <28) 
        {   
              string name; long long number = 0; string NewName; int year = 0; int month = 0;
            int n = 0; int timeHour = 0; int timeMinute = 0; int allTime = 0; int NUM = 0;
            switch (command)
            {
            case 0:
                cout << "命令表：" << endl
                    << "0:命令表" << endl
                    << "11:添加队员        " << "21:添加考勤" << endl
                    << "12:查找队员信息    " << "22:查找队员考勤信息" << endl
                    << "13:删除队员信息    " << "23:删除队员考勤信息" << endl
                    << "14:更新队员信息    " << "24:更新队员考勤信息" << endl
                    << "15:显示所有人员信息" << "25:显示所有考勤信息" << endl
                    << "16:按学号排序      " << "26:按考勤次数排序" << endl
                    << "17:按入队年月排序  " << "27:按总工作时长排序" << endl;
                break;
            case 11:{
                cout << "请输入姓名：";
                cin >> name;
                cout << "请输入学号：";
                cin >> number;
                auto alice = pm.findNUmber(number);
                if (alice != nullopt) { cout << "学号已存在！" << endl; }
                else {
                    cout << "请输入入队年月,以空格为间隔：" << endl;
                    cin >> year >> month;
                    if ((year > 2020 && year < 2026) && (month > 0 && month < 13)) {
                        pm.addPerson(Person(name, number, year, month));
                        am.addAttendance(name, 1, 0, 0, Attendance(name, 1, 0, 0, 0));
                        pm.displayAll();
                    }
                }
                break;
            }
            case 12: {//查找
                cout << "请输入姓名：";
                cin >> name;
                auto alice = pm.findPerson(name);
                if (alice) {
                    cout << "姓名: " << alice->getName() << ", 学号: " << alice->getNumber() << endl;
                }
                else { cout << "查无此人"; }
                break;
            }
            case 13://删除
                cout << "请输入姓名：";
                cin >> name;
                if (pm.deletePerson(name)) {
                    cout << "删除成功";
                }
                else {
                    cout << "查无此人" << endl;
                }
                pm.displayAll();
                break;
            case 14://更新
                cout << "请输入待更改人员姓名：";
                cin >> name;
                cout << "请输入学号：";
                cin >> number;
                cout << "请输入入队年月,以空格为间隔：" << endl;
                cin >> year;
                cin >> month;
                if ((year > 2020 && year < 2026) && (month > 0 && month < 13)) {
                    if (pm.updatePerson(name, number, year, month))
                    {
                        cout << "更新成功";
                    }
                    else
                    {
                        cout << "查无此人" << endl;
                    }
                    pm.displayAll();
                }
                else
                {
                    cout << "请输入正确的年月！" << endl;
                }
                break;
            case 15://显示
                pm.displayAll();
                break;
            case 16://按学号排序
                pm.displaySortedByNumber();
                break;
            case 17://按入队年月排序
                pm.displaySortedByNumber();
                break;
            case 21: {
                cout << "请输入姓名：";
                cin >> name;
                cout << "请输入考勤信息,以空格为间隔：" << endl;
                cin >> timeHour >> timeMinute;
                if ((timeHour > -1 && timeHour < 25) && (timeMinute > -1 && timeMinute < 61)) {
                    cout << "请输入总考勤次数：";
                    cin >> number;
                    auto alice = am.findAttendance(name);
                    if (alice != nullopt)
                    {
                        NUM = alice->getTimeHour().size() + 1;
                    }
                    else { NUM = 1; }
                    if (number == NUM)
                    {
                        cout << "请输入总工作时间（小时）：";
                        cin >> allTime;
                        am.addAttendance(name, number, timeHour, timeMinute, Attendance(name, number, timeHour, timeMinute, allTime));
                        am.displayAll();
                    }
                    else {

                        cout << "请输入正确的考勤次数！正确的考勤次数应为：" << NUM << endl;
    
                    }
                }
                else
                {
                    cout << "请输入正确的时间格式！" << endl;
                }
                break;
            }
            case 22: {
                cout << "请输入姓名：";
                cin >> name;
                auto att = am.findAttendance(name);
                if (att) {
                    auto hour = att->getTimeHour();
                    auto minute = att->getTimeMinutes();
                    cout << "姓名: " << att->getName() << ", 总考勤次数: " << att->getNumber() << "，总工作时长" << att->getAlltime() << endl;
                    for (int i = 0; i < hour.size(); i++)
                    {
                        cout << i + 1 << "："
                            << hour[i] << "点"
                            << minute[i] << "分"
                            << endl;
                    }
                }
                else { cout << "查无此人"; }
                break;
            }
            case 23:
                cout << "";
                cin >> name;
                if (am.deleteAttendance(name))
                {
                    cout << "删除成功！" << endl;
                }
                else
                {
                    cout << "查无此人！" << endl;
                }
                break;
            case 24:
                cout << "请输入姓名：";
                cin >> name;
                cout << "请输入需要修改的考勤序号（输入0表示不修改）：";
                cin >> n;
                if (n != 0) {
                    cout << "请输入考勤信息,以空格为间隔：" << endl;
                    cin >> timeHour >> timeMinute;
                }
                if ((timeHour > -1 && timeHour < 25) && (timeMinute > -1 && timeMinute < 61)) {
                    cout << "请输入总考勤次数：";
                    cin >> number;
                    auto alice = am.findAttendance(name);
                    if (alice != nullopt)
                    {
                        NUM = alice->getTimeHour().size() + 1;
                    }
                    else { NUM = 1; }
                    if (number = NUM)
                    {
                        cout << "请输入总工作时间（小时）：";
                        cin >> allTime;
                        am.updateAttendance(name, n, number, timeHour, timeMinute, allTime);
                        am.displayAll();
                    }
                    else {
                        cout << "请输入正确的考勤次数！正确的考勤次数应为：" << NUM << endl;
                    }
                }
                else
                {
                    cout << "请输入正确的时间格式！" << endl;
                }
                break;
            case 25:
                am.displayAll();
                break;
            case 26:
                am.displaySortedByNumber();
                break;
            case 27:
                am.displaySortedByAlltime();
                break;

            default:
                break;
            }
            command = 0;
        }
        else
        {
            cout << "请输入正确指令！" << endl;
            }
        if (command == 'q') { break; }
    }

    return 0;
}