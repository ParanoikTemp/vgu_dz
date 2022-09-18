#include <iostream>

using namespace std;

int main()
{
    int a, b, sum = 0;
    cout << "Введите первое число: "; cin >> a; cout << endl;
    cout << "Введите второе число: "; cin >> b; cout << endl;
    if (b > a) a = b;
    while (a > 0) {
        sum += a % 10;
        a -= a % 10;
        a /= 10;
    }
    cout << "Сумма чисел: " << sum;
    return 0;
}
