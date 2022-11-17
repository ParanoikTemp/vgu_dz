#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    char str[] = "122128329";
    long int num = 0, len = sizeof(str) / sizeof(str[0]);
    for (int i = len - 2; i >= 0; --i) num += ((int) str[len - 2 - i] - 48) * pow(10, i);
    cout << num;
    return 0;
}
