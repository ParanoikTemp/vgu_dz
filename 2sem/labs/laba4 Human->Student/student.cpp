#include "student.h"

Student::Student(string name, int age, bool sex, float weight, unsigned int year): Man(name, age, sex, weight) {
    yearOfStudy = new unsigned int(year);
}

Student::Student(const Student &other): Man(other) {
    yearOfStudy = new unsigned int(*(other.yearOfStudy));
}

Student::~Student() {
    delete yearOfStudy;
}

void Student::setYearOfStudy(unsigned int year) {
    *yearOfStudy = year;
}

Student& Student::operator++() {
    ++(*yearOfStudy);
    return *this;
}

Student& Student::operator=(const Student &other) {
    Man::operator=(other);
    *yearOfStudy = *(other.yearOfStudy);
    return *this;
}

void Student::print() {
    cout << *name << ' ' << *age << ' ' << *sex << ' ' << *weight << ' ' << *yearOfStudy << endl;
}
