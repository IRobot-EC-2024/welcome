#ifndef TEAM_MANAGER_H
#define TEAM_MANAGER_H

#include <vector>
#include "member.h"
#include "attendance.h"
#include <algorithm>

class MemberManager {
public:
    // 队员管理功能
    void addMember(const Member& member);
    void deleteMember(int id);
    Member* findMember(int id);
    void modifyMember(int id, const std::string& newName, const std::string& newJoinDate);
    void sortMembersById();  // 按学号排序
    void sortMembersByJoinDate();  // 按加入日期排序

    // 考勤管理功能
    void addAttendance(int memberId);
    void addAttendanceRecord(int memberId, const std::string& record, int workTime);
    void modifyAttendanceRecord(int memberId, int recordIndex, const std::string& record, int workTime);
    void sortAttendanceByWorkTime();  // 按工作时间排序
    void sortAttendanceByCheckInCount();  // 按打卡次数排序

private:
    std::vector<Member> members;
    std::vector<Attendance> attendanceList;  // 每个成员的考勤信息
};

#endif // TEAM_MANAGER_H
