#include <iostream>
#include <fstream>
#include <vector>

void printSubsetSums(const std::vector<int>& numbers, int targetSum, std::vector<int>& currentSubset, int currentIndex, int currentSum) {
    if (currentSum == targetSum) {
        std::cout << "Подмножество суммы " << targetSum << ": ";
        for (int num : currentSubset) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    if (currentIndex == numbers.size() || currentSum > targetSum) {
        return;
    }

    // Включаем текущий элемент и рекурсивно ищем подмножества
    currentSubset.push_back(numbers[currentIndex]);
    printSubsetSums(numbers, targetSum, currentSubset, currentIndex + 1, currentSum + numbers[currentIndex]);

    // Исключаем текущий элемент и рекурсивно ищем подмножества
    currentSubset.pop_back();
    printSubsetSums(numbers, targetSum, currentSubset, currentIndex + 1, currentSum);
}

int main() {
    std::string filename;
    std::cout << "Введите имя файла: ";
    std::cin >> filename;

    std::ifstream file(filename);
    if (!file) {
        std::cout << "Не удалось открыть файл." << std::endl;
        return 1;
    }

    int numCount;
    file >> numCount;

    std::vector<int> numbers(numCount);
    for (int i = 0; i < numCount; ++i) {
        file >> numbers[i];
    }

    file.close();

    int targetSum;
    std::cout << "Введите целевую сумму: ";
    std::cin >> targetSum;

    std::vector<int> currentSubset;
    printSubsetSums(numbers, targetSum, currentSubset, 0, 0);

    return 0;
}
