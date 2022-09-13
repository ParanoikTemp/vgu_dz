#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float x, y;
    cout << "Введите X: "; cin >> x; cout << endl;
    cout << "Введите Y: "; cin >> y; cout << endl;
    cout << (min(x, y) + 0.5) / (1 + pow(max(x, y), 2));
    return 0;
}
