#include "funcs.h"
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "Ru");
    string filename = "D:\\cpp_files\\task4\\men.txt";
    int len;
    man **men = getMenArray(filename, len);
    menSort(men, len);
    printMenArray(men, len);
    cout << "С любовью, от Никиты Евстигнеева";
    return 0;
}
