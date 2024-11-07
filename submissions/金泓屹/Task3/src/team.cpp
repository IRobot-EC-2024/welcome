// Team.cpp
#include "team.h"
#include <iostream>
#include <algorithm> // ����std::find_if

// ���캯��
Team::Team() {}

// ��ӳ�Ա����
void Team::addMember(const std::string& name, int student_id, int entry_year,int entry_month) {
    members.emplace_back(name, student_id, entry_year,entry_month);
}

// ���³�Ա��Ϣ����
void Team::updateMember(size_t index, const std::string& name, int student_id, int entry_year,int entry_month) {
    if (index < members.size()) {
        members[index] = Person(name, student_id, entry_year,entry_month);
    }
    else {
        std::cerr << "Index out of range" << std::endl;
    }
}

// ɾ����Ա����
void Team::removeMember(size_t index) {
    if (index < members.size()) {
        members.erase(members.begin() + index);
    }
    else {
        std::cerr << "Index out of range" << std::endl;
    }
}

// ���ҳ�Ա����
size_t Team::findMember(const std::string& name) const {
    auto it = std::find_if(members.begin(), members.end(),
        [&name](const Person& person) {
            return person.name == name;
        });
    if (it != members.end()) {
        return std::distance(members.begin(), it);
    }
    return members.size(); // ����һ����Ч����
}

void Team::printspecificMember(size_t index) const{
    std::cout <<"Name: " << members[index].name
        << ", Student ID: " << members[index].student_id
        << ", Entry year: " << members[index].entry_year 
        <<",entry month:"<<members[index].entry_month << std::endl;
    }
// ��ӡ��Ա��Ϣ����
void Team::printMembers() const {
    int i = 1;
    for (const auto& member : members) {
        std::cout << i << "   " << "Name: " << member.name
            << ", Student ID: " << member.student_id
            << ", Entry year: " << member.entry_year 
            <<",entry month:"<<member.entry_month << std::endl;
    }
    if (members.empty()) {
        std::cout << "The team has no members." << std::endl;
    }
}

// ����ѧ�������Ա����
void Team::sortByStudentIDzeng() {
    std::sort(members.begin(), members.end(), [](const Person& a, const Person& b) {
        return a.student_id < b.student_id;
        });
}

void Team::sortByStudentIDjian() {
    std::sort(members.begin(), members.end(), [](const Person& a, const Person& b) {
        return a.student_id > b.student_id;
        });
}

void Team::sortByStudentEntryzeng() {
    std::sort(members.begin(), members.end(), [](const Person& a, const Person& b) {
        return a.entry_year < b.entry_year || (a.entry_year == b.entry_year && a.entry_month < b.entry_month);
        });
}
void Team::sortByStudentEntryjian() {
    std::sort(members.begin(), members.end(), [](const Person& a, const Person& b) {
        return a.entry_year > b.entry_year || (a.entry_year == b.entry_year && a.entry_month > b.entry_month);
        });
}