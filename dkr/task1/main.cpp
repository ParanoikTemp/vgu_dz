#include "funcs.h"

// Создать бинарный файл, содержащий информации о товарах (цена, назв., кол.-во). Реализовать функцию добавления и удаления товара из файла

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "Ru");
    const string filename = "D:\\cpp_files\\dkr\\task1\\database.bin";
    Interface(filename);
    cout << "Хорошего дня!";
    return 0;
}
