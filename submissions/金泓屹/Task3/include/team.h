#ifndef TEAM_H
#define TEAM_H

#include <vector>
#include <string>
#include <iostream>

class Team {
public:
    Team(); // ���캯��
    void addMember(const std::string& name, int student_id, int entry_year,int entry_month); // ��ӳ�Ա����
    void updateMember(size_t index, const std::string& name, int student_id, int entry_year, int entry_month); // ���³�Ա��Ϣ����
    void removeMember(size_t index); // ɾ����Ա����
    size_t findMember(const std::string& name) const; // ���ҳ�Ա����
    void printMembers() const; // ��ӡ��Ա��Ϣ����
    void printspecificMember(size_t index) const;
    void sortByStudentIDzeng();
    void sortByStudentIDjian();
    void sortByStudentEntryzeng();
    void sortByStudentEntryjian();
private:
    struct Person {
        std::string name;   // ����
        int student_id; // ѧ��
        int entry_year; // �����
        int entry_month;

        // ���캯��
        Person(const std::string& name, int student_id, int entry_year, int entry_month)
            : name(name), student_id(student_id), entry_year(entry_year) ,entry_month(entry_month){}
    };

    std::vector<Person> members; // �洢��Ա���ݵ�����
};

#endif // TEAM_H
