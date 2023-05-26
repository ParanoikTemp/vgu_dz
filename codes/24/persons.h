#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <windows.h>

using namespace std;

struct Person {
    char full_name[41];
    char street[21];
    char house_number[5];
    char apartment[4];
    char phone_number[7];
};

void processInputFile(const string& input_filename, const string& output_filename);
Person findPersonByPhoneNumber(const string& filename, const char phone_number[7]);
void printPersonInfo(const Person& person);
void searchAndPrintPerson(const string& filename);