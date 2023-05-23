#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
#include <limits>

using namespace std;

struct Temperature {
    string city;
    int distanceToMoscow;
    string month;
    int morningTemp;
    int daytimeTemp;
    int eveningTemp;
};

Temperature* readTemperaturesFromFile(const string& filename, int& size) {
    Temperature* temperatures = nullptr;
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        size = 0;
        while (getline(file, line)) {
            size++;
        }
        file.clear();
        file.seekg(0, ios::beg); // Сброс позиции чтения файла

        temperatures = new Temperature[size];

        for (int i = 0; i < size; i++) {
            Temperature& temp = temperatures[i];
            getline(file, temp.city, '!');
            getline(file, line, '!');
            temp.distanceToMoscow = stoi(line);
            getline(file, temp.month, '!');
            getline(file, line, '!');
            temp.morningTemp = stoi(line);
            getline(file, line, '!');
            temp.daytimeTemp = stoi(line);
            getline(file, line);
            temp.eveningTemp = stoi(line);
        }
        file.close();
    } else {
        cout << "Unable to open file: " << filename << endl;
    }
    return temperatures;
}

std::string* findCities(const Temperature* temperatures, int size, int& citiesCount) {
    std::string* cities = nullptr;
    float maxAverageTemperature = -std::numeric_limits<float>::max();
    citiesCount = 0;

    for (int i = 0; i < size; i++) {
        const Temperature& temp = temperatures[i];
        if (temp.month == "Июнь" && temp.distanceToMoscow <= 600) {
            float averageTemperature = (temp.morningTemp + temp.daytimeTemp + temp.eveningTemp) / 3.0f;
            if (averageTemperature > maxAverageTemperature) {
                maxAverageTemperature = averageTemperature;
                delete[] cities; // Освобождаем память от предыдущего массива
                cities = new std::string[1];
                cities[0] = temp.city;
                citiesCount = 1;
            } else if (averageTemperature == maxAverageTemperature) {
                std::string* tempArray = new std::string[citiesCount + 1];
                for (int j = 0; j < citiesCount; j++) {
                    tempArray[j] = cities[j];
                }
                tempArray[citiesCount] = temp.city;
                delete[] cities; // Освобождаем память от предыдущего массива
                cities = tempArray;
                citiesCount++;
            }
        }
    }

    return cities;
}


int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "RU");
    string filename = "C:\\cpp_files\\task5\\cities_data.txt"; // Имя файла с данными
    int size = 0;
    Temperature* temperatures = readTemperaturesFromFile(filename, size);
    int citiesCount = 0;
    std::string* cities = findCities(temperatures, size, citiesCount);

// Вывод данных
    for (int i = 0; i < citiesCount; i++) {
        cout << "City: " << cities[i] << endl;
    }

// Освобождаем выделенную память
    delete[] cities;
    return 0;
}
