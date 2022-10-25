#include<iostream>

using namespace std;

int main()
{
    char cmd;
    int num, sum, i = 1;
    cout << "Введите выражение: \n";
    cin >> sum;
    while (cmd != '.') {
        if (i % 2) {
            cin >> cmd;
        } else {
            cin >> num;
            if (cmd == '+') sum += num;
            else sum -= num;
        }
        ++i;
    }
    cout << "Итоговая сумма: " << sum;
}
