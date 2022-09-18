#include <iostream>

using namespace std;

int main()
{
    int i = 1, p = 0, n = 0, o = 0;
    float a;
    while (i <= 100) {
        cout << "Введите " << i << " число: "; cin >> a; cout << endl;
        if (a > 0) ++p;
        else if (a == 0) ++n;
        else if (a < 0) ++o;
        ++i;
    }
    cout << "Положительных чисел: " << p << endl;
    cout << "Отрицательных чисел: " << o << endl;
    cout << "Нулей: " << n << endl;
}
