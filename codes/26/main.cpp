#include "functions.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "Ru");
    int count = 0;
    string way = "C:\\cpp_files\\task10\\bag.txt";

    luggage** arr = setBags(way, count);
    if (arr == nullptr) return 0;

    printOneLuggagePassenger(arr, count);
    printMaxLugMinWei(arr, count);
    return 0;
}
