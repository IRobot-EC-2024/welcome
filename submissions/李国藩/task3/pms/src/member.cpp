#include "member.h"

Member::Member(const std::string& name, int id) : name(name), id(id) {}

std::string Member::getName() const {
    return name;
}

int Member::getId() const {
    return id;
}