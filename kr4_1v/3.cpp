#include <iostream>
#include <fstream>
#include <string>
#include <set>

int main() {
    std::string filename;
    std::cout << "Введите имя текстового файла: ";
    std::cin >> filename;

    std::ifstream file(filename);
    if (!file) {
        std::cout << "Не удалось открыть файл." << std::endl;
        return 1;
    }

    std::string firstLine;
    std::getline(file, firstLine);

    std::set<char> characters(firstLine.begin(), firstLine.end());

    std::string outputFilename = "output.txt";
    std::ofstream outputFile(outputFilename);
    if (!outputFile) {
        std::cout << "Не удалось создать файл для записи." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        bool containsCharacters = false;
        for (char c : line) {
            if (characters.find(c) != characters.end()) {
                containsCharacters = true;
                break;
            }
        }
        if (!containsCharacters) {
            outputFile << line << std::endl;
        }
    }

    file.close();
    outputFile.close();

    std::cout << "Успешно записаны строки без символов из первой строки в файл " << outputFilename << std::endl;

    return 0;
}
