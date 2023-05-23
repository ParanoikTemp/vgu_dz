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

vector<Temperature> readTemperaturesFromFile(const string& filename) {
    vector<Temperature> temperatures;
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            Temperature temp;

            // Получение данных через getline с разделителем '!'
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

            temperatures.push_back(temp);
        }
        file.close();
    } else {
        cout << "Unable to open file: " << filename << endl;
    }
    return temperatures;
}

std::vector<std::string> findCities(const std::vector<Temperature>& temperatures) {
    std::vector<std::string> cities;
    float maxAverageTemperature = -std::numeric_limits<float>::max();

    for (const auto& temp : temperatures) {
        if (temp.month == "Июнь" && temp.distanceToMoscow <= 600) {
            float averageTemperature = (temp.morningTemp + temp.daytimeTemp + temp.eveningTemp) / 3.0f;
            if (averageTemperature > maxAverageTemperature) {
                maxAverageTemperature = averageTemperature;
                cities.clear();
                cities.push_back(temp.city);
            } else if (averageTemperature == maxAverageTemperature) {
                cities.push_back(temp.city);
            }
        }
    }

    return cities;
}


int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "RU");
    string filename = "C:\\cpp_files\\task5\\cities_data.txt"; // Имя файла с данными
    vector<Temperature> temperatures = readTemperaturesFromFile(filename);
    std::vector<std::string> cities = findCities(temperatures);
    // Вывод данных
    for (const auto& temp : cities) {
        cout << "City: " << temp << endl;
    }
    return 0;
}
