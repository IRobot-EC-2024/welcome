#ifndef MEMBER_H
#define MEMBER_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>  
#include <algorithm> 
#include <regex>

using namespace std;

class Member {
private:
    string student_id;//学号
    string name;//名字
    string entry_date;//入队时间
    string records;
    int times;
    int total_worktime;
    Member* next;
public:
    Member() :next(NULL) {}
    Member(string id, int t, int twt, string n, string ed, string r, Member* nxt = nullptr)
        : student_id(id), name(n), entry_date(ed), records(r), times(t), total_worktime(twt), next(nxt) {}

    void get_information(class  Member* head);//输入
    void get_student_id(class  Member* t);
    void get_name(class  Member* t);
    void delete_student_id(class  Member* t);
    void delete_name(class  Member* t);
    int put_information(class  Member* head);//输出
    /*更新*/
    void update(class  Member* head);
    void update_student_id(class  Member* head);
    void update_name(class  Member* head);
    void update_entry_date(class  Member* head);
    void update_records(class  Member* head);
    void update_times(class  Member* head);
    void update_total_worktime(class  Member* head);
    void update_all(class  Member* head);
    int read(class Member* head);
    void write(class Member* t);
    void sort_student_id(class Member*& head);
    void sort_times(class Member*& head);
    void sort_total_worktime(class Member*& head);
    void sort_entry_date(class Member*& head);
    bool operator<(const Member& other) const {
        return student_id < other.student_id;
        return times < other.times;
        return total_worktime < other.total_worktime;
        return entry_date < other.entry_date;
    }
    bool is_student_id_exists(Member* head, const string& student_id, const string& name) {
        while (head != nullptr) {
            if (head->student_id == student_id) {
                if (head->name != name) {

                    return true;
                }
            }
            head = head->next;
        }
        return false;
    }

    bool isValidTime(const std::string& timeStr) {

        std::regex timePattern(R"([01]?\d|2[0-3]):([0-5]?\d)");
        std::smatch match;

        if (std::regex_match(timeStr, match, timePattern)) {

            int hour = std::stoi(match[1]);
            int minute = std::stoi(match[2]);


            return true;
        }
        return false;
    }
};

void makeMenu();

#endif // !1
