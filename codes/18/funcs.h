#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

struct Address {
    char street[21];
    char number[5];
    char flat[4];
};

struct Chel {
    char fio[41];
    Address address;
    char number[7];
};

Chel* getChel(ifstream& file);
void makeDatabase(const string& input, const string& dbpath);
void Menu(const string input, const string output_file);