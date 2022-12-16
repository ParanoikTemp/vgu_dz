#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    double x, E, element, summa1 = 1, summa2 = 0, function;
    int N, count = 0;
    cin >> x >> N >> E;
    E *= 11;
    for (int i = 1; i < N; ++i) {
        int fact = 1;
        for (int j = 1; j <= i; ++j, fact *= i);
        summa1 += pow(x, i) * pow(-1, i) / (float) fact;
    }
    element = 1;
    while (abs(element) > E) {
        summa2 += element;
        ++count;
        int fact = 1;
        for (int j = 1; j <= count; ++j, fact *= count);
        element = pow(x, count) * pow(-1, count) / (float) fact;
    }
    function = pow(M_E, -1 * x);
    cout << "e^-x = " << function << endl;
    cout << "Summa 1: " << summa1 << " |e^-x - summa 1| = " << abs(function - summa1) << endl;
    cout << "Summa 2 (" << count << " elements): " << summa2 << " |e^-x - summa 2| = " << abs(function - summa2) << endl;
}
