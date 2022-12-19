#include <iostream>
#include <cmath>

using namespace std;

double CalcS(double r1, double r2) {
    return pow(r1, 2) * M_PI - pow(r2, 2) * M_PI;
}

int main() {
    int len, j;
    cin >> len;
    double *r = new double [len], *l = new double [len], *X = new double [len], number;
    for (int i = 0; i < len; ++i) cin >> r[i];
    for (int i = 0; i < len; ++i) cin >> l[i];
    for (int i = 0; i < len; ++i) X[i] = CalcS(r[i], l[i]);

    for (int i = 0; i < len; i += 2) {
        number = X[i];
        for (j = i - 2; j >= 0 && number <= X[j]; j -= 2) X[j + 2] = X[j];
        X[j + 2] = number;
    }

    cout << "Result: " << endl;
    for (int i = 0; i < len; ++i) cout << X[i] << "\t";
}
