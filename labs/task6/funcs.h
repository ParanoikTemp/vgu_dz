#ifndef TASK6_1_FUNCS_H
#define TASK6_1_FUNCS_H
#include<iostream>
#include<windows.h>
#include<fstream>
#include<string>

using namespace std;

struct Book {
    char author[41];
    char name[81];
    char year[5];
    char specialty[41];
};

Book nextBook(istream& input_file); // функция выдает по одной книге из текстового файла
bool makeDatabase(const string& input_file_name, const string& output_file_name, int& len);  // .txt -> .bin
bool makeFile(const string& input_file_name, const string& output_file_name, const string& specialty, int len); // .bin -> .txt
string* setSpecialtys(iostream& input_file, int len, int& count); // список специальностей для меню
bool Interface(const string& input_file_name, const string& output_file_name, int count); // меню

#endif //TASK6_1_FUNCS_H
