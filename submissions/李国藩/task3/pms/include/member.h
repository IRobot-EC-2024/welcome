#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <ctime>  // 用于处理日期

class Member {
public:
    Member(const std::string& name, int id, const std::string& joinDate);

    std::string getName() const;
    int getId() const;
    std::string getJoinDate() const;
    void setName(const std::string& newName);
    void setJoinDate(const std::string& newJoinDate);

private:
    std::string name;
    int id;
    std::string joinDate;  // 加入日期 (年月)
};

#endif // MEMBER_H
