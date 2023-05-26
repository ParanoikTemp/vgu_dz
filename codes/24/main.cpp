#include "persons.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "RU");
    string input_filename = "C:\\cpp_files\\task7\\input.txt";
    string output_filename = "C:\\cpp_files\\task7\\output.bin";
    processInputFile(input_filename, output_filename);
    searchAndPrintPerson(output_filename);
    return 0;
}
