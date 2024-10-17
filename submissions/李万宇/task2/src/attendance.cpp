#include "attendance.h"

// Attendance 类的实现
Attendance::Attendance(std::string name, int number, int timeHour, int timeMinutes, int alltime)
    : name_(name), number_(number), alltime_(alltime) {
    timeHour_.push_back(timeHour);
    timeMinutes_.push_back(timeMinutes);
}

std::string Attendance::getName() const { return name_; }
int Attendance::getNumber() const { return number_; }
std::vector<int> Attendance::getTimeHour() const { return timeHour_; }
std::vector<int> Attendance::getTimeMinutes() const { return timeMinutes_; }
int Attendance::getAlltime() const { return alltime_; }

void Attendance::setName(const std::string& name) { name_ = name; }
void Attendance::setNumber(int number) { number_ = number; }
void Attendance::setTime(int n, int timeHour, int timeMinutes) {
    timeHour_[n] = timeHour;
    timeMinutes_[n] = timeMinutes;
}
void Attendance::setAlltime(int alltime) { alltime_ = alltime; }
void Attendance::addTime(int timeHour, int timeMinutes) {
    timeHour_.push_back(timeHour);
    timeMinutes_.push_back(timeMinutes);
}

// AttendanceManager 类的实现
void AttendanceManager::addAttendance(std::string name, int num, int TH, int TM, const Attendance& attendance) {
    if (!addTimeForPerson(name, num, TH, TM)) {
        people_.push_back(attendance);
    }
}

bool AttendanceManager::addTimeForPerson(const std::string& name, int num, int timeHour, int timeMinutes) {
    auto it = std::find_if(people_.begin(), people_.end(),
        [&name](const Attendance& p) { return p.getName() == name; });
    if (it != people_.end()) {
        it->setNumber(num);
        it->addTime(timeHour, timeMinutes);
        return true;
    }
    return false;
}

bool AttendanceManager::deleteAttendance(std::string name) {
    auto it = std::find_if(people_.begin(), people_.end(),
        [&name](const Attendance& p) { return p.getName() == name; });
    if (it != people_.end()) {
        people_.erase(it);
        return true;
    }
    return false;
}

std::optional<Attendance> AttendanceManager::findAttendance(std::string name) const {
    auto it = std::find_if(people_.begin(), people_.end(),
        [&name](const Attendance& p) { return p.getName() == name; });
    if (it != people_.end()) {
        return *it;
    }
    return std::nullopt;
}

bool AttendanceManager::updateAttendance(std::string name, int n, int number, int timeHour, int timeMinutes, int alltime) {
    auto it = std::find_if(people_.begin(), people_.end(),
        [&name](const Attendance& p) { return p.getName() == name; });
    if (it != people_.end()) {
        it->setNumber(number);
        if (n != 0) { it->setTime(n - 1, timeHour, timeMinutes); }
        it->setAlltime(alltime);
        return true;
    }
    return false;
}

void AttendanceManager::displayAll() const {
    for (const auto& attendance : people_) {
        std::cout << " 姓名: " << attendance.getName()
            << ", 打卡次数: " << attendance.getNumber()
            << ",打卡总时间：" << attendance.getAlltime()
            << std::endl;
        auto hours = attendance.getTimeHour();
        auto minutes = attendance.getTimeMinutes();
        for (size_t i = 0; i < hours.size(); i++) {
            std::cout << i + 1 << ":"
                << hours[i] << "点"
                << minutes[i] << "分"
                << std::endl;
        }
    }
}

void AttendanceManager::displaySortedByNumber() {
    std::sort(people_.begin(), people_.end(), [](const Attendance& a, const Attendance& b) {
        return a.getNumber() < b.getNumber();
        });

    std::cout << "按考勤次数排序后的结果:" << std::endl;
    for (const auto& attendance : people_) {
        std::cout << " 姓名: " << attendance.getName()
            << ", 考勤次数: " << attendance.getNumber()
            << std::endl;
    }
}

void AttendanceManager::displaySortedByAlltime() {
    std::sort(people_.begin(), people_.end(), [](const Attendance& a, const Attendance& b) {
        return a.getAlltime() < b.getAlltime();
        });

    std::cout << "按工作时长排序后的结果:" << std::endl;
    for (const auto& attendance : people_) {
        std::cout << " 姓名: " << attendance.getName()
            << ", 工作时长: " << attendance.getAlltime()
            << std::endl;
    }
}