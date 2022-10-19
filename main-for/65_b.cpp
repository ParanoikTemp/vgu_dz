#include<iostream>
#include<cmath>

using namespace std;

int main() {
    float x, h;
    int n;
    cin >> h >> n;
    for (int i = 0; i <= n; ++i) {
        x = 1 + i * h;
        cout << x << "\t";
        cout << (x * x - 3 * x + 2) / sqrt(2 * pow(x, 3) - 1) << endl;
    }
}
