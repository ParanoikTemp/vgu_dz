#include <iostream>
#include <limits>

using namespace std;

int main()
{
    int i = 1;
    float a, max = numeric_limits<float>::min(), min = numeric_limits<float>::max();
    while (i <= 10) {
        cout << "Введите " << i << " число: "; cin >> a; cout << endl;
        if (a > max) max = a;
        else if (a < min) min = a;
        ++i;
    }
    cout << "Разность чисел равна: " << max - min;
}
