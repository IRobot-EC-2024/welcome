#include "manage.h"
#include "person.h"
#include "attendance.h"
using namespace std;



int main() {
    PersonManager pm;
    AttendanceManager am;
    cout << "--��ӭʹ��ս�ӿ���ϵͳ--" << endl
        << "�����" << endl
        << "0:�����" << endl
        << "11:��Ӷ�Ա        " << "21:��ӿ���" << endl
        << "12:���Ҷ�Ա��Ϣ    " << "22:���Ҷ�Ա������Ϣ" << endl
        << "13:ɾ����Ա��Ϣ    " << "23:ɾ����Ա������Ϣ" << endl
        << "14:���¶�Ա��Ϣ    " << "24:���¶�Ա������Ϣ" << endl
        << "15:��ʾ������Ա��Ϣ" << "25:��ʾ���п�����Ϣ" << endl
        << "16:��ѧ������      " << "26:�����ڴ�������" << endl
        << "17:�������������  " << "27:���ܹ���ʱ������" << endl;
    while (true) {
        int command; 
        cout << "���������" ;
        cin >> command;
        if (cin.fail()) {
            cin.clear(); // �������״̬
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������뻺����//-
            //cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������뻺����//+
            cout << "��������ȷ���������������\n";
        }
        else if(10 < command < 18 && 20<command <28) 
        {   
              string name; long long number = 0; string NewName; int year = 0; int month = 0;
            int n = 0; int timeHour = 0; int timeMinute = 0; int allTime = 0; int NUM = 0;
            switch (command)
            {
            case 0:
                cout << "�����" << endl
                    << "0:�����" << endl
                    << "11:��Ӷ�Ա        " << "21:��ӿ���" << endl
                    << "12:���Ҷ�Ա��Ϣ    " << "22:���Ҷ�Ա������Ϣ" << endl
                    << "13:ɾ����Ա��Ϣ    " << "23:ɾ����Ա������Ϣ" << endl
                    << "14:���¶�Ա��Ϣ    " << "24:���¶�Ա������Ϣ" << endl
                    << "15:��ʾ������Ա��Ϣ" << "25:��ʾ���п�����Ϣ" << endl
                    << "16:��ѧ������      " << "26:�����ڴ�������" << endl
                    << "17:�������������  " << "27:���ܹ���ʱ������" << endl;
                break;
            case 11:{
                cout << "������������";
                cin >> name;
                cout << "������ѧ�ţ�";
                cin >> number;
                auto alice = pm.findNUmber(number);
                if (alice != nullopt) { cout << "ѧ���Ѵ��ڣ�" << endl; }
                else {
                    cout << "�������������,�Կո�Ϊ�����" << endl;
                    cin >> year >> month;
                    if ((year > 2020 && year < 2026) && (month > 0 && month < 13)) {
                        pm.addPerson(Person(name, number, year, month));
                        am.addAttendance(name, 1, 0, 0, Attendance(name, 1, 0, 0, 0));
                        pm.displayAll();
                    }
                }
                break;
            }
            case 12: {//����
                cout << "������������";
                cin >> name;
                auto alice = pm.findPerson(name);
                if (alice) {
                    cout << "����: " << alice->getName() << ", ѧ��: " << alice->getNumber() << endl;
                }
                else { cout << "���޴���"; }
                break;
            }
            case 13://ɾ��
                cout << "������������";
                cin >> name;
                if (pm.deletePerson(name)) {
                    cout << "ɾ���ɹ�";
                }
                else {
                    cout << "���޴���" << endl;
                }
                pm.displayAll();
                break;
            case 14://����
                cout << "�������������Ա������";
                cin >> name;
                cout << "������ѧ�ţ�";
                cin >> number;
                cout << "�������������,�Կո�Ϊ�����" << endl;
                cin >> year;
                cin >> month;
                if ((year > 2020 && year < 2026) && (month > 0 && month < 13)) {
                    if (pm.updatePerson(name, number, year, month))
                    {
                        cout << "���³ɹ�";
                    }
                    else
                    {
                        cout << "���޴���" << endl;
                    }
                    pm.displayAll();
                }
                else
                {
                    cout << "��������ȷ�����£�" << endl;
                }
                break;
            case 15://��ʾ
                pm.displayAll();
                break;
            case 16://��ѧ������
                pm.displaySortedByNumber();
                break;
            case 17://�������������
                pm.displaySortedByNumber();
                break;
            case 21: {
                cout << "������������";
                cin >> name;
                cout << "�����뿼����Ϣ,�Կո�Ϊ�����" << endl;
                cin >> timeHour >> timeMinute;
                if ((timeHour > -1 && timeHour < 25) && (timeMinute > -1 && timeMinute < 61)) {
                    cout << "�������ܿ��ڴ�����";
                    cin >> number;
                    auto alice = am.findAttendance(name);
                    if (alice != nullopt)
                    {
                        NUM = alice->getTimeHour().size() + 1;
                    }
                    else { NUM = 1; }
                    if (number == NUM)
                    {
                        cout << "�������ܹ���ʱ�䣨Сʱ����";
                        cin >> allTime;
                        am.addAttendance(name, number, timeHour, timeMinute, Attendance(name, number, timeHour, timeMinute, allTime));
                        am.displayAll();
                    }
                    else {

                        cout << "��������ȷ�Ŀ��ڴ�������ȷ�Ŀ��ڴ���ӦΪ��" << NUM << endl;
    
                    }
                }
                else
                {
                    cout << "��������ȷ��ʱ���ʽ��" << endl;
                }
                break;
            }
            case 22: {
                cout << "������������";
                cin >> name;
                auto att = am.findAttendance(name);
                if (att) {
                    auto hour = att->getTimeHour();
                    auto minute = att->getTimeMinutes();
                    cout << "����: " << att->getName() << ", �ܿ��ڴ���: " << att->getNumber() << "���ܹ���ʱ��" << att->getAlltime() << endl;
                    for (int i = 0; i < hour.size(); i++)
                    {
                        cout << i + 1 << "��"
                            << hour[i] << "��"
                            << minute[i] << "��"
                            << endl;
                    }
                }
                else { cout << "���޴���"; }
                break;
            }
            case 23:
                cout << "";
                cin >> name;
                if (am.deleteAttendance(name))
                {
                    cout << "ɾ���ɹ���" << endl;
                }
                else
                {
                    cout << "���޴��ˣ�" << endl;
                }
                break;
            case 24:
                cout << "������������";
                cin >> name;
                cout << "��������Ҫ�޸ĵĿ�����ţ�����0��ʾ���޸ģ���";
                cin >> n;
                if (n != 0) {
                    cout << "�����뿼����Ϣ,�Կո�Ϊ�����" << endl;
                    cin >> timeHour >> timeMinute;
                }
                if ((timeHour > -1 && timeHour < 25) && (timeMinute > -1 && timeMinute < 61)) {
                    cout << "�������ܿ��ڴ�����";
                    cin >> number;
                    auto alice = am.findAttendance(name);
                    if (alice != nullopt)
                    {
                        NUM = alice->getTimeHour().size() + 1;
                    }
                    else { NUM = 1; }
                    if (number = NUM)
                    {
                        cout << "�������ܹ���ʱ�䣨Сʱ����";
                        cin >> allTime;
                        am.updateAttendance(name, n, number, timeHour, timeMinute, allTime);
                        am.displayAll();
                    }
                    else {
                        cout << "��������ȷ�Ŀ��ڴ�������ȷ�Ŀ��ڴ���ӦΪ��" << NUM << endl;
                    }
                }
                else
                {
                    cout << "��������ȷ��ʱ���ʽ��" << endl;
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
            cout << "��������ȷָ�" << endl;
            }
        if (command == 'q') { break; }
    }

    return 0;
}