#include<iostream>
#include<cmath>

using namespace std;

int main() {
    float x0 = 1, x1, x2, x;
    int n;
    cin >> x;
    x1 = x;
    cin >> n;
    if (n == 0) cout << 1;
    else if (n == 1) cout << x1;
    else for (int i = 2; i < n; ++i) {
        x2 = 2 * x * x1 - x0;
        x0 = x1; x1 = x2;
    }
    cout << x2;
}
