#include "funcs.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "RU");
    string filepath = "C:\\cpp_files\\task\\numbers.txt";
    string dbpath = "C:\\cpp_files\\task\\database.bin";
    string output = "C:\\cpp_files\\task\\output.txt";
    ifstream file(filepath);
    if (!file.is_open()) {
        cout << "Ошибка открытия файла!";
        return 0;
    }
    makeDatabase(filepath, dbpath);
    Menu(dbpath, output);
    return 0;
}