#ifndef ATTENDANCE_H
#define ATTENDANCE_H

#include <string>
#include <vector>

class Attendance
{
public:
    void addRecord(const std::string &time, double duration);
    void displayAttendance() const;
    double getTotalWorkTime() const;
    int getPunchCount() const;


private:
    std::vector<std::string> punchTimes;
    std::vector<double> workDurations;

    bool isValidDateTime(const std::string &datetime) const;
};

#endif // ATTENDANCE_H
