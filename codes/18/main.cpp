#include "funcs.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "RU");
    string filepath = "C:\\cpp_files\\numbers.txt";
    string dbpath = "C:\\cpp_files\\database.bin";
    string output = "C:\\cpp_files\\output.txt";
    ifstream file(filepath);
    if (!file.is_open()) {
        cout << "Ошибка открытия файла!";
        return 0;
    }
    int count;
    Chel** cheliki = setCheliki(file, count);
    makeDatabase(dbpath, cheliki, count);
    delete[] cheliki;
    Menu(dbpath, output);
    return 0;
}