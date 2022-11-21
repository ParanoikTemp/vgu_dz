#include <iostream>
#include <limits>

using namespace std;

int main() {
    int k, n;
    cout << "Input k and n values: ";
    cin >> k >> n; cout << endl;
    double a, min = numeric_limits<double>::max(), sum;
    for (int i = 0; i < n; ++i) {
        sum = 0;
        for (int j = 0; j < k; ++j) {
            cout << "Input " << i * k + j + 1 << " number: "; cin >> a; cout << endl;
            sum += a;
        }
        if (sum < min) min = sum;
    }
    cout << "Result: " << min;
    return 0;
}
