#include<iostream>

using namespace std;

int main() {
    double x1 = 1, x2 = 1, x3 = 1, sum=3, x4;
    for (float i = 4; i <= 20; ++i) {
        x4 = (i + 3) * (x3 - 1) + (x2 + 4) * x1;
        sum += x4;
        x1 = x2; x2 = x3; x3 = x4;
    }
    cout << sum;
}
