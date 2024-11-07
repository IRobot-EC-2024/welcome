#ifndef ATTENDANCERECORD_H
#define ATTENDANCERECORD_H

#include <vector>
#include <string>
#include <algorithm>

struct AttendanceRecord {
    std::string name;
    std::vector<std::pair<int, int>> records;
    int totalMinutes;
    int count;
};

void addRecord(std::vector<AttendanceRecord>& records, const std::string& name, int hour, int minute);
void removeRecord(std::vector<AttendanceRecord>& records, const std::string& name);
void modifyRecord(std::vector<AttendanceRecord>& records, const std::string& name, int index, int hour, int minute);
void printRecord(const AttendanceRecord& record);
void printRecords(const std::vector<AttendanceRecord>& records, const std::string& name);
void sortRecordsByCountzeng(std::vector<AttendanceRecord>& records);
void sortRecordsByCountjian(std::vector<AttendanceRecord>& records);
void sortRecordsByTotalMinuteszeng(std::vector<AttendanceRecord>& records);
void sortRecordsByTotalMinutesjian(std::vector<AttendanceRecord>& records);
void removeSpecificRecord(std::vector<AttendanceRecord>& records, const std::string& name, int index);
void clearAllRecords(std::vector<AttendanceRecord>& records);
int tti(int hour, int minute);//时间变时间戳
int ith(int chuo);//时间戳变时间_h
#endif // ATTENDANCERECORD_H