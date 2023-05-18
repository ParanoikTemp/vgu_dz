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

Chel** setCheliki(ifstream& file, int& count);
Chel* getChel(ifstream& file);
void makeDatabase(const string& dbpath, Chel** cheliki, int len);
void Menu(const string input, const string output_file);
