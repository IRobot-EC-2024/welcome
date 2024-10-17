#ifndef ATTENDANCE_H
#define ATTENDANCE_H

#include <string>

class Attendance {
public:
    Attendance(int memberId, const std::string& date) : memberId(memberId), date(date) {}

    int getMemberId() const { return memberId; }
    std::string getDate() const { return date; }

private:
    int memberId;
    std::string date;
};

#endif
