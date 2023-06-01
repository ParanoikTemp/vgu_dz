#include "funcs.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "RU");

    string inputtxt = "C:\\cpp_files\\task11\\input.txt";
    string outputbin = "C:\\cpp_files\\task11\\output.bin";
    convertFiles(inputtxt, outputbin);
    processBinaryFile(outputbin);
    // Твой код здесь

    return 0;
}