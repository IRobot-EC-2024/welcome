#ifndef TEAM_H
#define TEAM_H

#include <vector>
#include <string>
#include <iostream>

class Team {
public:
    Team(); // 构造函数
    void addMember(const std::string& name, int student_id, int entry_year,int entry_month); // 添加成员函数
    void updateMember(size_t index, const std::string& name, int student_id, int entry_year, int entry_month); // 更新成员信息函数
    void removeMember(size_t index); // 删除成员函数
    size_t findMember(const std::string& name) const; // 查找成员函数
    void printMembers() const; // 打印成员信息函数
    void printspecificMember(size_t index) const;
    void sortByStudentIDzeng();
    void sortByStudentIDjian();
    void sortByStudentEntryzeng();
    void sortByStudentEntryjian();
private:
    struct Person {
        std::string name;   // 名字
        int student_id; // 学号
        int entry_year; // 入队年
        int entry_month;

        // 构造函数
        Person(const std::string& name, int student_id, int entry_year, int entry_month)
            : name(name), student_id(student_id), entry_year(entry_year) ,entry_month(entry_month){}
    };

    std::vector<Person> members; // 存储人员数据的向量
};

#endif // TEAM_H
