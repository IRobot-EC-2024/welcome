#include "member.h"
void Member::get_information(class  Member* head) {
    while (head->next != NULL)
    {
        head = head->next;
    }
    Member* newnode = new Member;
    head->next = newnode;
    newnode->next = NULL;
    cout << "请输入：学号 姓名 入队时间 打卡记录 打卡次数 总工时\n" << endl;
    cin >> newnode->student_id >> newnode->name >> newnode->entry_date >> newnode->records >> newnode->times >> newnode->total_worktime;
    if (is_student_id_exists(head, newnode->student_id, newnode->name))
    {
        cout << "不是，哥们。。。。。。一个学号两个名  \n自己改改\n" << endl;
    }
    /* if (isValidTime(newnode->records)) {

     }
     else cout << "日期，这你也能错！！！——新程序别搞\n" << endl;*/


}

int Member::put_information(class  Member* head) {
    int i = 0;
    while (head->next != NULL) {
        i++;
        cout << i << "学号: " << head->next->student_id << '\t';
        cout << "姓名" << head->next->name << '\t';
        cout << "入队时间" << head->next->entry_date << '\t';
        cout << "打卡记录" << head->next->records << '\t';
        cout << "打卡次数 " << head->next->times << '\t';
        cout << "总工时" << head->next->total_worktime << endl;;
        head = head->next;
    }
    return i;
}

int Member::read(class Member* head)
{
    ofstream infile1;
    infile1.open("irobot.txt", ios::app);
    if (!infile1)
    {
        return 0;
    }
    else
    {
        infile1.close();
        ifstream infile;
        infile.open("irobot.txt", ios::in);
        while (!infile.eof())
        {
            Member* newnode = new Member;
            infile >> newnode->student_id;
            if (newnode->student_id.length() == 0)
            {
                delete newnode;
                break;
            }
            infile >> newnode->name;
            infile >> newnode->entry_date;
            infile >> newnode->records;
            infile >> newnode->times;
            infile >> newnode->total_worktime;
            head->next = newnode;
            head = head->next;
        }
        infile.close();
    }
    return 0;
}
void Member::write(class Member* t)
{
    ofstream outfile;
    outfile.open("irobot.txt", ios::out);
    while (t->next != NULL)
    {
        outfile << t->next->student_id << '\t';
        outfile << t->next->name << '\t';
        outfile << t->next->entry_date << '\t';
        outfile << t->next->records << '\t';
        outfile << t->next->times << '\t';
        outfile << t->next->total_worktime << endl;
        t = t->next;
    }
    outfile.close();
}
void Member::get_student_id(class  Member* t)//按学号查询 
{
    string n;
    cout << "请输入你想查询rm学号:" << endl;
    cin >> n;
    int count = 0;
    while (t->next != NULL)
    {
        if (t->next->student_id == n)
        {
            cout << "学号: " << t->next->student_id << '\t';
            cout << "姓名" << t->next->name << '\t';
            cout << "入队时间" << t->next->entry_date << '\t';
            cout << "打卡记录" << t->next->records << '\t';
            cout << "打卡次数 " << t->next->times << '\t';
            cout << "总工时" << t->next->total_worktime << endl;
            count++;
        }
        t = t->next;
    }
    if (count == 0)
    {
        cout << "查无此人！" << endl;
    }
}
void Member::get_name(class  Member* t)//按员工姓名查询 
{
    string n;
    cout << "请输入你想查询打工人姓名:" << endl;
    cin >> n;
    int count = 0;
    while (t->next != NULL)
    {
        if (t->next->name == n)
        {
            cout << "学号: " << t->next->student_id << '\t';
            cout << "姓名" << t->next->name << '\t';
            cout << "入队时间" << t->next->entry_date << '\t';
            cout << "打卡记录" << t->next->records << '\t';
            cout << "打卡次数 " << t->next->times << '\t';
            cout << "总工时" << t->next->total_worktime << endl;
            count++;
        }
        t = t->next;
    }
    if (count == 0)
    {
        cout << "查无此人！" << endl;
    }
}
void Member::delete_student_id(class  Member* t)//按员工号删除 
{
    string n;
    cout << "请输入你想删除rm学号:" << endl;
    cin >> n;
    int count = 0;
    while (t->next != NULL)
    {
        if (t->next->student_id == n)
        {
            Member* temp = t->next;
            t->next = t->next->next;
            delete temp;
            temp = NULL;
            cout << "删除成功！" << endl;
            count++;
            break;
        }
        t = t->next;
    }
    if (count == 0)
    {
        cout << "查无此人！" << endl;
    }
}
void Member::delete_name(class  Member* t)//按员工号删除 
{
    string n;
    cout << "请输入你想删除打工人姓名:" << endl;
    cin >> n;
    int count = 0;
    while (t->next != NULL)
    {
        if (t->next->name == n)
        {
            Member* temp = t->next;
            t->next = t->next->next;
            delete temp;
            temp = NULL;
            cout << "删除成功！" << endl;
            count++;
            break;
        }
        t = t->next;
    }
    if (count == 0)
    {
        cout << "查无此人！" << endl;
    }
}
void Member::update(class  Member* head)
{
    int num = 0;
    cout << "1.修改学号" << endl;
    cout << "2.修改打工人姓名" << endl;
    cout << "3.修改打工人入队时间" << endl;
    cout << "4.修改打工人打卡记录" << endl;
    cout << "5.修改打工人打卡次数" << endl;
    cout << "6.修改打工人部门" << endl;
    cout << "7.修改全部" << endl;
    cin >> num;
    switch (num)
    {
    case 1:
        update_student_id(head);
        break;
    case 2:
        update_name(head);
        break;
    case 3:
        update_entry_date(head);
        break;
    case 4:
        update_records(head);
        break;
    case 5:
        update_times(head);
        break;
    case 6:
        update_total_worktime(head);
        break;
    case 7:
        update_all(head);
        break;
    default:
        cout << "What did you fucking import...\n" << endl;
    }
}
void Member::update_student_id(class  Member* head)
{
    cout << "输入要修改对象的学号：" << endl;
    int count = 0;
    string temp;
    cin >> temp;
    while (head->next != NULL)
    {
        if (temp == head->next->student_id)
        {
            count = 1;
            cout << "输入新学号：" << endl;
            string temp2;
            cin >> temp2;
            head->next->student_id = temp2;
            cout << "修改成功" << endl;
            break;
        }
        head = head->next;
    }
    if (count == 0)
    {
        cout << "查无此人" << endl;
    }
}
void Member::update_name(class  Member* head)
{
    cout << "输入要修改对象的学号：" << endl;
    int count = 0;
    string temp;
    cin >> temp;
    while (head->next != NULL)
    {
        if (temp == head->next->student_id)
        {
            count = 1;
            cout << "输入新名字：" << endl;
            string temp2;
            cin >> temp2;
            head->next->name = temp2;
            cout << "修改成功" << endl;
            break;
        }
        head = head->next;
    }
    if (count == 0)
    {
        cout << "查无此人" << endl;
    }
}
void Member::update_entry_date(class  Member* head)
{
    cout << "输入要修改对象的学号：" << endl;
    int count = 0;
    string temp;
    cin >> temp;
    while (head->next != NULL)
    {
        if (temp == head->next->student_id)
        {
            count = 1;
            cout << "输入新入队时间：" << endl;
            string temp2;
            cin >> temp2;
            head->next->entry_date = temp2;
            cout << "修改成功" << endl;
            break;
        }
        head = head->next;
    }
    if (count == 0)
    {
        cout << "查无此人" << endl;
    }

}
void Member::update_records(class  Member* head)
{
    cout << "输入要修改对象的学号：" << endl;
    int count = 0;
    string temp;
    cin >> temp;
    while (head->next != NULL)
    {
        if (temp == head->next->student_id)
        {
            count = 1;
            cout << "输入新打卡记录：" << endl;
            string temp2;
            cin >> temp2;
            head->next->records = temp2;
            cout << "修改成功" << endl;
            break;
        }
        head = head->next;
    }
    if (count == 0)
    {
        cout << "查无此人" << endl;
    }
}
void Member::update_times(class  Member* head)
{
    cout << "输入要修改对象的学号：" << endl;
    int count = 0;
    string temp;
    cin >> temp;
    while (head->next != NULL)
    {
        if (temp == head->next->student_id)
        {
            count = 1;
            cout << "输入新打卡次数：" << endl;
            int temp2;
            cin >> temp2;
            head->next->times = temp2;
            cout << "修改成功" << endl;
            break;
        }
        head = head->next;
    }
    if (count == 0)
    {
        cout << "查无此人" << endl;
    }
}
void Member::update_total_worktime(class  Member* head)
{
    cout << "输入要修改对象的学号：" << endl;
    int count = 0;
    string temp;
    cin >> temp;
    while (head->next != NULL)
    {
        if (temp == head->next->student_id)
        {
            count = 1;
            cout << "输入新总共打卡时间：" << endl;
            int temp2;
            cin >> temp2;
            head->next->total_worktime = temp2;
            cout << "修改成功" << endl;
            break;
        }
        head = head->next;
    }
    if (count == 0)
    {
        cout << "查无此人" << endl;
    }

}
void Member::update_all(class  Member* head)
{
    cout << "输入要修改对象的工号：" << flush;
    int count = 0;
    string tmp;
    cin >> tmp;
    while (head->next != NULL)
    {
        if (tmp == head->next->student_id)
        {
            count = 1;
            cout << "输入新学号：" << endl;
            string temp;
            int tmp;
            cin >> temp;
            head->next->student_id = temp;
            cout << "输入新名字：" << endl;
            cin >> temp;
            head->next->name = temp;
            cout << "输入新入队时间：" << endl;
            cin >> temp;
            head->next->entry_date = temp;
            cout << "输入新打卡记录：" << endl;
            cin >> temp;
            head->next->records = temp;

            cout << "输入新打卡次数：" << endl;
            cin >> tmp;
            head->next->times = tmp;
            cout << "输入新入联系电话：" << endl;
            cin >> temp;
            head->next->total_worktime = tmp;
            cout << "修改成功" << endl;
            break;
        }
        head = head->next;
    }
    if (count == 0)
    {
        cout << "查无此人" << endl;
    }
}
void Member::sort_student_id(class Member*& head) {
    if (!head || !head->next) return;
    Member* sorted = nullptr;
    Member* current = head;
    Member* nextNode;
    while (current != nullptr) {
        nextNode = current->next;
        Member** insertPos = &sorted;
        while (*insertPos != nullptr && (*insertPos)->student_id < current->student_id) {
            insertPos = &(*insertPos)->next;
        }
        current->next = *insertPos;
        *insertPos = current;
        current = nextNode;
    }
    head = sorted;
}

void Member::sort_times(class Member*& head) {
    if (!head || !head->next) return;
    Member* sorted = nullptr;
    Member* current = head;
    Member* nextNode;
    while (current != nullptr) {
        nextNode = current->next;
        Member** insertPos = &sorted;
        while (*insertPos != nullptr && (*insertPos)->times < current->times) {
            insertPos = &(*insertPos)->next;
        }
        current->next = *insertPos;
        *insertPos = current;
        current = nextNode;
    }
    head = sorted;
}

void Member::sort_total_worktime(class Member*& head)
{
    if (!head || !head->next) return;
    Member* sorted = nullptr;
    Member* current = head;
    Member* nextNode;
    while (current != nullptr) {
        nextNode = current->next;
        Member** insertPos = &sorted;
        while (*insertPos != nullptr && (*insertPos)->total_worktime < current->total_worktime) {
            insertPos = &(*insertPos)->next;
        }
        current->next = *insertPos;
        *insertPos = current;
        current = nextNode;
    }
    head = sorted;
}
void Member::sort_entry_date(class Member*& head)
{
    if (!head || !head->next) return;
    Member* sorted = nullptr;
    Member* current = head;
    Member* nextNode;
    while (current != nullptr) {
        nextNode = current->next;
        Member** insertPos = &sorted;
        while (*insertPos != nullptr && (*insertPos)->entry_date < current->entry_date) {
            insertPos = &(*insertPos)->next;
        }
        current->next = *insertPos;
        *insertPos = current;
        current = nextNode;
    }
    head = sorted;
}
/*void Member::sort_student_id(class Member* head)
{
    cout << "排序：" << endl;
    int count = 0, a[10000] = { 0 }, b[10000], c[10000], g[10000] = { 0 }, tep = 0, count_1 = put_information(head);
    string d[10000], e[10000], f[10000];
    Member* sort = head;
    sort = head->next;
    while (count < count_1)
    {
        //int
        a[count] = stoi(sort->student_id);
        b[count] = sort->times;
        c[count] = sort->total_worktime;
        //string
        d[count] = sort->name;
        e[count] = sort->entry_date;
        f[count] = sort->records;

        sort = sort->next;
        count++;
    }
    for (int i = 0; i < count; i++)
    {
        g[i] = i;
    }

    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (a[i] > a[j])
            {
                int student_id = a[i];
                a[i] = a[j];
                a[j] = student_id;
                g[i] = j;
                g[j] = i;

            }
        }
    }

    int i = 0;
    sort = head->next;
    while (i < count_1) {
        sort->student_id = to_string(a[g[i]]);
        sort->times = b[g[i]];
        sort->total_worktime = c[g[i]];
        sort->name = d[g[i]];
        sort->entry_date = e[g[i]];
        sort->records = f[g[i]];
        sort = sort->next;
        i++;
    }
}*/



void makeMenu() {
    printf("人员管理系统\n");
    printf("===============\n");
    printf("1，添加人员\n");
    printf("2，删除人员\n");
    printf("3，列出所有人员\n");
    printf("4，修改人员信息\n");
    printf("5，查询考勤信息\n");
    printf("6，修改考勤信息\n");
    printf(">>>\n");
}