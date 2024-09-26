#include "member.h"
void Member::get_information(class  Member* head) {
    while (head->next != NULL)
    {
        head = head->next;
    }
    Member* newnode = new Member;
    head->next = newnode;
    newnode->next = NULL;
    cout << "�����룺ѧ�� ���� ���ʱ�� �򿨼�¼ �򿨴��� �ܹ�ʱ\n" << endl;
    cin >> newnode->student_id >> newnode->name >> newnode->entry_date >> newnode->records >> newnode->times >> newnode->total_worktime;
    if (is_student_id_exists(head, newnode->student_id, newnode->name))
    {
        cout << "���ǣ����ǡ�����������һ��ѧ��������  \n�Լ��ĸ�\n" << endl;
    }
    /* if (isValidTime(newnode->records)) {

     }
     else cout << "���ڣ�����Ҳ�ܴ����������³�����\n" << endl;*/


}

int Member::put_information(class  Member* head) {
    int i = 0;
    while (head->next != NULL) {
        i++;
        cout << i << "ѧ��: " << head->next->student_id << '\t';
        cout << "����" << head->next->name << '\t';
        cout << "���ʱ��" << head->next->entry_date << '\t';
        cout << "�򿨼�¼" << head->next->records << '\t';
        cout << "�򿨴��� " << head->next->times << '\t';
        cout << "�ܹ�ʱ" << head->next->total_worktime << endl;;
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
void Member::get_student_id(class  Member* t)//��ѧ�Ų�ѯ 
{
    string n;
    cout << "�����������ѯrmѧ��:" << endl;
    cin >> n;
    int count = 0;
    while (t->next != NULL)
    {
        if (t->next->student_id == n)
        {
            cout << "ѧ��: " << t->next->student_id << '\t';
            cout << "����" << t->next->name << '\t';
            cout << "���ʱ��" << t->next->entry_date << '\t';
            cout << "�򿨼�¼" << t->next->records << '\t';
            cout << "�򿨴��� " << t->next->times << '\t';
            cout << "�ܹ�ʱ" << t->next->total_worktime << endl;
            count++;
        }
        t = t->next;
    }
    if (count == 0)
    {
        cout << "���޴��ˣ�" << endl;
    }
}
void Member::get_name(class  Member* t)//��Ա��������ѯ 
{
    string n;
    cout << "�����������ѯ��������:" << endl;
    cin >> n;
    int count = 0;
    while (t->next != NULL)
    {
        if (t->next->name == n)
        {
            cout << "ѧ��: " << t->next->student_id << '\t';
            cout << "����" << t->next->name << '\t';
            cout << "���ʱ��" << t->next->entry_date << '\t';
            cout << "�򿨼�¼" << t->next->records << '\t';
            cout << "�򿨴��� " << t->next->times << '\t';
            cout << "�ܹ�ʱ" << t->next->total_worktime << endl;
            count++;
        }
        t = t->next;
    }
    if (count == 0)
    {
        cout << "���޴��ˣ�" << endl;
    }
}
void Member::delete_student_id(class  Member* t)//��Ա����ɾ�� 
{
    string n;
    cout << "����������ɾ��rmѧ��:" << endl;
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
            cout << "ɾ���ɹ���" << endl;
            count++;
            break;
        }
        t = t->next;
    }
    if (count == 0)
    {
        cout << "���޴��ˣ�" << endl;
    }
}
void Member::delete_name(class  Member* t)//��Ա����ɾ�� 
{
    string n;
    cout << "����������ɾ����������:" << endl;
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
            cout << "ɾ���ɹ���" << endl;
            count++;
            break;
        }
        t = t->next;
    }
    if (count == 0)
    {
        cout << "���޴��ˣ�" << endl;
    }
}
void Member::update(class  Member* head)
{
    int num = 0;
    cout << "1.�޸�ѧ��" << endl;
    cout << "2.�޸Ĵ�������" << endl;
    cout << "3.�޸Ĵ������ʱ��" << endl;
    cout << "4.�޸Ĵ��˴򿨼�¼" << endl;
    cout << "5.�޸Ĵ��˴򿨴���" << endl;
    cout << "6.�޸Ĵ��˲���" << endl;
    cout << "7.�޸�ȫ��" << endl;
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
    cout << "����Ҫ�޸Ķ����ѧ�ţ�" << endl;
    int count = 0;
    string temp;
    cin >> temp;
    while (head->next != NULL)
    {
        if (temp == head->next->student_id)
        {
            count = 1;
            cout << "������ѧ�ţ�" << endl;
            string temp2;
            cin >> temp2;
            head->next->student_id = temp2;
            cout << "�޸ĳɹ�" << endl;
            break;
        }
        head = head->next;
    }
    if (count == 0)
    {
        cout << "���޴���" << endl;
    }
}
void Member::update_name(class  Member* head)
{
    cout << "����Ҫ�޸Ķ����ѧ�ţ�" << endl;
    int count = 0;
    string temp;
    cin >> temp;
    while (head->next != NULL)
    {
        if (temp == head->next->student_id)
        {
            count = 1;
            cout << "���������֣�" << endl;
            string temp2;
            cin >> temp2;
            head->next->name = temp2;
            cout << "�޸ĳɹ�" << endl;
            break;
        }
        head = head->next;
    }
    if (count == 0)
    {
        cout << "���޴���" << endl;
    }
}
void Member::update_entry_date(class  Member* head)
{
    cout << "����Ҫ�޸Ķ����ѧ�ţ�" << endl;
    int count = 0;
    string temp;
    cin >> temp;
    while (head->next != NULL)
    {
        if (temp == head->next->student_id)
        {
            count = 1;
            cout << "���������ʱ�䣺" << endl;
            string temp2;
            cin >> temp2;
            head->next->entry_date = temp2;
            cout << "�޸ĳɹ�" << endl;
            break;
        }
        head = head->next;
    }
    if (count == 0)
    {
        cout << "���޴���" << endl;
    }

}
void Member::update_records(class  Member* head)
{
    cout << "����Ҫ�޸Ķ����ѧ�ţ�" << endl;
    int count = 0;
    string temp;
    cin >> temp;
    while (head->next != NULL)
    {
        if (temp == head->next->student_id)
        {
            count = 1;
            cout << "�����´򿨼�¼��" << endl;
            string temp2;
            cin >> temp2;
            head->next->records = temp2;
            cout << "�޸ĳɹ�" << endl;
            break;
        }
        head = head->next;
    }
    if (count == 0)
    {
        cout << "���޴���" << endl;
    }
}
void Member::update_times(class  Member* head)
{
    cout << "����Ҫ�޸Ķ����ѧ�ţ�" << endl;
    int count = 0;
    string temp;
    cin >> temp;
    while (head->next != NULL)
    {
        if (temp == head->next->student_id)
        {
            count = 1;
            cout << "�����´򿨴�����" << endl;
            int temp2;
            cin >> temp2;
            head->next->times = temp2;
            cout << "�޸ĳɹ�" << endl;
            break;
        }
        head = head->next;
    }
    if (count == 0)
    {
        cout << "���޴���" << endl;
    }
}
void Member::update_total_worktime(class  Member* head)
{
    cout << "����Ҫ�޸Ķ����ѧ�ţ�" << endl;
    int count = 0;
    string temp;
    cin >> temp;
    while (head->next != NULL)
    {
        if (temp == head->next->student_id)
        {
            count = 1;
            cout << "�������ܹ���ʱ�䣺" << endl;
            int temp2;
            cin >> temp2;
            head->next->total_worktime = temp2;
            cout << "�޸ĳɹ�" << endl;
            break;
        }
        head = head->next;
    }
    if (count == 0)
    {
        cout << "���޴���" << endl;
    }

}
void Member::update_all(class  Member* head)
{
    cout << "����Ҫ�޸Ķ���Ĺ��ţ�" << flush;
    int count = 0;
    string tmp;
    cin >> tmp;
    while (head->next != NULL)
    {
        if (tmp == head->next->student_id)
        {
            count = 1;
            cout << "������ѧ�ţ�" << endl;
            string temp;
            int tmp;
            cin >> temp;
            head->next->student_id = temp;
            cout << "���������֣�" << endl;
            cin >> temp;
            head->next->name = temp;
            cout << "���������ʱ�䣺" << endl;
            cin >> temp;
            head->next->entry_date = temp;
            cout << "�����´򿨼�¼��" << endl;
            cin >> temp;
            head->next->records = temp;

            cout << "�����´򿨴�����" << endl;
            cin >> tmp;
            head->next->times = tmp;
            cout << "����������ϵ�绰��" << endl;
            cin >> temp;
            head->next->total_worktime = tmp;
            cout << "�޸ĳɹ�" << endl;
            break;
        }
        head = head->next;
    }
    if (count == 0)
    {
        cout << "���޴���" << endl;
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
    cout << "����" << endl;
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
    printf("��Ա����ϵͳ\n");
    printf("===============\n");
    printf("1�������Ա\n");
    printf("2��ɾ����Ա\n");
    printf("3���г�������Ա\n");
    printf("4���޸���Ա��Ϣ\n");
    printf("5����ѯ������Ϣ\n");
    printf("6���޸Ŀ�����Ϣ\n");
    printf(">>>\n");
}