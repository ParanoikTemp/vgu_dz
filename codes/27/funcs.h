#include <windows.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct Book
{
    char author[41]; // автор - 40 знаков + 1 символ для конца строки
    char title[81]; // название - 80 знаков + 1 символ для конца строки
    char year[5]; // год - 4 знака + 1 символ для конца строки
    char specialization[41]; // специальность - 40 знаков + 1 символ для конца строки
};

void convertFiles(const string& inputFile, const string& outputFile);
void processBinaryFile(const string& fileName);