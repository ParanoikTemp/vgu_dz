#include "cars.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "RU");
    string filename = "C:\\cpp_files\\task3\\cars.txt";
    int count = 0;
    Car** cars = setCars(filename, count);
    func(cars, count);
    return 0;
}


