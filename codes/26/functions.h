#include <windows.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

struct luggage {
    int kolvo;
    int ves;
};

luggage** setBags(const string& way, int& count);
void printOneLuggagePassenger(luggage** arr, int count);
void printMaxLugMinWei(luggage** arr, int count);