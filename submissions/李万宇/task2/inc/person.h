#ifndef PERSON_H
#define PERSON_H

#include "manage.h"

class Person {
public:
    Person(std::string name, long long number, int Year, int Month);

    std::string getName() const;
    long long getNumber() const;
    int getYear() const;
    int getMonth() const;

    void setName(const std::string& name);
    void setNumber(long long number);
    void setYear(int year);
    void setMonth(int month);

private:
    std::string name_;
    long long number_;
    int Year_;
    int Month_;
};

class PersonManager {
public:
    void addPerson(const Person& person);
    bool deletePerson(std::string name);
    std::optional<Person> findPerson(std::string name) const;
    std::optional<Person> findNUmber(int number) const;
    bool updatePerson(std::string name, long long number, int Year, int Month);
    void displayAll() const;
    void displaySortedByNumber();
    void displaySortedBydate();

private:
    std::vector<Person> people_;
};

#endif // PERSON_H