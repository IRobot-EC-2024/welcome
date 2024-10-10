#include "member.h"
#include <stdexcept>
#include <regex>

Member::Member(const std::string &id, const std::string &name, const std::string &joinDate)
    : id(id), name(name)
{
    if (!isValidJoinDate(joinDate))
    {
        throw std::invalid_argument("无效的入队年月格式: " + joinDate);
    }
    this->joinDate = joinDate;
}

std::string Member::getId() const
{
    return id;
}

std::string Member::getName() const
{
    return name;
}

std::string Member::getJoinDate() const
{
    return joinDate;
}

void Member::setName(const std::string &name)
{
    this->name = name;
}

void Member::setJoinDate(const std::string &joinDate)
{
    if (!isValidJoinDate(joinDate))
    {
        throw std::invalid_argument("无效的入队年月格式: " + joinDate);
    }
    this->joinDate = joinDate;
}

void Member::displayInfo() const
{
    std::cout << "学号: " << id << ", 姓名: " << name << ", 入队年月: " << joinDate << std::endl;
}

bool Member::operator<(const Member &other) const
{
    return id < other.id;
}

bool Member::isValidJoinDate(const std::string &joinDate) const
{
    // 使用正则表达式检查日期格式
    std::regex datePattern(R"(\d{4}-\d{2})");
    return std::regex_match(joinDate, datePattern);
}
