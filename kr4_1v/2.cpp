#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream inputFile("f.txt"); // Имя файла для чтения
    std::ofstream outputFile("g.txt"); // Имя файла для записи

    if (!inputFile.is_open()) {
        std::cout << "Не удалось открыть входной файл." << std::endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        std::cout << "Не удалось открыть выходной файл." << std::endl;
        return 1;
    }

    // Вектор для хранения строк
    std::vector<std::string> lines;

    // Вектор для хранения счетчика использования символов
    std::vector<int> charCounts(256, 0); // Используем размер 256 для всех возможных символов ASCII

    std::string line;
    while (std::getline(inputFile, line)) {
        lines.push_back(line); // Добавляем строку в вектор строк

        // Обновляем счетчик использования символов для каждой строки
        for (char c : line) {
            // Игнорируем пробелы
            if (c != ' ') {
                charCounts[int(c)]++;
            }
        }
    }

    // Находим символ с наибольшим использованием
    int maxCount = 0;
    char mostFrequentChar = '\0';

    for (size_t i = 0; i < charCounts.size(); ++i) {
        if (charCounts[i] > maxCount) {
            maxCount = charCounts[i];
            mostFrequentChar = char(i);
        }
    }

    for (const std::string& currLine : lines) {
        // Проверяем, содержит ли строка самый часто используемый символ
        if (currLine.find(mostFrequentChar) != std::string::npos) {
            outputFile << currLine << std::endl;
        }
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Строки, содержащие самый часто используемый символ, записаны в файл g.txt." << std::endl;

    return 0;
}
