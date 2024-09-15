#include "team.h"
#include <algorithm>
#include <iostream>

void Team::addMember(const Member &member)
{
    auto it = std::find_if(members.begin(), members.end(), [&](const Member &m)
                           { return m.getId() == member.getId(); });
    if (it != members.end())
    {
        throw std::invalid_argument("学号重复，无法添加。");
    }
    members.push_back(member);
    attendances.emplace_back();
}

bool Team::removeMember(const std::string &id)
{
    auto it = std::find_if(members.begin(), members.end(), [&](const Member &m)
                           { return m.getId() == id; });
    if (it != members.end())
    {
        size_t index = it - members.begin();
        members.erase(it);
        attendances.erase(attendances.begin() + index);
        return true;
    }
    return false;
}

void Team::updateMember(const std::string &id, const std::string &name, const std::string &joinDate)
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

void Team::displayMembers() const
{
    for (const auto &member : members)
    {
        member.displayInfo();
    }
}

void Team::sortMembersById()
{
    std::sort(members.begin(), members.end());
}

void Team::sortMembersByJoinDate()
{
    std::sort(members.begin(), members.end(), [](const Member &a, const Member &b)
              { return a.getJoinDate() < b.getJoinDate(); });
}

void Team::addAttendance(const std::string &id, const std::string &time, double duration)
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

void Team::displayAttendance(const std::string &id) const
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

void Team::sortAttendanceByPunchCount()
{
    std::sort(attendances.begin(), attendances.end());
}

void Team::sortAttendanceByWorkTime()
{
    std::sort(attendances.begin(), attendances.end(), [](const Attendance &a, const Attendance &b)
              { return a.getTotalWorkTime() < b.getTotalWorkTime(); });
}
