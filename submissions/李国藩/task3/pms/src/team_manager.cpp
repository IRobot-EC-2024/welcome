#include <iostream>
#include "include/member.h"
#include "include/team_manager.h"

int main() {
    MemberManager manager;
    manager.addMember(Member("Alice", 1));
    manager.addMember(Member("Bob", 2));

    Member* member = manager.findMember(1);
    if (member) {
        std::cout << "Found member: " << member->getName() << std::endl;
    }

    manager.deleteMember(1);
    member = manager.findMember(1);
    if (!member) {
        std::cout << "Member not found" << std::endl;
    }

    return 0;
}
