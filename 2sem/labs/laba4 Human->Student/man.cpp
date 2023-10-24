#include "man.h"

Man::Man(string name, int age, bool sex, float weight) {
    this->name = new string(name);
    this->age = new int(age);
    this->sex = new bool(sex);
    this->weight = new float(weight);
}

Man::Man(const Man &other) {
    this->name = new string(*(other.name));
    this->age = new int(*(other.age));
    this->sex = new bool(*(other.sex));
    this->weight = new float(*(other.weight));
}

Man::~Man() {
    delete name;
    delete age;
    delete sex;
    delete weight;
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

Man& Man::operator= (const Man &other) {
    *name = *(other.name);
    *age = *(other.age);
    *sex = *(other.sex);
    *weight = *(other.weight);
    return *this;
}
