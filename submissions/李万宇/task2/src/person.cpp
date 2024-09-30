#include "person.h"

// Person ���ʵ��
Person::Person(std::string name, long long number, int Year, int Month)
    : name_(name), number_(number), Year_(Year), Month_(Month) {}

std::string Person::getName() const { return name_; }
long long Person::getNumber() const { return number_; }
int Person::getYear() const { return Year_; }
int Person::getMonth() const { return Month_; }

void Person::setName(const std::string& name) { name_ = name; }
void Person::setNumber(long long number) { number_ = number; }
void Person::setYear(int year) { Year_ = year; }
void Person::setMonth(int month) { Month_ = month; }

// PersonManager ���ʵ��
void PersonManager::addPerson(const Person& person) {
    people_.push_back(person);
}

bool PersonManager::deletePerson(std::string name) {
    auto it = std::find_if(people_.begin(), people_.end(), [name](const Person& p) { return p.getName() == name; });
    if (it != people_.end()) {
        people_.erase(it);
        return true;
    }
    return false;
}

std::optional<Person> PersonManager::findPerson(std::string name) const {
    auto it = std::find_if(people_.begin(), people_.end(), [name](const Person& p) { return p.getName() == name; });
    if (it != people_.end()) {
        return *it;
    }
    return std::nullopt;
}

std::optional<Person> PersonManager::findNUmber(int number) const {
    auto it = std::find_if(people_.begin(), people_.end(), [number](const Person& p) { return p.getNumber() == number; });
    if (it != people_.end()) {
        return *it;
    }
    return std::nullopt;
}

bool PersonManager::updatePerson(std::string name, long long number, int Year, int Month) {
    auto it = std::find_if(people_.begin(), people_.end(),
        [name](const Person& p) { return p.getName() == name; });
    if (it != people_.end()) {
        it->setNumber(number);
        it->setYear(Year);
        it->setMonth(Month);
        return true;
    }
    return false;
}

void PersonManager::displayAll() const {
    for (const auto& person : people_) {
        std::cout << " ����: " << person.getName()
            << ", ѧ��: " << person.getNumber()
            << ", �������: " << person.getYear() << "��"
            << std::setw(2) << std::setfill('0') << person.getMonth() << "��"
            << std::endl;
    }
}

void PersonManager::displaySortedByNumber() {
    std::sort(people_.begin(), people_.end(), [](const Person& a, const Person& b) {
        return a.getNumber() < b.getNumber();
        });

    std::cout << "��ѧ�������Ľ��:" << std::endl;
    displayAll();
}

void PersonManager::displaySortedBydate() {
    std::sort(people_.begin(), people_.end(), [](const Person& a, const Person& b) {
        if (a.getYear() != b.getYear())
            return a.getYear() < b.getYear();
        return a.getMonth() < b.getMonth();
        });

    std::cout << "��������������Ľ��:" << std::endl;
    displayAll();
}