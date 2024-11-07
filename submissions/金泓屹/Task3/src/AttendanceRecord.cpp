#include "AttendanceRecord.h"
#include <iostream>
#include<stdio.h>
///1111111
void addRecord(std::vector<AttendanceRecord>& records, const std::string& name, int hour, int minute) {
    for (auto& record : records) {
        if (record.name == name) {
            record.records.push_back({ hour, minute });
            record.totalMinutes += (hour * 60 + minute);
            record.count++;
            return;
        }
    }
    records.push_back({ name, {{hour, minute}}, hour * 60 + minute, 1 });
}

void removeRecord(std::vector<AttendanceRecord>& records, const std::string& name) {
    records.erase(std::remove_if(records.begin(), records.end(),
        [&name](const AttendanceRecord& record) { return record.name == name; }),
        records.end());
}

void modifyRecord(std::vector<AttendanceRecord>& records, const std::string& name, int index, int hour, int minute) {
    for (auto& record : records) {
        if (record.name == name) {
            if (index < record.records.size()) {
                int diffMinutes = hour * 60 + minute - (record.records[index].first * 60 + record.records[index].second);
                record.totalMinutes += diffMinutes;
                record.records[index] = { hour, minute };
            }
            return;
        }
    }
}

void printRecord(const AttendanceRecord& record) {
    std::cout << "Name: " << record.name << ", Total Minutes: " << record.totalMinutes
        << ", Count: " << record.count << ", Records: ";
    for (const auto& time : record.records) {
        std::cout << "(" << time.first << "h " << time.second << "m) ";
    }
    std::cout << std::endl;
}

void printRecords(const std::vector<AttendanceRecord>& records, const std::string& name) {
    for (const auto& record : records) {
        if (record.name == name) {
            printRecord(record);
            
        }
    }
}

void sortRecordsByCountzeng(std::vector<AttendanceRecord>& records) {
    std::sort(records.begin(), records.end(),
        [](const AttendanceRecord& a, const AttendanceRecord& b) {
            return a.count < b.count;
        });
}

void sortRecordsByCountjian(std::vector<AttendanceRecord>& records) {
    std::sort(records.begin(), records.end(),
        [](const AttendanceRecord& a, const AttendanceRecord& b) {
            return a.count > b.count;
        });
}


void sortRecordsByTotalMinuteszeng(std::vector<AttendanceRecord>& records) {
    std::sort(records.begin(), records.end(),
        [](const AttendanceRecord& a, const AttendanceRecord& b) {
            return a.totalMinutes < b.totalMinutes;
        });
}

void sortRecordsByTotalMinutesjian(std::vector<AttendanceRecord>& records) {
    std::sort(records.begin(), records.end(),
        [](const AttendanceRecord& a, const AttendanceRecord& b) {
            return a.totalMinutes < b.totalMinutes;
        });
}

void removeSpecificRecord(std::vector<AttendanceRecord>& records, const std::string& name, int index) {
    for (auto& record : records) {
        if (record.name == name && index < record.records.size()) {
            auto& recordTimes = record.records;
            int removedMinutes = recordTimes[index].first * 60 + recordTimes[index].second;
            record.totalMinutes -= removedMinutes;
            recordTimes.erase(recordTimes.begin() + index);
            record.count--;
            return;
        }
    }
}
//时间转时间戳
int tti(int hour, int minute) {
    return hour * 60 + minute;
}
//时间戳转时间_h
int ith(int chuo) {
    return chuo / 60;
}

void clearAllRecords(std::vector<AttendanceRecord>& records) {
    records.clear();
}