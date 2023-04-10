#include <iostream>
#include <string>
#include <vector>

struct man {
    std::string last_name, name, fatherhood;
    int age;
    int height;
    int eye_color[3];
    int hair_color[3];
    int salary;
    bool has_room, has_car;
    double cof; // коэффициент привлекательности
};

man** getMenArray(const std::string& filepath, int &len);
void menSort(man **men, int len);
void printMenArray(man **men, int len);
