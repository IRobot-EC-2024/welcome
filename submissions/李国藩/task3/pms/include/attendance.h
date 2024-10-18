#ifndef ATTENDANCE_H
#define ATTENDANCE_H

#include <string>
#include <vector>

class Attendance {
public:
    Attendance(int memberId);

    int getMemberId() const;
    void addRecord(const std::string& record, int workTime);  // 添加打卡记录
    void modifyRecord(int index, const std::string& record, int workTime);  // 修改打卡记录
    std::vector<std::string> getRecords() const;
    int getTotalWorkTime() const;  // 获取总工作时间
    int getCheckInCount() const;  // 获取打卡次数

private:
    int memberId;
    std::vector<std::string> records;  // 打卡记录
    int totalWorkTime;  // 总工作时间
};

#endif // ATTENDANCE_H
