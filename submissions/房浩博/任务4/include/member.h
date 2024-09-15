#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <iostream>

class Member {
public:
    Member(const std::string& id, const std::string& name, const std::string& joinDate);

    std::string getId() const;
    std::string getName() const;
    std::string getJoinDate() const;

    void setName(const std::string& name);
    void setJoinDate(const std::string& joinDate);

    void displayInfo() const;

    bool operator<(const Member& other) const;

private:
    std::string id;
    std::string name;
    std::string joinDate;

    // 验证日期
    bool isValidJoinDate(const std::string& joinDate) const;
};

#endif 
