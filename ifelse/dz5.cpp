#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float x;
    cout << "Введите X: "; cin >> x; cout << endl;
    if (x < 0) cout << -4;
    else if (0 <= x && x <= 1) cout << x * x + 3 * x + 4;
    else cout << pow((x * x + 3 * x + 4), 2) - 1;
}
