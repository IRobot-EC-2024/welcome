#ifndef TEAM_H
#define TEAM_H

#include "member.h"
#include "attendance.h"
#include <vector>

class Team {
public:
    // 队员
    void addMember(const Member& member);
    bool removeMember(const std::string& id);
    void updateMember(const std::string& id, const std::string& name, const std::string& joinDate);
    void displayMembers() const;
    void sortMembersById();
    void sortMembersByJoinDate();

    // 考勤
    void addAttendance(const std::string& id, const std::string& time, double duration);
    void displayAttendance(const std::string& id) const;
    void sortAttendanceByPunchCount();
    void sortAttendanceByWorkTime();

private:
    std::vector<Member> members;
    std::vector<Attendance> attendances;
};

#endif
