#include "code.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "RU");
    const string input = "C:\\cpp_files\\task2\\input.txt";
    const string binfile = "C:\\cpp_files\\task2\\binfile.bin";
    const string output = "C:\\cpp_files\\task2\\output.txt";
    createBinFile(input, binfile);
    createFinalFile(binfile, output);
    return 0;
}
