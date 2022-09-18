#include <iostream>

using namespace std;

int main()
{
    int i = 1, p = 0, o = 0, p_count = 0, o_count = 0;
    float a;
    while (i <= 100) {
        cout << "Введите " << i << " число: "; cin >> a; cout << endl;
        if (a > 0) {
            ++p_count;
            p += a;
        }
        else if (a == 0) {
            ++o_count;
            o += a;
        }
        ++i;
    }
    cout << "Среднее значение положительных чисел: " << p / p_count << endl;
    cout << "Срежнее значение отрицательных чисел: " << o / o_count << endl;
}
