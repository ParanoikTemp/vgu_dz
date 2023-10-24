#include <string>
#include <iostream>

using namespace std;

class Man {
protected:
    string* name;
    int* age;
    bool* sex;
    float* weight;
public:
    Man(string name, int age, bool sex, float weight);
    virtual ~Man();
    void setName(string name);
    void setAge(int age);
    void setSex(bool sex);
    void setWeight(float weight);
};

class Student : public Man {
private:
    unsigned int* yearOfStudy;
public:
    Student(string name, int age, bool sex, float weight, unsigned int year);
    virtual ~Student();
    void setYearOfStudy(unsigned int year);
    Student& operator++();
    void print();
};
