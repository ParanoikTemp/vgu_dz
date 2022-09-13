#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float x, y, r;
    cout << "Введите R: "; cin >> r; cout << endl;
    cout << "Введите X: "; cin >> x; cout << endl;
    cout << "Введите Y: "; cin >> y; cout << endl;
    float rast = sqrt(x * x + y * y);
    bool answer = ((abs(x) + abs(y) > r && rast <= r && x * y >= 0) || (abs(x) + abs(y) <= r && x * y < 0));
    cout << answer;
    return 0;
}
