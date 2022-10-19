#include<iostream>

using namespace std;

int main() {
    float x1 = 1, x2 = 0.3, x3, sum=1.3;
    for (int i = 3; i <= 20; ++i) {
        x3 = (i + 1) * x1;
        sum += x3
        x1 = x2; x2 = x3;
    }
    cout << sum;
}
