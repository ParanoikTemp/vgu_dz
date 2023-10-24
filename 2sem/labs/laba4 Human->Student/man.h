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
    Man(const Man &other);
    virtual ~Man();
    void setName(string name);
    void setAge(int age);
    void setSex(bool sex);
    void setWeight(float weight);
    Man& operator= (const Man &other);
};
