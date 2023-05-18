#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <sstream>

using namespace std;

struct Exam {
    char object[11] = "Nothing";
    int mark = 0;
};

struct Student {
    char fio[41];
    int course;
    int group;
    bool education;
    Exam exams[50];
};

void createBinFile(const string& input, const string& output);
void createFinalFile(const string& input, const string& output);
