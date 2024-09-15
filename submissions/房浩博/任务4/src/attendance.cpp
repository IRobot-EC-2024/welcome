#include "attendance.h"
#include <iostream>
#include <stdexcept>
#include <regex>

void Attendance::addRecord(const std::string &time, double duration)
{
    if (!isValidDateTime(time))
    {
        throw std::invalid_argument("无效的时间格式: " + time);
    }
    if (duration <= 0)
    {
        throw std::invalid_argument("工作时间必须为正数。");
    }
    punchTimes.push_back(time);
    workDurations.push_back(duration);
}

int Attendance::getPunchCount() const
{
    return punchTimes.size();
}

double Attendance::getTotalWorkTime() const
{
    double total = 0;
    for (double duration : workDurations)
    {
        total += duration;
    }
    return total;
}

void Attendance::displayAttendance() const
{
    std::cout << "考勤记录：" << std::endl;
    for (size_t i = 0; i < punchTimes.size(); ++i)
    {
        std::cout << "时间: " << punchTimes[i] << ", 工作时长: " << workDurations[i] << "小时" << std::endl;
    }
}

bool Attendance::operator<(const Attendance &other) const
{
    if (getPunchCount() != other.getPunchCount())
    {
        return getPunchCount() < other.getPunchCount();
    }
    return getTotalWorkTime() < other.getTotalWorkTime();
}

bool Attendance::isValidDateTime(const std::string &datetime) const
{

    std::regex datetimePattern(R"(\d{4}-\d{2}-\d{2}-\d{2}-\d{2})");
    if (!std::regex_match(datetime, datetimePattern))
    {
        return false;
    }

    int year = std::stoi(datetime.substr(0, 4));
    int month = std::stoi(datetime.substr(5, 2));
    int day = std::stoi(datetime.substr(8, 2));
    int hour = std::stoi(datetime.substr(11, 2));
    int minute = std::stoi(datetime.substr(14, 2));

    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    if (hour < 0 || hour >= 24)
        return false;
    if (minute < 0 || minute >= 60)
        return false;
    return true;
}
