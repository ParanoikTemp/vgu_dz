#include "man.h"

class Student: public Man {
private:
    unsigned int* yearOfStudy;
public:
    Student(string name, int age, bool sex, float weight, unsigned int year);
    Student(const Student &other);
    virtual ~Student();
    void setYearOfStudy(unsigned int year);
    Student& operator++();
    Student& operator= (const Student &other);
    void print();
};
