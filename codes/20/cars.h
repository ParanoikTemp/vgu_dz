#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>

using namespace std;

struct Number {
    int region = 0;
    int number = 0;
    string letters;
};

struct Car {
    char model[11];  // 10 символов + для конечного 1
    Number* number;
    int color[3] = {255, 255, 255};  // цвет в формате RGB
    string last_name;
    string name;
    string patronymic;
    string inspection;
};

Car **setCars(const string &name, int& count);
void func(Car** cars, int count);
Car* nextCar(ifstream& input);
void splitNumber(const string& input, string& chars, int& number1, int& number2);
Car* getCar(const Number& number, Car** cars, int len);
void printCar(const Car* car, const string& num);