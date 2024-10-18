#include "team.h"
#include <algorithm>
#include <iostream>

void Team::addMember(const Member &member) // 添加
{
    auto it = std::find_if(members.begin(), members.end(), [&](const Member &m)
                           { return m.getId() == member.getId(); }); // 遍历队员学号
    if (it != members.end())
    {
        throw std::invalid_argument("学号重复，无法添加。");
    }
    members.push_back(member);  // 将新的member对象添加到末尾
    attendances.emplace_back(); ////建立空的attendance
}

bool Team::removeMember(const std::string &id) // 删除
{
    auto it = std::find_if(members.begin(), members.end(), [&](const Member &m)
                           { return m.getId() == id; }); // 遍历
    if (it != members.end())
    {
        size_t index = it - members.begin();
        members.erase(it);
        attendances.erase(attendances.begin() + index);
        return true;
    }
    return false;
}

void Team::updateMember(const std::string &id, const std::string &name, const std::string &joinDate) // 更新学号
{
    for (auto &member : members)
    {
        if (member.getId() == id)
        {
            member.setName(name);
            member.setJoinDate(joinDate);
            return;
        }
    }
    throw std::invalid_argument("未找到指定学号的队员。");
}

void Team::displayMembers() const // 列出所有成员
{
    for (const auto &member : members)
    {
        member.displayInfo();
    }
}

void Team::sortMembersById() // 学号排序
{
    std::sort(members.begin(), members.end(), [](const Member &a, const Member &b)
              { return a.getId() < b.getId(); });
}

void Team::sortMembersByJoinDate() // 入队日期排序
{
    std::sort(members.begin(), members.end(), [](const Member &a, const Member &b)
              { return a.getJoinDate() < b.getJoinDate(); });
}

void Team::addAttendance(const std::string &id, const std::string &time, double duration) // 添加考勤
{
    auto it = std::find_if(members.begin(), members.end(), [&](const Member &m)
                           { return m.getId() == id; });
    if (it == members.end())
    {
        throw std::invalid_argument("未找到指定学号的队员。");
    }
    size_t index = it - members.begin();
    attendances[index].addRecord(time, duration);
}

void Team::displayAttendance(const std::string &id) const // 显示考勤
{
    auto it = std::find_if(members.begin(), members.end(), [&](const Member &m)
                           { return m.getId() == id; });
    if (it == members.end())
    {
        throw std::invalid_argument("未找到指定学号的队员。");
    }
    size_t index = it - members.begin();
    attendances[index].displayAttendance();
}
