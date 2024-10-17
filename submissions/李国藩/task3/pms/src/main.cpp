#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// Member 类定义
class Member {
public:
    Member(const std::string& name, int id, const std::string& joinDate) 
        : name(name), id(id), joinDate(joinDate) {}

    std::string getName() const { return name; }
    int getId() const { return id; }
    std::string getJoinDate() const { return joinDate; }
    void setName(const std::string& newName) { name = newName; }
    void setJoinDate(const std::string& newJoinDate) { joinDate = newJoinDate; }

private:
    std::string name;
    int id;
    std::string joinDate;  // 入队日期
};

// Attendance 类定义
class Attendance {
public:
    Attendance(int memberId) : memberId(memberId), totalWorkTime(0) {}

    int getMemberId() const { return memberId; }

    // 累积打卡记录和工作时间
    void addRecord(const std::string& record, int workTime) {
        records.push_back(record);  // 添加打卡记录
        workTimes.push_back(workTime);  // 添加工作时间
        totalWorkTime += workTime;  // 累积工作时间
    }

    // 修改特定的打卡记录和工作时间
    void modifyRecord(int index, const std::string& newRecord, int newWorkTime) {
        if (index >= 0 && index < records.size()) {
            totalWorkTime -= workTimes[index];  // 减去旧的工作时间
            records[index] = newRecord;  // 更新打卡记录
            workTimes[index] = newWorkTime;  // 更新工作时间
            totalWorkTime += newWorkTime;  // 累积新的工作时间
        }
    }

    // 获取打卡次数
    int getCheckInCount() const { return records.size(); }

    // 获取总工作时间
    int getTotalWorkTime() const { return totalWorkTime; }

private:
    int memberId;  // 成员ID
    std::vector<std::string> records;  // 打卡记录
    std::vector<int> workTimes;  // 每次打卡的工作时间
    int totalWorkTime;  // 总工作时间
};

// MemberManager 类中的考勤部分代码
// MemberManager 类定义
class MemberManager {
public:
    // 添加成员
    void addMember(const Member& member) {
        members.push_back(member);
    }
    
    // 删除成员
    void deleteMember(int id) {
        members.erase(std::remove_if(members.begin(), members.end(),
            [id](const Member& m) { return m.getId() == id; }), members.end());
    }

    // 查找成员
    Member* findMember(int id) {
        for (auto& member : members) {
            if (member.getId() == id) {
                return &member;
            }
        }
        return nullptr;
    }

    // 修改成员信息
    void modifyMember(int id, const std::string& newName, const std::string& newJoinDate) {
        Member* member = findMember(id);
        if (member) {
            member->setName(newName);
            member->setJoinDate(newJoinDate);
        }
    }

    // 按ID排序成员
    void sortMembersById() {
        std::sort(members.begin(), members.end(),
            [](const Member& a, const Member& b) { return a.getId() < b.getId(); });
    }

    // 按入队日期排序成员
    void sortMembersByJoinDate() {
        std::sort(members.begin(), members.end(),
            [](const Member& a, const Member& b) { return a.getJoinDate() < b.getJoinDate(); });
    }

    // 获取成员列表
    std::vector<Member>& getMembers() {
        return members;
    }

    // 添加考勤记录
    void addAttendanceRecord(int memberId, const std::string& record, int workTime) {
    Attendance* attendance = findAttendance(memberId);  // 查找成员的考勤记录
    if (attendance) {
        attendance->addRecord(record, workTime);  // 如果已有记录，添加新记录
    } else {
        Attendance newAttendance(memberId);  // 如果没有记录，为成员创建新的考勤记录
        newAttendance.addRecord(record, workTime);  // 添加第一次打卡记录
        attendances.push_back(newAttendance);  // 将新记录添加到考勤记录列表中
    }
}

    // 修改考勤记录
    void modifyAttendanceRecord(int memberId, int recordIndex, const std::string& newRecord, int newWorkTime) {
        Attendance* attendance = findAttendance(memberId);
        if (attendance) {
            attendance->modifyRecord(recordIndex, newRecord, newWorkTime);
        }
    }

    // 按打卡次数排序考勤记录
    void sortAttendanceByCheckInCount() {
        std::sort(attendances.begin(), attendances.end(),
            [](const Attendance& a, const Attendance& b) { return a.getCheckInCount() > b.getCheckInCount(); });
    }

    // 按总工作时间排序考勤记录
    void sortAttendanceByWorkTime() {
        std::sort(attendances.begin(), attendances.end(),
            [](const Attendance& a, const Attendance& b) { return a.getTotalWorkTime() > b.getTotalWorkTime(); });
    }

    // 获取考勤记录列表
    std::vector<Attendance>& getAttendances() {
        return attendances;
    }

private:
    std::vector<Member> members;
    std::vector<Attendance> attendances;

    // 查找考勤记录
    Attendance* findAttendance(int memberId) {
        for (auto& attendance : attendances) {
            if (attendance.getMemberId() == memberId) {
                return &attendance;
            }
        }
        return nullptr;
    }
};

// 打印菜单
void printMenu() {
    std::cout << "==============================" << std::endl;
    std::cout << "1. 添加成员" << std::endl;
    std::cout << "2. 删除成员" << std::endl;
    std::cout << "3. 查找成员" << std::endl;
    std::cout << "4. 修改成员信息" << std::endl;
    std::cout << "5. 添加考勤记录" << std::endl;
    std::cout << "6. 修改考勤记录" << std::endl;
    std::cout << "7. 排序成员信息" << std::endl;
    std::cout << "8. 排序考勤信息" << std::endl;
    std::cout << "9. 退出程序" << std::endl;
    std::cout << "==============================" << std::endl;
}

int main() {
    MemberManager manager;
    int choice;

    while (true) {
        printMenu();
        std::cout << "请输入操作编号: ";
        std::cin >> choice;

        if (choice == 1) {
            // 添加成员
            std::string name, joinDate;
            int id;
            std::cout << "请输入成员姓名: ";
            std::cin >> name;
            std::cout << "请输入成员ID: ";
            std::cin >> id;
            std::cout << "请输入入队日期(格式：YYYY-MM): ";
            std::cin >> joinDate;
            Member newMember(name, id, joinDate);
            manager.addMember(newMember);
            std::cout << "成员已添加: " << name << " (ID: " << id << ")" << std::endl;
        } 
        else if (choice == 2) {
            // 删除成员
            int id;
            std::cout << "请输入要删除的成员ID: ";
            std::cin >> id;
            manager.deleteMember(id);
            std::cout << "成员ID " << id << " 已删除。" << std::endl;
        } 
        else if (choice == 3) {
            // 查找成员
            int id;
            std::cout << "请输入要查找的成员ID: ";
            std::cin >> id;
            Member* foundMember = manager.findMember(id);
            if (foundMember) {
                std::cout << "找到成员: " << foundMember->getName() << ", ID: " << foundMember->getId() << ", 入队日期: " << foundMember->getJoinDate() << std::endl;
            } else {
                std::cout << "未找到ID为 " << id << " 的成员。" << std::endl;
            }
        } 
        else if (choice == 4) {
            // 修改成员信息
            int id;
            std::string newName, newJoinDate;
            std::cout << "请输入要修改的成员ID: ";
            std::cin >> id;
            std::cout << "请输入新的成员姓名: ";
            std::cin >> newName;
            std::cout << "请输入新的入队日期(格式：YYYY-MM): ";
            std::cin >> newJoinDate;
            manager.modifyMember(id, newName, newJoinDate);
            std::cout << "成员信息已更新。" << std::endl;
        } 
        else if (choice == 5) {
	    // 添加考勤记录
	    int id, workTime;
	    std::string record;
	    std::cout << "请输入成员ID: ";
	    std::cin >> id;
	    std::cout << "请输入打卡记录: ";
	    std::cin >> record;
	    std::cout << "请输入工作时间(分钟): ";
	    std::cin >> workTime;
	    manager.addAttendanceRecord(id, record, workTime);
	    std::cout << "考勤记录已添加。" << std::endl;
	}
        else if (choice == 6) {
            // 修改考勤记录
            int id, recordIndex, workTime;
            std::string newRecord;
            std::cout << "请输入成员ID: ";
            std::cin >> id;
            std::cout << "请输入要修改的记录编号: ";
            std::cin >> recordIndex;
            std::cout << "请输入新的打卡记录: ";
            std::cin >> newRecord;
            std::cout << "请输入新的工作时间(分钟): ";
            std::cin >> workTime;
            manager.modifyAttendanceRecord(id, recordIndex, newRecord, workTime);
            std::cout << "考勤记录已修改。" << std::endl;
        }
       else if (choice == 7) {
	    std::cout << "按1学号排序，按2入队日期排序: ";
	    int sortChoice;
	    std::cin >> sortChoice;
	    if (sortChoice == 1) {
		manager.sortMembersById();
		std::cout << "成员信息已按学号排序。" << std::endl;
		for (const auto& member : manager.getMembers()) {
		    std::cout << "成员姓名: " << member.getName() 
		              << ", 学号: " << member.getId() 
		              << ", 入队日期: " << member.getJoinDate() << std::endl;
		}
	    } else if (sortChoice == 2) {
		manager.sortMembersByJoinDate();
		std::cout << "成员信息已按入队日期排序。" << std::endl;
		for (const auto& member : manager.getMembers()) {
		    std::cout << "成员姓名: " << member.getName() 
		              << ", 学号: " << member.getId() 
		              << ", 入队日期: " << member.getJoinDate() << std::endl;
		}
	    } else {
		std::cout << "无效的选择。" << std::endl;
	    }
	}
        else if (choice == 8) {
	    std::cout << "按1打卡次数排序，按2工作时间排序: ";
	    int sortChoice;
	    std::cin >> sortChoice;
	    if (sortChoice == 1) {
		manager.sortAttendanceByCheckInCount();
		std::cout << "考勤信息已按打卡次数排序。" << std::endl;
		for (const auto& attendance : manager.getAttendances()) {
		    std::cout << "成员ID: " << attendance.getMemberId()
		              << ", 打卡次数: " << attendance.getCheckInCount()
		              << ", 总工作时间: " << attendance.getTotalWorkTime() << " 分钟" << std::endl;
		}
	    } else if (sortChoice == 2) {
		manager.sortAttendanceByWorkTime();
		std::cout << "考勤信息已按工作时间排序。" << std::endl;
		for (const auto& attendance : manager.getAttendances()) {
		    std::cout << "成员ID: " << attendance.getMemberId()
		              << ", 打卡次数: " << attendance.getCheckInCount()
		              << ", 总工作时间: " << attendance.getTotalWorkTime() << " 分钟" << std::endl;
		}
	    } else {
		std::cout << "无效的选择。" << std::endl;
	    }
	}
        else if (choice == 9) {
            // 退出程序
            std::cout << "退出程序。" << std::endl;
            break;
        } 
        else {
            std::cout << "无效的选择，请重新输入。" << std::endl;
        }
    }

    return 0;
}
