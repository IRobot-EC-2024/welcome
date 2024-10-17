#ifndef MEMBERMANAGER_H
#define MEMBERMANAGER_H

#include <vector>
#include "Member.h"
#include <algorithm>

class MemberManager {
public:
    void addMember(const Member& member) {
        members.push_back(member);
    }

    void deleteMember(int id) {
        members.erase(std::remove_if(members.begin(), members.end(), 
                        [id](const Member& m) { return m.getId() == id; }), members.end());
    }

    Member* findMember(int id) {
        for (auto& member : members) {
            if (member.getId() == id) return &member;
        }
        return nullptr;
    }

private:
    std::vector<Member> members;
};

#endif
