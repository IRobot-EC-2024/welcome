#ifndef MANAGE_H
#define MANAGE_H

#include "manage.h"
class Attendance {
public:
    Attendance(std::string name, int number, int timeHour, int timeMinutes, int alltime);

    std::string getName() const;
    int getNumber() const;
    std::vector<int> getTimeHour() const;
    std::vector<int> getTimeMinutes() const;
    int getAlltime() const;

    void setName(const std::string& name);
    void setNumber(int number);
    void setTime(int n, int timeHour, int timeMinutes);
    void setAlltime(int alltime);
    void addTime(int timeHour, int timeMinutes);

private:
    std::string name_;
    int number_;
    std::vector<int> timeHour_;
    std::vector<int> timeMinutes_;
    int alltime_;
};

class AttendanceManager {
public:
    void addAttendance(std::string name, int num, int TH, int TM, const Attendance& attendance);
    bool addTimeForPerson(const std::string& name, int num, int timeHour, int timeMinutes);
    bool deleteAttendance(std::string name);
    std::optional<Attendance> findAttendance(std::string name) const;
    bool updateAttendance(std::string name, int n, int number, int timeHour, int timeMinutes, int alltime);
    void displayAll() const;
    void displaySortedByNumber();
    void displaySortedByAlltime();

private:
    std::vector<Attendance> people_;
};

#endif // MANAGE_H