#ifndef TASK1_FUNCS_H
#define TASK1_FUNCS_H
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
using namespace std;

struct Product {
    float cost;
    char name[31];
    int count;
};

Product** setItemsList(const string& input_filename, int& count);
void saveItemsList(const string& output_filename, Product** items, int count);
void Interface(const string& output_filename);
#endif //TASK1_FUNCS_H
