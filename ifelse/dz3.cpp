#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float x1, y1, x2, y2;
    cout << "Введите X1: "; cin >> x1; cout << endl;
    cout << "Введите Y1: "; cin >> y1; cout << endl;
    cout << "Введите X2: "; cin >> x2; cout << endl;
    cout << "Введите Y2: "; cin >> y2; cout << endl;
    float rast1 = sqrt(x1 * x1 + y1 * y1);
    float rast2 = sqrt(x2 * x2 + y2 * y2);
    if (rast1 > rast2) cout << "X: " << x1 << " Y: " << y1;
    else cout << "X: " << x2 << " Y: " << y2;
    return 0;
}
