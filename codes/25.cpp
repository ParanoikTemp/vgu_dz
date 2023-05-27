#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

double calculate_sum(int N, double x) {
    double result = 0.0;
    for (int i = 0; i < N; ++i) {
        double term = pow(-1, i) * pow(x, i);
        result += term;
    }
    return result;
}

double calculate_sum_with_threshold(double x, const double E, int& count) {
    double result = 0.0;
    count = 0;

    double term = 1.0;
    int i = 0;
    while (abs(term) > E && count < 300) {
        result += term;
        count++;
        i++;
        term = pow(-1, i) * pow(x, i);
    }

    return result;
}


int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "RU");
    double x;
    int terms[] = {1, 2, 3, 4, 5, 10, 15, 20, 30, 50};
    double precision[] = {0.1, 0.05, 0.025, 0.01, 0.005, 0.001, 0.0005,0.0001, 0.00005,0.000001};
    cout << "Введите x: (|x| < 1) "; cin >> x; cout << endl;
    double num = 1 / (1 + x);
    cout << "Результат функции: " << num << endl;
    cout << "Таблица результатов:\n";
    cout << " N   |  Сумма  |  Разница с фукнцией || Погрешность (precision)  |  Сумма |  Разница с фукнцией | \n";
    cout << "--------------------------------------\n";

    for (int i = 0; i < 10; i++) {
        double term_sum = calculate_sum(terms[i], x);

        int count;
        double term2_sum = calculate_sum_with_threshold(x, precision[i], count);

        cout << " " << terms[i] << "   |  " << term_sum << "  |  " << abs(num - term_sum) << "  ||  "<< precision[i] << " (Кол-во слагаемых: " << count << ")  |  " << term2_sum << "  |  " << abs(num - term2_sum)<< endl;
    }

    return 0;
}
