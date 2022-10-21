#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    double x, E, sum1, sum2, fact, element;
    int N, count = 0;
    cout << "Введите x: "; cin >> x; cout << endl;
    cout << "Введите N: "; cin >> N; cout << endl;
    cout << "Введите E: "; cin >> E; cout << endl;
    for (int i = 0; i < N; ++i) {
        fact = 1;
        for (int j = 1; j <= i; ++j) fact *= j;
        sum1 += pow(x, i) / fact * pow(-1, i);
    }
    for (int i = 0; i < N; ++i) {
        fact = 1;
        for (int j = 1; j <= i; ++j) fact *= j;
        element = pow(x, i) / fact * pow(-1, i);
        if (abs(element) > E * 11) {sum2 += element; ++count;}
        else break;
    }
    cout << "Первая сумма: " << sum1 << endl;
    cout << "Вторая сумма: " << sum2 << endl;
    cout << "Количество слагаемых: " << count << endl;
    cout << "Результат расчета функции: " << pow(M_E, x * -1) << endl;
    cout << "Результат функции - сумма2 = " << pow(M_E, x * -1) - sum2;
    return 0;
}
