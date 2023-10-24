#include "classes.h"

Man::Man(string name, int age, bool sex, float weight) {
    this->name = new string(name);
    this->age = new int(age);
    this->sex = new bool(sex);
    this->weight = new float(weight);
}

void Man::setName(string name) {
    *(this->name) = name;
}

void Man::setAge(int age) {
    *(this->age) = age;
}

void Man::setSex(bool sex) {
    *(this->sex) = sex;
}

void Man::setWeight(float weight) {
    *(this->weight) = weight;
}

Man::~Man() {
    delete name;
    delete age;
    delete sex;
    delete weight;
};

Student::Student(string name, int age, bool sex, float weight, unsigned int year) : Man(name, age, sex, weight) {
    yearOfStudy = new unsigned int(year);
}

void Student::setYearOfStudy(unsigned int year) {
    *yearOfStudy = year;
}

Student& Student::operator++() {
    ++(*yearOfStudy);
    return *this;
}

void Student::print() {
    cout << *name << ' ' << *age << ' ' << *sex << ' ' << *weight << ' ' << *yearOfStudy << endl;
}

Student::~Student() {
    delete yearOfStudy;
}
