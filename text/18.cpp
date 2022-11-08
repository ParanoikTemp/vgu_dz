#include<iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    char k;
    while (k != '!') {
        if (k >= 'а' && k <= 'я') cout << k - ('a' - 'A');
        else cout << k;
        cin.get(k);
    }
}
