#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int giri[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, ves, sum;
    cout << "Input number: "; cin >> ves; cout << endl;
    int count = 0, code, k = 1;
    for (int i = 0; i < pow(2, 10); ++i) {
        if (i >= pow(2, k)) k += 1;
        sum = 0;
        code = i;
        for (int j = 0; j < k; ++j) {
            sum += giri[j] * (code % 2);
            code /= 2;
        }
        if (ves == sum) ++count;
    }
    cout << count;
    return 0;
}
