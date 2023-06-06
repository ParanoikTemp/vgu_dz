#include <iostream>
#include <fstream>
#include <sstream>

int findMaxNumber(const std::string& line) {
    std::istringstream iss(line);
    int maxNumber = 0;
    int number;

    while (iss >> number) {
        if (number > maxNumber) {
            maxNumber = number;
        }
    }

    return maxNumber;
}

int main() {
    std::ifstream inputFile("input.txt"); // Имя файла для чтения
    std::ofstream outputFile("output.txt"); // Имя файла для записи

    if (!inputFile.is_open()) {
        std::cout << "Не удалось открыть входной файл." << std::endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        std::cout << "Не удалось открыть выходной файл." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        int maxNumber = findMaxNumber(line);
        outputFile << maxNumber << std::endl;
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Максимальные числа записаны в файл output.txt." << std::endl;

    return 0;
}
