#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int N, count = 0;
    double x, E, el, sum1 = 0, sum2 = 0, fact;
    cin >> N >> x >> E;
    E *= 11;
    for (int i = 0; i < N; ++i) {
        fact = 1;
        for (int j = 1; j < i + 1; ++j) fact *= j;
        double drob = pow(x, i)/fact;
        sum1 += drob * pow(-1, i);
    }
    el = E + 1;
    int i = 0;
    while (el > E) {
        fact = 1;
        for (int j = 1; j < i + 1; ++j) fact *= j;
        double drob = pow(x, i)/fact;
        el += drob * pow(-1, i);
        ++i;
        if (abs(el) <= E) break;
        sum2 += el;
        ++count;
    }
    double func = pow(M_E, x);
    cout << "Сумма 1: " << sum1 << endl;
    cout << "Сумма 2: " << sum2 << endl;
    cout << "Количество слагаемых: " << count << endl;
    cout << "Результат функции: " << func << endl;
    cout << "Разница функции и суммы: " << func - sum2;
}
