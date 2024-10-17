#ifndef MEMBER_H
#define MEMBER_H

#include <string>

class Member {
public:
    Member(const std::string& name, int id) : name(name), id(id) {}
    
    std::string getName() const { return name; }
    int getId() const { return id; }

private:
    std::string name;
    int id;
};

#endif
