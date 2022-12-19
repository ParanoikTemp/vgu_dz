#include <iostream>
#include <cmath>

using namespace std;

double CalcS(double r1, double r2) {
    return pow(r1, 2) * M_PI - pow(r2, 2) * M_PI;
}

int main() {
    int len, j;
    cin >> len;
    double *r = new double [len], *l = new double [len], *A = new double [len], number;
    for (int i = 0; i < len; ++i) cin >> r[i];
    for (int i = 0; i < len; ++i) cin >> l[i];
    for (int i = 0; i < len; ++i) A[i] = CalcS(r[i], l[i]);

    for (int i = 0; i < len; i += 2) {
        number = A[i];
        for (j = i - 2; j >= 0 && number <= A[j]; j -= 2) A[j + 2] = A[j];
        A[j + 2] = number;
    }

    cout << "Result: " << endl;
    for (int i = 0; i < len; ++i) cout << A[i] << "\t";
}
